#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int cnt,time,value,key;
    Node(int c,int t,int v,int k)
    {   
        cnt=c;
        time=t;
        value=v;
        key=k;
    }
    bool operator<(const Node& a)const
    {
        return cnt==a.cnt?time<a.time:cnt<a.cnt;
    }
};
class LFUCache {
public:
    int cap,time;
    unordered_map<int,Node>keyTable;
    set<Node>st;
    LFUCache(int capacity) {
        cap=capacity;
        time=0;
        keyTable.clear();
        st.clear();
    }
    int get(int key) {
        if(cap==0)return -1;
        auto it=keyTable.find(key);
        if(it==keyTable.end())return -1;
        Node pre=it->second;
        st.erase(pre);
        pre.cnt++;
        pre.time=++time;
        st.insert(pre);
        it->second=pre;
        return pre.value;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        auto it =keyTable.find(key);
        if(it==keyTable.end())
        {
            if(cap==keyTable.size())
            {
                keyTable.erase(st.begin()->key);
                st.erase(st.begin());
            }
            Node newNode=Node(0,++time,value,key);
            keyTable.insert(make_pair(key,newNode));
            st.insert(newNode);
        }
        else
        {
            Node pre=it->second;
            st.erase(pre);
            pre.time=++time;
            pre.cnt++;
            pre.value=value;
            st.insert(pre);
            it->second=pre;
        }
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}