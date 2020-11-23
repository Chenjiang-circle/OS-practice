#include "SortJobs.h"

/**
 * 定义对Job的比较
 * @param a
 * @param b
 * @return
 */
bool compare_jobs_by_come_time(Job a, Job b)
{
    return a.come_time < b.come_time;
}

/**
 * 按照作业服务时间对两个作业进行比较
 * @param a 作业A
 * @param b 作业B
 * @return 比较结果
 */
bool compare_jobs_by_serve_time(Job a, Job b)
{
    return a.serve_time < b.serve_time;
}

/**
 * 对获取到的作业列表，按照到达时间进行排序
 * @param jobs 作业列表
 * @return 按照到达时间排序的作业队列
 */
vector<Job> sort_jobs(vector<Job> jobs)
{
    queue<Job> sorted_jobs;
    sort(jobs.begin(), jobs.end(), compare_jobs_by_come_time);
    return jobs;
}