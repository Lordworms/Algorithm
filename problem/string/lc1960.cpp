/*
    题意：给你一个下标从 0 开始的字符串 s ，你需要找到两个 不重叠的回文 子字符串，它们的长度都必须为 奇数 ，使得它们长度的乘积最大。
    更正式地，你想要选择四个整数 i ，j ，k ，l ，使得 0 <= i <= j < k <= l < s.length ，且子字符串 s[i...j] 和 s[k...l] 都是回文串且长度为奇数。s[i...j] 表示下标从 i 到 j 且 包含 两端下标的子字符串。
    请你返回两个不重叠回文子字符串长度的 最大 乘积。
    题解：
        看到奇数回文串，马上想manacher，我们manacher预处理出对应的p数组，之后枚举分割点i，分别计算出i左侧和i右侧的奇数回文串的最大值，然后
        针对每次枚举，我们更新答案即可
    
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    using ll =long long;
public:
    long long maxProduct(string s) {
        string mod=s;
        int n=mod.size();
        vector<int>p(n+1,0);
        int R=0,mid;
        for(int i=1;i<n;++i)
        {
            p[i]=R>i?min(R-i,p[2*mid-i]):0;
            while((i+p[i]+1<n&&i-p[i]-1>=0)&&mod[i+p[i]+1]==mod[i-p[i]-1])++p[i];
            if(i+p[i]>R)
            {
                R=i+p[i];
                mid=i;
            }
        }
        vector<ll>maxL(n,0),maxR(n,0);
        maxL[0]=1,maxR[n-1]=1;
        for(int i=1,k=0;i<n;++i)
        {
            while(k+p[k]<i)++k;
            maxL[i]=max(maxL[i-1],(ll)2*(i-k)+1);//对称中心覆盖到i，且距离i最远
        }
        ll ans=1;
        for(int i=n-2,k=n-1;i>=0;--i)
        {
            while(k-p[k]>i)--k;
            maxR[i]=max(maxR[i+1],(ll)2*(k-i)+1);
        }
        for(int i=0;i<n-1;++i)ans=max(ans,maxL[i]*maxR[i+1]);
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.maxProduct("ababbb");
  return 0;
}