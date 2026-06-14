class Solution:
    def digitFrequencyScore(self, n: int) -> int:
        list=[int(d) for d in str(n)]
        list.sort()
        l=len(list)
        sum=list[0]*list.count(list[0])
        for i in range(1,l):
            if list[i]!=list[i-1]:
                sum+=list[i]*list.count(list[i])
        return sum

s=Solution()
print(s.digitFrequencyScore(122))