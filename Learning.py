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

#字符串编码转换
'''
a='hello'
print(a,type(a))    #str，字符串是以字符为单位进行处理
a1=a.encode()       #编码
print(a1,type(a1))  #bytes，以字符为单位进行处理
a2=a1.decode()      #解码
print(a2,type(a2))
#注意；对于bytes，只需要直到它跟字符串类型之间的相互转换

st='你好'
st1=st.encode("utf-8")
print(st1,type(st1))
st2=st1.decode("utf-8")
print(st2,type(st2))
'''

#字符串操作
#1.'+'字符串拼接

# s1='你好'
# s2='世界'
# print(s1+s2)
# print(s1,s2,sep='')

#2.'*'重复输出

#print('hello world\n'*5) # *重复次数

#3.成员运算符
#作用：检查字符串中是否包含某个字串
#in: 如果包含，返回True；如果不包含，返回False
#not in: 如果不包含，返回True；如果包含，返回False

# s1='hello world'
# s2='hello'
# s3='hehe'
# print(s2 in s1)
# print(s3 in s1)
# print(s2 not in s1)
# print(s3 not in s1)

#4.下标
#从左往右，下标从0开始，0，1···
#从右往左，下标从-1开始，-1，-2···

# s='Chinese'
# print(s[2])
# print(s[-2])

#5.切片：对操作的对象截取其中的一部分
#语法：[开始位置：结束位置：步长]  (遵循包前不包后原则,开始计数从0开始)
#步长：步长的绝对值大小决定切取的间隔，正负号决定切取方向。正数表示从左往右切取，负数表示从右往左切取

# ss='abcdefgh'
# print(ss[1:3])
# print(ss[1: ])
# print(ss[ :3])
# print(ss[-1:-5:-1])
# print(ss[1:7:2])

#6.查找元素
#find
#作用：检查字符串中是否包含某个字串，如果包含则返回子字符串开始位置的下标，否则返回-1
#find(子字符串，开始查找位置下标，结束查找位置下标) （开始和结束查找位置下标可以省略，表示在整个字符串中查找）

# st="hello,world"
# print(st.find('wor'))
# print(st.find('e',4))    #超出范围
# print(st.find('o',3,4))  #包前不包后原则

#index(用法同find)
#作用：检查字符串中是否包含某个字串，如果包含则返回子字符串开始位置的下标，否则报错

# st="hello,world"
# print(st.index('o',3,4))

#count返回某个子字符串在整个字符串中出现的次数，没有就返回0
#count(子字符串，开始查找位置下标，结束查找位置下标)

#7.startswith()判断是否以某个字符串开头，是返回True，否则返回False
#endswith()判断是否以某个字符串结尾，是返回True，否则返回False
#startswith(子字符串，开始查找位置下标，结束查找位置下标)

# st="hello,world"
# print(st.startswith('o',4,6))

#8.isupper()检测字符串中所有字符是否为大写，是则返回True
#  islower()检测字符串中所有字符是否为小写，是则返回True

# print('Yes'.isupper())

#replace()替换字符字符串
#replace(被替换内容，替换内容，替换次数) 替换次数可以省略，默认全部替换

# st="gogogo出发"
# print(st.replace('go','come'))

#9.split()根据指定分隔符分割字符串，以列表的形式返回
#如果字符串中不存在指定分隔符，则作为一个整体不分割

# st="go,go,go,出发"
# print(st.split(','))
# print(st.split('o'))
# print(st.split('a'))
# print(st.split(',',1))  #可以指定分割次数

#10.capitalize()将第一个字符大写

# st="hello"
# print(st.capitalize())

#11.lower()大写字母转换为小写字母
#   upper()小写字母转换为大写字母

#强制类型转换
#1.浮点数强转为整数int():截断小数点部分，只保留整数部分
#2.字符型强转为整型int():字符串只能由纯数字组成，'+''-'只能在数字前面表示数字的正负，不能写在后面

# st1='+12'
# print(int(st1))

#input默认输出的是字符串类型
# age=int(input("输入年龄："))
# if age>=18:
#     print("已成年")

#3.整型强转为浮点型float()添加一位小数
#4.字符型强转为浮点型float():字符串只能由纯数字组成，'+''-'只能在数字前面表示数字的正负，不能写在后面
# print(float(3))

#5.任何类型都可以转化成字符串类型(float转换成str会取出末位为0的小数部分)

# print(str(-1.30))
# print(str(-1.3000))
# print(str(-1.03200))
# print(str([1,2,3]))

#6.eval()可以实现list、dict、tuple和str之间的转换
#eval()非常强大，但不够安全，容易被恶意修改数据

#str->list
# s1="[[1,2],[3,4],[5,6]]"
# print(s1,type(s1))
# li=eval(s1)
# print(li,type(li))

#str->dict
# s2="{'name':'ZhangYuan','age':40}"  #注意：在str->dict情况下，字符串外层用双引号，内层字典的键与值用单引号
# print(s2,type(s2))
# dic=eval(s2)
# print(dic,type(dic))

#eval()用来执行一个字符串表达式，并返回表达式的值

# print('10+10')
# print(eval('10+10'))

#7.list()将可迭代对象转换成列表
#支持转换为list的类型：str、tuple、dict、set

# print(list('abcdefg'))
# print(list((1,2,3,4,5)))
# print(list({'name':'ZhangYuan','age':40}))  #字典转换成列表，只取键名作为列表的值
# print(list({1,2,3,4,2,5}))                  #集合转换成列表，先去重

# a=1
# b=a
# print(a,b)
# a=1+1
# print(a,b)
# print(id(a))
# print(id(b))
#
# l1=[1,2,3,4]
# l2=l1
# print('前',l1)
# print('前',l2)
# l1.append(5)
# print('后',l1)
# print('后',l2)
# print(id(l1))
# print(id(l2))
#赋值：完全共享资源，一个值的改变会被另一个值共享

#浅拷贝(数据半共享)
#会创建新的对象，拷贝第一层数据，嵌套层会指向原来的内存地址
# import copy
# l1=[1,2,3,[4,5]]  #定义一个嵌套列表
# l2=copy.copy(l1)  #浅拷贝
# print('l1',l1)
# print('l2',l2)
# l1.append(6)
# print('添加后l1',l1)
# print('添加后l2',l2)
# l1[3].remove(5)
# print('删除后l1',l1)
# print('删除后l2',l2)
# print('l1的内存地址:',id(l1))
# print('l2的内存地址:',id(l2))
# print('l1[3]的内存地址:',id(l1[3]))
# print('l2[3]的内存地址:',id(l2[3]))
#外层的内存地址不同，但内层的内存地址相同

#优点：拷贝速度快，占用空间少，拷贝效率高

#浅拷贝(数据完全不共享)
#外层的对象和内部的元素都拷贝了
# import copy
# l1=[1,2,3,[4,5]]  #定义一个嵌套列表
# l2=copy.deepcopy(l1)  #深拷贝
# print('l1',l1)
# print('l2',l2)
# l1.append(6)
# print('添加后l1',l1)
# print('添加后l2',l2)
# l1[3].remove(5)
# print('删除后l1',l1)
# print('删除后l2',l2)
# print('l1的内存地址:',id(l1))
# print('l2的内存地址:',id(l2))
# print('l1[3]的内存地址:',id(l1[3]))
# print('l2[3]的内存地址:',id(l2[3]))
#深拷贝数据变化只影响自己本身，跟原来的对象没有关联

#可变对象：变量对应的值可以修改，但内存地址不会发生改变
#常见可变对象：列表、字典、集合
# li=[1,2,3,4]
# print(li,id(li))
# li.append(5)
# print(li,id(li))

#不可变对象：变量对应的值不可以修改，如果修改就会生成一个新的对象从而分配新的内存空间
#常见不可变对象：数值类型int、float、bool、complex，字符串，元组
# n=10
# print(n,id(n))
# n=20
# print(n,id(n))

#深浅拷贝只针对可变对象


#函数
#定义函数
# def 函数名():
#     函数体
#调用函数
# 函数名()

#return返回多个值，以元组的形式返回给调用者
#return后面没有给定返回值，则返回的是None

#函数参数
#1.必备参数(位置参数)：传递和定义参数的顺序及个数必须一致

#2.默认参数：为参数提供默认值，调用函数时可以不传该默认参数的值
#注意：所有的位置参数必须出现在默认参数前，包括函数的定义与调用
# def Add(a=1,b=2):
#     return a+b
# print(Add(4))  #函数有两个形参，但函数调用的时候只传入一个值，默认该值是第一个形参的值

# def Add(a,b=2):
#     return a+b
# print(Add(4))

# def Add(a=1,b):  #报错，所有的位置参数必须出现在默认参数前
#     return a+b
# print(Add(4))
#设置默认值，没有传值会根据默认值来执行代码，传值则根据传入的值来执行代码

#3.可变参数：传入的值的数量可以改变，可以传多个，也可以不传
# def fun(*args):   #可以把args改为其他参数名，但args更符合代码的规范性
#     return args
#     print(type(args))  #以元组的形式接收
# print(fun('海绵宝宝','派大星','痞老板'))

#4.关键字参数
# def fun(**kwargs):
#     print(kwargs)    ##以字典的形式接收
#     print(type(kwargs))
# fun()     #返回空字典
# fun(name='ZhangYuan',age=40)  #传值时，需要采用键=值的形式，键不加引号
#作用：扩展函数的功能

#嵌套函数定义
# def test1():
#     print('海绵宝宝')
#     def test2():
#         print('派大星')
#     test2()
# test1()

#global关键字:将变量声明为全局变量
# def test():
#     global a   #声明全局变量
#     a=10
#     print('a=',a)
# test()
# print('a=',a)

#nonlocal关键字：用来声明外层的局部变量，只能在嵌套函数中使用，在外部函数先进行声明，内部函数进行nonlocal声明
# a=10
# def test1():
#     print('test1 a=',a)
#     def test2():
#         a=20
#         print('test2前 a=',a)
#         def test3():
#             nonlocal a
#             a=30
#             print('test3 a=',a)
#         test3()
#         print('test2后 a=',a)
#     test2()
# test1()
#nonlocal只能对上一级进行修改

#内置函数
#查看所有内置函数
# import builtins
# print(dir(builtins))
#大写字母开头一般是内置常量名，小写字母开头一般是内置函数名
#常见内置函数
#  1.abs()返回绝对值

#  2.sum()求和  #参数要是可迭代对象，列表、元组、集合可以，字符串、字典不可以
# print(sum([1,2,3]))
# print(sum({4,5,6}))

#  3.min()求最小值
#    max()求最大值
# print(max(1,2,3))
# #比较绝对值大小
# print(max(-6,4,key=abs))   #注意这里只能写key

#  4.zip()将可迭代对象作为参数，将对象中对应的元素打包成一个个元组
#第一种方式：通过for循环
# li1=[1,2,3]
# li2=['a','b','c']
# print(zip(li1,li2))
# for i in zip(li1,li2):
#     print(i)
#     print(type(i))
#如果元素个数不一致，则按照长度最短的返回

#第二种方式：转换成列表打印
# li1=[1,2,3]
# li2=['a','b','c']
# print(list(zip(li1,li2)))

#  5.map()对可迭代对象中的每一个元素进行映射，分别执行
#map(func,iter1)  func是定义的函数，iter1是要执行的可迭代对象

# li1=[1,2,3]
# func=lambda x:x+10
# mp=map(func,li1)
# for i in mp:
#     print(i)
# print(list(mp))    #打印的是空列表
#map对象在Python中是一个迭代器
#迭代器是一次性的：当用for循环遍历mp时，已经将迭代器中的所有元素消耗完了。当迭代器被遍历完后，它就处于"耗尽"状态，不再包含任何元素。

#  6.reduce()先把对象中的两个元素取出，计算出一个值后保存着，再把这个计算值跟第三个元素进行计算
#需要导包
# from functools import reduce
# #reduce(函数,可迭代对象)   #函数里面只能有两个参数
# li1=[1,2,3,4]
# add=lambda x,y:x+y
# result=reduce(add,li1)
# print(result)

#拆包：对于函数中的多个返回数据，去掉元组、列表或者字典，直接获取里面的数据的过程
#第一种方法：一般在获取元组值时使用
# tua=(1,2,3,4)
# a,b,c,d=tua
# print('a=',a,'b=',b,'c=',c,'d=',d)
#要求元组内元素个数与接收的变量个数相同

#第二种方法：一般在函数调用时使用
# tua=(1,2,3,4)
# a,*b=tua
# print(a,b)
# c,d,e=b
# print(c,d,e)

# def func(a,b,*args):
#     print(a,b)
#     print(args)
# func(1,2,3,4,5)

#抛出异常
#1.创建一个exception('xxx')对象，xxx--是异常提示信息
#2.raise抛出这个对象
# raise Exception('报错啦！报错啦！')

#捕获异常
#捕获异常后代码还能继续执行，程序不会终止
# def func(a,b):
#     if b==0:
#         raise Exception('除数不能为0')
# try:
#     print(func(5,0))
# except Exception as e:
#     print(e)
# print("a,b无效，重新选择")

#模块
#一个py文件就是一个模块，及导入一个模块本质上就是执行一个py文件
#模块的分类：
#  1.内置模块
#如random、time、os、logging,直接导入即可使用
#  2.第三方模块(第三方库)
#下载：cmd窗口输入 pip install 模块名
#  3.自定义模块
#自己在项目中定义的模块，命名要遵循标识符规定以及变量的命名规范，不能与内置模块起冲突

#导入模块
#  1.import 模块名
#调用功能：模块名.功能名
# import pytest
# #调用模块中的变量
# print(pytest.name)
# #调用模块中的函数
# pytest.func()

#  2.from...import...
#从模块中导入指定部分
#from 模块名 import 功能1，功能2...
#调用功能：功能名    (不需要加模块名)
# from pytest import func2   #导入函数，只需要写函数名，不需要加小括号
# func2()

#  3.from...import *
# from pytest import *
# func2()

#注意：不建议过多使用form...声明(方式2、3)，有时命名冲突会造成一些错误

#as起别名
#1.  给模块起别名
# import 模块名 as 别名
# import pytest as pt
# pt.func()

#2.  给功能起别名
# from 模块名 import 功能 as 别名
# from pytest import func as a,func2 as b
# a()
# b()

#内置全局变量__name__
#作用：用来控制py文件在不同应用场景执行不同的逻辑
# 1.文件在当前程序执行(自己执行自己)：__name__ == "__main__"
#当被当作模块导入时，__name__ == "__main__"后面的代码不会执行

# 2.文件被当做模块被其他文件导入：__name__ == 模块名

#包：就是项目结构中的文件夹/目录
#与普通文件夹的区别：包是含有__init__.py的文件夹
#作用：将有联系的模块放在同一个文件夹下，有效避免模块名冲突问题，让结构更清晰

#import导入包时，首先执行__init__.py文件的代码
# import pack01

#__all__:本质上一个列表，列表里面的元素就代表要导入的模块
#作用：可以控制要引入的东西
# from pack01 import *
# register.reg()
# login.log()

#包的本质依然是包，包又可以包含包

# def func(n):
#    if n==1:
#        return 1
#    else:
#        return n+func(n-1)
# print(func(100))

#斐波那契数列
# def func1(n):
#     if(n<=2):
#         return 1
#     else:
#         return func1(n-1)+func1(n-2)
# print(func1(5))

#闭包
#条件:1.函数嵌套
#    2.内层函数使用外层函数的局部变量
#    3.外层函数的返回值是内层函数的函数名