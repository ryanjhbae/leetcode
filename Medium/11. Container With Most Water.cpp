#include <vector>

using namespace std;

class Solution {
public:

    int computeArea(vector<int> &height, int i, int j) {
        return std::abs(j - i) * std::min(height[i], height[j]);
    }

    // essentially, the problem is to find the pair of indices (i, j) such that
    //   (j - i) * min(height[j], height[i]) is maximized
    int maxArea(vector<int>& height) {
        // looking at solution

        int k = 0, l = height.size() - 1;
        int maxAreaSoFar = computeArea(height, 0, l);

        while (k < l) {
            if (height[k] < height[l]) {
                ++k;
            } else {
                --l;
            }
            int area = computeArea(height, k, l);
            if (area > maxAreaSoFar) {
                maxAreaSoFar = area;
            }
        }

        return maxAreaSoFar;

        #if 0
        // hints: two pointers, greedy
        // start wide and converge toward the middle

        int i = 0, j = height.size() - 1;
        int area = computeArea(height, i, j);
        int maxAreaSoFar = area;
        int k = 0, l = j;
        while (k < l) {
            ++k;
            if (computeArea(height, k, j) > maxAreaSoFar) {
                i = k;
            } else {
                --l;
                if (computeArea(height, i, l) > maxAreaSoFar) {
                    j = l;
                    ++k;
                } else if (computeArea(height, k, l) > maxAreaSoFar) {
                    i = k;
                    j = l;
                }
            }
            
            area = computeArea(height, i, j);
            if (area > maxAreaSoFar) {
                maxAreaSoFar = area;
            }
        }

        return maxAreaSoFar;
        
        // try the brute force solution first
        // too slow!
        int maxSoFar = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                int volumeOfWater = (j - i) * std::min(height[j], height[i]);
                if (volumeOfWater > maxSoFar) {
                    maxSoFar = volumeOfWater;
                }
            }
        }
        return maxSoFar;
        #endif
    }
};