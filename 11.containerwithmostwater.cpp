// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn 
// such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, 
// such that the container contains the most water.

// Notice that you may not slant the container.

//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int maxa=0,s;
        int left=0;
        int right=n;
        while(left<right) {
            s=min(height[left],height[right])*(right-left);
            maxa=max(maxa,s);
            if(height[left]<=height[right]){
                left ++;
            }
            else {
                right --;
            }
        }
    return maxa;
    }
};