class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        path.clear();
        results.clear();
        
        map<string, unordered_set<string>> adjacents;
        unordered_set<string> unvisited = dict;
        unordered_set<string> currentSteps;
        unordered_set<string> nextSteps;
        
        //Set start as visited
        if (unvisited.find(start) != unvisited.end()) {
            unvisited.erase(start);
        }
        
        currentSteps.insert(start);
        
        while (!currentSteps.empty() && currentSteps.find(end) == currentSteps.end()) {
            nextSteps.clear();
            
            for (auto iter = currentSteps.begin(); iter != currentSteps.end(); iter++) {
                string adjWord = *iter;
            
                for (int i = 0; i < adjWord.size(); i++) {
                    char originalChar = adjWord[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != adjWord[i]) {
                            adjWord[i] = c;
                            
                            if (unvisited.find(adjWord) != unvisited.end()) {
                                nextSteps.insert(adjWord);
                                
                                adjacents[*iter].insert(adjWord);
                            }
                        }
                    }
                    
                    adjWord[i] = originalChar;   //revert the change
                }
            }
            
            for (auto iter = nextSteps.begin(); iter != nextSteps.end(); iter++) {
                unvisited.erase(*iter);
            }
            
            currentSteps = nextSteps;
        }
        
        //Generate paths after generating all possible edges
        //It is recursive way, so put it after the while loop
        genPaths(adjacents, start, end);
        
        return results;
    }

private:
    vector<string> path;
    vector<vector<string>> results;
    
    void genPaths(map<string, unordered_set<string>> &adjacents, string start, string end) {
        path.push_back(start);
        
        if (start == end) {
            results.push_back(path);
        } else {
            unordered_set<string> adjs = adjacents[start];
            for (auto iter = adjs.begin(); iter != adjs.end(); iter++) {
                genPaths(adjacents, *iter, end);
            }
        }
        
        path.pop_back();
    }
};
