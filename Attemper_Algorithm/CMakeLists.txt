cmake_minimum_required(VERSION 3.15)
project(Attemper_Algorithm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(Attemper_Algorithm main.cpp BASE.h FCFS.h FCFS.cpp ReadFile.h ReadFile.cpp FormatInput.h FormatInput.cpp SortJobs.h SortJobs.cpp SJF.h SJF.cpp HRRN.h HRRN.cpp SRT.h SRT.cpp ExecuteAlgorithm.h ExecuteAlgorithm.cpp)