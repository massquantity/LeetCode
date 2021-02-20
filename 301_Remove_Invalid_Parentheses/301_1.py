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
        
        level = set([s])
        while True:
            valid = [i for i in level if isValid(i)]
            if valid:
                return valid
            next_level = set()
            for string in level:
                for i in range(len(string)):
                    if string[i] in "()":
                        next_level.add(string[:i] + string[i+1:])
            level = next_level
            if not level:
                return []
