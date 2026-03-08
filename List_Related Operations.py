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