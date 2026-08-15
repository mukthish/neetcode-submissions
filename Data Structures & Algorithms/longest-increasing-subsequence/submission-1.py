class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1]*n

        def dfs(i):
            if dp[i] != -1:
                return dp[i]

            LIS = 1
            for j in range (i + 1, n):
                if nums[i] < nums[j]:
                    LIS = max(LIS, 1 + dfs(j))

            dp[i] = LIS
            return LIS

        return max(dfs(i) for i in range(n))
        