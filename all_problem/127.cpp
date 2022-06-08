#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>words={wordList.begin(),wordList.end()};//单词列表
    unordered_set<string>front={beginWord},back={endWord};
    if(words.count(endWord)==0)return 0;
    int step=0;
    while(!front.empty())
    {   
        ++step;
        unordered_set<string>tmp;
        for(auto& word:front)words.erase(word);
        for(auto& word:front)
        {
            for(int i=0;i<word.size();++i)
            {
                 string x=word;
                for(char c='a';c<='z';++c)
                {
                    x[i]=c;
                    if(!words.count(x)){continue;}
                   
                    if(back.count(x))return step;
                    tmp.insert(x);
                }
            }
        }
        if(tmp.size()>back.size()){front=back,back=tmp;}
        else front=tmp;
    }
    return 0;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   vector<string>wordList={"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog",wordList);
   return 0;
}
