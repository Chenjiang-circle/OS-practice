#include "Algorithm.h"

/**
 * 计算作业的松弛度
 * @param job 作业
 * @param now 当前时间
 * @return 松弛度
 */
int computeLaxity(Job job, int now)
{
    return job.getDeadline() - job.getRemainTime() - now;
}

/**
 * 寻找当前未完成且已经到达的作业中松弛度最小的作业的索引
 * @param jobs 按找到达时间顺序排列好的作业集
 * @param now 当前时间
 * @return 作业的索引下标，未找到返回-1
 */
int find_least_laxity_job_index(vector<Job> jobs, int now)
{
    int index = -1;
    int laxity = MAX;
    for (int i = 0; i < jobs.size(); i++)
    {
        if (!jobs[i].getOver() && jobs[i].getComeTime() <= now)
        {
            int tmpLaxity = computeLaxity(jobs[i], now);
            if (tmpLaxity < laxity)
            {
                index = i;
                laxity = tmpLaxity;
            }
        }
    }
    return index;
}

bool Algorithm::LLFAlgorithm(vector<Job> jobs, string fileName)
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

    int now = 0;
    bool flag = false; // 表示当前是否有进程（作业）正在执行
    int begin = 0;
    int index = find_least_laxity_job_index(jobs, now);
    int workIndex = index;
    while (index != -1)
    {
        // 当前没有进程在执行
        if (!flag)
        {
            workIndex = index;
            begin = now;
        }

        // 当前有进程在执行，但是出现了松弛度为0的进程，发生进程切换
        if (computeLaxity(jobs[workIndex], now) == 0)
        {
            output_file << jobs[workIndex].getJobName() << "(" << begin << "->" << now << "),";
            workIndex = index;
            begin = now;
        }

        flag = true;
        jobs[workIndex].setRemainTime(jobs[workIndex].getRemainTime() - 1);
        now++;
        if (jobs[workIndex].getRemainTime() == 0)
        {
            output_file << jobs[workIndex].getJobName() << "(" << begin << "->" << now << "),";
            begin = now;
            jobs[workIndex].setOver(true);
            flag = false;
        }
        index = find_least_laxity_job_index(jobs, now);
    }
    return true;
}