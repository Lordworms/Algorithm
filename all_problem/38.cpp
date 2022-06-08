#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
       if(n==1)return "1";
       int num[10];
       string now="1",res;
       char car;
       int count=0;
       memset(num,0,sizeof(num));
       for(int i=1;i<n;++i)
       {
           car=now[0];
           for(int j=0;j<now.size();++j)
           {
                 count++; 
                if(j==now.size()-1||((j!=now.size()-1)&&(now[j]!=now[j+1])))
                {
                   car=now[j];
                   res+=(char)(count+'0');
                   res+=car;
                   count=0;
                }   
               
            }
           
            now=res;
            res="";
       }
       return now;
    }
int main()
{
    cout<<countAndSay(4)<<endl;
}