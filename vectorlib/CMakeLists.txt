file(GLOB hdrs "${CMAKE_CURRENT_SOURCE_DIR}/*.h*")
file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(${vectorlib} STATIC ${srcs} ${hdrs})