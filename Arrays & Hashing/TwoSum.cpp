#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int c = target - num;
            
            if (mp.find(c) != mp.end()) {
                return {i, mp[c]};
            }
            
            mp[num] = i; // Store the current number with its index
        }
        
        return {}; // Return empty vector if no solution is found
    }
};
