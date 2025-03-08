#include<iostream>
#include<vector>
using namespace std;

/*求一个正整数二进制形式中1的个数，动态规划：某个数的1的个数等于其去除掉最高位1的数的
二进制在数中1的个数加一
要点是x&(x-1)可以得到x去掉后面一个1后的数字*/
class Solution {
public:
    vector<int> countBits(int n) {
        int highbit=0;
        vector<int> res(n+1,0);
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                highbit=i;
            }
            res[i]=res[i-highbit]+1;
        }    
        return res;    
    }
};