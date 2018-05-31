class Solution:
    def isValid(self, s):
        stack = []
        for char in s:
            if char == "(":
                stack.append(")")
            elif char == "{":
                stack.append("}")
            elif char == "[":
                stack.append("]")
            elif stack == [] or stack.pop() != char:
                return False
        return stack == []
				
if __name__ == '__main__':
    s='{[]}'
    res = Solution().isValid(s)
    print(res)