/*
题意：
    黑白棋游戏的棋盘由 4 \times 44×4 方格阵列构成。棋盘的每一方格中放有 11 枚棋子，共有 88 枚白棋子和 88 枚黑棋子。
    这 1616 枚棋子的每一种放置方案都构成一个游戏状态。在棋盘上拥有 11 条公共边的 22 个方格称为相邻方格。一个方格最多可有
     44 个相邻方格。在玩黑白棋游戏时，每一步可将任何 22 个相邻方格中棋子互换位置。对于给定的初始游戏状态和目标游戏状态，
     编程计算从初始游戏状态变化到目标游戏状态的最短着棋序列。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string start,target;
  char c;
  unordered_map<string,string>mp;
  for(int i=15;i>=0;--i)
  {
    cin>>c;
    start+=c;
  }
  for(int i=15;i>=0;--i)
  {
    cin>>c;
    target+=c;
  }
  queue<string>q;
  q.push(start);
  auto ver=[&](string pre,int pos){
      string now=pre;
      swap(now[pos],now[pos+4]);
      if(mp.count(now)!=0)return;
      q.push(now);
      char i='1'+(pos/4),ip=i+1,j='1'+(pos%4),jp=j;
      mp[now]=mp[pre]+i+j+ip+jp;
  };
  auto hor=[&](string pre,int pos){
      string now=pre;
      swap(now[pos],now[pos+1]);
      if(mp.count(now)!=0)return;
      q.push(now);
      char i='1'+(pos/4),j='1'+(pos%4),jp=j+1;
      mp[now]=mp[pre]+i+j+i+jp;
  };
  mp[start]="";//注意开始情况
  while(!q.empty())
  {
     string now=q.front();
     for(int i=0;i<16;++i)
    {
      if(i<12)
      {
        ver(now,i);
      }
      if(i%4!=3)
      {
        hor(now,i);
      }
    }
     if(mp.count(target)!=0)
      {
        cout<<mp[target].size()/4<<endl;
        for(int i=0;i<mp[target].size();++i)
        {
          cout<<mp[target][i];
          if(i%4==3)cout<<endl;
        }
        return 0;
      }
      q.pop();
  }
  return 0;
}