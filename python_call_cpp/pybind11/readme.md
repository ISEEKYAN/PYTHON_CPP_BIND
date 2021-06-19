# 使用方法

在 cmake_example 中执行`mkdir build && cd build && cmake .. && make -j`，再使用`python ../tests/test.py`

# 总结

总体来说推荐使用，机遇 swig 开发，pytorch、tensorflow 都在用。

## pros

- 与 cmake 工程完美契合，只需要编译出一个 so 文件即可运行
- 上限高，原生支持 stl、numpy、eigen

## cons

- 上手易精通难
