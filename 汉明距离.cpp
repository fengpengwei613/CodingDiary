#include<iostream>
using namespace std;

/*
题目要求计算汉明距离：两个整数二进制位不同的位数。异或运算再求1的数量。
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp=x^y;
        int res=0;
        if(tmp<0){
            res++;
            tmp*=-1;
        }
        while(tmp!=0){
            if(tmp%2==1){
                res++;
            }
            tmp/=2;
        }
        return res;
    }
};