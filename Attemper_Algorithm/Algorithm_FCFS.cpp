#include "Algorithm.h"

/**
 * 先来线服务算法
 * @param jobs 按找到达时间顺序排好顺序的作业集
 * @param fileName 输出结果的文件名
 * @return 成功返回true，否则返回false
 */
bool Algorithm::FCFSAlgorithm(vector<Job> jobs, string fileName) {
    int begin_time = 0; // 作业开始时间
    int end_time = 0; // 作业完成时间
    int all_time = 0; // 作业周转时间
    float weight_all_time = 0; // 作业的加权周转时间
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
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++)
    {
        begin_time = end_time;
        end_time += it->getServeTime();
        all_time = end_time - it->getComeTime();
        weight_all_time = (all_time + 0.0) / it->getServeTime();
        output_file << it->getJobName() << "\t\t" << it->getComeTime() << "\t\t" << it->getServeTime() << "\t\t" << begin_time <<"\t\t" << end_time << "\t\t" << all_time << "\t\t" << weight_all_time << endl;
    }
    output_file.close();
    return true;
}
