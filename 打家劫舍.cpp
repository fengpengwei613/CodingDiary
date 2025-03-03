#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
题目给定一个数组，表示每间房屋存放的金钱，要计算在不偷相邻房屋的情况下的最优值。
最优化的问题一般会考虑动态规划与贪心，贪心在这里不适用
动态规划：每间房根据偷与不偷分为两种情况，若偷第k间房，则金额为前k-2间房最大值加上第k间房金额。
若不偷，则总金额为前k-1间房的最大金额。 
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int total=nums.size();
        vector<int>dp;
        if(total==0){
            return 0;
        }else if(total==1){
            return nums[0];
        }
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0],nums[1]));
        for(int i=2;i<total;i++){
            dp.push(max(dp[i-1],dp[i-2]+nums[i]));
        }
        return max(dp[dp.size()-1],dp[dp.size()-2]);
    }
};