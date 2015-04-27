class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        path.clear();
        results.clear();
        
        unordered_set<string> currentSteps, nextSteps;
        
        unordered_map<string, unordered_set<string>> adjs;
        
        unordered_set<string> unvisited = dict;
        
        if (unvisited.find(start) != unvisited.end())
            unvisited.erase(start);
            
        currentSteps.insert(start);
        
        while (currentSteps.find(end) == currentSteps.end() && !unvisited.empty()) {
            for (auto pCur = currentSteps.begin(); pCur != currentSteps.end(); pCur++) {
                string word = *pCur;
                
                for (int i = 0; i < start.length(); i++) {
                    for (int j = 0; j < 26; j++) {
                        string tmp = word;
                        if (tmp[i] == 'a' + j)
                            continue;
                        
                        tmp[i] = 'a' + j;
                        if (unvisited.find(tmp) != unvisited.end()) {
                            nextSteps.insert(tmp);
                            adjs[tmp].insert(word);
                        }
                    }
                }
            }
            
            if (nextSteps.empty())
                break;
            
            for (auto it = nextSteps.begin(); it != nextSteps.end(); it++) {
                unvisited.erase(*it);
            }
            
            currentSteps = nextSteps;
            nextSteps.clear();
        }
         
        if (currentSteps.find(end) != currentSteps.end()) {
            GeneratePath(adjs, end, start);
        }
        
        return results;
    }

private:
    vector<string> path;
    vector<vector<string>> results;
    
    void GeneratePath(unordered_map<string, unordered_set<string>> &adjs, const string &start, const string &end) {
        path.push_back(start);
        if (start == end) {
            vector<string> reversePath = path;
            reverse(reversePath.begin(), reversePath.end());
            results.push_back(reversePath);
            return;
        }
        
        unordered_set<string> adjacentStrings = adjs[start];
        for (auto it = adjacentStrings.begin(); it != adjacentStrings.end(); it++) {
            GeneratePath(adjs, *it, end);
            path.pop_back();
        }
    }
};
