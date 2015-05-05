class Solution {
public:
    bool isValid(string s) {
        //For right parentheses, the other 2 kind of left parentheses must be all matched
        //And the left parentheses of the same kind must have some left not matched yet
        //Otherwise, the string is invalid
        vector<int> counts(6, 0);
        stack<char> lastParen;
        
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    counts[0]++;
                    lastParen.push('(');
                    break;
                case '[':
                    counts[1]++;
                    lastParen.push('[');
                    break;
                case '{':
                    counts[2]++;
                    lastParen.push('{');
                    break;
                case ')':   //Bug: && is prior to >, need to use ()
                    if ((counts[0] > counts[3]) && lastParen.top() == '(') {
                        counts[3]++;
                        lastParen.pop();
                    } else {
                        return false;
                    }
                    
                    break;
                case ']':
                    if ((counts[1] > counts[4]) && lastParen.top() == '[') {
                        counts[4]++;
                        lastParen.pop();
                    } else {
                        return false;
                    }
                    
                    break;
                case '}':
                    if ((counts[2] > counts[5]) && lastParen.top() == '{') {
                        counts[5]++;
                        lastParen.pop();
                    } else {
                        return false;
                    }
                    
                    break;
            }
        }
        
        for (int i = 0; i < 3; i++) {
            if (counts[i] != counts[i+3])
                return false;
        }
        
        return true;
    }
};
