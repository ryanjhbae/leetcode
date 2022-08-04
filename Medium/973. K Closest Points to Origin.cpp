class Solution {
public:
    static int squared_distance(const vector<int> &a) {
        return a[0] * a[0] + a[1] * a[1];
    }
    
    // sort it in ascending order (we want to create a maxheap)
    // just using references here speeds it up a lot
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return squared_distance(a) < squared_distance(b);
    }
    
    // improvised approach: be a bit more selective with who we let in
    //   - use a maxheap instead of a minheap (that is, the top of the heap
    //     should have the element farthest from the origin out of the heap)
    //   - if the element we're about to insert has a higher distance than the 
    //     one at the top, and we already have k elements in the heap, 
    //     then don't let it in
    //   - otherwise, if the element we're about to insert has a lower distance
    //     than the one at the top and we already have k elements in the heap, 
    //     delete the current top of the heap
    // still slow af
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&Solution::cmp)> pq(cmp);
        for (auto &point : points) {
            if (pq.size() == k) {
                int point_dist = squared_distance(point);
                int max_dist = squared_distance(pq.top());
                if (point_dist >= max_dist) {
                    continue;
                } else if (point_dist < max_dist) {
                    pq.pop();
                }
            }
            pq.push(point);
        }
        vector<vector<int>> result;
        result.resize(k);
        for (int i = 0; i < k; ++i) {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
    
};


#if 0
class Solution {
public:
    static int squared_distance(vector<int> &a) {
        return a[0] * a[0] + a[1] * a[1];
    }
    
    // sort it in descending order (we want to create a minheap)
    static bool cmp(vector<int> a, vector<int> b) {
        return squared_distance(a) > squared_distance(b);
    }
    
    // kind of monke but should work
    // VERY slowly
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(&Solution::cmp)> pq(cmp);
        for (auto point : points) {
            pq.push(point);
        }
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
    
};
#endif