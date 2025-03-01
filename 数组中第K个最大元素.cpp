#include<iostream>
#include<vector>
using namespace std;
/*
题目要求计算一个数组的第k个大的元素。要求时间复杂度为O(n)
要求O(n)我们想到的是计数排序
我们观察题目数值范围为-10^4-10^4，因为存在负数不太满足要求，但我们给每一个元素均加上10^4就可以满足。
题目也就迎刃而解了。
*/
int arr[20001];

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=20000;i>=0;i--)
        {
            arr[i]=0;
        }
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]+10000]++;
        }
        int res=0;
        for(int i=20000;i>=0;i--)
        {
            if(arr[i]>0){
                k=k-arr[i];
             
            }
            if(k<=0){
                res=i;
                break;
            }
        }
        return res-10000;
    }
}