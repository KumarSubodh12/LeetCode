class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        
        min_diff = float('inf')
        res = []
        
        # find minimum difference
        for i in range(1, len(arr)):
            min_diff = min(min_diff, arr[i] - arr[i - 1])
        
        # collect pairs with minimum difference
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] == min_diff:
                res.append([arr[i - 1], arr[i]])
        
        return res
