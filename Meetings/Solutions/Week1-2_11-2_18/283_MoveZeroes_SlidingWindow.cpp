class Solution {
public:
    
    void swap(int& val1, int& val2) {
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }
    
    void findFirstZero(vector<int>& nums, int& firstZero, const int& curIndex) {
        while(nums[firstZero] != 0) {
            ++firstZero;
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        
        int curIndex = 0, firstZero = -1;
        
        while(curIndex < nums.size()) {
            
            if(nums[curIndex] == 0 && firstZero == -1) {
                
                // First zero encountered
                firstZero = curIndex;
                
            } else if(nums[curIndex] != 0 && firstZero != -1) {
                
                // Swapping the current element with our current first zero
                swap(nums[curIndex], nums[firstZero]);
                
                // Updating firstZero until we encounter a zero
                findFirstZero(nums, ++firstZero, curIndex);
                
            }
            ++curIndex;
        }
        
    }
};