/*
开始做的时候没有想清楚,现在也还没有。。。
首先明确一点，这个游戏alice不可能输，这是因为无论何时，alice都能选择那个更优的结果
我们的前提是：这个字符串的长度为“偶数”！
由于这个字符串的长度为偶数，所以我们先处理两端相同的情况，因为这种情况会导致draw，设处理完后的两个指针的位置分别为a和b
那么如果a>=b那么每次两端都相等，那么我们返回draw
否则我们继续向下处理
那么我们考虑，什么情况下，能够平局呢？
如果我们[a,b]的所有数都是aabbccdd...的形式的话，我们才会得到平局，否则的话，alice都可以得到更优的解


*/
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin>>T;
  
  while(T--)
  {
    cin>>s;
    int a=0,b=s.size()-1;
    while(s[a]==s[b])++a,--b;
    if(a<b)
    {
        int count=0;
        bool flag=false;
        for(int i=a;i<b;++i)
        {
            if(s[i]==s[i+1])++count;
            else 
            {
                if((count+1)&1)//不然全不等的话就有问题
                {
                    flag=true;
                    break;
                }
                else count=0;
            }
        }
        if(flag)cout<<"Alice"<<endl;
        else cout<<"Draw"<<endl;
    }
    else cout<<"Draw"<<endl;
  }
  return 0;
}