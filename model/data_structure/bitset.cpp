#include <bits/stdc++.h>
using namespace std;
struct Bitset{
    unsigned long long arr[3130]={};
    unsigned long long AF=-1ull;
    
    void flip(int l,int r){
        arr[l/64]^=(1ull<<(l%64))-1;
        if (r%64==63) arr[r/64]^=AF;
        else arr[r/64]^=(1ull<<(r%64+1))-1;
        l/=64,r/=64;
        if (l==r) return;
        arr[l]^=AF;
        
        for (int x=l+1;x<r;x++) arr[x]^=AF;
    }
    
    int get(int i){
        if (arr[i/64]&(1ull<<(i%64))) return 1;
        else return 0;
    }
    
    int get1(int i){
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=arr[i]&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==0) i++;
            else return i*64+__builtin_ctzll(arr[i]);
        }
    }
    
    int get0(int i){
        unsigned long long mask=AF^((1ull<<(i%64))-1);
        
        i=i/64;
        unsigned long long temp=(arr[i]^AF)&mask;
        if (temp) return i*64+__builtin_ctzll(temp);
        i++;
        while (true){
            if (arr[i]==AF) i++;
            else return i*64+__builtin_ctzll(arr[i]^AF);
        }
    }
    
    int gethigh(){
        int i=3129;
        while (true){
            if (arr[i]==0) i--;
            else return i*64+63-__builtin_clzll(arr[i]);
        }
    }
} BS;