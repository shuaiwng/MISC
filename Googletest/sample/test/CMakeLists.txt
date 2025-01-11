cmake_minimum_required(VERSION 3.1.0)

set(gtest_path "C:/XYZ/XYZ/googletest-1.15.2/build/output")

find_package(GTest PATHS ${gtest_path}/lib/cmake/GTest NO_DEFAULT_PATH)

function(create_test name)
    add_executable(${name} ${name}.cpp ${PROD_SRC})
    target_include_directories(${name} PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${gtest_path}/include
    )
    target_link_libraries(${name} PRIVATE GTest::gtest GTest::gmock)
    add_test(NAME ${name} COMMAND "$<TARGET_FILE:${name}>")
endfunction()


list(REMOVE_ITEM PROD_SRC ${CMAKE_SOURCE_DIR}/src/main.cpp)
# create_test(gtest_ex1)
# create_test(gtest_ex2)
# create_test(gtest_ex3)
# create_test(gtest_fixture)
create_test(gtest_mock)
