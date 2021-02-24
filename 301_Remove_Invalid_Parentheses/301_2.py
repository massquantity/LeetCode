class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(string):
            count = 0
            for i in string:
                if i == '(':
                    count += 1
                elif i == ')':
                    count -= 1
                if count < 0:
                    return False
            return count == 0
        
        def dfs(string, index, left, right):
            if left == 0 and right == 0 and isValid(string):
                res.append(string)
                return
            for i in range(index, len(string)):
                if i > index and string[i] == string[i-1]:
                    continue
                tmp = string[:i] + string[i+1:]
                if left > 0 and string[i] == '(':
                    dfs(tmp, i, left - 1, right)
                if right > 0 and string[i] == ')':
                    dfs(tmp, i, left, right - 1)
        
        res = []
        left, right = 0, 0
        for string in s:
            if string == '(':
                left += 1
            elif string == ')':
                if left > 0:
                    left -= 1
                else:
                    right += 1
        dfs(s, 0, left, right)
        return res
