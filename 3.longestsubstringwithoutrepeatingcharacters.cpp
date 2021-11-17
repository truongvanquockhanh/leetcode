
//Given a string s, find the length of the longest substring without repeating characters.

//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> a(256,-1);
    int maxl=0, st=-1;
    for (int i=0; i<s.length();i++) {
        if(a[s[i]]>st) 
            st=a[s[i]];
        a[s[i]]=i;
        maxl=max(maxl,i-st);
        
    }
    return maxl;
}
};