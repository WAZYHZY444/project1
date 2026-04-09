#面向对象和面向过程的区别
#面向过程：需要实现一个功能时，看重的是过程，分析出一个个步骤，用一个个函数实现，再依次去调用函数
#面向对象：需要实现一个功能时，看重的是谁去做这件事情

#类：一系列具有相同属性和行为的事物的统称，是不真实存在的事物
#对象：类的具体实现，是类创建出来的真实存在的事物，面向对象的核心
#再开发中，先有类，再有对象

#类的三要素：1.类名
#          2.属性：对象的特征描述，用来说明是什么样子的
#          3.方法：对象具有的功能(行为)，用来说明能够做什么

#基本格式
# class 类名:   #类名必须符合标识符规定，同时遵循大驼峰命名法，见名知义
#     代码块

# class Washer:
#     height=800
#查看类属性:类名.属性名
# print(Washer.height)
#新增类属性：类名.属性名=值
# Washer.width=450
# print(Washer.width)

#创建对象：创建对象的过程也叫做实例化对象
#基本格式：对象名=类名()
# wa=Washer()
# print(wa)  #显示的是对象在内存中的地址
# wa2=Washer()
# print(wa2) #内存地址不一样，说明是不同的对象，可以实例化多个对象

#实例方法：有对象调用，至少有一个self参数，执行实例方法的时候，自动将调用该方法的对象赋值给self
#self代表对象本身，当对象调用实例方法时，python会自动将对象本身的引用作为参数，传递到实例方法的第一个参数self里面
# class Washer:
#     height=800
#     def wash(self):
#         print('我会洗衣服')
# #实例化对象
# wa=Washer()
# #对象调用类中的方法
# wa.wash()

#实例属性
#格式：self.属性名
# class Person:
#     name='ZhangYuan'      #类属性
#     def introduce(self):  #实例化方法
#         print('我是实例化方法')
#         print(f"{Person.name}的年龄是{self.age}") #self.age是属性实例
# pe=Person()  #实例化对象
# pe.age=40
# pe.introduce()

#实例属性和类属性的区别
#类属性属于类，是公共的，大家都可以访问到，实例属性属于对象，是私有的，只能由对象访问，不能由类访问
# pe2=Person()
# pe2.sex='女'
# print(pe2.sex)  #根据对象名访问实例属性
# #print(Person.sex) #根据类名访问实例属性，报错，实例属性只能由对象访问，不能由类访问
# print(pe2.name)
# print(Person.name)

# pe3=Person()
# print(pe3.sex) #pe2.sex='女'是给pe2对象新增的实例属性，其他对象依然是没有这个属性的

#构造函数 __init__()
#作用：通常用来实现属性初始化或者赋值操作
#注意；在实例化对象的时候，会被自动调用
# class Test:
#     def __init__(self):
#         print("这是__init__()函数")
# te=Test()

# class Test:
#     def __init__(self,a,b):
#         self.a=a  #实例属性
#         self.b=b
#     def add(self):
#         return self.a+self.b
#     def div(self):
#         return self.a/self.b
# #实例化对象
# pe=Test(10,5)  #在实例化的时候传值
# print(pe.add())
# print(pe.div())

#析构函数 __del__():主要表示该程序块或函数已经全部执行结束
#删除对象的时候，解释器会默认调用__del__()
# class Person:
#     def __init__(self):
#         print('Hello!')
#     def __del__(self):
#         print('Bye!')
# p=Person()   #实例化对象
# del p  #删除对象
# #del p语句执行时，内存会立即被回收，会调用对象本身的__del__()
# print("下次再见！")
#正常运行时，不会调用__del__()，对象执行结束后，系统会自动调用__del__()

######面向对象的三大特性：封装、继承、多态
#封装：指的是隐藏对象中一些不希望被外部所访问到的属性或方法
# 1.
#私有属性/私有方法：双下划线开头，如果定义在类中，无法在外部直接访问，子类不会继承，要访问只能通过间接的方式，另一个py文件中通过from xxx import *导入的时候，也无法导入
#                一般是python中的魔术方法或属性，都是有特殊含义或者功能的，自己不要轻易定义
# class Person:
#     name='ZhangYuan'
#     __age=40   #隐藏属性
#     def func(self):
#         print(f"{Person.name}的年龄是{Person.__age}")  #在实例方法中访问类属性和私有属性
# pe=Person()
# print(pe.name)
#print(pe.age)  #不能用对象名来访问私有属性

#1.私有属性实际上是将名字修改为：_类名__属性名 _Person__age
# print(pe._Person__age)
# pe.func()
#2.在类的内部访问

# 2.
#保护属性(相当于C++的protected)：单下划线开头，如果定义在类中，外部可以访问，子类不会继承，另一个py文件中通过from xxx import *导入的时候，无法导入
#               一般是为了避免与python关键字冲突而采用的命名方法
# class Person:
#     name='Suxing'
#     _age=41
#     __sex='男'
# pe=Person()
# print(pe._age)   #使用对象名._属性名调用
# print(pe.__sex)  #不可以这么调用

#继承
#class 类名(父类名):
#   代码块
#1.单继承
# class Person:
#     def Money(self):
#         print("钱")
#     def House(self):
#         print("房")
# class Girl(Person):
#     pass
# girl=Girl()
# girl.Money()
# girl.House()

#2.继承的传递(多重继承)
# class Person:
#     def Money(self):
#         print("钱")
#     def House(self):
#         print("房")
# class Son(Person):
#     pass
# class Grandson(Son):
#     pass
# son=Son()
# son.Money()
# son.House()
# grandson=Grandson()
# grandson.Money()
# grandson.House()

#3.多继承
"""
class Father:
    A=10
class Mother:
    A=30
    B=20
class Son(Father,Mother):
    A=40
son=Son()
print(son.A)
print(son.B)
"""
# import threading
#有多个父类的属性和方法，如果多个父类具有同名的属性或方法，调用采用就近原则（括号内哪一个在前就调用哪个）,如果子类出现同名，则调用子类的
#python中内置的属性__mro__可以查看方法搜索顺序
# print(Son.__mro__)

#重写：在子类中定义与父类相同名称的方法
#1.覆盖父类方法
# class Person:
#     def Money(self):
#         print("爸爸的钱")
# class Son(Person):
#     def Money(self):
#         print("儿子的钱")
# son=Son()
# son.Money()
#2.对父类方法进行扩展：继承父类方法，子类也可以增加自己的功能
# 父类名.方法名(self)
# super().方法名()   (super在python中是一个特殊的类，super()是使用super类创建出来的对象)
# super(子类名.self).方法名()

# class Person:
#     def Money(self):
#         print("爸爸的钱")
#     def House(self):
#         print("爸爸的房")
# class Son(Person):
#     def Money(self):
#         Person.Money(self)
#         print("儿子的钱")
#     def House(self):
#         super().House()
# son=Son()
# son.Money()
# son.House()

# class A(object):
#     pass
#object是一个对象，是python为所有对象提供的基类(顶级父类)，提供了一些内置的属性和方法，可以使用dir()查看
#python3中，如果一个类没有继承任何类，则默认继承object类

#多态：指同一种行为具有不同的表现形式
#继承+重写
#多态性：一种调用方式，有不同的执行结果
# class Father:
#     def name(self):
#         print("我是爸爸")
# class Son(Father):
#     def name(self):
#         print("我是儿子")
# class Daughter(Father):
#     def name(self):
#         print("我是女儿")
# #多态性：定义一个统一的接口，一个接口有多种实现
# def test(obj):
#     obj.name()
#
# father=Father()
# test(father)
# son=Son()
# test(son)


#类中定义方法的方式
# 1.实例方法
#第一个参数为self，指向实例本身
# 2.静态方法
#使用@staticmethod来进行修饰，静态方法没有self、cls参数的限制
#静态方法与类无关，可以被转换成函数使用
# class Person:
#     @staticmethod     #静态方法
#     def study(name):  #没有self参数,也可以不传参
#         print(f"{name}在学习")
# #静态方法既可以使用对象访问，也可以使用类访问
# Person.study("ZhangSan")
# pe=Person()
# pe.study("LiSi")
#静态方法本质上就是一个普通函数，只是借用了类的命名空间，调用时需带类名前缀
#把相关函数放在一起，提高可读性，不同类的静态方法可以重名，避免命名冲突

# 3.类方法
#使用装饰器@classmethod来标识为类方法，对于类方法，第一个参数必须是类对象，一般以cls作为第一个参数
# class Person:
#     name="ZhangSan"
#     @classmethod
#     def sleep(cls):
#         print("cls:",cls)   #cls代表类对象本身，类本质上就是一个对象
#         print("在睡觉")
#         print(cls.name)
# print(Person)
# Person.sleep()
#实例方法和类方法本质上都是自动传参的方法，只是self指向具体的那个对象，cls指向这个对象的类

# __new__():object基类提供的内置的静态方法
# 作用：1.在内存中为对象分配空间  2.返回对象的引用
# class Test:
#     def __init__(self):
#         print("__init__()")
#     def __new__(cls):    #重写了new函数，把原本new函数作用覆盖了
#         print("__new__()")
#         return super().__new__(cls)  #扩展
# te=Test()
# print("te:",te)
#重写__new__()一定要return super().__new__(cls)，否则python解释器得不到分配空间的对象引用，就不会调用__init__()
#1.__new__()创建对象，__init__()初始化对象
#2.__new__()是返回对象的引用，__init__()定义实例属性
#3.__new__()是类级别的方法，__init__()是实例级别的方法

#单例模式
#可以理解成一个特殊的类，这个类只存在一个对象，对象的内存地址都是一样的
#优点：可以节省内存空间，减少了不必要的资源浪费
#弊端：多线程访问时容易引发线程安全问题
#方式
#1.通过@classmethod
#2.通过装饰器
#3.通过重写__new__()实现
#4.通过导入模块实现

# 通过重写__new__()实现
# class Singleton:
#     #记录第一个被创建的对象的引用
#     obj=None
#     def __new__(cls):
#         print('__new__()')
#         if cls.obj==None:   #相当于只对obj进行一次赋值，后面返回的obj都是同一个引用
#             cls.obj=super().__new__(cls)
#         return cls.obj
#     def __init__(self):
#         print('__init__()')
# s1=Singleton()
# print("s1:",s1)
# s2=Singleton()
# print("s2:",s2)

# 通过导入模块实现
#模块就是天然的单例模式
# from pytest02 import te as te01
# from pytest02 import te as te02
# print(te01,id(te01))
# print(te02,id(te02))
#应用场景
#1.回收站对象  2.音乐播放器  3.开发游戏软件  4.数据库配置

#__doc__:特殊属性，可以直接访问，用于获取文档字符串
# class Person:
#     """哈哈哈"""
#     pass
# print(Person.__doc__)
#
# def person():
#     """嘻嘻嘻"""
#     pass
# print(person.__doc__)

#__module__   表示当前操作对象现在的模块
#__class__    表示当前操作对象所在的类
# import pytest02
# b=pytest02.Test()
# print(b)
# print(b.__module__)  #输出所在模块
# print(b.__class__)   #输出所在类

# class Person:
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
# p1=Person("ZhangYuan",40)
# print(p1)
#VS
# class People:
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
#     def __str__(self):
#         return f"People(name={self.name},age={self.age})"
# p2=People("ZhangYuna",40)
# print(p2)
#__str__():（魔法方法）必须要有返回值，而且一定是字符串类型

#__call__():（魔法方法）使一个对象成为可调用对象
#可调用对象：callable()判断一个对象是否是可调用对象，是返回True，不是返回False
# class Greeting:
#     def __call__(self,name):
#         return f"Hello,{name}!"
# g=Greeting()
# print(g("ZhangYuan"))


#文件操作
#1.打开文件
#2.读写文件
#3.关闭文件
#open():创建一个file对象，默认是以只读模式打开
#read(n):n表示从文件中读取数据的长度，没有n值默认一次性读取文件按所有内容
#write():将指定内容写入文件
#close():关闭文件
#属性
#文件名.name:返回要打开的文件名，可以包含文件的具体路径
#文件名.mode:返回文件的访问模式
#文件名.closed:检测文件是否关闭，关闭就返回True

# f=open(r'D:\朱艳\Documents\test.txt')  #需要在路径后面加上文件名
# #路径前面的r是原生字符串，默认取消转义
# print(f.name)  #文件所在的具体路径（绝对路径）
# print(f.mode)
# print(f.read())
# f.close()
# #使用open打开文件就必须要调用close
# print(f.closed)

#readline():一次读取一行内容，方法执行完，会把文件指针移到下一行，准备在次读取
# f=open('ctype.h.txt',encoding='utf-8')
# # print(f.readline())
# # print(f.readline())
# while True:
#     text=f.readline()
#     if not text:
#         break
#     print(text)
# f.close()

#readlines():按照行的方式把文件一次性读取，返回的是一个列表，每一行的数据就是列表的一个元素
# f=open(r'D:\朱艳\Documents\test.txt',encoding='utf-8')
# text=f.readlines()
# print(text)
# for i in text:
#     print(i)
# f.close()

#访问模式
#1.'r'只读模式（默认模式），文件必须存在
#2.'w'只写模式，文件存在则先清空文件内容，再写入添加内容，不存在就创建新文件
# f=open(r'D:\朱艳\Documents\test.txt','w',encoding='utf-8')
# f.write('Bird can fly!')
# f.close()

# +:表示可以同时读写某个文件
#使用+会影响文件的读写效率，开发过程中更多时候会以只读、只写的方式来操作文件
# r+:可读写文件，文件不存在报错
# w+:先写再读，文件存在则先清空文件内容，再写入添加内容，不存在就创建新文件

#3.'a':追加模式，文件存在则追加内容，不存在就创建新文件
# f=open(r'D:\朱艳\Documents\test.txt','a',encoding='utf-8')
# f.write('\ngo go go!')
# f.close()

#文件定位操作
#tell():显示文件内当前位置，即文件指针当前位置
#seek(offset,whence):移动文件读取指针到指定位置
#                    offset:偏移量，表示要移动的字节数
#                    whence:起始位置，表示移动字节的参考位置，默认是0。0表示代表文件开头作为参考位置，1代表当前位置作为参考位置，2代表文件结尾作为参考位置
#seek(0,0)就会把文件指针移到文件开头

# f=open(r'D:\朱艳\Documents\test.txt','w+',encoding='utf-8')
# f.write('Bird can fly!')
# print("当前文件指针所在位置：",f.tell())
# f.seek(0,0)
# print("移动后文件指针所在位置：",f.tell())
# print(f.read())
# f.close()

#with open 代码执行完，系统会自动调用f.close()
# with open(r'D:\朱艳\Documents\test.txt','w+',encoding='utf-8') as f:
#     f.write("哈哈哈")
# print(f.closed)

#Windows系统字符编码默认为GBK，Linux系统默认UTF-8

#读取图片
# with open(r'D:\朱艳\Pictures\LeNet.png','rb') as f:
#     img=f.read()
#     print(img)
# #将读取到内容写入到当前文件中
# with open(r'D:\PyCharm Projects\BirdZY\LeNet.png','wb') as f:
#     f.write(img)

#目录常用操作
#需要导包
# import os
#  1.文件重命名   os.rename(旧名称,新名称)
#  2.删除文件     os.remove()
#  3.创建文件夹   os.mkdir()
#  4.删除文件夹   os.rmdir()
#  5.获取当前目录 os.getcwd()
# print(os.getcwd())
#  6.获取目录列表 os.listdir()
# print(os.listdir())    #获取当前目录列表
# print(os.listdir('../')) #获取上一级目录的列表

#可迭代对象Iterable
#数据类型:str、list、tuple、dict、set等
#可迭代对象满足的条件：1.对象实现了__iter__()方法
#                  2.__iter__()方法返回可迭代对象的迭代器
#for循环工作原理
#  1.先通过__iter__()获取可迭代对象的迭代器
#  2.对获取的迭代器不断调用__next__()方法获取下一个值并将其赋值给临时变量i

#isinstance():判断一个对象是否是可迭代对象或者一个已知的数据类型
#isinstance(o,t)  o:对象 t:类型，可以是直接或者间接类名、基本类型或者元组
# from collections.abc import Iterable  #需要导包
# print(isinstance(123,Iterable))
# print(isinstance('123',str))
# print(isinstance('123',(int,str)))

#迭代器Iterator：可以记住遍历位置的对象
#iter():获取可迭代对象的迭代器
#next():逐一取元素，取完元素会引发一个异常

# li=[1,2,3]
# #创建迭代器对象
# l=iter(li)   # l=li.__iter__()
# print(l)
# #获取数据
# print(next(l)) # print(l.__iter__())
# print(next(l))
# print(next(l))
# print(next(l))   #元素取完后，在使用next()会引发StopIteration异常

#iter()在调用对象的__iter__(),并把返回值结果作为自己的返回值
#next()在调用对象的__next__()

#凡是可以作用于for循环的都是属于可迭代对象
#凡是可以作用于next()的都是属于迭代器
# from collections.abc import Iterable,Iterator
# name='ZhangSan'
# print(isinstance(name,Iterable))  #True
# print(isinstance(name,Iterator))  #False
# #可迭代对象不一定是迭代器对象
# name2=iter(name)
# print(isinstance(name2,Iterable))  #True
# print(isinstance(name2,Iterator))  #True
#迭代器对象一定是可迭代对象
#总结：可迭代对象可以通过iter()转换成迭代器对象
#如果一个对象拥有__iter__()方法，是可迭代对象，如果一个对象拥有__iter()和__next__()，是迭代器对象

#自定义迭代器类
# class MyIterator:
#     def __init__(self):
#         self.num=0
#     def __iter__(self):
#         return self  #返回的是当前迭代器类的实例的对象
#     def __next__(self):
#         if self.num==10:
#             raise StopIteration("终止迭代")
#         self.num+=1
#         return self.num
# m=MyIterator()
# # print(next(m))
# for i in m:
#     print(i)

#生成器：
#列表推导式
# li=[i*5 for i in range(3)]
# print(li)

#生成器表达式
# gen=(i*5 for i in range(3))
# print(gen)
# print(next(gen))
# print(next(gen))
# print(next(gen))
# # print(next(gen))
#生成器函数
# 使用了yield的函数
#1.类似return，yield像return一样返回值，但函数不会结束，而是暂停等待下次调用时继续
#2.yield语句一次返回一个结果，在每个结果中间挂起函数，执行next()，再重新从挂起点继续往下执行
# def gen():
#     print('嘻嘻')
#     yield '嘿嘿'
#     yield '哈哈'
# g=gen()
# print(g)
# print(next(g))
# print(next(g))
#生成器计算了一个值就返回，在计算下一个值，始终只占一个值的内存

#可迭代对象>迭代器>生成器

#多线程
#线程和进程
#进程：是操作系统进行资源分配的基本单位，每打开一个程序至少就会有一个进程
#线程：是CPU调度的基本单位，每个进程至少有一个线程
#一个进程默认有一个线程，进程里面可以创建多个线程，线程依附在进程里面

#需要导入线程模块
# import threading
#Thread线程类参数
#target：执行任务名
#args:以元组的形式给任务传参
#kwargs:以字典的形式给任务传参

# import threading
# import time #导入时间模块
# def sleep(name1):
#     print(f"{name1}睡觉了")
#     time.sleep(2)
#     print("睡醒了")
# def eat(name2):
#     print(f"{name2}吃饭了")
#     time.sleep(2)
#     print("吃饱了")
#
# #主程序入口
# if __name__ == "__main__":
#     #1.创建主线程
#     t1=threading.Thread(target=sleep,args=('xiaozhu',))
#     # print(t1)
#     t2=threading.Thread(target=eat,args=('xiaozhu',))
#     #3.守护线程，[必须放在start()前面]:主线程执行结束，子线程跟着也结束
#     # t1.setDaemon(True)  #已被弃用
#     # t2.setDaemon(True)
#     t1.daemon=True
#     t2.daemon=True
#     #2.开启子线程
#     t1.start()
#     t2.start()
#     #阻塞主线程join()[必须放在start()后面]:等子线程执行结束后，主线程才继续执行
#     t1.join()
#     t2.join()
#     #获取线程名字
#     print(t1.name)
#     print(t2.name)
#     #更改线程名
#     t1.name="线程1"
#     t2.name="线程2"
#     print(t1.name)
#     print(t2.name)
#     print("吃饱喝足，睡觉!")

#线程之间执行是无序的
#线程执行是根据CPU调度决定的
# import time
# def task():
#     time.sleep(1)
#     print("当前线程是：",threading.current_thread().name)  #显示当前线程对象名
# if __name__ == "__main__":
#     for i in range(3):
#         t=threading.Thread(target=task)
#         t.start()

#线程之间共享资源
# import time
# import threading
# li=[]
# def wdata():
#     for i in range(4):
#         li.append(i)
#         time.sleep(1)
#     print("写入的数据：",li)
# def rdata():
#     print("读取的数据：",li)
# if __name__ == "__main__":
#     wd=threading.Thread(target=wdata)
#     rd=threading.Thread(target=rdata)
#     wd.start()
#     wd.join()
#     # time.sleep(4)
#     rd.start()


#资源竞争
# import threading
# a=0
# b=1000000
# def add1():
#     for i in range(b):
#         global a
#         a+=1
#     print('第一次累加:',a)
# def add2():
#     for i in range(b):
#         global a
#         a+=1
#     print('第二次累加:',a)
# if __name__ == "__main__":
#     a1=threading.Thread(target=add1)
#     a2=threading.Thread(target=add2)
#     a1.start()
#     a1.join()
#     a2.start()

#线程同步
#主线程和创建的子线程之间各自执行完自己的代码直至结束
#1.线程等待 a1.join()
#2.互斥锁：对共享数据进行锁定，保证多个线程访问共享数据不会出现数据错误问题，保证同一时刻只有一个线程去操作
#        上锁：锁名.acquire_lock()，释放锁：锁名.release_lock()  上锁与释放锁必须成对出现，否则易造成死锁现象（会造成应用程序停止响应，不能再处理其他任务）
#互斥锁缺点：会影响代码的执行效率
# import threading
# from threading import Lock   #互斥锁需要导入Lock模块
# # 1.创建全局互斥锁
# lock=Lock()
# a=0
# b=1000000
# def add1():
#     #2.上锁
#     lock.acquire_lock()
#     for i in range(b):
#         global a
#         a+=1
#     print('第一次累加:',a)
#     #3.释放锁
#     lock.release_lock()
#
# def add2():
#     for i in range(b):
#         global a
#         a+=1
#     print('第二次累加:',a)
# if __name__ == "__main__":
#     a1=threading.Thread(target=add1)
#     a2=threading.Thread(target=add2)
#     a1.start()
#     a1.join()
#     a2.start()

#进程：是操作系统进行资源分配和调度的基本单位，是操作系统结构的基础
#一个正在运行的程序或软件就是一个进程
#进程里面可以创建多个线程
#进程的状态
#  1.就绪状态：运行的条件都已满足，正在等待CPU执行
#  2.执行状态：CPU正在执行其功能
#  3.等待(阻塞)状态：等待某些条件满足（如一个程序sleep了）

#进程语法结构
# multiprocessing模块提供了进程要执行的任务
# from multiprocessing import Process
#Process进程类参数
#target：执行任务名
#args:以元组的形式给任务传参
#kwargs:以字典的形式给任务传参
#方法：
#  1.start():开启子进程
#  2.is_alive():判断子进程是否还活着,存活返回True，死亡返回False
#  3.join():主进程等待子进程执行结束
#常见属性：
#  1.name:当前进程的别名，默认Process—N
#  2.pid:当前进程的进程编号
from multiprocessing import Process
import os
def sleep():
    # os.getpid()  #获取当前进程的编号
    os.getppid()   #获取当前父进程的编号(父进程的id就是py文件主进程的id)
    print(f'sleep子进程编号:{os.getpid()},父进程编号:{os.getppid()}')
    print('睡觉了!')
def eat():
    print(f'eat子进程编号:{os.getpid()},父进程编号:{os.getppid()}')
    print('吃饭了!')
if __name__ == "__main__":
    #创建子进程
    p1=Process(target=sleep,name='子进程1') #修改子进程名方式一
    p2=Process(target=eat,name='子进程2')
    #开启子进程
    p1.start()
    p2.start()
    # 修改子进程名方式二
    p1.name='number one'
    p2.name='number two'
    #访问name属性
    print("p1:",p1.name)
    print("p2:",p2.name)
    #查看子进程的进程编号
    print("p1.pid:",p1.pid)
    print("p2.pid:",p2.pid)