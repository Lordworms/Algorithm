#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    double a=1.0,b=0;
    cout<<a/b;
}