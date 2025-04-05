#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int total = 0;

    void dfs(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) {
            total += currentXor;
            return;
        }
        dfs(nums, index + 1, currentXor ^ nums[index]);
        dfs(nums, index + 1, currentXor);
    }

    int subsetXORSum(vector<int>& nums) {
        dfs(nums, 0, 0);
        return total;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {5, 1, 6};
    vector<int> nums3 = {3, 4, 5, 6, 7, 8};

    cout << "Output 1: " << sol.subsetXORSum(nums1) << endl; 

    //reset each case
    sol.total = 0; 
    cout << "Output 2: " << sol.subsetXORSum(nums2) << endl; 

    sol.total = 0;  
    cout << "Output 3: " << sol.subsetXORSum(nums3) << endl;  

    return 0;
}
