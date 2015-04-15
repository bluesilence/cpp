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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> results;
        if (intervals.empty()) {
            results.push_back(newInterval);
            return results;
        }
        
        bool inserted = false;
        Interval tmp;
        int startingIndex;
        if (newInterval.start < intervals[0].start) { //Decide which interval as beginning
            tmp = newInterval;
            startingIndex = 0;
            inserted = true;
        } else {
            tmp = intervals[0];
            startingIndex = 1;
        }
        
        Interval intermediate;
        for (int i = startingIndex; i < intervals.size();) {    //Insert newInterval in order
            if (inserted || intervals[i].start < newInterval.start) {
                intermediate = intervals[i];
                i++;
            } else {
                intermediate = newInterval;
                inserted = true;
            }
            
            if (hasOverlap(tmp, intermediate)) {
                tmp.start = min(tmp.start, intermediate.start);
                tmp.end = max(tmp.end, intermediate.end);
            } else {
                results.push_back(tmp);
                tmp = intermediate;
            }
        }
       
        //Important: collect last interval
        if (!inserted) {
            if (hasOverlap(tmp, newInterval)) { //Merge last interval with newInterval
                tmp.start = min(tmp.start, newInterval.start);
                tmp.end = max(tmp.end, newInterval.end);
                results.push_back(tmp);
            } else {
                results.push_back(tmp);
                results.push_back(newInterval);
            }
        } else {
            results.push_back(tmp);
        }
        
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
