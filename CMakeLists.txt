cmake_minimum_required(VERSION 3.16)
project(SIMS)

set(CMAKE_CXX_STANDARD 14)

add_executable(SIMS main.cpp DB.cpp DB.h Student.cpp Student.h)

#I added
link_directories(/usr/lib/x86_64-linux-gnu/)
target_link_libraries(SIMS -lmysqlclient)