class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dicto = defaultdict(list)
        for string in strs:
            counts = [0] * 26
            for s in string:
                counts[ord(s) - ord('a')] += 1
            sig = tuple(counts)
            dicto[sig].append(string)
        return list(dicto.values())
            
        