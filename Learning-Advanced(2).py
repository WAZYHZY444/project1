# 协程：单线程下的开发，又称为微线程
# 注意：线程和进程的操作是由程序触发系统接口，最后的执行者是系统，协程的操作则是程序员
# 应用场景：
#  1.如果一个线程里面IO操作比较多，可以使用协程
#  2.适合高并发处理
# 为了更好使用协程来完成多任务，python中的greenlet模块对其封装，从而使得切换任务变得更加简单
# greenlet模块：由C语言实现的的协程模块，通过设置switch()来实现任意函数之间的切换
# 注意：greenlet属于手动切换，当遇到IO操作，程序会阻塞，而不是进行自动切换
import re

# 通过greenlet实现任务的切换
# from greenlet import greenlet
# def sleep():
#     print("睡觉了")
#     g2.switch()
#     print("睡醒了")
# def eat():
#     print("吃饭了")
#     print("吃饱了")
# if __name__ == "__main__":
#     # 创建协程对象  greenlet(任务名)
#     g1=greenlet(sleep)
#     g2=greenlet(eat)
#     g1.switch()   # 切换到g1中运行

# gevent遇到IO操作时，会进行自动切换，属于主动式切换
# 导入模块
# import gevent

# gevent.spawn(函数名):创建协程对象
# gevent.sleep():     耗时操作
# gevent.join():      阻塞，等待某个协程执行结束
# gevent.joinall():   等待所有协程对象都执行结束再退出，参数是一个协程对象列表

# import gevent
# def sleep():
#     print("睡觉了")
#     gevent.sleep(2)
#     print("睡醒了")
# def eat():
#     print("吃饭了")
#     gevent.sleep(3)
#     print("吃饱了")
# if __name__ == "__main__":
#     #创建协程对象
#     g1=gevent.spawn(sleep)
#     g2=gevent.spawn(eat)
#     g1.join()
#     g2.join()

# import gevent
# def sing(name):
#     for i in range(3):
#         gevent.sleep(1)
#         print(f"{name}在唱歌，第{i}次唱歌")
# if __name__ == "__main__":
#     gevent.joinall([
#         gevent.spawn(sing,"ZhangYuan"),
#         gevent.spawn(sing,"SuXing")
#     ])

#monkey补丁
# from gevent import monkey
# monkey.patch_all()  #将time.sleep()代码替换成gevent里面自己实现耗时操作的gevent.sleep()代码
# import gevent
# import time
# def sing(name):
#     for i in range(3):
#         time.sleep(1)
#         print(f"{name}在唱歌，第{i}次唱歌")
# if __name__ == "__main__":
#     gevent.joinall([
#         gevent.spawn(sing,"ZhangYuan"),
#         gevent.spawn(sing,"SuXing")
#     ])

# 总结：
#1.线程是CPU调度的基本单位，进程是资源分配的基本单位
#2.进程、线程和协程对比
#  进程：切换需要的资源最大，效率最低
#  线程：切换需要的资源一般，效率一般
# :协程：切换需要的资源最小，效率高
#3.多线程适合10密集型操作（文件操作、爬虫），多进程适合CPU密集型操作（科学及计算、对视频进行高清解码、计算围周率）
#4.进程、线程、协程都是可以完成多任务的，可以根据自己实际开发的需要选择使用。

#正则表达式：字符串处理工具
#  缺点：语法较复杂，可读性较差
#  优点：通用性强，适用于各种编程语言
#需要导入re模块
# import re
#步骤:
#  1．导入re模块
#  2．使用match方法进行匹配操作
#     re.match()能匹配出以xxx开头的字符串
#     如果起始位置没有匹配成功，返回None
#  3．如果上一步数据匹配成功，使用group()提取数据

# re.match(pattern,string)
#  pattern 匹配的正则表达式
#  string  要匹配的字符串

# import re
# res=re.match("Zhang","ZhangYuan")
# print(res)
# print(res.group())
#注意：match是从开头位置匹配,且匹配的是整体

# 匹配单个字符
#1.  . 匹配任意一个字符，除\n以外
import re
res1=re.match('..','hello')
print(res1.group())

#2.  [] 匹配[]中列举的字符
# res2=re.match('[he]','hello')
# print(res2.group())
# res3=re.match('[he][ll]','ello')
# print(res3.group())
# #匹配0-9(1)
# res4=re.match('[123456789]','56854')
# print(res4.group())
# #匹配0-9(2)
# res5=re.match('[1-9]','56854')
# print(res5.group())
# res6=re.match('[1-45-9]','56854')
# print(res6.group())
# res7=re.match('[1-68-9]','56854')  #不包含7
# print(res7.group())
# res8=re.match('[a-zA-Z]','Hello')
# print(res8.group())

#3.  \d 匹配数字0-9
# res=re.match(r'\d\d','214')
# print(res.group())

#4.  \D 匹配非数字
# res=re.match(r'\D\D','<sa214')
# print(res.group())

#5.  \s 匹配空白，即空格、tab键
# res=re.match(r'\s...','   <sa214')
# print(res.group())

#6.  \S 匹配非空白
#7.  \w 匹配单词字符，即a-z,A-Z,0-9，汉字
#8.  \W 匹配非单词字符

#匹配多个字符
#1.  *   匹配前一个字符出现0次或者无限次，即可有可无
#2.  +   匹配前一个字符出现1次或者无限次，即至少1次
#3.  ?   匹配前一个字符出现1次或者0次
#4. {m}  匹配前一个字符出现m次
#5.{m,n} 匹配前一个字符出现从m次到n次(m<n)
# import re
# res=re.match(r'\w*','ZhangYuan')
# print(res.group())
# res=re.match(r'\d*','ZhangYuan')
# print(res.group())   #输出为空
# # res=re.match(r'\d+','ZhangYuan')
# # print(res.group())   #报错
# res=re.match(r'\w?','ZhangYuan')
# print(res.group())
# res=re.match(r'\w{3}','ZhangYuan')
# print(res.group())
# res=re.match(r'\w{2,4}','Zha///////')
# print(res.group())    #最少匹配2个，最多匹配4个，至少要有2个能匹配

#匹配字符串开头和结尾
#1.  ^ 表示以……开头，表示对……取反
# import re
# res=re.match('^Zh','ZhangYuan')
# print(res.group())
# res=re.match('[^py]','ZhangYuan') #[^py]表示匹配除了p、y
# print(res.group())
#
# #2.  $ 匹配字符串结尾
# res=re.match('.*n$','ZhangYuan')
# print(res.group())
# res=re.match('.{8}n$','ZhangYuan')
# print(res.group())

#匹配分组
#1.  | 匹配左右任意一个表达式
import re
res=re.match("abc|def",'abc')
print(res.group())
res=re.match(r"\d|\s",'1abc')  #优先匹配左边
print(res.group())

#2.  (ab) 将括号中的字符作为一个分组
res=re.match(r'\w*@(163|qq|126).com','123@163.com')  #163|qq|126 三选一
print(res.group())

#3.  \num 匹配分组num匹配到的字符串
res=re.match(r'<(\w*)>\w*</\1>','<html>login</html>')
print(res.group())
res=re.match(r'<(\w*)><(\w*)>\w*</\2></\1>','<html><body>login</body></html>')  #从外到内排序，编号从1开始
print(res.group())

#4.  (?P<name>) 分组起别名
#5.  (?P=name)  引用别名为name分组匹配到的字符串
res=re.match(r'<(?P<L1>\w*)><(?P<L2>\w*)>\w*</(?P=L2)></(?P=L1)>','<html><body>login</body></html>')
print(res.group())

#匹配网址 前缀一般是www. 后缀：.com、.cn、.org
li=['www.baidu.com','www.python.org','http.jd.cn','www.py.en','www.adc.cn']
# res=re.match(r'www(\.)\w*\1(com|cn|org)','www.baidu.com')
# print(res.group())
for i in li:
    res=re.match(r'www(\.)\w*\1(com|cn|org)',i)
    if res:
        print(res.group())
    else:
        print(f'{i}这个网址有错误')