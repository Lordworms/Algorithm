/*
题意：一个国家由 n 个编号为 0 到 n - 1 的城市组成。在这个国家里，每两个 城市之间都有一条道路连接。

总共有 m 个编号为 0 到 m - 1 的朋友想在这个国家旅游。他们每一个人的路径都会包含一些城市。每条路径都由一个整数数组表示，每个整数数组表示一个朋友按顺序访问过的城市序列。同一个城市在一条路径中可能 重复 出现，但同一个城市在一条路径中不会连续出现。

给你一个整数 n 和二维数组 paths ，其中 paths[i] 是一个整数数组，表示第 i 个朋友走过的路径，请你返回 每一个 朋友都走过的 最长公共子路径 的长度，如果不存在公共子路径，请你返回 0 。

一个 子路径 指的是一条路径中连续的城市序列。
题解：很容易想到，对于每个公共路径长度len，总是存在1、2、.....len-1长度的公共路径，所以考虑二分长度
    另外，此题含有哈希冲突的数据，我们也需要对其进行考虑,考虑新的哈希方式
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        using ll=unsigned long long;
        const int b1=1e5,b2=1e5+7,b3=1e9+7;
        vector<ll>base1(b1+5),base2(b1+5);
        base1[0]=1,base2[0]=1;
        for(int i=1;i<b1;++i)
        {
            base1[i]=base1[i-1]*b1;
            base2[i]=base2[i-1]*b2;
        }
        auto check=[&](int len){
            unordered_map<ll,int>count;
            for(int i=0;i<paths.size();++i)
            {
                ll hash1=0,hash2=0;
                unordered_set<ll>st;
                for(int k=0;k<paths[i].size();++k)
                {
                    if(k>len)//求出下一位
                    {
                        hash1-=paths[i][k-len]*base1[len-1];
                    }   hash2-=paths[i][k-len]*base2[len-1];
                    hash1=hash1*b1+paths[i][k];
                    hash2=hash2*b2+paths[i][k];
                    ll hash3=hash1*b3+hash2;
                    if(i>len&&!st.count(hash3))
                    {
                        st.insert(hash3);
                        count[hash3]++;
                    }
                }
            }
            for(auto& x:count)
            {
                if(x.second==paths.size())return true;
            }
            return false;
        };//比较一下是否含有对应的公共路径
        int l=0,r=b1,len;
        while(l<r)
        {
            len=(l+r)>>1;
            if(check(len))l=len+1;
            else r=len-1;
        }
        return l;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>>paths={{0,1,2,3,4},{2,3,4},{4,0,1,2,3}};
  Solution sol;
  cout<<sol.longestCommonSubpath(5,paths);
  return 0;
}