class Solution:     
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low=0
        high=(len(matrix)*len(matrix[0]))-1
        n=len(matrix[0])
        
        while(low<=high):
                mid=low+(high-low)//2

                if matrix[mid//n][mid%n]==target:
                    return True
                elif matrix[mid//n][mid%n]>target:
                    high=mid-1
                else:
                    low=mid+1
        return False
        

            
        