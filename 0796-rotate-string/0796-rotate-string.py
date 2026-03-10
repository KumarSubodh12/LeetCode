class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        length = len(s)
        s = list(s)
        goal = list(goal)
        for i in range(length):
            element = s.pop(0)
            s.append(element)

            if s == goal:
                return True
        return False
        
        