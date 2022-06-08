#include<bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    int capacity;
    list<pair<int,int>>recent;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        auto value=(*mp[key]).second;
        recent.erase(mp[key]);
        recent.push_front({key,value});
        mp[key]=recent.begin();
        return value;
    }
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            if(recent.size()==capacity)
            {
                mp.erase(recent.back().first);
                recent.pop_back();
            }
        }
        else
        {
            recent.erase(mp[key]);
        }
        recent.push_front({key,value});
        mp[key]=recent.begin();
    }
};
int main()
{
    LRUCache lRUCache(3);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2,2); // cache is {1=1, 2=2}
    lRUCache.put(3,3);
    lRUCache.put(4,4);
    cout<<lRUCache.get(4)<<endl;
    cout<<lRUCache.get(3)<<endl;      
    cout<<lRUCache.get(2)<<endl;      
    cout<<lRUCache.get(1)<<endl;      
    lRUCache.put(5,5);
    cout<<lRUCache.get(1)<<endl;
    cout<<lRUCache.get(2)<<endl;
    cout<<lRUCache.get(3)<<endl;
    cout<<lRUCache.get(4)<<endl;
    cout<<lRUCache.get(5)<<endl;
}
