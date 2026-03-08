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


#列表
#列表名=[元素1，元素2，元素3···]
#元素之间数据类型可以不相同
#列表可以进行切片操作
#列表是可迭代对象，可以for循环遍历取值

# li=[1,2,3,'a','b','c']
# print(li[2:5])
# for i in li:
#     print(i)

#列表相关操作
#1.添加元素 append() extend() insert()
#append()、extend()、insert()都是原地修改列表,它们返回 None,而不是返回修改后的列表

# Li=['one','two','three']
# Li.append('four')     #append是在列表所有元素后面整体添加
# print(Li)
# Li.extend('four')     #extend分散添加，将另一个类型中得的元素注意添加，被添加元素必须是可迭代对象
# print(Li)
# Li.insert(0,'four')   #insert在指定位置插入元素(指定位置有元素，指定位置后面的原元素整体后移)
# print(Li)

#2.修改元素
#直接通过下标进行修改

# li=[1,2,3]
# li[2]='a'
# print(li)

#3.查找元素
#in:判断指定元素是否存在列表中，如果存在就返回True，不存在就返回False
#not in:判断指定元素是否存在列表中，如果不存在就返回True，存在就返回False
#index: 返回指定元素所在位置下标，如果指定元素不存在则报错
#count:统计指定元素在当前列表出现的次数

# name_list=['Zhangyuan','Whangyuexing','Luhu']
# while True:
#     name=input("请输入名字：")
#     if name in name_list:
#         print(f"该名字{name}已存在，请重新输入：")
#     else:
#         print("添加成功！")
#         name_list.append(name)
#         print(name_list)
#         break

#4.删除元素
#del

# li=['a','b','c','d','b']
# # del li    #删除列表,打印列表会报错
# del li[2]   #根据下标删除
# print(li)

#pop:删除指定下标的元素，python3版本默认删除最后一个元素

# li=['a','b','c','d','b']
# li.pop()
# li.pop(1)
# print(li)

#remove:根据元素的值进行删除

# li=['a','b','c','d','b']
# li.remove('d')
# # li.remove('t')  #指定元素不存在，则会报错
# li.remove('b')    #指定元素在列表中重复出现，默认删除最开始出现的指定元素
# print(li)

#5.排序
#sort:将列表按从大到小的顺序排列
#reverse:逆序，将列表顺序倒置

# li=['abc','ccb','bas','cca']
# li.reverse()
# print(li)
# li.sort()
# print(li)

#6.列表推导式
#格式一：[表达式 for 变量 in 列表]
#注意：in后面除了可以放列表，还可以放range()、可迭代对象

# li=[]
# for i in range(1,6):
#     li.append(i)
# print(li)

# li=[]
# [li.append(i) for i in range(1,6)]
# print(li)

#格式二：[表达式 for 变量 in 列表 if 条件]

# li=[]
# for i in range(1,11):
#     if i%2==1:
#         li.append(i)
# print(li)

# li=[]
# [li.append(i) for i in range(1,11) if i%2==1]
# print(li)

#列表嵌套

# li=[1,2,3,[4,5,6]]
# print(li[3])
# print(li[3][1])