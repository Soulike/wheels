cmake_minimum_required(VERSION 3.28)
project(wheels)
set(CMAKE_CXX_STANDARD 20)

# 启用测试支持
enable_testing()

# 查找 GTest
find_package(GTest REQUIRED)

# 递归收集所有 .test.cc 文件（假设测试文件分布在任意目录）
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "*.test.cc")

# 遍历每个测试文件，生成可执行目标
foreach (test_source ${TEST_SOURCES})
    # 提取测试基础名（如 test_feature1.test.cc → test_feature1）
    get_filename_component(test_base ${test_source} NAME_WE)

    # 查找对应的 .h 和 .cpp 文件（假设与测试文件同目录）
    get_filename_component(test_dir ${test_source} DIRECTORY)
    set(test_impl_h "${test_dir}/${test_base}.h")      # 头文件路径
    set(test_impl_cpp "${test_dir}/${test_base}.cc")  # 实现文件路径

    # 检查实现文件是否存在
    if (EXISTS ${test_impl_h} AND EXISTS ${test_impl_cpp})
        # 生成唯一目标名（路径转下划线，如 module1_test_feature1）
        file(RELATIVE_PATH relative_path ${CMAKE_SOURCE_DIR} ${test_dir})
        string(REPLACE "/" "_" target_prefix ${relative_path})
        set(target_name "${target_prefix}_${test_base}")

        # 创建可执行文件（包含测试文件和实现文件）
        add_executable(${target_name}
                ${test_source}
                ${test_impl_cpp}  # 添加对应的 .cpp
        )

        # 链接依赖库
        target_link_libraries(${target_name}
                PRIVATE
                GTest::GTest
                GTest::Main
        )

        # 注册到 CTest
        add_test(
                NAME "${relative_path}/${test_base}"  # 清晰路径标识
                COMMAND ${target_name}
        )
    else ()
        message(WARNING "Missing implementation files for test: ${test_base}")
    endif ()
endforeach ()
