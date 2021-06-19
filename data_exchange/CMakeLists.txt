cmake_minimum_required(VERSION 3.4...3.18)

project(json_exchange)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_subdirectory(json)
# find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(read 1_read.cpp)

target_link_libraries(read PRIVATE nlohmann_json::nlohmann_json)




# add_custom_target()
