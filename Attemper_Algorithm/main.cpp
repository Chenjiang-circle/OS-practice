#include "ReadFile.h"
#include "SortJobs.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRN.h"

int main() {
    vector<Job> jobs = read_file("test.txt");
    vector<Job> jobs_vector = sort_jobs(jobs);
    // 先来先服务算法测试
    //FCFS_Algorithm(jobs_vector, "fcfs_result.txt");
    // 最短作业优先算法测试
    //SJF_Algorithm(jobs_vector, "sjf_result.txt");
    // 高响应比优先算法测试
    HRRN_Algorithm(jobs_vector, "hrrn_result.txt");
    return 0;
}
