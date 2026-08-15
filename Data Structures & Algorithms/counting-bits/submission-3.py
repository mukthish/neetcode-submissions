class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n + 1):
            count = 0
            while i:
                i &= i - 1
                count += 1
            res += [count]
        return res
