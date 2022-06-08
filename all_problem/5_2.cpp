#include<iostream>
using namespace std;
pair<int,int> find_pos(string s,int left,int right)
{
    while(left>=0&&right<s.size()&&s[left]==s[right])
    {
        left--;
        right++;
    }
    return {left+1,right-1};

}
string solution(string s)
{
    int len=s.size();
    int start=0,end=0;
    int left1,right1,left2,right2;
    for(int i=0;i<len;++i)
    {
        auto[left1,right1]=find_pos(s,i,i);
        auto[left2,right2]=find_pos(s,i,i+1);
        if(right1-left1>end-start)
        {
            start=left1;
            end=right1;
        }
        if(right2-left2>end-start)
        {
            start=left2;
            end=right2;
        }
    
    }
    return s.substr(start,end-start+1);
}
int main()
{
    cout<<solution("ccc");


}