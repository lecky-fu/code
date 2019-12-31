# code
echo "# code" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/lecky-fu/code.git
git push -u origin master

# C++学习记录
----------------
[TOC]
##  一，C++语言可信编码实现
###  1 编程语言能力
#### 1.1 基本数据类型
[基本数据类型定义](https://www.runoob.com/cplusplus/cpp-data-types.html)
#### 1.2 C字符串和String
#### 1.3 char数组
#### 1.4 数组&指针
#### 1.5 数组替代品
#### 1.6 数据类型新特性
#### 1.7 const限定符
#### 1.8 类型推到
#### 1.9 类型别名
Typedef：用来定义类型别名
Typename/class：用来在模板的时候定义泛型类型
```
typedef typename T::LengthType LengthType; 告诉编译器T::LengthType为类型而不是字符串
```
[类型别名说明参考](https://www.runoob.com/note/12729)
#### 1.10 作用域和命名空间
#### 1.11 算术运算符
#### 1.12 运算优先级
#### 1.13 类型提升
#### 1.14 表达式
#### 1.15 关系运算符&逻辑运算符&?:运算符
#### 1.16 条件语句
#### 1.17 循环语句&迭代器
#### 1.18 异常语句
#### 1.19 局部变量和全局变量
#### 1.20 局部变量和全局变量隐藏
#### 1.21 局部静态变量
#### 1.22 函数参数
#### 1.23 函数返回值
#### 1.24 内联函数
#### 1.25 可调用对象
#### 1.26 函数指针
#### 1.27 函数对象(opearator(重载
#### 1.28 function模板
#### 1.29 lambda函数
#### 1.30 函数递归
#### 1.31 对象析构/构造/拷贝
#### 1.32 对象移动
#### 1.33 对象成员
#### 1.34 继承
#### 1.35 多态
#### 1.36 纯虚类
#### 1.37 动态内存分配
```
Foo *f = new Foo;
Delete f;
// 每个过程都分为两个步骤：
// 1,调用operator new 分配内存
// 2,调用Foo::Foo()构造函数
```
#### 1.38 智能指针
1. Auto_ptr
永远不要使用auto_ptr作为元素建立容器，因为再auto_ptr类型指针进行拷贝时，会将s1=NULL，容器拷贝时，会发生问题，详细见effective stl 条款8
```
Auto_ptr<string> s1(new string(“wrwer”))
Auto_ptr<string>s2 = s1
```
2. Share_ptr
3. Unique_ptr
#### 1.39 内存池
#### 1.40 顺序容器
#### 1.41 关联容器
- unordered_map
         对于自定义的结构体，需要自己实现hashcode方法和==方法
        >[基于hash实现使用参考1](https://www.sczyh30.com/posts/C-C/cpp-stl-hashmap/)
         [基于hash实现使用参考1](https://blog.csdn.net/Cypress1010/article/details/53669409)
- map
        >[基于红黑树实现使用参考](https://www.cnblogs.com/tp-16b/p/9156810.html)
#### 1.42  元组
#### 1.43  内存分配器
#### 1.44  泛型算法   
#### 1.45  类模板和函数模板
#### 1.46  仿函数(函数对象）
#### 1.47  现代C++高级特性
#### 1.48  设计模式
#### 1.49  代码重构
#### 1.50  原子操作
#### 1.51  锁和信号量
#### 1.52  线程库
#### 1.53  标准库的实现
#### 1.54  性能调优
#### 1.55  对象重载方法
----------
## 二，算法
### 1 本排序算法
### 2 递归算法
### 3 动态规划算法
### 4 贪心算法
### 5 分治算法
### 6 回溯算法

-----------
## 三 数据库
### 1 链接关系
#### 1.1 左连接
#### 1.2 右连接
#### 1.3 交叉连接
#### 1.4 全连接
### 2 数据库索引
### 3 数据库常用优化方式
