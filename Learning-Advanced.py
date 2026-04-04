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


'''类中定义方法的方式'''
'''1.实例方法'''
#第一个参数为self，指向实例本身
'''2.静态方法'''
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

'''3.类方法'''
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
class Singleton:
    #记录第一个被创建的对象的引用
    obj=None
    def __new__(cls):
        print('__new__()')
        if cls.obj==None:   #相当于只对obj进行一次赋值，后面返回的obj都是同一个引用
            cls.obj=super().__new__(cls)
        return cls.obj
    def __init__(self):
        print('__init__()')
s1=Singleton()
print("s1:",s1)
s2=Singleton()
print("s2:",s2)

