class RandomizedCollection {
public:
    vector<int> arr;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {}

    bool insert(int val) {
        arr.push_back(val);
        mp[val].insert(arr.size() - 1);
        return mp[val].size() <= 1;
    }

    bool remove(int val) {
        if (mp[val].size() == 0)
            return false;
        int ind = *mp[val].begin();
        mp[val].erase(ind);

        int num = arr.back();
        swap(arr[ind], arr[arr.size() - 1]);
        mp[num].insert(ind);
        mp[num].erase(arr.size() - 1);
        arr.pop_back();
        return true;
    }

    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */