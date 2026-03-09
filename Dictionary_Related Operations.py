#字典
#字典名={键1:值1,键2:值2···}
#键值对保存形式，键和值之间用冒号隔开，每个键值对之间用逗号隔开(键名需要加引号)
# dic={'name':'Zhangyuan','age':40}
# print(type(dic))

#字典的键具备唯一性，但值可以重复
# dic1={'name':'Zhangyuan','name':'suxing'}  #不会报错，键名重复前面的值会被后面的值覆盖
# print(dic1)

# dic2={'age1':40,'age2':40}
# print(dic2)

#字典相关操作
#1.  查看元素
#字典名[键名]      #键名不存在则报错

# dic={'name':'Zhangyuan','age':40}
# print(dic['name'])  #键名相当于下标

#字典名.get(键名)  #键名不存在返回None

# dic={'name':'Zhangyuan','age':40}
# print(dic.get("name"))
# print(dic.get('tel','键名不存在'))   #键名不存在，可以设置返回内容

#2.  修改元素
#字典名[键名]=值

# dic={'name':'Zhangyuan','age':40}
# dic['age']=41   #通过键名修改
# print(dic)

#3.  添加元素
#字典名[键名]=值
#注意：键名存在就修改，不存在就添加

# dic={'name':'Zhangyuan','age':40}
# dic['tel']=12345
# print(dic)

#4.  删除元素
#del
#clear()清空整个字典里的内容，但保留了字典，后续可以添加内容
#pop()删除指定的键值对，键名不存在则会报错

# dic={'name':'Zhangyuan','age':40}
# del dic        #删除字典，打印会报错
# del dic['age']   #删除指定的键值对，键名不存在则会报错
# print(dic)

# dic={'name':'Zhangyuan','age':40}
# dic.clear()
# print(dic)

# dic={'name':'Zhangyuan','age':40}
# #dic.pop('age')
# # dic.pop()    #报错，没有指定键名
# dic.popitem()  #3.7版本之前是随机删除一个键值对，3.7版本之后是默认删除最后一个键值对
# print(dic)

#5.  len()求长度,返回有多少对键值对
# dic={'name':'Zhangyuan','age':40}
# print(len(dic))

#6.  keys()返回字典里面包含的所有键名

# dic={'name':'Zhangyuan','age':40}
# print(dic.keys())  #返回的不是列表类型
# for i in dic:      #只取出键名
#     print(i)
# for i in dic.keys():
#     print(i)

#7.  values()返回字典里包含的所有值

# dic={'name':'Zhangyuan','age':40}
# print(dic.values())
# for i in dic.values():
#     print(i)

#8.  items()返回字典里包含的所有键值对，键值对是以元组的形式

# dic={'name':'Zhangyuan','age':40}
# print(dic.items())
# for i in dic.items():
#     print(i,type(i))

#字典的应用场景：使用键值对，存储描述一个物体的相关信息