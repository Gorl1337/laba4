file(GLOB hdrs "${CMAKE_CURRENT_SOURCE_DIR}/*.h*")
file(GLOB srcs "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${vector} ${srcs} ${hdrs})

target_link_libraries(${vector} ${vectorlib})