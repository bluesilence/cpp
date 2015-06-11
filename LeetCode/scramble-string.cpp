class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        
        if (s1.empty() || s1 == s2)
            return true;
            
        if (!hasSameCharCount(s1, s2))
            return false;
            
        for (int len = 1; len < s1.size(); len++) {
            bool result = isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len));
            
            if (result)
                return true;
                
            result = isScramble(s1.substr(0, len), s2.substr(s2.size() - len)) && isScramble(s1.substr(len), s2.substr(0, s2.size() - len));
            
            if (result)
                return true;
        }
        
        return false;
    }
        
private:
    bool hasSameCharCount(string &s1, string &s2) {
        vector<int> charCount1(256, 0);
        vector<int> charCount2(256, 0);
        
        for (int i = 0; i < s1.size(); i++) {
            charCount1[s1[i]]++;
        }
        
        for (int i = 0; i < s2.size(); i++) {
            charCount2[s2[i]]++;
        }
        
        for (int i = 0; i < 256; i++) {
            if (charCount1[i] != charCount2[i])
                return false;
        }
        
        return true;
    }
};
