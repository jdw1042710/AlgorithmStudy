import sys

nums = dict()
n = int(input())
for i in range(n):
    nums[int(input())] = ""
nums = list(nums.keys()).sort()
for i in nums:
    print(i)
