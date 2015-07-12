class Solution {
public:
    int numDecodings(string s) {
        //Define dp[N], dp[i] == the ways of decoding substring[0...i].
        //dp[0] = 1
        //dp[1] = dp[0] + (s[1] == '0' ? 0 : 1) + (isValid(substring[0...1]) ? 1 : 0)
        const int N = s.size();
        if (N == 0 || s[0] == '0')  //If the beginning is 0, there is no way to decode s
            return 0;
        
        vector<int> dp(N, 0);
        dp[0] = 1;
        
        for (int i = 1; i < N; i++) {
            if (s[i] == '0') {
                 //Invalid coding if current 0 cannot form a tens with previous character
                 if (!isValid(s[i-1], s[i])) {
                     return 0;
                 } else {
                     //Decode s[i-1, i] as 2 digits
                     dp[i] = i >= 2 ? dp[i-2] : 1;
                 }
            } else {
                 if (isValid(s[i-1], s[i])) {
                     //Decode s[i-1, i] as 2 digits
                     dp[i] = i >= 2 ? dp[i-2] : 1;
                 }
                 
                 //Decode s[i] as 1 digit
                 dp[i] += dp[i-1];
            }
        }
        
        return dp[N-1];
    }

private:
    bool isValid(char ten, char one) {
        if (ten == '0') //'0' cannot be the ten, it must be the one of previous tens
            return false;
            
        int num = 10 * (ten - '0') + (one - '0');
        
        return num <= 26 && num >= 10;
    }
};
