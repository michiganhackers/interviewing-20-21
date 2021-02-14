    void findAllPalindromicSubstrings(const string& s, vector<vector<bool>>& isPalindrome) {
        
        isPalindrome[0][0] = true;
        
        for(int i = 1; i < s.length(); ++i) {
            
            isPalindrome[i][i] = true;
            
            if(s[i - 1] == s[i]) {
                isPalindrome[i - 1][i] = true;
            }
            
            for(int j = 0; j < i - 1; ++j) {
                if(s[j] == s[i] && isPalindrome[j + 1][i - 1]) {
                    isPalindrome[j][i] = true;
                }
            }
            
        }
        
    }
    
    void findMinCuts(const string& s, vector<int>& numPartitions, vector<vector<bool>>& isPalindrome) {
        
        for(int i = 1; i < s.length(); ++i) {
            
            int min = i;
            
            for(int j = 0; j <= i; ++j) {
                
               if(j == 0) {
                   if(isPalindrome[0][i]) {
                       min = 0;
                       break;
                   }
               } else {
                    if(isPalindrome[j][i] && numPartitions[j - 1] + 1 < min) {
                        min = numPartitions[j - 1] + 1 ;
                    } 
               }
                
            }
            
            numPartitions[i] = min;
            
        }
        
    }
    
    
    int getMinimumPartitions(string s) {
        
        if(s.length() < 2) {
            return 0;
        }
        
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        
        findAllPalindromicSubstrings(s, isPalindrome);
        
        vector<int> numPartitions(s.length(), 0);
        
        findMinCuts(s, numPartitions, isPalindrome);
        
        return numPartitions.back();
    }