#include<bits/stdc++.h>
using namespace std;
    bool check(char a)
    {
        if(a>='0'&&a<='9')return true;
        return false;
    }
    int myAtoi(string s) {
       int ans=0;
       int digit=0;
       int start=0,flag=1,set=0;
       int overflow=0;
       while(s[start]==' '||s[start]=='+'||s[start]=='-')
       {
           if(s[start]=='-')
           {
               if(set)return 0;
               flag=-1;
               set=1;
           }
           else if(s[start]=='+')
           {
               if(set)return 0;
               set=1;
           }
           else if(s[start==' ']&&set)
           {
               return 0;
           }
           start++;
       }
       while(s[start]=='0')
       {
           start++;
       }
       for(int i=start;i<s.size();++i)
       {
           if(!check(s[i]))
           {
               break;
           }
           if(ans>INT_MAX/10||(ans==INT_MAX/10&&(s[i]-'0')>(INT_MAX%10)))
           {
               return INT_MAX;
           }
           if(ans<INT_MIN/10||(ans==INT_MIN/10&&(s[i]-'0')>-(INT_MIN%10)))
           {
               return INT_MIN;
           }
           
           ans=ans*10+flag*(int)(s[i]-'0');
       }
       
     
      
       return ans;   
    }


int main()
{
    //cout<<INT_MIN;
    cout<<myAtoi("  +  413");
}