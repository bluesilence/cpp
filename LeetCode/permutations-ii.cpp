class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > results;
        
        if (num.empty())
            return results;
        
        //Make duplicate numbers come together
        sort(num.begin(), num.end());
        
        permute(num, results, 0);
    }

private:
    void permute(vector<int> &num, vector<vector<int> > &results, int index) {
        if (index == num.size()) {
            results.push_back(num);
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            if (hasDup(num, index, i))
                continue;
            
            swap(num, index, i);
            permute(num, results, index+1);
            swap(num, index, i);
        }
    }
    
    bool hasDup(vector<int> &num, int start, int end) {
        if (start < 0 || start > end || end >= num.size())
            throw "Invalid start/end";
        
        for (int i = start; i < end; i++) {
            if (num[i] == num[end])
                return true;
        }    
        
        return false;
    }
    
    void swap(vector<int> &num, int index1, int index2) {
        if (index1 != index2 && index1 < num.size() && index2 < num.size() && index1 >= 0 && index2 >= 0) {
            int temp = num[index1];
            num[index1] = num[index2];
            num[index2] = temp;
        }
    }
};
