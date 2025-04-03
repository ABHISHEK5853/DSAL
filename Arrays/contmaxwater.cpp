// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int max_water = 0;
    
            while (left < right) {
                int width = right - left;
                int container_height = min(height[left], height[right]);
                int current_area = width * container_height;
                max_water = max(max_water, current_area);
    
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
    
            return max_water;
        }
    };
    