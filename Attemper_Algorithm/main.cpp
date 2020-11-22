#include "ReadFile.h"
#include "SortJobs.h"
#include "FCFS.h"

int main() {
    vector<Job> jobs = read_file("test.txt");
    queue<Job> jobs_queue = sort_jobs(jobs);
    FCFS_Algorithm(jobs_queue, "fcfs_result.txt");
    return 0;
}
