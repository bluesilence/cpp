class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() < 2)
            return 0;
        
        //Store unmatched left parentheses
        stack<int> leftParens;
        //Store if the substring ended at i can form valid pair
        vector<bool> canFormPair(s.size(), false);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftParens.push(i);
            } else {
                if (!leftParens.empty()) {
                    canFormPair[i] = true;
                    canFormPair[leftParens.top()] = true;
                    leftParens.pop();
                }
            }
        }
        
        int maxLen = 0;
        int len = 0;    //The length of continuous canFormPair[i] == true
        
        for (int i = 0; i < s.size(); i++) {
            if (canFormPair[i]) {
                len++;
                continue;
            }
            
            //canFormPair[i] == false
            if (len > maxLen) {
                maxLen = len;
            }
            
            //Prepare for next valid substring
            len = 0;
        }
        
        //All the elements in canFormPair are true
        if (len > maxLen) {
            maxLen = len;
        }
        
		return maxLen;
    }
};
