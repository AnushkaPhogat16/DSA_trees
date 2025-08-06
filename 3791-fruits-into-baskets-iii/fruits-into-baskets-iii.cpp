class Solution {
    int n;
    vector<int> seg; // segment tree for max

    // build tree over baskets[0..n-1]
    void build(const vector<int>& A, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = A[l];
            return;
        }
        int m = (l + r) >> 1;
        build(A, idx<<1,     l,   m);
        build(A, idx<<1|1, m+1,   r);
        seg[idx] = max(seg[idx<<1], seg[idx<<1|1]);
    }

    // update position pos -> value val
    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update(idx<<1,     l,   m, pos, val);
        else         update(idx<<1|1, m+1,   r, pos, val);
        seg[idx] = max(seg[idx<<1], seg[idx<<1|1]);
    }

    // find leftmost index in [l..r] with value >= x
    // returns n if none
    int findFirstGE(int idx, int l, int r, int x) {
        if (seg[idx] < x) return n;       // no such in this segment
        if (l == r) return l;             // leaf but ≥ x
        int m = (l + r) >> 1;
        if (seg[idx<<1] >= x)
            return findFirstGE(idx<<1,     l,   m, x);
        else
            return findFirstGE(idx<<1|1, m+1,   r, x);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n = baskets.size();
        seg.assign(4*n, 0);
        build(baskets, 1, 0, n-1);

        int unplaced = 0;
        for (int f : fruits) {
            int j = findFirstGE(1, 0, n-1, f);
            if (j == n) {
                // no basket can fit this fruit
                unplaced++;
            } else {
                // use basket j
                update(1, 0, n-1, j, 0);
            }
        }
        return unplaced;
    }
};
