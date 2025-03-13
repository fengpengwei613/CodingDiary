#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int record=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[record]=nums[i];
                if(i!=record){
                    nums[i]=0;
                }
                
                record++;
            }
        }
    }
};