file(GLOB SUB_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(SUB_DIR ${SUB_DIRS})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/main.cpp)
        string(REPLACE "/" "_" SUB_DIR_TARGET_NAME ${SUB_DIR})

        file(GLOB_RECURSE SUB_DIR_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/*.h)
        file(GLOB_RECURSE SUB_DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/*.cpp)

        add_executable(${SUB_DIR_TARGET_NAME}
                       UULP.h UULP.cpp
                       ${SUB_DIR_HEADERS} ${SUB_DIR_SRCS})

        # 去掉 main.cpp 以便制作静态链接库进行测试
        list(REMOVE_ITEM SUB_DIR_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/${SUB_DIR}/main.cpp)
        list(APPEND ALL_SUB_DIRS_SRCS_WITHOUT_MAIN ${SUB_DIR_SRCS})
        list(APPEND ALL_SUB_DIRS_HEADERS ${SUB_DIR_HEADERS})
    endif()
endforeach()

add_library(UULP UULP.h UULP.cpp
            ${ALL_SUB_DIRS_SRCS_WITHOUT_MAIN} ${ALL_SUB_DIRS_HEADERS})
