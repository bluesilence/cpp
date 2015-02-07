class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		map<string, int> expectedCount;
		map<string, int> occurredCount;
		
		int wordNum = L.size();
		int wordLen = L[0].size();
		
		for (int i = 0; i < wordNum; i++)
			expectedCount[L[i]]++;
		
		vector<int> results;
		
		for (int i = 0; i <= (int)S.size() - wordLen * wordNum; i++) {   //For all the possible starting index
			occurredCount.clear();
			int j;
			for (j = 0; j < wordNum; j++) {  //Get the jth word starting from index i
				string word = S.substr(i + j * wordLen, wordLen);
				if (expectedCount.find(word) == expectedCount.end())    //The current word is not in the list
					break;
					
				occurredCount[word]++;
				if (occurredCount[word] > expectedCount[word])   //Too many occurrence of word will break the match
					break;
			}
			
			if (j == wordNum)
				results.push_back(i);
		}
		
		return results;
	}
};
