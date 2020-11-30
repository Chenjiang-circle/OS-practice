cmake_minimum_required(VERSION 3.15)
project(Attemper_Algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(Attemper_Algorithm main.cpp BASE.h old/FCFS.h old/FCFS.cpp old/ReadFile.h old/ReadFile.cpp old/FormatInput.h old/FormatInput.cpp old/SortJobs.h old/SortJobs.cpp old/SJF.h old/SJF.cpp old/HRRN.h old/HRRN.cpp old/SRT.h old/SRT.cpp Job.cpp Job.h Algorithm.cpp Algorithm.h Utils.cpp Utils.h Algorithm_FCFS.cpp Algorithm_SJF.cpp Algorithm_HRRN.cpp Algorithm_SRT.cpp Algorithm_SPF.cpp Algorithm_RR.cpp Algorithm_nonPreemptivePriority.cpp Algorithm_preemptivePriorityScheduling.cpp)