/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> results = generateCore(1, n);  
        return results;
    }

private:
    vector<TreeNode *> generateCore(int start, int end) {
        vector<TreeNode *> results; 
        
        if (start > end) {  
            results.push_back(NULL);          
        } else {  
            for (int i = start; i <= end; i++) {
                //Collect all the possible subtrees
                vector<TreeNode *> left = generateCore(start, i - 1);  
                vector<TreeNode *> right = generateCore(i + 1, end); 
                
                //Combine with each possible subtree to form a new tree
                for (int j = 0; j < left.size(); j++) {  
                    for (int k = 0; k < right.size(); k++) {  
                        TreeNode *root = new TreeNode(i);  
                        root->left = left[j];  
                        root->right = right[k];  
                        results.push_back(root);  
                    }  
                }  
            }  
        }
        
        return results;
    }
};
