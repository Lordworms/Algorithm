/*
	重新认识一哈二分哈
	现在有这样一个数组
	[1,2,3,5,5,5,8,9]
	有四个问题 				check	return
	1.找到第一个>=5的元素  	  <5       r	
	2.找到最后一个<5的元素	  <5		l
	3.第一个>5的元素		 <=5		r	
	4.最后一个<=5的元素		 <=5		l
*/
#include <bits/stdc++.h>
using namespace std;
//1.查找
void bs(vector<int>arr,int k)
{
	int n=arr.size();
	int l=-1,r=n+1,m;
	while(l+1!=r)
	{
		m=(l+r)>>1;
		if(check(m))
		{
			l=m;
		}
		else 
		{
			r=m;
		}
	}
	return l/r
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
