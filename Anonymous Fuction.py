# 匿名函数
#基本语法：   函数名=lambda 形参:返回值

# def test1(a,b):
#     return a+b
# print(test1(1,2))
#
# test2=lambda a,b:a+b
# print(test1(1,2))

#lambda的参数形式
#1.无参数
test1=lambda :"Hello World!"
print(test1())
#2.默认参数
test2=lambda a,b=10:(a,b)   #直接返回参数值，不做计算处理，要以元组的形式
print(test2(5))
#3.关键字参数
test3=lambda **kwargs:kwargs
print(test3(name='ZhangYuan',age=40))