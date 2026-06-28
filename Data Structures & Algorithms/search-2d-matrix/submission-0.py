class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low=0
        high=len(nums)-1
        while(low<=high):
            mid=low+(high-low)//2
            if nums[mid]==target:
                return True
            elif nums[mid]>target:
                high=mid-1
            else:
                low=mid+1
        return False
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        flag=False
        for i in range(len(matrix)):
            if target>=matrix[i][0] and target<=matrix[i][len(matrix[i])-1]:
                flag=self.search(matrix[i],target)
            if flag:
                return True
        return False
            
        