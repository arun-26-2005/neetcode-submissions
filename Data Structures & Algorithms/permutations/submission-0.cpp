class Solution {
public:
void backtrack(vector<int>& nums,vector<int> temp,vector<vector<int>> &result,vector<bool> x,int index)
{
    if(temp.size()==nums.size())
    {
        result.push_back(temp);
        temp.clear();
        return;

    }
    for(int i=0;i<nums.size();i++)
    {
        if(x[i]==false)
        {temp.push_back(nums[i]);
        x[i]=true;
        backtrack(nums,temp,result,x,i);
        x[i]=false;
        temp.pop_back();
        
        
        }
    }
    return;



}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        vector<bool> x(nums.size(),false);
        backtrack(nums,temp,result,x,0);
        return result;
        
    }
};
