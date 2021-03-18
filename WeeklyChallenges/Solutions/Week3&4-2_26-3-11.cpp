// Week 3 & 4 Interviewing Challenge C++ Solution

int getNumDecodings(string s) {
        
        if(s.empty()) return 0;
        
        vector<int> dp(s.length() + 1);
        dp[dp.size() - 1] = 1;
        dp[dp.size() - 2] = (s.back() == '0') ? 0 : 1;
        
        for(int i = static_cast<int>(s.length()) - 2; i >= 0; --i) {
            
            if(s[i + 1] == '0') {
                
                if(s[i] == '1' || s[i] == '2') {
                    dp[i] = dp[i + 2];
                } else {
                    return 0;
                }
                
            } else if(s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1] +
                    ((stoi(s.substr(i, 2)) <= 26)? dp[i + 2] : 0);
            }
            
        }
        
        return dp[0];
    }
