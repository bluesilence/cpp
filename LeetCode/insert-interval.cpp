/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        //Similar as merge-interval, the difference is to check where to merge newInterval along the way
        vector<Interval> results;
        if (intervals.empty()) {
            results.push_back(newInterval);
            return results;
        }
        
        bool inserted = false;
        Interval curr;
        if (intervals[0].start < newInterval.start) {
            curr = intervals[0];
        } else {
            curr = newInterval;
            inserted = true;
        }
        
        Interval next;
        int i = inserted ? 0 : 1;   //Where to start in the intervals array
        while (i < intervals.size()) {
            if (inserted || intervals[i].start <= newInterval.start) {
                next = intervals[i++];
            } else {   //!insertedNewInteval && intervals[i].start > newInterval.start
                next = newInterval;
                inserted = true;
            }
            
            if (hasOverlap(curr, next)) {
                curr.start = min(curr.start, next.start);
                curr.end = max(curr.end, next.end);
            } else {
                results.push_back(curr);
                curr = next;
            }
        }
        
        //The original intervals only has 1 interval
        if (!inserted) {
            if (hasOverlap(curr, newInterval)) {
                curr.start = min(curr.start, newInterval.start);
                curr.end = max(curr.end, newInterval.end);
                results.push_back(curr);
            } else {
                results.push_back(curr);
                results.push_back(newInterval);
            }
        } else {
            results.push_back(curr);
        }
            
        return results;
    }

private:
    bool hasOverlap(Interval i1, Interval i2) {
        if (i1.end < i2.start || i2.end < i1.start)
            return false;
        
        return true;
    }
};
