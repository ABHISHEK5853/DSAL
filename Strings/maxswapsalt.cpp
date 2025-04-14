
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        int minSwaps(string s) {
            int count0 = 0, count1 = 0;
            for (char c : s) {
                if (c == '0') count0++;
                else count1++;
            }
            if (abs(count0 - count1) > 1) return -1;
            
            int swaps1 = 0, swaps2 = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (i % 2 == 0) {
                    if (s[i] != '0') swaps1++;
                    if (s[i] != '1') swaps2++;
                } else {
                    if (s[i] != '1') swaps1++;
                    if (s[i] != '0') swaps2++;
                }
            }
            
            if (count0 == count1) return min(swaps1, swaps2) / 2;
            return count0 > count1 ? swaps1 / 2 : swaps2 / 2;
        }
    };