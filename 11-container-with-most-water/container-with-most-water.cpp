class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0, j=n-1;
        int maxi=0;
        while(i<j){
            int p=min(height[i],height[j]);
            int dis=j-i;
            maxi=max(maxi,p*dis);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return maxi;
    }   
};