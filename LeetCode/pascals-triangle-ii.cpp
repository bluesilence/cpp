class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr;
        vector<int> pre;
        
        for(int i = 0; i <= rowIndex; i++) {
            curr.clear();
            curr.push_back(1);
            if(i > 1) {
                for(int j = 1; j < i; j++) {
                    curr.push_back(pre[j-1] + pre[j]);
                }
            }
            
            if(i > 0) {
                curr.push_back(1);
            }
            
            pre = curr;
        }
        
        return curr;
    }
};
