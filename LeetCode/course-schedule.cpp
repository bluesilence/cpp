class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses < 2 || prerequisites.empty())
            return true;
        
        map<int, unordered_set<int>> adjs;
        vector<bool> canBeStart(numCourses, true);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            adjs[prerequisites[i].second].insert(prerequisites[i].first);
            canBeStart[prerequisites[i].first] = false; //If a course appears as dependent, it cannot be startingCourse
        }
            
        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (canBeStart[i]) {
                if (DFSCheckCircle(adjs, visited, i)) {
                    return false;
                }
            }
        }
        
        //If there are trees without circle and trees with circles (no startingCourse for them), not all nodes can be visited
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] != 2) {
                return false;
            }
        }
        
        return true;
    }

private:
    bool DFSCheckCircle(map<int, unordered_set<int>> &adjs, vector<int> &visited, int startingCourse) {
        if (adjs.empty() || startingCourse < 0 || startingCourse >= visited.size())
            return false;
        
        visited[startingCourse] = 1;
        
        if (adjs.find(startingCourse) != adjs.end()) {
            unordered_set<int> dependents = adjs[startingCourse];
            for (auto iter = dependents.begin(); iter != dependents.end(); iter++) {
                if (visited[*iter] == 0) {
                    bool result = DFSCheckCircle(adjs, visited, *iter);
                    if (result) {   //Found circle including dependent courses
                        return true;
                    }
                } else if (visited[*iter] == 1) {   //Found circle including startingCourse
                    return true;
                }
            }
        }
        
        visited[startingCourse] = 2;
        
        return false;
    }
};
