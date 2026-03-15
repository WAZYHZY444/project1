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
#查看类属性：类名.属性名
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

class Test:
    def __init__(self,a,b):
        self.a=a  #实例属性
        self.b=b
    def add(self):
        return self.a+self.b
    def div(self):
        return self.a/self.b
#实例化对象
pe=Test(10,5)  #在实例化的时候传值
print(pe.add())
print(pe.div())