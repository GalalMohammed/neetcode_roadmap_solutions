class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = 0
        for i in nums:
            index += 1
            if target - i in nums[index:]:
                return [nums.index(i), (nums[index:].index(target - i)) + index]
