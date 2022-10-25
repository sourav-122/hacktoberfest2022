/* 
Given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        string ans="";
        for(auto &it: order){
            if(m.find(it)!=m.end()){
                auto temp=m.find(it);
                int freq=temp->second;
                string s(freq,it);
                ans+=s;
                m.erase(it);
            }
        }
        for(auto &it: m){
            string s(it.second,it.first);
            ans+=s;
        }
        return ans;
    }
};

/*
Input: order = "cba", s = "abcd"
Output: "cbad"

Input: order = "cbafg", s = "abcd"
Output: "cbad"
*/