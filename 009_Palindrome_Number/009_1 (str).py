class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        cur = str(x)
        if cur == cur[::-1]:
            return True
        else:
            return False