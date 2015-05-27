class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        
        if (s.size() < 4)
            return results;
        
        restoreIpCore(results, "", s, 4);
        
        return results;
    }

private:
    void restoreIpCore(vector<string> &results, string result, string s, int n) {
        if (s.size() == 0 && n == 0) {
            results.push_back(result);
            return;
        }
        
        for (int i = 1; i <= 3 && i <= s.size(); i++) {  //The digits of this ip number
            if (i + 3 * (n-1) < s.size())   //pruning for next recursion
                continue;
            
            string ipStr = s.substr(0, i);
            if (isValidIpStr(ipStr)) {
                string ipStrWithDot = n > 1 ? ipStr + "." : ipStr;
                restoreIpCore(results, result + ipStrWithDot, s.substr(i, s.size() - i), n - 1);
            }
        }
    }
    
    bool isValidIpStr(string ipStr) {
        int ip = 0;
        
        if (ipStr[0] == '0' && ipStr.size() > 1)    //0 can only appear alone if it's the first number in the ipStr
            return false;
            
        for (int i = 0; i < ipStr.size(); i++) {
            if (ipStr[i] > '9' || ipStr[i] < '0')
                return false;
                
            ip *= 10;
            ip += ipStr[i] - '0';
            if (ip > 255)
                return false;
        }
        
        return true;
    }
};
