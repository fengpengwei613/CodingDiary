#include<iostream>
#include<vector>
using namespace std;

//要我们找出数组中消失的元素，如1，2，2，4，消失的是3
//关键就是利用原数组作为哈希数组，这样不需要单独开辟空间。

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=(nums[i]-1)%n;
            if(nums[tmp]<=n){
            nums[tmp]+=n;
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(nums[i]<=n){
                res.push_back(i+1);
            }
        }
        return res;
    }
};