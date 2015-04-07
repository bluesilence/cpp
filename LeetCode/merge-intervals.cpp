/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(const Interval &a, const Interval &b) {  
    if(a.start == b.start)
        return a.end > b.end;   //a can merge b, so a comes first
    
    return a.start < b.start;   //Otherwise, order by start time
 }
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> results;
        
        if (intervals.empty())
            return results;
            
        //Important: Sort ensures intervals that are most possible to merge others come first
        sort(intervals.begin(), intervals.end(), comp);
        
        Interval tmp = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (hasOverlap(tmp, intervals[i])) {    //Get the widest interval by merging tmp and results[i]
                tmp.start = min(tmp.start, intervals[i].start);
                tmp.end = max(tmp.end, intervals[i].end);
            } else {    //Previous interval doesn't overlap with current one, need to push it to result first
                results.push_back(tmp);
                tmp = intervals[i];
            }
        }
        
        //Important: collect last interval
        results.push_back(tmp);
        
        return results;
    }

private:
    bool hasOverlap(Interval i1, Interval i2) {
        return (i1.start <= i2.end && i1.end >= i2.end) 
                || (i2.start <= i1.end && i2.end >= i1.end) 
                || (i1.start >= i2.start && i1.end <= i2.end) 
                || (i2.start >= i1.start && i2.end <= i1.end);
    }
};
