/*
    ai对bj的贡献可以抽象成从ai到bj的独特的路径数（观察！）
    可以这样想，想成一个mxn的矩形，我们要从(0,0)走到(m,n)必须经过m+n个格子，那么这m+n个格子里有n个是向右走的即可
    即C(m+n,n) or C(m+n,m);
    所以对于此题来说，一个数ai的贡献为
    C(n-i+(j-1),j-1)
    所以当且仅当该数为奇数的时候，贡献为1
    C(n-i+(j-1),j-1)的奇偶性和C(n-1,j-1)一致
    当且仅当(n-1)&(j-1)=(j-1)的时候为奇数
    所以当且仅当n-1为1的位，j-1为0才行
    所以当且仅当n-1为~(j-1)的子掩码才行
    https://www.cnblogs.com/irty/p/16566370.html
*/
#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int main()
{
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<19;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (j&(1<<i)) a[j]^=a[j^(1<<i)];
		}
	}
	for (int i=0;i<19;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (j&(1<<i)) a[j^(1<<i)]^=a[j];
		}
	}
	for (int i=n-1;i>=0;i--) cout << a[i] << " ";
	return 0;
}

