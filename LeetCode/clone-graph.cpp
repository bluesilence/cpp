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
        if(!node)
            return NULL;
        
        map<int, UndirectedGraphNode*> nodes;  
        queue<UndirectedGraphNode*> q;  
        
        //First BFS to copy nodes
        q.push(node);
        while(!q.empty())  {  
            UndirectedGraphNode* tmp = q.front();
            q.pop();
            
            if(nodes.find(tmp->label) == nodes.end())  {  //Not visited
                UndirectedGraphNode* new_node = new UndirectedGraphNode(tmp->label);
                
                //Update pointer of original node with that of new node
                nodes[new_node->label] = new_node;
                
                for(int i = 0; i < tmp->neighbors.size(); i++)  {  
                    q.push(tmp->neighbors[i]);  
                }  
            }  
        }  
        
        
        //Second BFS to copy neighbors
        q.push(node);  
        while(!q.empty())  {  
            UndirectedGraphNode* tmp = q.front();  
            q.pop();
            
            UndirectedGraphNode* existingnode = nodes[tmp->label];  
            if(existingnode->neighbors.empty() && !tmp->neighbors.empty())  {   //Not visited
                for(int i = 0; i < tmp->neighbors.size(); i++)  {  
                    existingnode->neighbors.push_back(nodes[tmp->neighbors[i]->label]);  
                    q.push(tmp->neighbors[i]);  
                }  
            }  
        }  
          
        return nodes[node->label];  
    }  
};  
