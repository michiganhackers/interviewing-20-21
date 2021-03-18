class RandomizedCollection {
    
private:
    
    vector<int> nums;
    unordered_map<int, unordered_set<int>> umap;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        umap[val].insert(static_cast<int>(nums.size()));
        nums.push_back(val);
        return umap[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        
        if(umap.find(val) == umap.end() || umap[val].size() == 0) {
            return false;
        }
        
        if(nums.size() == 1) {
            nums.clear();
            umap.clear();
            return true;
        }
        
        int index = -1;
        
        for(auto& it : umap[val]) {
            index = it;
            break;
        }
        
        if(val == nums.back()) {
            umap[val].erase(static_cast<int>(nums.size()) - 1);
        } else {
            nums[index] = nums.back();
            umap[nums.back()].erase(static_cast<int>(nums.size()) - 1);
            umap[nums.back()].insert(index);
            umap[val].erase(index);
        }
        
        nums.pop_back();
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
