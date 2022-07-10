/*
题意：你需要从空字符串开始 构造 一个长度为 n 的字符串 s ，构造的过程为每次给当前字符串 前面 添加 一个 字符。构造过程中得到的所有字符串编号为 1 到 n ，其中长度为 i 的字符串编号为 si 。

比方说，s = "abaca" ，s1 == "a" ，s2 == "ca" ，s3 == "aca" 依次类推。
si 的 得分 为 si 和 sn 的 最长公共前缀 的长度（注意 s == sn ）。

给你最终的字符串 s ，请你返回每一个 si 的 得分之和
题解：后缀数组板子题
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MAXN=1e5+10;
    long long sumScores(string s) {
        int n=s.size();
        int m=s.size()+1>130?s.size()+1:130;
        using ll=unsigned long long;
        vector<ll>rk(n+1,0),sa(n+1,0),pos(n+1,0),cnt(m,0),lcp(n+1,0);
        auto base_sort=[&](){
            fill(cnt.begin(),cnt.begin()+m,0);
            for(int i=1;i<=n;++i)cnt[rk[i]]++;
            cout<<"begin"<<endl;
            for(int i=2;i<m;++i){cnt[i]+=cnt[i-1];if(cnt[i]!=0)cout<<cnt[i]<<" "<<i<<endl;}
            cout<<"end"<<endl;
            for(int i=n;i>=1;--i)sa[cnt[rk[pos[i]]]--]=pos[i];
        };
        auto getSa=[&](){
            auto check=[&](int x,int y,int k){
                if(pos[x]!=pos[y])
                {
                    return false;
                }
                int r1=x+k>n?-1:pos[x+k];
                int r2=y+k>n?-1:pos[y+k];
                return r1==r2;
            };
            for(int i=1;i<=n;++i)pos[i]=i,rk[i]=s[i-1];
            
            base_sort();
            for(int k=1;k<=n;k<<=1)
            {
                int rank=0;for(int i=n-k+1;i<=n;++i)pos[++rank]=i;
                for(int i=1;i<=n;++i)if(sa[i]>k)pos[++rank]=sa[i]-k;
                base_sort();
                swap(rk,pos);
                rk[sa[1]]=rank=1;
                for(int i=2;i<=n;++i){if(!check(sa[i],sa[i-1],k))++rank;rk[sa[i]]=rank;}
                if(rank==n)break;
                m=rank;
            }
           
        };
        auto getHeight=[&]()
        {
            getSa();
            int h=0;
            lcp[rk[1]]=0;
            for(int i=1;i<=n;++i)
            {
                int k=sa[rk[i]-1];//sa[i-1]的开始位置
                if(!k)continue;
                if(h)--h;
                for(;k+h<=n&&i+h<=n;++h){
                    if(s[k+h-1]!=s[i+h-1])break;
                }
                lcp[rk[i]]=h;
                
            }
        };
        long long ans=n;
        getHeight();
        //st表维护rank[i]到rank[j]的最小公共前缀的长度
        vector<ll>lg(n+1);vector<ll>bin(log2(n)+2);
        lg[1]=0;for(int i=2;i<=n;++i)lg[i]=lg[i/2]+1;bin[1]=2;bin[0]=1;
        for(int i=2;i<lg[n]+2;++i)bin[i]=bin[i-1]*2;
        vector<vector<ll>>st(n+1,vector<ll>(lg[n]+1,0));
        for(int i=1;i<=n;++i)st[i-1][0]=lcp[i];
        for(int j=1;j<=lg[n];++j)
        {
            for(int i=1;i+bin[j]<=n;++i)
            {
                st[i][j]=min(st[i][j-1],st[i+bin[j-1]][j-1]);
            }
        }
        
        for(int i=2;i<=n;++i)
        {
            int l=rk[i],r=rk[1];
            if(l>r)swap(l,r);
            int k=r-l;
            ans+=min(st[l][lg[k]],st[r-(1<<(lg[k]))][lg[k]]);
        }
        
        return ans;
    
    }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.sumScores("ikftdchmyxykxrhxkqvssdwpohgkiumizffdsjnytvmbfhoeirsuinwadjwfayyrfmcxydmahwnseimpmmbadmixazxqeqdwwyeafvgcfhtaepixijqggaclqirhoatjlbbnnruroukcgpasshhwjjedollpptdxotpvmhcsjqfwgqhtrpxrrgkjmzhucizzbwwfhdnvkfbdymbmmhvqfisfjmujmtvhtyglmxssxsqykjgvbxcltaacwxikyljtshqakjowpyxmzmhrtjyhwjmvejxyyzufjctvmgxwtpcnayueofrmgpvhpysircoaeupawcjsfujjefavgcjqcgpxdpfwwjpgczftqadgypnnevbffvuwbqmaktkhzjogajiwcjdgbygsnfpmbonbttvwamqdhfdvdhkdfkhndcyvd");
  return 0;
}
