// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

//https://leetcode.com/problems/two-sum/

class Solution {
public:
  
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        int length=nums.size();
        for (int i = 0; i < length; i++){
            for (int j = i + 1; j < length; j ++){
                if (nums[i]==nums[j]){
                    nums.erase( nums.begin() + i );

                }
            }
        }
        length=nums.size();
        for(int g=0; g < length; g ++){
            for (int u =g+1; u<length; u++){
                if(nums[g]+nums[u]==target){
                    output.push_back(g);
                    output.push_back(u);
                }
            }
        }
        return output;
        
    }
};