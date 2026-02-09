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
"""

#比较运算符成立返回True，不成立返回False
a=666
b=999
print(a!=b)