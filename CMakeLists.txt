cmake_minimum_required(VERSION 3.23)
project(3sem_DM_2)
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

add_executable(A A.cpp)
add_executable(A_Test A_Test.cpp)
target_compile_definitions(A_Test PUBLIC TEST_ON)
target_link_libraries(A_Test GTest::gtest GTest::gtest_main)

add_executable(B B.cpp)
#[[add_executable(C C.cpp)
add_executable(D D.cpp)
add_executable(E E.cpp)
add_executable(F F.cpp)
add_executable(G G.cpp)
add_executable(H H.cpp)]]
