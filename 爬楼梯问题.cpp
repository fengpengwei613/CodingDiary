class Solution {
public:
    int climbStairs(int n) {
        int val1=0,val2=1,val3=1;
        for(int i=2;i<=n;i++){
            val3=val1+val2;
            val1=val2;val2=val3;
        }
        return val3;
    }
};