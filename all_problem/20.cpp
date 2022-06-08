#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        int one=0,two=0,three=0;
        stack<char>st;
        unordered_map<char,char>mapp={{'(',')'},{'[',']'},{'{','}'}};
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size()&&mapp[st.top()]==s[i])
                {
                    st.pop();
                }
                else return false;
            }
        }
        if(st.size()!=0)return false;
        return true;
}
int main()
{
    cout<<isValid("()")<<endl;

}