//Roman numerals are usually written largest to smallest from left to right.
// However, the numeral for four is not IIII. Instead, the number four is written as IV. 
// Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. 
// There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

// https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> roman;
        roman[1]="I";
        roman[4]="IV";
        roman[5]="V";
        roman[9]="IX";
        roman[10]="X";
        roman[40]="XL";
        roman[50]="L";
        roman[90]="XC";
        roman[100]="C";
        roman[400]="CD";
        roman[500]="D";
        roman[900]="CM";
        roman[1000]="M";
        int i=1,check=1;
        int k;
        int h=num;
        string R;
        while(h/10>0) {
            i=i+1;
            h=h/10;
        }
        std::map<int, string>::iterator sh;
        sh=roman.begin();
        while (sh!=roman.find(10)) {
             if (num==sh->first) {
                return sh->second;
            }
            sh++;
        }
        if (num%10!=0){
            k=num%10;
            sh=roman.begin();
            while (sh!=roman.end()) {
                 if (k==sh->first) {
                    R.insert(0,sh->second);
                    check=5;
                    break;
                }
                sh++;
            }
            if(check!=5){
                if (k<4) {
                    R.insert(0,"I");
                    for (int t=1;t<k;t++){
                        R.insert(0,"I");
                    }
                }
                else {
                    for (int t=1;t<=k-5;t++){
                    R.insert(0,"I");                    
                    }
                    R.insert(0,"V");
                }
            }
            
        }
        i=i-1;
        if (i==0)
            return R;
        h=num/10;
        if (h%10!=0){
            k=h%10;
            k=k*10;
            sh=roman.find(10);
            while (sh!=roman.find(100)) {
                 if (k==sh->first) {
                    R.insert(0,sh->second);
                    check=6;
                    break;
                }
                sh++;
            }
            if(check!=6){
                if (k<40) {
                    R.insert(0,"X");
                    for (int t=1;t<k/10;t++){
                        R.insert(0,"X");
                    }
                }
                else {
                    for (int t=1;t<=k/10-5;t++){
                    R.insert(0,"X");                    
                    }
                    R.insert(0,"L");
                }
            }
           
        }
         i=i-1;
        if (i==0)
            return R;
        h=h/10;
        if (h%10!=0){
            k=h%10;
            k=k*100;
            sh=roman.find(100);
            while (sh!=roman.find(1000)) {
                 if (k==sh->first) {
                    R.insert(0,sh->second);
                    check=7;
                    break;
                }
                sh++;
            }
            if(check!=7){
                if (k<400) {
                    R.insert(0,"C");
                    for (int t=1;t<k/100;t++){
                        R.insert(0,"C");
                    }
                }
                else {
                    for (int t=1;t<=k/100-5;t++){
                    R.insert(0,"C");                    
                    }
                    R.insert(0,"D");
                }
            }
           
        }
        i=i-1;
        if (i==0)
            return R;
        h=h/10;
        if (h%10!=0){
            k=h%10;
            k=k*1000;
            sh=roman.find(1000);
            if (k==sh->first){
                R.insert(0,sh->second);
                return R;
            }
            else {
                R.insert(0,"M");
                for(int t=1;t<k/1000;t++){
                    R.insert(0,"M");
                }
            }
        }
        return R;
    
       
    }
    
    
};