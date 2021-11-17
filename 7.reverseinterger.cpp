//Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    bool ktra(int x) {
        if (x>1000000000 && (x%10)>2) {
            return  true; 
        }
        if (x <-1000000000 && (x%10) < -2) {
            return true;
        }
        return false;
    }
    int reverse(int x) {
        if (ktra(x)) {
            return 0;
        }
        int i =1,t=10;
        int y=x%10;
        x=x/10;
        while((x/10)!=0){
            y=(y*t)+(x%10);
            i++;
            x=x/10;
        }
        if(y>100000000 ) {
            if (y%10>4) 
                return 0;
            if (x>7)
                return 0;
        }
        if (y < -100000000){
            if (y%10<-4 )
                return 0;
            if (x<-8)
                return 0;
        }
        if (x!=0 && x<10) {
            y=y*t+x;
        }
            
        return y;
    }
};