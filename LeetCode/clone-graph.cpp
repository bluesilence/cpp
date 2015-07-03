/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        
        UndirectedGraphNode *startNode = new UndirectedGraphNode(node->label);
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> oldNewMap;
        oldNewMap[node] = startNode;
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while (!q.empty()) {
            UndirectedGraphNode* tmp = q.front();
            q.pop();
            
            const int adjCount = tmp->neighbors.size();
            for (int i = 0; i < adjCount; i++) {
                if (oldNewMap.find(tmp->neighbors[i]) == oldNewMap.end()) {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(tmp->neighbors[i]->label);
                    oldNewMap[tmp->neighbors[i]] = newNode;
                    
                    q.push(tmp->neighbors[i]);
                }
                
                (oldNewMap[tmp]->neighbors).push_back(oldNewMap[tmp->neighbors[i]]);
            }
        }
        
        return startNode;
    }
};
