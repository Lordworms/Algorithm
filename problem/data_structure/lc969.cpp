/*
题意：给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
题解：一次翻转确定一个元素即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        for(int i=n;i>1;--i)
        {
            int index=max_element(arr.begin(),arr.begin()+i)-arr.begin();
            if(index==n-1)continue;
            reverse(arr.begin(),arr.begin()+index+1);
            reverse(arr.begin(),arr.begin()+i);
            ans.push_back(index+1);
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  return 0;
}