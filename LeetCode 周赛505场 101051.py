class Solution:
    def han(self,n):
        res=['0','1']
        for i in range(1,n):
            s=[]
            for j in res:
                s.append(j+'0')
                if not j.endswith('1'):
                    s.append(j+'1')
            res=s
        return res
        
    def generateValidStrings(self, n: int, k: int) -> list[str]:
        res=self.han(n)
        result=[]
        for i in (res):
            cnt=0
            for j,c in enumerate(i):
                if c=='1':
                    cnt+=j
            if cnt<=k:
                result.append(i)
        return result
s=Solution()
print(s.generateValidStrings(3,1))