/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //This order ensures that intervals which might be overlapped appear one by one
 bool mergeOrderComp(Interval i1, Interval i2) {
     return i1.start < i2.start;
 };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //Compare current interval with next interval
        //If the 2 intervals overlap, merge them to form a larger interval
        //Else, insert current interval, assign next interval as current interval
        //Scan until all intervals are compared
        if (intervals.size() < 1)
            return intervals;
        
        vector<Interval> results;
        
        sort(intervals.begin(), intervals.end(), mergeOrderComp);
        Interval curr = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (hasOverlap(curr, intervals[i])) {
                curr.start = min(curr.start, intervals[i].start);
                curr.end = max(curr.end, intervals[i].end);
            } else {
                results.push_back(curr);
                curr = intervals[i];
            }
        }
        
        results.push_back(curr);
        
        return results;
    }

private:
    bool hasOverlap(const Interval &i1, const Interval &i2) {
        if (i1.end < i2.start || i2.end < i1.start)
            return false;
        
        return true;
    }
};
