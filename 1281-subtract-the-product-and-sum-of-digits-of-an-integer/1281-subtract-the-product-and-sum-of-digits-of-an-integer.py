class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        pro=1
        ts=0
        for digit in str(n):
            num=int(digit)
            pro*=num
            ts+=num
        return pro-ts