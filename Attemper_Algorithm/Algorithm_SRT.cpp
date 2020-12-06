#include "Algorithm.h"

/**
 * 在所用未完成且已经到达的作业中，选出服务时间最短的作业的索引
 * @param jobs 所有的作业
 * @param now_time 现在时间
 * @return 作业索引
 */
int find_shortest_remain_time_job(vector<Job> jobs, int now_time)
{
    int index = 0;
    int shortest_index = -1;
    int shortest_remain_time = MAX;
    vector<Job>::iterator it;
    for (it = jobs.begin();  it != jobs.end(); it++)
    {
        if (!it->getOver() && it->getComeTime() <= now_time)
        {
            if (it->getRemainTime() < shortest_remain_time)
            {
                shortest_remain_time = it->getRemainTime();
                shortest_index = index;
            }
        }
        index++;
    }
    return shortest_index;
}

bool Algorithm::SRTAlgorithm(vector<Job> jobs, string fileName) {
    // 打开输出文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "作业 到达时间 服务时间 开始时间 结束时间 周转时间 加权周转时间" << endl;

    // SRT算法
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        it->setRemainTime(it->getServeTime());
    }
    int now = 0; // 现在时间
    int all_time = 0;
    int weighted_all_time = 0;
    Job job;
    int index = find_shortest_remain_time_job(jobs, now);
    while (index != -1)
    {
        job = jobs[index];
        if (jobs[index].getStartTime() == -1)
            jobs[index].setStartTime(now);
        now++;
        jobs[index].setRemainTime(jobs[index].getRemainTime() - 1);
        // 判断作业是否完成
        if (jobs[index].getRemainTime() == 0)
        {
            jobs[index].setOver(true);
            all_time = now - jobs[index].getComeTime();
            weighted_all_time = (all_time + 0.0) / job.getServeTime();
            output_file << job.getJobName() << "\t\t" << job.getComeTime() << "\t\t" << job.getServeTime() << "\t\t" << jobs[index].getStartTime() << "\t\t" << now << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        }
        index = find_shortest_remain_time_job(jobs, now);
    }
    output_file.close();
    return true;
}