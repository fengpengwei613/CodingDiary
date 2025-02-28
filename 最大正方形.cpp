#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
题目要我们计算矩阵中值为1的元素组成的最大的正方形面积
有两种方法，一种是暴力求解，一种是动态规划。
暴力求解即依次遍历每个节点[i,j],把该节点作为正方形左上角节点，向外扩展直到出现0即停止。
动态规划：dp[i][j]代表以[i][j]点为右下角的由1组成的最大正方形的的边长。当[i][j]点为0是，则dp[i][j]为0
若为1，则与dp[i][j-1],dp[i-1][j],dp[i-1][j-1]三个值有关，即状态转移方程为
dp[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1，三个值的最小值加一
最后找出dp矩阵的最大值，再进行平方计算即可。
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int length=matrix.size();
        int width=matrix[0].size();
       
        std::vector<vector<int>>vec(length,std::vector<int>(width,0));
        for(int i=0;i<width;i++){
            if(matrix[0][i]=='1'){
                vec[0][i]=1;
            }
        }
        for(int i=0;i<length;i++){
            if(matrix[i][0]=='1'){
                vec[i][0]=1;
            }
        }
        for(int i=1;i<length;i++){
            for(int j=1;j<width;j++){
                
                if(matrix[i][j]=='0'){
                    vec[i][j]=0;
                }else{
                    vec[i][j]=min(vec[i-1][j-1],min(vec[i-1][j],vec[i][j-1]))+1;
                }
            }
        }
        int res=0;
        for(int i=0;i<length;i++){
            for(int j=0;j<width;j++){
                if(res<vec[i][j]){
                    res=vec[i][j];
                }
            }
        }
        return res*res;
    }
};