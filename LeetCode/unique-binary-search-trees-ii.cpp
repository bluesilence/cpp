/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> results;
        
        return generateCore(1, n);
    }

private:
    vector<TreeNode*> generateCore(int start, int end) {
        vector<TreeNode*> results;
        
        if (start > end) {
            results.push_back(NULL);    //So that one-sided trees can also leverage the double-loops in L29~30.
        } else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode*> leftTrees = generateCore(start, i - 1);
                vector<TreeNode*> rightTrees = generateCore(i + 1, end);
                
                for (int j = 0; j < leftTrees.size(); j++) {
                    for (int k = 0; k < rightTrees.size(); k++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = leftTrees[j];
                        root->right = rightTrees[k];
                        
                        results.push_back(root);
                    }
                }
            }
        }
        
        return results;
    }
};
