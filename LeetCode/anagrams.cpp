class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> results;
        
        //Record the index of original string in strs for the first anagram
        map<string, int> anagramOriginMap;
        
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (anagramOriginMap.find(tmp) == anagramOriginMap.end()) {
                anagramOriginMap[tmp] = i;
            } else {
                if (anagramOriginMap[tmp] == -1) { //Already inserted the first anagram
                    results.push_back(strs[i]);
                } else {
                    results.push_back(strs[anagramOriginMap[tmp]]);    //First anagram
                    anagramOriginMap[tmp] = -1;
                    results.push_back(strs[i]);
                }
            }
        }
        
        return results;
    }
};
