class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> mp;
    RandomizedSet() {}
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        int index = mp[val];
        int last = nums.back();
        nums[index] = last;
        mp[last] = index;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
