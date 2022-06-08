#include<bits/stdc++.h>
using namespace std;
    int trans(string a)
    {
        int flag=0;
        int ans=0;
        for(auto& i:a)
        {
            if(i=='-')
            {
                flag=1;
                continue;
            }
            if(i>='0'&&i<='9')
            {
                ans=ans*10+(i-'0');
            }
        }
        return flag?-ans:ans;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int a,b;
        for(auto& str:tokens)
        {
            if(str=="+"||str=="-"||str=="*"||str=="/")
            {
                b=s.top();s.pop();
                a=s.top();s.pop();
                if(str=="+")
                {
                    a=a+b;
                    s.push(a);
                }
                if(str=="-")
                {
                    a=a-b;
                    s.push(a);
                }
                if(str=="*")
                {
                    a=a*b;
                    s.push(a);
                }
                if(str=="/")
                {
                    a=a/b;
                    s.push(a);
                }
            }
            else
            {
                s.push(trans(str));
            }
        }
        return s.top();
    }

int main()
{
 vector<string>a={"4","13","5","/","+"};
 cout<<evalRPN(a);  
}