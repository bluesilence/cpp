class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        
        string temp[nRows];
        
        int idx = -1, step = 1;
        
        for (int i = 0; i < s.size(); i++) {
            //Next row to append
            idx += step;
            
            //Out of bound
            if (idx == nRows) {
                idx = nRows - 2;
                step = -1;
            } else if (idx == -1) { //Out of bound reversely
                idx = 1;
                step = 1;
            }
            
            temp[idx] += s[i];
        }
        
        string ans = temp[0];
        for (int i = 1; i < nRows; i++) {
            ans += temp[i];
        }
        
        return ans;
    }
};
