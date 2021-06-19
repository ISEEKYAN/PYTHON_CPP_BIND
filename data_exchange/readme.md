# 总结

这里试了三个轻量级的数据交换格式，分别是 json,bson,msgpack, 都使用`nlohmann/json`为 cpp 提供解析。

为了最小化依赖，所以更为重量级的如 thrift、protobuf、numpy 等暂未尝试。

结论是文件性能方面 msgpack 最好（文件尺寸最小，读取最快），json 最差，但 json 可读性好。

# 运行实验

先在 `data_exchange` 目录运行`python 0_generate_data.py`，然后`mkdir build && cd build && cmake .. && make -j && ./read`
