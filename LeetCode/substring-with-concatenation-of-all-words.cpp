class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        if (words.empty() || s.size() < words[0].size())
            return results;
        
        map<string, int> expectedCounts;
        map<string, int> actualCounts;
        
        const int wordsNum = words.size();
        const int wordLen = words[0].size();
        
        for (int i = 0; i < wordsNum; i++) {
            expectedCounts[words[i]]++;
        }
        
        for (int i = 0; i + wordsNum * wordLen <= s.size(); i++) {   //Starting index to find next substring
            actualCounts.clear();
            int j;
            for (j = 0; j < wordsNum; j++) {
                string substring = s.substr(i + j * wordLen, wordLen);
                if (expectedCounts.find(substring) == expectedCounts.end()) {
                    break;  //The substring doesn't exist in words
                }
                
                actualCounts[substring]++;
                
                if (actualCounts[substring] > expectedCounts[substring]) {
                    break;
                }
            }
            
            if (j == wordsNum) {    //Found all expected words
                results.push_back(i);
            }
        }
        
        return results;
    }
};
