// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        int sum=0, kqua=0, dem=0, check=0, dau=0,check1=0,dem1=0;
        for(int i=0; i<s.length(); i++) {
            if(int(s[i])==40) {
                dem ++;
                check ++;
            }
            if (int(s[i])==41 && check!=0) {
                dem--;
                check--;
                sum=sum+2;
            }
            else if (int(s[i])==41 && check==0){
                kqua=max(kqua,sum);
                sum=0;
            }
            //cout<<"s(i): "<<int(s[i])<<endl<<"i: "<<i<<endl<<"dem: "<<dem<<endl<<"sum"<<sum<<endl<<"kqua: "<<kqua<<endl;
        }
        //return kqua;
        if (dem == 0 )
            return kqua=max(kqua,sum);
        sum=0;
        int j=s.length()-1;
        while(dem!=0) {
            if(int(s[j])==41) {
                dem1 ++;
                check1 ++;
            }
            if (int(s[j])==40 && check1!=0) {
                dem1--;
                check1--;
                sum=sum+2;
            }
            else if(int(s[j])==40 && check1==0){
                kqua=max(kqua,sum);
                sum=0;
                dem=dem-1;
            }
            j--;
        }
        //return j;
        int n=j+1;
        dem=0;
        check=0;
        sum=0;
        for(int h=0;h<n;h++) {
            if(int(s[h])==40) {
                dem ++;
                check ++;
            }
            if (int(s[h])==41 && check!=0) {
                dem--;
                check--;
                sum=sum+2;
            }
            else if (int(s[h])==41 && check==0){
                kqua=max(kqua,sum);
                sum=0;
            }
        }
        return kqua=max(kqua,sum);
    }
};