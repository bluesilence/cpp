class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<double, int> countPerLine;
        
        const int N = points.size();
        
        if (N < 2)
            return N;
            
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        
        int count = 0;
        for (int i = 0; i + 1 < N; i++) {
            x1 = points[i].x;
            y1 = points[i].y;
            
            int dups = 0;
            
            //Reset counter map
            countPerLine.clear();
            
            for (int j = i + 1; j < N; j++) {
                x2 = points[j].x;
                y2 = points[j].y;
                
                if (x1 == x2 && y1 == y2) {
                    dups++;
                } else if (x1 == x2) {  //Vertical line, slope is infinite
                    countPerLine[(double)INT_MAX]++;
                } else {
                    double slope = (double)(y2 - y1) / (double)(x2 - x1);
                    countPerLine[slope]++;
                }
            }
            
            for (auto iter = countPerLine.begin(); iter != countPerLine.end(); iter++) {
                count = max(count, iter->second + dups);
            }
            
            //There are only dups, so countPerLine is empty and the loop above won't be entered
            count = max(count, dups);
        }
        
        //Add the first point in the line
        return ++count;
    }
};
