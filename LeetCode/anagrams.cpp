class Solution {  
public:  
    vector<string> anagrams(vector<string> &strs) {
        //Record the count of anagrams
        map<string, int> baseWord;  
        
        for(int i = 0; i < strs.size(); i++)  {  
            string tmpStr = strs[i];  
            sort(tmpStr.begin(), tmpStr.end());  
            if(baseWord.find(tmpStr) == baseWord.end())
                baseWord[tmpStr] = 1;
            else
                baseWord[tmpStr]++;  
        }  
          
        vector<string> results;  
        
        //Find if an original string has anagram
        for(int i = 0; i < strs.size(); i++)  {  
            string tmpStr = strs[i];  
            sort(tmpStr.begin(), tmpStr.end());
            if (baseWord.find(tmpStr) != baseWord.end() && baseWord[tmpStr] > 1)
                results.push_back(strs[i]);  
        }  
          
        return results;  
    }  
};  
