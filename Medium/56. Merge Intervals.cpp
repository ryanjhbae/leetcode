class Solution {
public:
    
    // determines if intervals a and b overlap
    bool overlap(const vector<int> &a, const vector<int> &b) {
        return (a[0] <= b[0] && b[0] <= a[1]) || (b[0] <= a[0] && a[0] <= b[1]);
    }
    
    // define sorting function for intervals
    
    static bool comp(const vector<int> &a, const vector<int> &b) {
        if (a[0] < b[0]) return true;
        else if (a[0] == b[0]) return a[1] < b[1];
        else return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals, then do a linear traversal
        // O(nlogn) time
        std::sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> merged;
        merged.resize(1);
        merged[0] = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (overlap(merged[merged.size() - 1], intervals[i])) {
                merged[merged.size() - 1][1] = std::max(merged[merged.size() - 1][1],       
                                                        intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};