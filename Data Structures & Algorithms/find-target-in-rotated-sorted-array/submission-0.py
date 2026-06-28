class Solution:
    def search(self, nums: List[int], target: int) -> int:
        result=0
        low,high=0,len(nums)-1
        while(low<=high):
            if nums[low]<=nums[high]:
                if nums[low]<nums[result]:  
                    result=low
                break
            mid = low + (high-low)//2
            if nums[mid]<nums[result]:
                result=mid
            if nums[mid]>=nums[low]:
                low=mid+1
            else:
                high=mid-1
        if target<nums[result] or (result>0 and nums[result-1]<target):
            return -1
        else:
            if nums[len(nums)-1]<target:
                for i in range(0,result+1):
                    if nums[i]==target:
                        return i
            else:
                for i in range(result,len(nums)):
                    if nums[i]==target:
                        return i
        return -1
                

        
        