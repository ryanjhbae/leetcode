

class Solution {
public:
    
    
    // constant space solution: work backwards through the arrays!
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < m + n; ++i) {
            
        }
    }
    
    #if 0
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        temp.resize(m);
        for (int i = 0; i < m; ++i) {
            temp[i] = nums1[i];
        }
        
        int pos1 = 0;
        int pos2 = 0;
        
        for (int i = 0; i < m + n; ++i) {
            if (pos1 == m) {
                nums1[i] = nums2[pos2];
                pos2++;
            } else if (pos2 == n) {
                nums1[i] = temp[pos1];
                pos1++;
            } else {
                if (temp[pos1] < nums2[pos2]) {
                    nums1[i] = temp[pos1];
                    pos1++;
                } else {
                    nums1[i] = nums2[pos2];
                    pos2++;
                }
            }
            
        }
    }
    
    #endif
};