cmake_minimum_required(VERSION 3.15)
project(Attemper_Algorithm)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(Attemper_Algorithm main.cpp BASE.h Job.cpp Job.h Algorithm.h Utils.cpp Utils.h Algorithm_FCFS.cpp Algorithm_SJF.cpp Algorithm_HRRN.cpp Algorithm_SRT.cpp Algorithm_SPF.cpp Algorithm_RR.cpp Algorithm_nonPreemptivePriority.cpp Algorithm_preemptivePriorityScheduling.cpp Executor.cpp Executor.h Base.cpp Algorithm_nonPreemptiveEDF.cpp Algorithm_preemptiveEDF.cpp Algorithm_LLF.cpp)