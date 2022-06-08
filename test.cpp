#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
        int more=(a&b)<<1;
        return b==0?a:add(a^b,(a&b)<<1);
    }
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout<<add(-1,2)<<endl;
   return 0;
}
