class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > results;
        const int size = num.size();
        if (size < 3)
            return results;
        
        sort(num.begin(), num.end());
        
        vector<int> result;
        int start, end;
        int tmpSum = 0;
        for (int i = 0; i + 2 < size; i++) {
			      if (i > 0 && num[i] == num[i-1])	//dedup
				        continue;

			      result.push_back(num[i]);
            start = i + 1;
            end = size - 1;
            while (start < end) {
                tmpSum = num[start] + num[end] + num[i];
                if (tmpSum == 0) {
                    result.push_back(num[start]);
                    result.push_back(num[end]);
                    results.push_back(result);
					          result.pop_back();
					          result.pop_back();
                    
                    //Dedup when looking for next number
                    while (start < end && num[start] == num[start+1])
                        start++;
                    start++;    //Now num[start] != num[start+1], move to (start+1)
                    
                    while (end > start && num[end] == num[end-1])
                        end--;
                    end--;
                } else if (tmpSum < 0) {
                    start++;
                } else {
                    end--;
                }
            }

			      result.pop_back();
        }
        
        return results;
    }
};
