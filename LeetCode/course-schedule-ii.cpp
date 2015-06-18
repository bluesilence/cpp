class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result;

        if (numCourses < 2 || prerequisites.empty())
            return result;
        
        map<int, unordered_set<int>> adjs;
        vector<bool> canBeStart(numCourses, true);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adjs[prerequisites[i].second].insert(prerequisites[i].first);
            canBeStart[prerequisites[i].first] = false;
        }
            
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (canBeStart[i]) {
                DFSCheckCircle(adjs, result, visited, i);
				        if (result.empty())
					        break;
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] != 2) {
                result.clear();
				        break;
			      }
        }
        
        return result;
    }

private:
    void DFSCheckCircle(map<int, unordered_set<int>> &adjs, vector<int> &result, vector<int> &visited, int startingCourse) {
        if (adjs.empty() || startingCourse < 0 || startingCourse >= visited.size())
            return;
        
        visited[startingCourse] = 1;
		    result.push_back(startingCourse);
        
        if (adjs.find(startingCourse) != adjs.end()) {
            unordered_set<int> dependents = adjs[startingCourse];
            for (auto iter = dependents.begin(); iter != dependents.end(); iter++) {
                if (visited[*iter] == 0) {
                    DFSCheckCircle(adjs, result, visited, *iter);
                    if (result.empty()) {
                        return;
                    }
                } else if (visited[*iter] == 1) {
					          result.clear();
                    return;
                }
            }
        }
        
        visited[startingCourse] = 2;
    }
};
