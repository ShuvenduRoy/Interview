import collections
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        
        ds = collections.Counter(s)
        dt = collections.Counter(t)
        print ds
        print dt
        print dt-ds
        
        print (dt-ds).values().pop()
        return (dt-ds).keys().pop()
    
if __name__=='__main__':
    s = Solution()
    c = s.findTheDifference("abcd", "abcde")
    print c