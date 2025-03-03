#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
计算数组的多数元素：元素数量大于总元素数量的一半。
1、哈希表统计频率
2、排序，然后取中间值
3、摩尔投票
*/

//摩尔投票为1/3时,依照核心思想对拼消耗，弄两个候选人,注意此时要判断是否满足超过1/3
class Solution {
public:
    vector<int>  majorityElement(vector<int>& nums) {
        int res1=0,res2=1,time1=0,time2=0;
        for(int val:nums){
            if(val==res1){
                time1++;
            }else if(val==res2){
                time2++;
            }else if(time1==0){
                res1=val;
                time1=1;
                continue;
            }else if(time2==0){
                res2=val;
                time2=1;
                continue;
            }else{
                time1--;
                time2--;
            }
            

        }
        vector<int> res;
        int count1,count2;
        for(int val:nums){
            if(val==res1){count1++;}
            else if(val==res2){count2++;}
        }
        if(count1>nums.size()/3){
            res.push_back(res1);
        }
        if(count2>nums.size()/3){
            res.push_back(res2);
        }
        return res;

    }
};





//摩尔投票
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res,time=0;
       for(int val:nums){
        if(times==0){
            res=val;
        }else{
            if(res==val){
                times++;
            }else{
                times--;
            }
        }
       }
       return res; 
    }
};




//哈希
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int judge=nums.size()/2;
        unordered_map<int,int> m;
        for(int val:nums){
            m[val]++;
        }        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>judge){
                return it->first;
            }
        }
        return 0;
    }
};