/*
As Will is stuck in the Upside Down, he can still communicate with his mom, Joyce, through the Christmas lights (he can turn them on and off with his mind). He can't directly tell his mom where he is, because the monster that took him to the Upside Down will know and relocate him.


Thus, he came up with a puzzle to tell his mom his coordinates. His coordinates are the answer to the following problem.

A string consisting only of parentheses ('(' and ')') is called a bracket sequence. Some bracket sequence are called correct bracket sequences. More formally:

Empty string is a correct bracket sequence.
if s is a correct bracket sequence, then (s) is also a correct bracket sequence.
if s and t are correct bracket sequences, then st (concatenation of s and t) is also a correct bracket sequence.
A string consisting of parentheses and question marks ('?') is called pretty if and only if there's a way to replace each question mark with either '(' or ')' such that the resulting string is a non-empty correct bracket sequence.

Will gave his mom a string s consisting of parentheses and question marks (using Morse code through the lights) and his coordinates are the number of pairs of integers (l, r) such that 1 ≤ l ≤ r ≤ |s| and the string slsl + 1... sr is pretty, where si is i-th character of s.

Joyce doesn't know anything about bracket sequences, so she asked for your help.
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;++i){
        int left=0,vir=0;
        for(int j=i;j<n;++j){
            if(s[j]=='('){
                ++left;
            }
            if(s[j]==')'){
                --left;
            }
            if(s[j]=='?'){
                if(left>0){
                    --left,++vir;
                }else{
                    ++left;
                }

            }
            if(left<0&&vir){
                left+=2,--vir;
            }
            if(left<0&&!vir){
                break;
            }
            if(left==0){
                ++ans;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}