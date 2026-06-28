class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int low=0;
        int high=height.size()-1;
        while(low<high)
        {
            int temp_area=min(height[low],height[high])*(high-low);
            if(temp_area>area){
                area=temp_area;
            }
            if(height[low]<height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return area;
        
    }
};