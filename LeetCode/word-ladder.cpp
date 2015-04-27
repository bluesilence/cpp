class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		if (start.size() == 0 || end.size() == 0 || start == end || start.length() != end.length())
			return 0;
			
		unordered_set<string> currentSteps, nextSteps;    //All possible steps for current and next BFS layer
		unordered_set<string> unvisited = dict;
		
		unvisited.insert(end);
		
		currentSteps.insert(start);
		int len = 1;
		while (currentSteps.find(end) == currentSteps.end() && !unvisited.empty()) {
		    for (auto iter = currentSteps.begin(); iter != currentSteps.end(); iter++) {    //BFS
		        string tmp = *iter;
		        for (int i = 0; i < start.length(); i++) {
		            char c = tmp[i];
                    for (int j = 0; j < 26; j++) {
                        if (tmp[i] == 'a' + j)
                            continue;
                        
                        tmp[i] = 'a' + j;
                        if (unvisited.find(tmp) != unvisited.end()) {
                            nextSteps.insert(tmp);
                        }
                    }
                    
                    tmp[i] = c; //Revert this character
		        }
		    }
		    
		    if (nextSteps.empty())
		        break;
		
		    //Important: This erasion must be done after trying all possible words in the above loops
		    //Otherwise, some possible paths might be incorrectly excluded
		    for (auto iter = nextSteps.begin(); iter != nextSteps.end(); iter++) {
		        unvisited.erase(*iter);
		    }
		    
		    currentSteps = nextSteps;
		    len++;
		    
		    nextSteps.clear();
		}
		
		if (currentSteps.find(end) != currentSteps.end())
		    return len;
		else
		    return 0;
    }
};
