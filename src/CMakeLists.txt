file(GLOB_RECURSE SRC_FILES ./*.cpp)

add_executable(todo ${SRC_FILES})

target_include_directories(todo PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
