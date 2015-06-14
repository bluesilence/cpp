class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        path.clear();
        results.clear();
        
        map<string, unordered_set<string>> adjacents;
        unordered_set<string> unvisited = dict;
        unordered_set<string> currentSteps;
        unordered_set<string> nextSteps;
        
        if (unvisited.find(start) != unvisited.end()) {
            unvisited.erase(start);
        }
        
        currentSteps.insert(start);
        
        while (!currentSteps.empty() && currentSteps.find(end) == currentSteps.end()) {
            nextSteps.clear();
            
            for (auto iter = currentSteps.begin(); iter != currentSteps.end(); iter++) {
                string originalWord = *iter;
                string adjWord = originalWord;
            
                for (int i = 0; i < adjWord.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c != adjWord[i]) {
                            adjWord[i] = c;
                            
                            if (unvisited.find(adjWord) != unvisited.end()) {
                                nextSteps.insert(adjWord);
                                adjacents[originalWord].insert(adjWord);
                            }
                        }
                    }
                    
                    adjWord[i] = originalWord[i];   //revert the change
                }
            }
            
            for (auto it = nextSteps.begin(); it != nextSteps.end(); it++) {
                unvisited.erase(*it);
            }
            
            currentSteps = nextSteps;
        }
        
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
