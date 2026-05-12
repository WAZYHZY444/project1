"""
给定一个只含小写字母的字符串 s，返回它所有子串的美丽值中的最大值。
美丽值 = 子串中 出现次数最多的字母次数 - 出现次数最少的字母次数。
"""

# 统计频率相关
from collections import Counter
def beauty_max(s):
    n=len(s)
    result=0
    for i in range(n):
        count=Counter()
        for j in range(i,n):
            count[s[j]]+=1
            max_count=max(count.values())
            min_count=min(count.values())
            result=max(result,max_count-min_count)
    return result

print(beauty_max("aabcbaa"))


# 1. 普通字典手动统计
cnt = {}
for ch in "aabca":
    cnt[ch] = cnt.get(ch, 0) + 1
print(cnt)

# 2. Counter最常用
cnt = Counter("aabca")    # Counter({'a':3, 'b':1, 'c':1})
print(cnt)

# 3. 获取所有次数
cnt.values()   # dict_values([3,1,1])

# 4. 获取所有元素（按次数重复）
list(cnt.elements())  # ['a','a','a','b','c']

# 5. 最少的n个（没有直接方法，但可以这样）
cnt.most_common()[:-3:-1]  # 最后2个（最少的）