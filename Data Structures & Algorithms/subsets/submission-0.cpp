class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>& result,vector<int> x,int current_index)
    {
        if(current_index>=nums.size())
        {
            result.push_back(x);
            return;
        }
        x.push_back(nums[current_index]);
        backtrack(nums,result,x,current_index+1);
        x.pop_back();
        backtrack(nums,result,x,current_index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> x;
        backtrack(nums,result,x,0);
        return result;
    }
};
