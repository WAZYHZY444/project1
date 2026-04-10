# 协程：单线程下的开发，又称为微线程
# 注意：线程和进程的操作是由程序触发系统接口，最后的执行者是系统，协程的操作则是程序员
# 应用场景：
#  1.如果一个线程里面IO操作比较多，可以使用协程
#  2.适合高并发处理
# 为了更好使用协程来完成多任务，python中的greenlet模块对其封装，从而使得切换任务变得更加简单
# greenlet模块：由C语言实现的的协程模块，通过设置switch()来实现任意函数之间的切换
# 注意：greenlet属于手动切换，当遇到IO操作，程序会阻塞，而不是进行自动切换

# 通过greenlet实现任务的切换
from greenlet import greenlet
def sleep():
    print("睡觉了")
    g2.switch()
    print("睡醒了")
def eat():
    print("吃饭了")
    print("吃饱了")
if __name__ == "__main__":
    # 创建协程对象  greenlet(任务名)
    g1=greenlet(sleep)
    g2=greenlet(eat)
    g1.switch()   # 切换到g1中运行
    # g2.switch()

