#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int minOps = (n + 2) / 3; 

        for (int i = 0; i <= n; ++i) {
            unordered_set<int> seen;
            bool isDistinct = true;
            for (int j = i; j < n; ++j) {
                if (seen.count(nums[j])) {
                    isDistinct = false;
                    break;
                }
                seen.insert(nums[j]);
            }

            if (isDistinct) {
                int ops = (i + 2) / 3;
                minOps = min(minOps, ops);
            }
        }

        return minOps;
    }
};