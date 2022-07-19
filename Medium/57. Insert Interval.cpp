class Solution {
public:
    #if 1
    bool overlap(vector<int> &a, vector<int> &b) {
        if (a[0] <= b[0] && b[0] <= a[1]) {
            return true;
        } else if (b[0] <= a[0] && a[0] <= b[1]) {
            return true;
        } else if (b[0] == a[0] && b[1] == a[1]) {
            return true;
        } else {
            return false;
        }
    }
    
    // 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        int start = -1;
        int end = -1;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (!overlap(intervals[i], newInterval)) {
                
                // if we haven't inserted newInterval yet but we have passed the rightmost
                //   interval overlapped by newInterval
                if (!inserted && intervals[i][0] > newInterval[1]) {
                    newIntervals.push_back(newInterval);
                    inserted = true;
                }
                newIntervals.push_back(intervals[i]);
            } else {
                // expand newInterval to cover all intervals it overlaps
                // (so we have one giant interval)
                if (intervals[i][0] <= newInterval[0]) {
                    newInterval[0] = intervals[i][0];
                }
                // if we have reached the rightmost interval overlapped by newInterval,
                //   insert it
                if (intervals[i][1] >= newInterval[1]) {
                    newInterval[1] = intervals[i][1];
                    newIntervals.push_back(newInterval);
                    inserted = true;
                }
            }
        }
        // if intervals was empty
        if (!inserted) {
            newIntervals.push_back(newInterval);
        }
        return newIntervals;
    }
    #endif

    #if 0
    // inefficient approach
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left_index = -1;
        int right_index = -1;
        int last_non_overlapping_index = -1;
        
        int left_start = -1;
        int left_end = -1;
        int right_start = -1;
        int right_end = -1;
        
        // find leftmost and rightmost blocks overlapped by the block you're
        //   trying to insert (implicitly finding all blocks touched by the newInterval)
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> &interval = intervals[i];
            // no overlap
            if (interval[1] < newInterval[0]) {
                last_non_overlapping_index = i;
            }
            if (overlap(interval, newInterval)) {
                #if 0
                cout << i << ": overlap" << endl;
                #endif
                if (left_index == -1) {
                    left_index = i;
                    left_start = interval[0];
                    left_end = interval[1];
                }
                right_index = i;
                right_start = interval[0];
                right_end = interval[1];
            }
        }
        #if 0
        cout << "left_index: " << left_index << endl;
        cout << "right_index: " << right_index << endl;
        cout << "last_non_overlapping_index: " << last_non_overlapping_index << endl;
        cout << "intervals.size() : " << intervals.size() << endl;
        #endif
        // if no overlap
        if (left_index == -1) {
            if (last_non_overlapping_index + 1 >= intervals.size()) {
                intervals.push_back(newInterval);
            } else {
                #if 0
                cout << "here";
                #endif
                intervals.insert(intervals.begin() + last_non_overlapping_index + 1, newInterval);
            }
            return intervals;
        } else {
            // delete all intervals overlapped by the newInterval
            for (int i = 0; i <= right_index - left_index; ++i) {
                intervals.erase(intervals.begin() + left_index);
            }
        
            vector<int> new_block = {std::min(left_start, newInterval[0]), std::max(right_end, newInterval[1])};
            intervals.insert(intervals.begin() + left_index, new_block);
        }
        
        return intervals;
    }
    #endif
};