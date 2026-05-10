from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        buckets = [[] for _ in range(len(nums)+1)]
        countnums = Counter(nums)
        for d in countnums:
            buckets[countnums[d]].append(d)
        result = []
        for i in range(len(buckets) - 1, -1, -1):
            for element in buckets[i]:
                result.append(element)
                if len(result) == k:
                    return result
        return result
            


        