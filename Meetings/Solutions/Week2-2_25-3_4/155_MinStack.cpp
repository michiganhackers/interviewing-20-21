class MinStack {
    
private:
    
    vector<int> nums;
    vector<int> mins;
    
public:
    
    MinStack() {}
    
    void push(int x) {
        if(mins.empty() || x <= mins.back()) {
            mins.push_back(x);
        }
        nums.push_back(x);
    }
    
    void pop() {
        if(nums.back() == mins.back()) {
            mins.pop_back();
        }
        nums.pop_back();
    }
    
    int top() {
        return nums.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
