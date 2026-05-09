class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dicto = {}
        for string in strs:
            counts = [0] * 26
            for s in string:
                counts[ord(s) - ord('a')] += 1
            sig = tuple(counts)
            if (sig in dicto):
                dicto[sig].append(string)
            else:
                 dicto[sig] = [string]
        return list(dicto.values())
            
        