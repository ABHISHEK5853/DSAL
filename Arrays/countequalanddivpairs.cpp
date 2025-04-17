// class Solution {
// public:
//     int countPairs(vector<int>& nums, int k) {
        
//     }
// };


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        unordered_map<int, vector<int>> valueIndices;
        
        for (int i = 0; i < n; ++i) {
            valueIndices[nums[i]].push_back(i);
        }
        
        for (const auto& entry : valueIndices) {
            const vector<int>& indices = entry.second;
            int size = indices.size();
            
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
