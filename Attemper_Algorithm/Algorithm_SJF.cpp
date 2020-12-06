#include "Algorithm.h"

/**
 * 找到最短的未完成的作业
 * @param jobs 作业向量
 * @param now_time 现在时间
 * @return 最短的未完成作业的位置（从0开始算）
 */
int find_short_job(vector<Job> jobs, int now_time)
{
    int shortest_serve_time = MAX;
    int index = 0;
    int shortest_job_index = -1;
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        if (it->getServeTime() < shortest_serve_time && !it->getOver() && it->getComeTime() <= now_time)
        {
            shortest_serve_time = it->getServeTime();
            shortest_job_index = index;
        }
        index++;
    }
    return shortest_job_index;
}


bool Algorithm::SJFAlgorithm(vector<Job> jobs, string fileName) {
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "作业 到达时间 服务时间 开始时间 结束时间 周转时间 加权周转时间" << endl;

    // SJF算法
    int now = 0; // 当前时间
    int begin_time = 0; // 开始时间
    int end_time = 0; // 结束时间
    int all_time = 0; // 周转时间
    float weighted_all_time = 0.0; // 加权周转时间
    int index = find_short_job(jobs, now);
    Job job_tmp;
    while (index != -1)
    {
        job_tmp = jobs[index];
        begin_time = end_time;
        end_time += job_tmp.getServeTime();
        jobs[index].setOver(true);
        all_time = end_time - job_tmp.getComeTime();
        weighted_all_time = (all_time + 0.0) / job_tmp.getServeTime();
        output_file << job_tmp.getJobName() << "\t\t" << job_tmp.getComeTime() << "\t\t" << job_tmp.getServeTime() << "\t\t" << begin_time << "\t\t" << end_time << "\t\t" << all_time << "\t\t" << weighted_all_time << endl;
        now += job_tmp.getServeTime();
        index = find_short_job(jobs, now);
    }
    output_file.close();
    return true;
}