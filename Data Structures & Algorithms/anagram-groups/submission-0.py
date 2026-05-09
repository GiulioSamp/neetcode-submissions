class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dicto = {}
        for string in strs:
            sig = "".join(sorted(string))
            if (sig in dicto):
                dicto[sig].append(string)
            else:
                 dicto[sig] = [string]
        return list(dicto.values())
            
        