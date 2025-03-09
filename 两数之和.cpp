#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num;
        for(int i=0;i<nums.size();i++){
            num.insert(make_pair(nums[i],i));
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            auto it=num.find(target-nums[i]);
            if(it!=num.end()&&2*nums[i]!=target)
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        return res;
    }
};