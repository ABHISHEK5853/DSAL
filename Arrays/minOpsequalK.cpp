// class Solution {
// public:
//     int minOperations(vector<int>& nums, int k) {
        
//     }
// };

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> greaterThanK;
        for (int num : nums) {
            if (num > k) {
                greaterThanK.insert(num);
            }
        }
        
        for (int num : nums) {
            if (num < k) {
                return -1;  
            }
        }
        
        vector<int> greaterThanKVec(greaterThanK.begin(), greaterThanK.end());
        sort(greaterThanKVec.begin(), greaterThanKVec.end(), greater<int>());
        
        int operations = 0;
        for (int num : greaterThanKVec) {
            operations++;  
        }
        
        return operations;
    }
};