// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward. 
// For example, 121 is palindrome while 123 is not.

// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x<0 )
            return false;
        if (x==0)
            return true;
        vector<int> a;
        int i,j;
        while(x/10!=0) {
            a.push_back(x%10);
            x=x/10;
        }
        a.push_back(x);
        i=0;
        j=a.size()-1;
        while (i!=j && i<j) {
            if (a[i]==a[j]) {
                i ++;
                j --;
            }
            else return false;
        }
        return true;
        }
};