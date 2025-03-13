#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    bool match(char a,char b){
        if(a=='('&&b==')'){
            return true;
        }else if(a=='['&&b==']')
        {
            return true;
        }else if(a=='{'&&b=='}'){
            return true;
        }else{
            return false;
        }
    }
    bool isValid(string s) {
        int length=s.length();
        if(length==0){
            return true;
        }
        if(length%2==1){
            return false;
        }
        stack<char> sta;
        for(int i=0;i<length;i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
                sta.push(s[i]);
            }else{
                if(!sta.empty()&&match(sta.top(),s[i])){
                    sta.pop();
                }else{
                    return false;
                }
            }
        }
        if(sta.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};