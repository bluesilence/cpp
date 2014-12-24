class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0;
        int end = num.size() - 1;
        int mid = (start + end) / 2;
        
        while (start < end) {
            if (start == end || num[start] < num[end])  //the sub array is already sorted
                return num[start];
            else if (num[mid] > num[start]) //mid in first half  
                start = mid + 1;
            else if (num[mid] < num[end])   //mid in second half
                end = mid;
            else //num[mid] == num[start] || num[mid] == num[end]
                start++;
            
            mid = (start + end) / 2;
        }
        
        return num[start];
    }
};
