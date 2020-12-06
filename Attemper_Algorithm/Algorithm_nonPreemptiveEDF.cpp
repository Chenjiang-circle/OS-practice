#include "Algorithm.h"

/**
 * 定义对Job的比较
 * @param a
 * @param b
 * @return
 */
bool compare_jobs_by_latest_start_time(Job a, Job b)
{
    return a.getLatestStartTime() < b.getLatestStartTime();
}

//vector<Job>

bool Algorithm::nonPreemptiveEDF(vector<Job> jobs, string fileName)
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
    output_file << "作业 到达时间 服务时间 开始截至时间 截至时间 开始时间 结束时间 周转时间 加权周转时间" << endl;

    // 首先对jobs按照开始截至时间排序
    sort(jobs.begin(), jobs.end(), compare_jobs_by_latest_start_time);
    queue<Job> jobQueue;
    // 将作业按照作业开始截至时间加入到队列中
    for (int i = 0; i < jobs.size(); i++)
    {
        jobQueue.push(jobs[i]);
    }
    int now = 0; // 当前时间
    Job job;
    while (!jobQueue.empty())
    {
        if (now >= jobQueue.front().getComeTime())
        {
            if (jobQueue.front().getStartTime() == -1)
                jobQueue.front().setStartTime(now);
            jobQueue.front().setRemainTime(jobQueue.front().getRemainTime() - 1);
            now++;
            // 如果当前队列第一个作业完成了
            if (jobQueue.front().getRemainTime() == 0)
            {
                jobQueue.front().setOverTime(now);
                int allTime = now - jobQueue.front().getComeTime();
                float weightedAllTime = (allTime + 0.0) / jobQueue.front().getServeTime();
                output_file << jobQueue.front().getJobName() << "\t\t" << jobQueue.front().getComeTime() << "\t\t" << jobQueue.front().getServeTime() << "\t\t" << jobQueue.front().getLatestStartTime() << "\t\t" << jobQueue.front().getDeadline() << "\t\t" << jobQueue.front().getStartTime() << "\t\t" << jobQueue.front().getOverTime() << "\t\t" << allTime << "\t\t" << weightedAllTime << endl;
                jobQueue.pop();
            }
        }
        else
            now++;
    }
    return true;
}