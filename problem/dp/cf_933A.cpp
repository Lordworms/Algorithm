/*
    A dragon symbolizes wisdom, power and wealth. On Lunar New Year's Day, people model a dragon with bamboo strips and clothes, raise them with rods, and hold the rods high and low to resemble a flying dragon.

A performer holding the rod low is represented by a 1, while one holding it high is represented by a 2. Thus, the line of performers can be represented by a sequence a1, a2, ..., an.

Little Tommy is among them. He would like to choose an interval [l, r] (1 ≤ l ≤ r ≤ n), then reverse al, al + 1, ..., ar so that the length of the longest non-decreasing subsequence of the new sequence is maximum.

A non-decreasing subsequence is a sequence of indices p1, p2, ..., pk, such that p1 < p2 < ... < pk and ap1 ≤ ap2 ≤ ... ≤ apk. The length of the subsequence is k.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(5);
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        dp[1]+=(x==1);
        dp[2]=max(dp[1],dp[2]+(x==2));
        dp[3]=max(dp[2],dp[3]+(x==1));
        dp[4]=max(dp[3],dp[4]+(x==2));
    }
    cout<<dp[4]<<'\n';
}