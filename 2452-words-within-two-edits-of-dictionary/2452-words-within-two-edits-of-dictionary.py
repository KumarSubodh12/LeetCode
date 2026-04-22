class Solution:
    def twoEditWords(self, q: List[str], d: List[str]) -> List[str]:
        res = []
        for s in q:
            for t in d:
                mismatchs = deque(takewhile(lambda p:p<4,
                    accumulate(map(ne,s,t))),maxlen=1)[0]
                if mismatchs<3:
                    res.append(s)
                    break
        
        return res