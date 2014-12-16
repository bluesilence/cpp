class Solution {
public:
    int longestValidParentheses(string s) {
        //Use 2 stack to store position of left and right parentheses that form valid pairs
        //Scan the string, if a right parentheses appears earlier than the left one, skip the parentheses
        //Otherwise, count it
        //Count the number of pairs whose right appears later than left, return 2 * size as length.
        stack<int> pair;
        bool *formedPair = new bool[s.size()];
        memset(formedPair, false, s.size());
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                pair.push(i);
            } else if (s[i] == ')') {
                if (!pair.empty()) {
                    formedPair[i] = true;
                    formedPair[pair.top()] = true;
                    pair.pop();
                }
            }
        }
        
        int maxLen = 0, len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (formedPair[i] == true) {
                len++;
                continue;
            }
            
            if (len > maxLen)
                maxLen = len;
            
            len = 0;
        }
        
        //All are valid pairs, the loop hasn't calculated maxLen
        if (len > maxLen)
                maxLen = len;
                
        delete formedPair;
        
        return maxLen;
    }
};
