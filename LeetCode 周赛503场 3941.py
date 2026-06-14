class Solution:
    def passwordStrength(self, password: str) -> int:
        s=set(password)
        strength=0
        for ch in s:
            if 'a'<=ch<='z':
                strength+=1
            elif 'A'<=ch<='Z':
                strength+=2
            elif '0'<=ch<='9':
                strength+=3
            elif ch in '!@#$':
                strength+=5
        return strength
    
s=Solution()
print(s.passwordStrength("aA1!"))