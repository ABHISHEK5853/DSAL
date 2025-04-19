#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int left = lower - nums[i];
            int right = upper - nums[i];

            int low = std::lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            int high = std::upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();

            count += (high - low);
        }

        return count;
    }
};
