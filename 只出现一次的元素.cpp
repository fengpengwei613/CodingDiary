#include<iostream>
#include<vector>
using namespace std;

/*
要找出数组中只出现一次的元素，题目要求使用O(1)的时间复杂度
那么就只能使用位运算了，因为存在a^a=0,0^a=a，且异或满足交换律。
*/







class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int val:nums){
            res=res^val;
        }
        return res;
    }
};