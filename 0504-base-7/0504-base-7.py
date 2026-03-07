class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"

        output = []
        number = abs(num)
        template = "0123456"

        while number > 0:
            output.append(template[number % 7])
            number //= 7

        return ("-" if num < 0 else "") + "".join(reversed(output))