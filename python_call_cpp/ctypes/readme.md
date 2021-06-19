# 使用方法

执行`sh build.sh`，使用`python test.py`

# 总结

## cons

- ctypes 只能对 C 有比较好的支持，不兼容 c++的类
- 调用 c++时需要在函数声明前添加`extern "C"`

## pros

- 不需要额外内容的安装，轻度场景建议使用
