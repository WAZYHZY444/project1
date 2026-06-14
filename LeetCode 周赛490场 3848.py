def Fact(n):
    return 1 if n<=1 else n*Fact(n-1)
class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:
        sst1=[int(d) for d in str(n)]
        l=len(sst1)
        sum=0
        for i in range(0,l):
            sum+=Fact(sst1[i])
        sst2=[int(d) for d in str(sum)]
        return sorted(sst1)==sorted(sst2)
        # sst.sort()返回的是None，return None==None，所以不能直接用sst.sort()来比较两个列表是否相等

s=Solution()
print(s.isDigitorialPermutation(145))