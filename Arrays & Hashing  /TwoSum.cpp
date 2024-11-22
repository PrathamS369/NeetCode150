#include <vector>
#include <unordered_map>
using namespace std;

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Map to store number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int ele= target - num;
            
            if (mp.find(ele) != mp.end()) {
                return {i, mp[ele]};
            }
            
            pairIdx[num] = i; // Store the current number with its index
        }
        
        return {}; // Return empty vector if no solution is found
    }
};
