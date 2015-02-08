class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0)
            return 0;
         
        int result = 0;
        vector<int> tmp = height;
        tmp.push_back(0);  // Lower bound
 
        stack<int> s;
        for(int i = 0; i < tmp.size(); i++) {
            //1) Not met histograms higher than current histogram, or
            //2) The height of left histogram < the height of current histogram
            if(s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) { 
                s.push(i);
            } else {
                while(!s.empty() && tmp[s.top()] > tmp[i]) {
                    int index = s.top();
                    s.pop();
                    // Note it's s.top() in (i - s.top() - 1)
                    // s.top() is the index of left histogram that has height < the height of histogram at index
                    int width = s.empty() ? i : (i - s.top() - 1);
                    result = max(result, tmp[index] * width);
                }
                
                s.push(i);  // Important
            }
        }
        
        return result;
    }
};
