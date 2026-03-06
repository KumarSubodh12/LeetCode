# Recursive solution
"""class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        if rowIndex == 0:
            return [1]

        prev = self.getRow(rowIndex - 1)
        return [1] + [a + b for a, b in zip(prev, prev[1:])] + [1]"""


# Math solution
class Solution:
    def getRow(self, rowIndex: int) -> list[int]:
        answer = [1] * (rowIndex + 1)
        for i in range(1, rowIndex + 1):
            answer[i] = answer[i - 1] * (rowIndex - i + 1) // i

        return answer