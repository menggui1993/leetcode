class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            if d.get(target-nums[i], 0) != 0:
                return [d[target-nums[i]], i + 1]
            else:
                d[nums[i]] = i + 1