class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> results;
        if (numbers.size() < 2)
            return results;
        
        vector<int> copy(numbers);
        sort(copy.begin(), copy.end());
        
        int begin = 0, end = copy.size() - 1;
        while (begin < end) {
            int sum = copy[begin] + copy[end];
            if (sum == target) {
                int originalBegin = find(numbers, copy[begin], 0);
                int originalEnd = find(numbers, copy[end], originalBegin);
                results.push_back(originalBegin);
                results.push_back(originalEnd);
                break;
            } else if (sum < target) {
                begin++;
            } else {
                end--;
            }
        }
        
        sort(results.begin(), results.end());
        
        return results;
    }
    
private:
    int find(vector<int> &numbers, int target, int dupIndex) {
        for (int i = 1; i <= numbers.size(); i++) {
            if (numbers[i - 1] == target && i != dupIndex)
                return i;
        }
    }
};
