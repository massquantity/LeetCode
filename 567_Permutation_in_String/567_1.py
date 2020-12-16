class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        char_count   = [0 for _ in range(26)]
        window_count = [0 for _ in range(26)]
        for c in s1:
            char_count[ord(c) - ord('a')] += 1
        
        left = right = distance = 0
        for i in range(26):
            if char_count[i] > 0:
                distance += 1
        
        while right < len(s2):
            c = ord(s2[right]) - ord('a')
            right += 1
            if char_count[c] > 0:
                window_count[c] += 1
                if char_count[c] == window_count[c]:
                    distance -= 1
    
            if distance == 0:
                return True

            while right - left >= len(s1):
                d = ord(s2[left]) - ord('a')
                left += 1
                if char_count[d] > 0:
                    if char_count[d] == window_count[d]:
                        distance += 1
                    window_count[d] -= 1
        
        return False