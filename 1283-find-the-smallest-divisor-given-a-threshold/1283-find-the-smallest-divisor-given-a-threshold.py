import math
class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        left, right = 1, max(nums)

        while left<right:
            mid = left + (right-left)//2
            total = 0
            for n in nums:
                total += math.ceil(n/mid)
            # print("left:", left, "right", right, "total:", total, "mid:", mid )
            if total>threshold:
                left = mid+1
                # print("increasing as", total, ">", threshold)
            else:
                right = mid
                # print("decreasing as", total, "<=", threshold)
        # print("left:", left, "right:", right)
        return left