#include "Algorithm.h"

/**
 * 定义对Job的比较
 * @param a
 * @param b
 * @return
 */
bool compare_jobs_by_end_time(Job a, Job b)
{
    return a.getRemainTime() < b.getRemainTime();
}

/**
 * 查看当前到达的任务
 * @param jobs 所有的任务集
 * @param now 当前时间
 * @return 当前到达的任务集，如果当前没有到达的作业，返回空的作业集
 */
vector<Job> findComeWorkNow(vector<Job> jobs, int now)
{
    vector<Job> nowComeJobs;
    for (int i = 0; i < jobs.size(); i++)
    {
        if (jobs[i].getComeTime() == now)
            nowComeJobs.push_back(jobs[i]);
    }
    return nowComeJobs;
}

bool Algorithm::preemptiveEDF(vector<Job> jobs, string fileName)
{
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "最早截止完成时间优先算法执行过程：" << endl;
    vector<Job>::iterator it;
    vector<Job> workJobs;
    int now = 0;
    int countOver = 0;
    vector<Job> jobsTmp = findComeWorkNow(jobs, now);
    while (jobsTmp.empty())
    {
        now++;
        jobsTmp = findComeWorkNow(jobs, now);
    }
    for (int i = 0; i < jobsTmp.size(); ++i) {
        workJobs.push_back(jobsTmp[i]);
    }
    jobsTmp.clear();
    sort(workJobs.begin(), workJobs.end(), compare_jobs_by_end_time);
    bool flag = false;
    int begin = now;
    while (countOver != jobs.size())
    {
        if (workJobs.begin()->getStartTime() == -1)
            workJobs.begin()->setStartTime(now);
        workJobs.begin()->setRemainTime(workJobs.begin()->getRemainTime() - 1);
        now++;
        if (workJobs.begin()->getRemainTime() == 0)
        {
            output_file << workJobs.begin()->getJobName() << "(" << begin << "->" << now << ")" << ",";
            begin = now;
            workJobs.erase(workJobs.begin());
            countOver++;
        }
        vector<Job> jobsTmps = findComeWorkNow(jobs, now);
        if (!jobsTmps.empty())
        {

            for (int i = 0; i < jobsTmps.size(); ++i) {
                workJobs.push_back(jobsTmps[i]);
            }
            Job job1 = workJobs[0];
            sort(workJobs.begin(), workJobs.end(), compare_jobs_by_end_time);
            if (job1.getJobName() != workJobs.begin()->getJobName())
            {
                output_file << job1.getJobName() << "(" << begin << "->" << now << ")" << ",";
                begin = now;
            }
        }
    }
    return true;
}