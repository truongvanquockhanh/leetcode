// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. 
// This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. 
// Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. 
// Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.

// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s)
{
    if(int(s[0])==0)
        return 0;
    int atoi=0, ad = 1, i = 0, hetdau = 0, x = 10;
    for (i; i < s.length(); i++)
    {

        if (hetdau == 0)
        {
            if (int(s[i]) == 45)
            {
                ad = -1;
                int tama = i + 1;
                if (int(s[tama]) < 48 || int(s[tama]) > 57)
                    return 0;
            }
            if (int(s[i]) == 43)
            {
                int tamd = i + 1;
                if (int(s[tamd]) < 48 || int(s[tamd]) > 57)
                    return 0;
            }
            if (int(s[i]) != 32 && int(s[i]) != 43 && int(s[i]) != 45 && (int(s[i])<48 || int(s[i])>57))
                return 0;
            if (int(s[i]) >= 48 && int(s[i]) <= 57)
            {
                hetdau = 1;
                atoi = (int(s[i]) - 48);
            }
        }
        else
        {
            if (int(s[i]) >= 48 && int(s[i]) <= 57)
            {
                if(atoi>214748364 && ad==1)
                    return 2147483647;
                if(atoi>214748364 && ad==-1)
                    return -2147483648;
                if(atoi==214748364 && ad==-1 && int(s[i])-48>=8)
                    return -2147483648;
                if(atoi==214748364 &&ad==1 && int(s[i])-48>=7)
                    return 2147483647;
                else 
                    atoi = atoi * x + (int(s[i]) - 48);
            }
            else
                return atoi * ad;
        }
    }
    return atoi * ad;
}
};