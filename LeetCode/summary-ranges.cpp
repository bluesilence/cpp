class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if (nums.empty())
            return result;
        
        int begin = nums[0];
        int end = begin;
        
        string range;
        
        for (int i = 1; i < nums.size(); i++) {
            //Guaranteed by sorted & no-duplicate condition, the nums[i] - end must be >= 1
            //int minus may overflow. Convert to long long first.
            if ((long long)nums[i] - (long long)end == 1) {
                end = nums[i];
            } else {
                if (begin != end) {
                    range = itoa(begin) + "->" + itoa(end);
                } else {
                    range = itoa(begin);
                }
                
                result.push_back(range);
                
                begin = nums[i];
                end = begin;
            }
        }
        
		    //Remember to push last range
		    if (begin != end) {
            range = itoa(begin) + "->" + itoa(end);
        } else {
            range = itoa(begin);
        }
        
		result.push_back(range);

        return result;
    }

private:
	string itoa(int num) {
		if (num == 0)
			return "0";

		string str = "";
		long long lNum = num;
		if (num < 0) {
			lNum = 0 - (long long)num;
		}

		while (lNum > 0) {
			char ch = lNum % 10 + '0';
			str = ch + str;
			lNum /= 10;
		}

		if (num < 0)
			str = "-" + str;

		return str;
	}
};
