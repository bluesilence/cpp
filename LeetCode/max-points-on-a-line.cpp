class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() == 0)
            return 0;
            
        unordered_map<double, int> count;
        int size = points.size();
        int ans = 0;
        
        for (int i = 0; i < size; i++) {
            count.clear();
            int x = points[i].x;
            int y = points[i].y;
            int dups = 0;
            
            for(int j = i+1; j < size; j++) {
                int x1 = points[j].x;
                int y1 = points[j].y;
                if(x == x1 && y == y1) {
                    dups++;
                } else if (x == x1) {   //Vertical line
                    count[(double)INT_MAX]++;
                } else {
                    double k = (double)(y1-y) / (double)(x1-x); //Note: convert int to double
                    count[k]++;
                }
            }
            
            for (auto it = count.begin(); it != count.end(); it++){
                ans = max(ans, it->second + dups);
            }
            
            ans = max(ans, dups);   //Only duplicate points
        }
        
        return ans + 1; //Add the original point that was enumerated in the outer loop
    }
};
