/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalComparer(Interval& i1, Interval& i2) {
    return i1.start < i2.start;
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        //2 intervals can be merged if 1 interval's start falls in the range of the other interval
        //If so, the end of the merged interval will be the max end of the 2 intervals
        //To do this, we need to first sort all the intervals order by start ascendingly
        //Scan all the intervals, and try to merge as many intervals as possible
        //If we meet a interval that cannot be merged with previous interval, insert the previous interval into results, and try to merge upcoming intervals with current interval
        
        vector<Interval> results;
        
        const int N = intervals.size();
        if (N == 0)
            return results;
        
        sort(intervals.begin(), intervals.end(), intervalComparer);
        
        Interval merged = intervals[0];
        
        for (int i = 1; i < N; i++) {
            if (overlapped(merged, intervals[i])) {
                merged.end = max(merged.end, intervals[i].end);
            } else {
                results.push_back(merged);
                merged = intervals[i];
            }
        }
        
        results.push_back(merged);
        
        return results;
    }

private:
    bool overlapped(Interval& i1, Interval& i2) {
        if (i1.end < i2.start || i2.end < i1.start)
            return false;
        
        return true;
    }
};
