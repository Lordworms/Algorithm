#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();++i)
        {
            if((s[i]>='0'&&s[i]<='9'))
            {
                str+=s[i];
            }
            if(isalpha(s[i]))
            {
                str+=tolower(s[i]);
            }
        }
        for(int i=0;i<str.size()/2;++i)
        {
            if(str[i]!=str[str.size()-i-1])
            {
                return false;
            }
        }
        return true;
    
}
int main()
{
    cout<<isPalindrome("A man, a plan, a canal: Panama");
}