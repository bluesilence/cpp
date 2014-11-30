class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (1 == triangle.size())   //Only 1 element
            return triangle[0][0];
            
        //Use dp from bottom up
        //dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1])
        //The size is the size of the bottom of the triangle
        int *cur = new int[triangle[triangle.size()-1].size()] { 0 };
        int *pre = new int[triangle[triangle.size()-1].size()] { 0 };
        
        bool flag = false;
        for (int i = triangle.size() - 1; i >= 0; i--) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                if (triangle.size() - 1 == i) { //Bottom row
                    pre[j] = triangle[i][j];
                } else {
                    cur[j] = triangle[i][j] + min(pre[j], pre[j+1]);
                    flag = true;
                }
            }
            
            if (flag) {
                int *tmp = pre;
                pre = cur;
                cur = tmp;
            }
        }
        
        int result = pre[0];
        delete cur;
        delete pre;
        
        return result;
    }
};
