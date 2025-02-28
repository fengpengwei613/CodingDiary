#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<utility>
using namespace std;
/*
题目要求计算数组每个元素与右侧第一个比当前元素大的元素的距离。
这类题目使用单调栈解决。
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //初始化为1
        vector<int> res(temperatures.size(),1);
        stack<pair<int,int>> sta;
        for(int i=temperatures.size();i>0;i--)
        {
            //如果栈为空说明后面没有更大的数，就直接压入栈并更新结果为0
            if(sta.empty()){
                sta.push(make_pair(i-1,temperatures[i-1]));
                res[i-1]=0;
            }
            else{
                //循环主体，每次弹出一个元素都要加上该元素的res
                while(!sta.empty()&&sta.top().second<=temperatures[i-1])
                {
                    res[i-1]+=res[sta.top().first];
                    sta.pop();
                }
                //如果全部弹出，说明后面没有更大的
                if(sta.empty())
                {
                    sta.push(make_pair(i-1,temperatures[i-1]));
                    res[i-1]=0;
                }else
                {
                    sta.push(make_pair(i-1,temperatures[i-1]));
                }
            }
        }
        return res;
    }
};