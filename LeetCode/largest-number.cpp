class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            strs.push_back(to_string(nums[i]));
        }
        
        sort(strs.begin(), strs.end(), [&](const string& s1, const string& s2) {
            return (s1 + s2) > (s2 + s1);
        });
        
        string result = "";
        for (int i = 0; i < N; i++) {
            result += strs[i];
            if (result == "0") {
                break;  //The maximum number is 0, then the following numbers are all 0, avoid duplicate "0"s
            }
        }
        
        return result;
    }
};
