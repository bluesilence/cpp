class Solution {
public:
    int majorityElement(vector<int> &num) {
        if (num.empty())
            return 0;
        
        map<int, int> count;
        
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (count.find(num[i]) == count.end())
                count[num[i]] = 1;
            else
                count[num[i]]++;
        }
        
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            if (it->second > n / 2)
                return it->first;
        }
        
        return 0;
    }
};
