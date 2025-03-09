#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num=prices.size();
        vector<int> vec;
        for(int i=0;i<num-1;i++){
            vec.push_back(prices[i+1]-prices[i]);

        }
        int res=0,record=0,index1=0,index2=0;
        for(int i=0;i<vec.size();i++){
            record+=vec[i];
            if(record>=0){
                if(record>res){
                    res=record;
                    index2=i+1;
                }
            }else{
                index1=i+1;
                record=0;
            }
        }
        return res;
    }
};