class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty())
            return true;
        
        const int sLEN = s.size();
        const int tLEN = t.size();
        
        if (sLEN != tLEN)
            return false;
        
        vector<int> charCounts(26, 0);
        
        for (int i = 0; i < sLEN; i++) {
            charCounts[s[i] - 'a']++;
        }
        
        for (int i = 0; i < tLEN; i++) {
            if (charCounts[t[i] - 'a'] == 0)
                return false;
                
            charCounts[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] > 0)
                return false;
        }
        
        return true;
    }
};
