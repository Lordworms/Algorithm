/*
    这节讲解二进制枚举子集
*/
#include <bits/stdc++.h>
using namespace std;
void subSet(int x)
{
    for(int mask=x;mask;mask=(mask-1)&x)//每次消除最后一位
    {
        bitset<7>a(mask);
        cout<<a<<endl;
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  subSet(6);
  return 0;
}