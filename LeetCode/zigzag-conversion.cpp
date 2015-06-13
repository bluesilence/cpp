class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows <= 1)
            return s;
        
        string tmpRows[numRows];
        
        int row = -1;
        int step = 1;
        
        for (int i = 0; i < s.size(); i++) {
            row += step;
            
            if (row >= numRows) {
                row = numRows - 2;  //Note: it's "- 2", not "- 1"
                step = -1;
            } else if (row < 0) {
                row = 1;
                step = 1;
            }
            
            tmpRows[row] += s[i];
        }
        
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result += tmpRows[i];
        }
        
        return result;
    }
};
