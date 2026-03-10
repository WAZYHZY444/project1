# Python与C语言重要区别

#1.
# 在Python中使用算数运算符/，结果一定是浮点数 (在python中，使用算数运算符，操作数有浮点数，返回值一定是浮点数)
print(25/5)
print(25//5) #返回整数(向下取整)
print(-7//2)

#2.
# Python中的取模运算符%，两个操作数既可以是整数(包括负数)，也可以是浮点数
print(10.5%3)

#3.
# 幂运算，Python使用**运算符(但也可以使用pow函数)，C语言运用pow函数
print(2**3)

#4.
# Python中print输出末尾默认换行，C语言换行需要手动加\n

#5.
# C语言：&&   ||   !
# python：and  or  not
# print(not 3>9)

#6.
# 三目运算符
# c         condition ? expression1 : expression2;      a>b?a:b
# python    expression1 if condition else expression2   a if a>b else b

#7.
# C语言  if-if else-else
#python  if-elif-else

#8.
# Python没有C语言那样的++和--自增/自减运算符

#9.
# 强制类型转换时，C语言：数据类型加括号,(int)x; python：变量名加括号,int(x).

#10.
#isupper/islower函数. C语言：处理的是单个字符，返回0或非0; python：处理的是整个字符串，返回True或False。

#11.
#使用内置函数的时候，C语言是把操作对象写在函数名后面括号里面；python把操作对象写在函数名前面，与函数名用一个点隔开
# C                 python
# char c='a';       c="aaa"
# isupper(c);       c.isupper()

#12.
#C       tolower/toupper  单个字符大小写转换的库函数
#python  lower/upper      整个字符串大小写转换的内置函数

#13.
#浮点型强制转换成整型
#python:  float(3)    打印显示3.0         创建一个新的双精度浮点数对象，显示时默认保留一位小数。
#C:       (float)3    打印显示3.000000    将整数在内存中的表示形式重新解释为单精度浮点数格式，printf默认打印6位小数。

#14.
#C:      float是单精度浮点型，double是双精度浮点型
#python：float是双精度浮点型，没有double类型
#Python把C语言中的float和double合并成了一个类型，选择了更强大的double作为唯一的标准，但沿用了float这个名字。