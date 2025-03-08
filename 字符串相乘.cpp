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



class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0"){
            return "0";
        }
        int m=num1.length(),n=num2.length();
        string myres="0";
        for(int i=m-1;i>=0;i--){
            int record=0;
            string res="";
            string real="";
            for(int j=n-1;j>=0;j--){
                if((num1[i]-'0')*(num2[j]-'0')+record>=10){
                    res+=(((num1[i]-'0')*(num2[j]-'0')+record)%10+'0');
                    record=((num1[i]-'0')*(num2[j]-'0')+record)/10;
                }else{
                    res+=(((num1[i]-'0')*(num2[j]-'0')+record)+'0');
                    record=0;
                }
            }
            if(record>=1){
                res+=(record+'0');
            }
            for(int i=res.length()-1;i>=0;i--)
            {
                real+=res[i];
            }
            for(int q=0;q<m-1-i;q++){
                real+='0';
            }
            myres=bignumplus(myres,real);
            cout<<myres<<endl;
        }
        return myres;
    }
    string bignumplus(string num1,string num2){
    if(num1=="0"){
        return num2;
    }else if(num2=="0"){
        return num1;
    }
    int m=num1.length(),n=num2.length();
    int record=0;
    string res="";
    for(int i=num1.length()-1,j=num2.length()-1;i>=0&&j>=0;j--,i--){
        if((num1[i]+num2[j]-'0'-'0')+record>=10)
        {
            res+=(((num1[i]+num2[j]-'0'-'0')+record-10)+'0');
            record=1;
        }
        else{
            res+=(((num1[i]+num2[j]-'0'-'0')+record)+'0');
            record=0;
        }
    }
    if(num1.length()<num2.length()){
        for(int i=num2.length()-num1.length()-1;i>=0;i--){
            if(num2[i]+record-'0'>=10){
                res+=((num2[i]+record-'0')%10+'0');
                record=1;
            }else{
                res+=(num2[i]+record);
                record=0;
            }
        }
        if(record==1){
            res+="1";
        }
    }else if(num1.length()>num2.length()){
        for(int i=num1.length()-num2.length();i>=0;i--){
            if(num1[i]+record-'0'>=10){
                res+=((num1[i]+record-'0')%10+'0');
                record=1;
            }else{
                res+=(num1[i]+record);
                record=0;
            }
        }
        if(record==1){
            res+="1";
        }
    }else{
        if(record==1){
            res+=char(1+'0');
        }
    }
    string real="";
    for(int i=res.length()-1;i>=0;i--)
    {
        real+=res[i];
    }
    return real;
}
};