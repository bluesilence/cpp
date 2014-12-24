class Solution {
public:
    int majorityElement(vector<int> &num) {
        if (num.empty())
            return 0;
        
        int n = num.size();
            
        //Solution 1: Use extra array to track the counts
        /*
        map<int, int> count;
        for (int i = 0; i < n; i++) {
            if (count.find(num[i]) == count.end())
                count[num[i]] = 1;
            else
                count[num[i]]++;
        }
        
        for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
            if (it->second > n / 2)
                return it->first;
        }*/
        
        //Solution 2: Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x: If the counter is 0, we set the current candidate to x and the counter to 1. If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
        int candidate = num[0];
        int counter = 1;
        
        for (int i = 1; i < n; i++) {
            if (0 == counter) {
                candidate = num[i];
                counter = 1;
            } else if (num[i] == candidate) {
                counter++;
            } else {
                counter--;
            }
        }
        
        return candidate;
    }
};
