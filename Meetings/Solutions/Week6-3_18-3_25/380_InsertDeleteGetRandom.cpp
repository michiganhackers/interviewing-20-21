class RandomizedSet {
    
private:
    
    unordered_map<int, int> umap;
    vector<int> nums;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(umap.find(val) == umap.end()) {
            umap[val] = static_cast<int>(nums.size());
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(umap.find(val) != umap.end()) {
            nums[umap[val]] = nums.back();
            umap[nums.back()] = umap[val];
            nums.pop_back();
            umap.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
