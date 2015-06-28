class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //The key is to map each character to its first occurrence in a string, so that the freq distribution is only relevant to the order of characters' occurrent in a string
        if (s.empty() && t.empty() || s == t)
            return true;
        
        const int LEN = s.size();
        
        return convert(s) == convert(t);
    }

private:
    string convert(const string &origin) {
        if (origin.empty())
            return origin;
            
        vector<int> firstOccurrence(256, -1);
        const int LEN = origin.size();
        
        string transformed = origin;
        
        for (int i = 0; i < LEN; i++) {
            int index = origin[i];  //Convert char to int
            if (firstOccurrence[index] == -1) { //First occurrence of s[i]
                firstOccurrence[index] = i;
            }
            
            transformed[i] = firstOccurrence[index];
        }
        
        return transformed;
    }
};
