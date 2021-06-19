import ctypes
import os
from ctypes import cdll, CDLL

path = os.path.dirname(os.path.abspath(__file__))
libname = "libadd.so"


lib = CDLL(os.path.join(path, libname))

if 1:
    # 运行成功
    print(lib.add1(1, 1))

if 1:
    # 运行失败，不兼容c++的类
    print(lib.add2(b"1", b"1"))

if 1:
    # 设置函数原型：返回值类型和参数类型，勉强能用
    lib.add3.restype = ctypes.c_char_p
    lib.add3.argtypes = [ctypes.c_char_p, ctypes.c_char_p]
    print(lib.add3(b"1", b"1"))
