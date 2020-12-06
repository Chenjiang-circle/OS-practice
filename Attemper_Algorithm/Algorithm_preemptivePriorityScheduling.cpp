#include "Algorithm.h"

/**
 * 在未完成作业集中选出优先数最小并且已经到达的作业的索引下标
 * @param jobs 按作业到达时间排序的作业集
 * @param nowTime 当前时间
 * @return 优先数最小未完成且已到达的作业的索引下表
 */
int find_min_priority_job(vector<Job> jobs, int nowTime)
{
    int minIndex = -1;
    int index = 0;
    int minPriority = MAX;
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        if (!it->getOver() && it->getComeTime() <= nowTime)
        {
            if (it->getPriority() < minPriority)
            {
                minPriority = it->getPriority();
                minIndex = index;
            }
        }
        index++;
    }
    return minIndex;
}

/**
 * 判断当前作业集是否都完成了
 * @param jobs 作业集
 * @return 全部完成返回true，否则返回false
 */
bool isAllOver(vector<Job> jobs)
{
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++) {
        if (!it->getOver())
            return it->getOver();
    }
    return true;
}

bool Algorithm::preemptivePrioritySchedulingAlgorithm(vector<Job> jobs, string fileName) {
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "进程 到达时间 服务时间 优先数 开始时间 结束时间 周转时间 加权周转时间" << endl;

    int now = 0;
    queue<Job> jobQueue; // 当前作业队列
    int index = find_min_priority_job(jobs, now);
    while (index != -1)
    {
        if (jobs[index].getStartTime() == -1)
            jobs[index].setStartTime(now);
        jobs[index].setRemainTime(jobs[index].getRemainTime() - 1);
        now++;
        if (jobs[index].getRemainTime() == 0)
        {
            jobs[index].setOver(true);
            jobs[index].setOverTime(now);
            int allTime = now - jobs[index].getComeTime();
            int weightedAllTime = (allTime + 0.0) / jobs[index].getServeTime();
            output_file << jobs[index].getJobName() << "\t\t" << jobs[index].getComeTime() << "\t\t" << jobs[index].getServeTime() << "\t\t" << jobs[index].getPriority() << "\t\t" << jobs[index].getStartTime() << "\t\t" << jobs[index].getOverTime() << "\t\t" << allTime << "\t\t" << weightedAllTime << endl;
        }
        index = find_min_priority_job(jobs, now);
    }
    return true;
}