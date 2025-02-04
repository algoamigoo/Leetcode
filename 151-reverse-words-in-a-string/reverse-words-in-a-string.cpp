#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) 
    {
        stringstream ss(s);
        string word;
        s="";
        while(ss >> word)
        s =  " " +word+s;
        s.erase(s.begin());
        return s;
    }
};