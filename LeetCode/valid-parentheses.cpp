class Solution {
public:
    bool isValid(string s) {
        //Use an array to store the count of parantheses
        //Scan the string, for each character, if it is right parantheses, check if the corresponding left parantheses' count > right's count. If not, return false
        //0: '('
        //1: '{'
        //2: '['
        //3: ')'
        //4: '}'
        //5: ']'
        int parenCounts[6] = {0};
        stack<char> lastParen;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if ('(' == ch) {
                parenCounts[0]++;
                lastParen.push('(');
            } else if ('{' == ch) {
                parenCounts[1]++;
                lastParen.push('{');
            } else if('[' == ch) {
                parenCounts[2]++;
                lastParen.push('[');
            } else if (')' == ch) {   //Right parentheses must appear after left one
                if ((parenCounts[0] > parenCounts[3]) && lastParen.top() == '(') {
                    parenCounts[3]++;
                    lastParen.pop();
                } else {
                    return false;
                }
            } else if ('}' == ch) {
                if (parenCounts[1] > parenCounts[4] && lastParen.top() == '{') {
                    parenCounts[4]++;
                    lastParen.pop();
                } else {
                    return false;
                }
            } else if (']' == ch) {
                if (parenCounts[2] > parenCounts[5] && lastParen.top() == '[') {
                    parenCounts[5]++;
                    lastParen.pop();
                } else {
                    return false;
                }
            }
        }
        
        //Each left parentheses must be closed by a right one
        for (int i = 0; i < 3; i++) {
            if (parenCounts[i] != parenCounts[i + 3])
                return false;
        }
        
        return true;
    }
};
