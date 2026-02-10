#print("Hello","my name is Zhuyan",sep=",",end="!")

#Python数据类型有复数型
"""
a=2+4j #j是虚数单位
print(type(a)) #打印数据类型
print(a)
b=complex(5,3)
print(b)
"""

#f格式化
"""
name="Zhangyuan"
age=40
print(f"他的名字是{name},他今年{age}岁了")
"""
#r原生字符串，默认取消转义
#print(r"Zhuang\\\yuan")

#Python与C语言重要区别
""""
#使用算数运算符，操作数有浮点数，返回值也是浮点数
#1.在Python中使用算数运算符/，结果一定是浮点数
print(25/5)
print(25//5) #返回整数(向下取整)
print(-7//2)

#2.Python中的取模运算符%，两个操作数既可以是整数(包括负数)，也可以是浮点数
print(10.5%3)

#3.幂运算，Python使用**运算符(但也可以使用pow函数)，C语言运用pow函数
print(2**3)

#4.Python中print输出末尾默认换行，C语言换行需要手动加\n

#5.C语言：&&   ||   !
 python：and  or  not
print(not 3>9)

#6.三目运算符
c         condition ? expression1 : expression2;      a>b?a:b
python    expression1 if condition else expression2   a if a>b else b

#7.C语言  if-if else-else
 python  if-elif-else
 
 #8.Python没有C语言那样的++和--自增/自减运算符
 
 #9.强制类型转换时，C语言：数据类型加括号,(int)x; python：变量名加括号,int(x).
"""

#比较运算符成立返回True，不成立返回False
"""
a=666
b=999
print(a!=b)
"""

"""
i=1
Sum=0
while i<=100:
    Sum+=i
    i+=1
print('结果是',Sum)
"""

# 错误写法	            正确写法	                 说明
# print('结果是'Sum)	    print('结果是', Sum)	     需要逗号分隔(中间有空格)
# print('结果是'+Sum)	print('结果是'+str(Sum))	 sum需要转为字符串(中间没空格)
# print('结果是Sum')	    print(f'结果是{Sum}')	 直接写sum在引号里是字符串
'''
Sum=666
print('结果是',Sum)
print('结果是'+str(Sum))
print(f'结果是{Sum}')
'''

#for循环
#for 临时变量 in 可迭代对象：
#   循环体
''''
str='12345'
for i in str:
    print(f'i={i}')
'''

#range()，用来记录循环次数，相当于一个计数器。有三个参数(start,stop,step)
'''
for i in range(2,4):   #从2开始，从3结束。遵循包前不包后原则，相当于前闭后开
    print("Hello World")
'''
#range()里面只写一个数，这个数就代表循环次数，默认从0开始
#range()里面写两个数，第一个数代表开始位置，第二个数代表结束位置
'''
s=0
for i in range(1,101):
    s+=i
print(f'计算结果{s}')   #注意取消此处的缩进
'''

#Unicode:所有字符都是两个字节
#优点：数字与字符之间转换速度更快
#缺点：占用空间更大

#3UTF-8:更加精准,对不同的字符用不同的字符表示
#优点：节省空间
#缺点：字符与数字的转换速度较慢，每次都需要计算字符要用多少个字节来表示