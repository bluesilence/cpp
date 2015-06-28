struct Graph {
    int vertices;
    //adjs stores the prosteriors of each course
    vector<int> *adjs;
    
    Graph(int v) {
        vertices = v;
        adjs = new vector<int>[vertices];
    }
    
    //src: posterior course;
    //dest: prior course
    void addedges(int src, int dest) {
        adjs[dest].push_back(src);
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        Graph g(numCourses);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            g.addedges(prerequisites[i].first, prerequisites[i].second);
        }
        
        vector<int> result;
        stack<int> s;
        
        if(!courseScheduleCheck(g, s))
            return result;
        
        while(!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        
        return result;       
    }
    
    bool courseScheduleCheck(Graph &g, stack<int> &s) {
        int v = g.vertices;    
        vector<char> visited(v, 'w'); //'white': node not visited
        
        for (int i = 0; i < g.vertices; i++) {        
            if (visited[i] == 'w') {
                if (iscycle(g, i, visited, s)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool iscycle(Graph &g, int i, vector<char>& visited, stack<int> &s) {
        visited[i] = 'g';    //visiting node i
        
        for (auto iter = g.adjs[i].begin(); iter != g.adjs[i].end(); iter++) {
            if (visited[*iter] == 'g') { //'grey': node is being visiting as prior course
                return true;    //Found a cycle
            } else if (visited[*iter] == 'w') {
                if (iscycle(g, *iter, visited, s)) {   //Recursively DFS from node *iter
                    return true;
                }
            }     
        }
        
        //'black': All the posteriors of course i have been visited, and no cycle found
        visited[i] = 'b';
        
        s.push(i);
        
        return false;
    }
};
