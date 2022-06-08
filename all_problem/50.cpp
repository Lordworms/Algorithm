#include<iostream>
using namespace std;
double quick_pow_non_recursive(double x,int n)
{
    if(x==1)return x;
    double ans=1;
    while(n)
    {
        if(n&1)
            ans*=x;
        x*=x;
        n>>=1;
    }
    return ans;
}
double quick_pow_recursive(double x,int n)
{
    if(n==0)
        return 1;
    else if(n%2==1)
        return quick_pow_recursive(x,n-1)*x;
    else
    {
        double tmp=quick_pow_recursive(x,n/2);
        return  tmp*tmp;
    }
    
}
int main()
{
    cout<<quick_pow_non_recursive(2.00,10);

}