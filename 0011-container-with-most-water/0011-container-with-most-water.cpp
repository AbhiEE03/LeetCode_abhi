class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0,n=height.size();
        int l=0,r=n-1;

        while(l<r){
            int h=min(height[l],height[r]);
            water=max(water,(r-l)*h);
            if(height[l]>height[r]){
                r--;
            }else l++;
        }
        return water;
    }
};