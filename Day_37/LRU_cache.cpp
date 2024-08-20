class LRUCache {
    class DLL{
      public:
        pair<int,int> Pair;
        DLL* prev;
        DLL* next;
        DLL(int x, int y){
            Pair.first = x;
            Pair.second = y;
            prev = NULL;
            next = NULL;
        }
    };
    map<int,DLL*> mp;
    DLL* start;
    DLL* end;
    int sz;
    
public:
    LRUCache(int capacity) {
        sz = capacity;
        DLL* temp = new DLL(-1,-1);
        DLL* temp2 = new DLL(-1,-1);
        start = temp;
        end = temp2;
        end->prev = start;
        start->next = end;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        deleteit(mp[key]);
        addtoStart(mp[key]);
        return mp[key]->Pair.second;
    }
    
    void put(int key, int value) {        
        if(mp.find(key) != mp.end())
        {
            DLL* temp = mp[key];
            deleteit(temp);
            mp.erase(key);
        }
        if(mp.size() == sz)
        {
            int k = end->prev->Pair.first;
            deleteit(end->prev);
            mp.erase(k);
        }
        DLL* newNode = new DLL(key,value);
        addtoStart(newNode);
        mp[key] = newNode;
    }
     
    void addtoStart(DLL* newNode) {
        DLL * temp = start -> next;
        newNode -> next = temp;
        newNode -> prev = start;
        start -> next = newNode;
        temp -> prev = newNode;
    }

    void deleteit(DLL * newNode) {
        DLL * temp1 = newNode -> prev;
        DLL * temp2 = newNode -> next;
        temp1 -> next = temp2;
        temp2 -> prev = temp1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */