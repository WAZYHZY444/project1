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
import copy
l1=[1,2,3,[4,5]]  #定义一个嵌套列表
l2=copy.deepcopy(l1)  #深拷贝
print('l1',l1)
print('l2',l2)
l1.append(6)
print('添加后l1',l1)
print('添加后l2',l2)
l1[3].remove(5)
print('删除后l1',l1)
print('删除后l2',l2)
print('l1的内存地址:',id(l1))
print('l2的内存地址:',id(l2))
print('l1[3]的内存地址:',id(l1[3]))
print('l2[3]的内存地址:',id(l2[3]))
#深拷贝数据变化只影响自己本身，跟原来的对象没有关联