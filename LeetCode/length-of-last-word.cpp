class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
            
        int lastWordBegin = 0;
        int lastWordEnd = s.size() - 1;
        
        for (; lastWordEnd >= 0 && s[lastWordEnd] == ' '; lastWordEnd--);
        
        if (lastWordEnd < 0)
            return 0;
        
        for (lastWordBegin = lastWordEnd - 1; lastWordBegin >= 0 && s[lastWordBegin] != ' '; lastWordBegin--);
        
        return lastWordEnd - lastWordBegin;
    }
};
