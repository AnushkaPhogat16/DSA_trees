class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int> workersSet(begin(workers), begin(workers) + mid); //take mid best workers

        //take easiest tasks
        //give hardest task to strongest worker
        for(int i = mid - 1; i >= 0; i--){
            int reqdStrength = tasks[i];
            auto it = prev(workersSet.end());

            if(*it >= reqdStrength){
                workersSet.erase(it);
            }else if(pillsUsed >= pills){
                return false;
            }else{
                //find the weakest worker who can do the strong task using pill
                auto weakestWorkerIt = workersSet.lower_bound(reqdStrength - strength);
                if(weakestWorkerIt == workersSet.end()){
                    return false;
                }
                workersSet.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }

        return true;

        
    }


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();

        int l = 0;
        int r = min(m, n);

        sort(tasks.begin(), tasks.end());
        sort(begin(workers), end(workers), greater<int>());

        int result = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return result;
    }
};

