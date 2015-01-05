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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > results;
        vector<int> path;
        if (!root)
            return results;
        else
            pathSumCore(root, sum, path, results);
        
        return results;
    }
    
private:
    void pathSumCore(TreeNode *root, int sum, vector<int> &path, vector<vector<int> >& results) {
        if (!root->left && !root->right) {  //Is leaf node
            if (root->val == sum) { //Found a path
                path.push_back(root->val);
                results.push_back(path);
                path.pop_back();    //Remove current leaf node to try another way
            } else {    //This way is no way
                return;
            }
        } else {
            //Going this way
            path.push_back(root->val);
            
            //Going down to left
            if (root->left)
                pathSumCore(root->left, sum - root->val, path, results);
                
            //Going down to right
            if (root->right)
                pathSumCore(root->right, sum - root->val, path, results);
            
            //Not going this way
            path.pop_back();
        }
            
    }
};
