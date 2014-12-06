class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.empty())
            return -1;
            
        int index = 0;
        
        for (int i = 1; i < num.size(); i++) {
            if (num[i] > num[index])
                index = i;
        }
        
        return index;
    }
};
