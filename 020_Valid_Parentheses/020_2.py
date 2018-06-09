class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        vi = {']':'[', '}':'{', ')':'('}
        for char in s:
            if char in vi.values():
                stack.append(char)
            elif char in vi.keys():
                if stack == [] or stack.pop() != vi[char]:
                    return False
        return stack == []