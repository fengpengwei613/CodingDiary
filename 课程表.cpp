#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
题目要求我们判断课程是否能完成，其实就是判断是都存在环结构。
常见的有两种，一种是kahn算法，基于队列实现。另一种是dns反向后序遍历，基于递归和状态管理。
两种方法复杂度相同均是O(V+N),我们采用时间较为简单的kahn算法。
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses,vector<int>());
        vector<int> inDegree(numCourses,0);
        queue<int> que;
        int res=0;
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int node=que.front();
            que.pop();
            res++;
            for(int val:adjList[node]){
                if(--inDegree[val]==0){
                    que.push(val);
                }
            }
        }
        if(res==numCourses){
            return true;
        }
        return false;
        

    }
};