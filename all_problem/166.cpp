#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    bool flag=(numerator>>31)^(denominator>>31);
    if(!(numerator%denominator))
    {
        return to_string(numerator/denominator);
    }
    //整数
    string ans;
    if(flag)ans.push_back('-');
    int a=abs(numerator),b=abs(denominator);
    ans+=(to_string(a/b));
    ans+='.';
    //小数
    string decimal;
    int remainder=a%b;
    unordered_map<int,int>mp;
    int index=0;
    while(remainder&&!mp.count(remainder))
    {
        mp[remainder]=index;
        remainder*=10;
        decimal+=to_string(remainder/b);
        remainder%=b;
        index++;
    }
    //有循环节
    if(remainder)
    {
        decimal=decimal.substr(0,mp[remainder])+'('+decimal.substr(mp[remainder])+')';
    }
    ans+=decimal;
    return ans;
}   
int main()
{
    cout<<fractionToDecimal(4,333);

}
