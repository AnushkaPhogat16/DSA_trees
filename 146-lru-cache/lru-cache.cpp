class LRUCache {
public:
    list<int> dll; //key
    // doubly linked list
     
    map<int, pair<list<int>::iterator, int>> mp;
    // address type in linked list

    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecentlyUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            // key does not exist
            return -1;
        }

        //have to mark as recently used
        makeRecentlyUsed(key);

        return mp[key].second;


    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }

        if(n < 0){
            int keyToDelete = dll.back();
            mp.erase(keyToDelete);

            dll.pop_back();
            n++;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */