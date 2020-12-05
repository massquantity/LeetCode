class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for n in num:
            while k > 0 and stack and n < stack[-1]:
                stack.pop()
                k -= 1
            stack.append(n)

        while stack and k > 0:
            stack.pop()
            k -= 1

        return "".join(stack).lstrip('0') or "0"
