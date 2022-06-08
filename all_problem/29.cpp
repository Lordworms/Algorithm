#include<bits/stdc++.h>
using namespace std;
long long div1(long long a,long long b)
{
    if(a<b)return 0;
    long long tb=b,count=1;
    while((tb+tb)<=a)
    {
        tb+=tb;
        count+=count;
    }
    return count+div1(a-tb,b);

}
int divide(int dividend, int divisor) {
    if(dividend==0)return 0;
    if(divisor==1)
    {
        if(dividend==INT_MAX)return INT_MAX;
        else return dividend;
    }                
    if(divisor==-1)
    {
        if(dividend==INT_MIN)return INT_MAX;
        return -dividend;
    }
    int sign=((dividend<0&&divisor>0)||(dividend>0&&divisor<0))?1:0;
    long long a=dividend,b=divisor;
    if(a<0)a=-a;
    if(b<0)b=-b;
    long res=div1(a,b);
    if(sign==1)
    {
        res=-res;
    }
    if(sign==0)return res>INT_MAX?INT_MAX:res;
    return res;
}
int main()
{
   
    cout<<divide(-2147483648,2)<<endl;
}