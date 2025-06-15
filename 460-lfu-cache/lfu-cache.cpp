class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int, list<vector<int>>::iterator> mp; // key -> address in dll
                    //address of each node
    map<int, list<vector<int>>> freq; // counter -> list w each node{key, value, counter}


    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = *(mp[key]);
        int value = vec[1];
        int f = vec[2]; //frequency

        freq[f].erase(mp[key]); //pass address

        if(freq[f].empty()) freq.erase(f);

        f++;
        freq[f].push_front({key, value, f});

        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        auto vec = (*(mp[key])); // mp[key] gives the address nd when we do *, directly gives us the node at that address
        //  the node is a vector {key, value, counter}
        int value = vec[1];

        // update as most recently used

        makeMostFrequentlyUsed(key);

        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(mp.find(key) != mp.end()){
            auto &vec = (*(mp[key]));
            vec[1] = value;

            makeMostFrequentlyUsed(key);
        }else if(size < cap){
            size++;

            // new so counter = 1 & front
            freq[1].push_front(vector<int>({{key, value, 1}}));
            mp[key] = freq[1].begin();
        }else{
            // remove lfu or lru if tie
            auto &lf_list = freq.begin() -> second;
            int key_to_delete = (lf_list.back())[0];

            lf_list.pop_back();

            if(lf_list.empty()){
                freq.erase(freq.begin() -> first); // map.erase(key) and the key is counter
            }

            freq[1].push_front(vector<int>({key, value, 1}));

            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */