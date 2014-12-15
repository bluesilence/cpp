class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        //Use a set to store all the numbers
        //Iterate the set and find each element's neighborhood range
        //Update max range and delete visited elements along each iteration
        set<int> numSet;
        for (int i = 0; i < num.size(); i++) {
            numSet.insert(num[i]);
        }
        
        set<int>::iterator it = numSet.begin();
        int globalMax = 0, iterMax;
        
        while (it != numSet.end()) {
            set<int>::iterator cur = it;
            int n = *it, max = n + 1, min = n - 1;
            iterMax = 1;
            
            set<int>::iterator tmpIter;
            while ((tmpIter = numSet.find(max)) != numSet.end()) {
                numSet.erase(tmpIter);
                max++;
                iterMax++;
            }
            
            while ((tmpIter = numSet.find(min)) != numSet.end()) {
                numSet.erase(tmpIter);
                min--;
                iterMax++;
            }
            
            it++;
            numSet.erase(cur);
            if (iterMax > globalMax)
                globalMax = iterMax;
        }
        
        return globalMax;
    }
};
