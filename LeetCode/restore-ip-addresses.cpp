class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        
        if (s.size() < 4)
            return results;
        
        restoreIpCore(results, s, 0, "", 4);
        
        return results;
    }

private:
    void restoreIpCore(vector<string>& results, string &s, int begin, string ipStr, int unitsLeft) {
        if (begin == s.size() && unitsLeft == 0) {
            results.push_back(ipStr);
        } else {
            for (int unitLen = 1; unitLen < 4 && begin + unitLen <= s.size(); unitLen++) {
                if (begin + unitLen + 3 * (unitsLeft - 1) < s.size()) {
                    continue;
                }
                
                string unit = s.substr(begin, unitLen);
                if (isValidIPUnit(unit)) {
                    if (unitsLeft > 1) {
                        unit += '.';
                    }
                    
                    restoreIpCore(results, s, begin + unitLen, ipStr + unit, unitsLeft - 1);
                }
            }
        }
    }

    bool isValidIPUnit(string &unit) {
        if (unit.empty() || unit.size() > 3)
            return false;
        
        if (unit[0] == '0' && unit.size() > 1)
            return false;
        
        int ipNum = 0;
        for (int i = 0; i < unit.size(); i++) {
            if (unit[i] < '0' || unit[i] > '9') {
                return false;
            }
            
            ipNum *= 10;
            ipNum += unit[i] - '0';
            
            if (ipNum > 255) {
                return false;
            }
        }
        
        return true;
    }
};
