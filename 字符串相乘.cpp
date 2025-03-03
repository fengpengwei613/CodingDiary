#include<iostream>
#include<vector>
using namespace std;

/*
大数计算系列问题，直接按照错位乘法进行计算，将该位的计算结果以整数形式保存在数组中，
最后再对数组进行进位，得出计算结果。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        int m=num1.length(),n=num2.length();
        vector<int> res(m+n,0);
        for(int i=m-1;i>=0;i--){
            int tmp=num1[i]-'0';
            for(int j=n-1;j>=0;j--){
                int tmp2=num2[j]-'0';
                res[i+j+1]+=tmp*tmp2;
            }
        }
        for(int i=m+n-1;i>0;i--){
            res[i-1]+=res[i]/10;
            res[i]=res[i]%10;
        }
        string realres;
        if(res[0]!=0){
            realres+=('0'+res[0]);
        }
        for(int i=1;i<=m+n-1;i++){
            realres+=('0'+res[i]);
        }
        return realres;
    }
};