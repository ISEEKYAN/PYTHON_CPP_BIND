# 总结

- 第一选择：pybind11
- 第二选择：ctypes （只提供 C 扩展）

# 备选项

## ctypes

用 python 直接调用动态链接库中的函数，但要求是 C 接口的。

## pybind11

基于 swig 实现，torch/tf 都在用。用法为添加 header-only 的库并编译成 so 文件供 python 直接调用。推荐。

## SWIG

太复杂了，要学单独的一门语言。不推荐。

## Cython

更像是介于 c 和 python 之间的一门语言，主要用途是为 python 加速。语法类似 python，但是需要指定强类型，使用 c 编译器编译。
对于纯 python 用户上手门槛低，但深入了解较难。对 C++用户来说语法有些怪异。不推荐。

## boost.python

缺点在于 boost 太臃肿了，其他功能都可以被 pybind11 代替。

## 直接用 Python 的 API

> 可以称之为最终解决方案。Cython, SWIG, SIP 的接口文件转换后所生成的 C/C++代码实际上都使用 Python 的 API。与其它方案相比，这种方案相当地繁复，必须为每次函数调用编写数据转换代码，还要操心 Python 对象的引用计数。我觉得这种方案一无是处，这时就不再多讲了。其它的工具 pybindgen 不知道什么情况。有兴趣的话可以看看。
> ————————————————
> 版权声明：本文为 CSDN 博主「assassin_sword」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
> 原文链接：https://blog.csdn.net/weixin_41521681/article/details/105966415

# ref

[python/C++ 混合编程\_\_方案调研](https://blog.csdn.net/weixin_41521681/article/details/105966415)

[C/C++与 python 互相调用](https://blog.csdn.net/u012234115/article/details/50210835)
