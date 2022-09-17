/*
    注意，单调队列一开始--tail是为了让队列单调，而之后++head是为了保证队列在当前考虑的范围中
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int q[maxn], a[maxn];
int n, k;

void getmin() {  // 得到这个队列里的最小值，直接找到最后的就行了
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    printf("%d ", a[q[head]]);
  }
}

void getmax() {  // 和上面同理
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    printf("%d ", a[q[head]]);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  getmin();
  printf("\n");
  getmax();
  printf("\n");
  return 0;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}