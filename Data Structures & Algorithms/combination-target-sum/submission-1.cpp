class Solution {
public:
    void subset_sum(vector<int>& nums,vector<vector<int>>& result,vector<int>& x,int target,int curr_sum,int curr_index)
    {
        if(curr_sum==target)
        {
            vector<int> temp;
            for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<x[i];j++)
                {
                    temp.push_back(nums[i]);
                }

            }
            result.push_back(temp);
            return;
        }
        if(curr_index<nums.size())
        {if(curr_sum+nums[curr_index]<=target)
        {
        x[curr_index]++;
        subset_sum(nums,result,x,target,curr_sum+nums[curr_index],curr_index);
        x[curr_index]--;
        subset_sum(nums,result,x,target,curr_sum,curr_index+1);

        }
        }
       
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> result;
        vector<int> x(nums.size(),0);
        sort(nums.begin(),nums.end());
        subset_sum(nums,result,x,target,0,0);
        return result;
        
    }
};
