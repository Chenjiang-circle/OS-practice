#include "Algorithm.h"

/**
 * 选择优先级最高的作业
 * @param jobs 作业向量
 * @return 优先级最高的未完成作业的位置（从0开始算）
 */
int find_privilege_job(vector<Job> jobs, int now_time) {
    int max_privilege = MAX;
    int index = 0;
    int ans_index = -1;
    vector<Job>::iterator it;
    for (it = jobs.begin(); it != jobs.end(); it++) {
        if (it->getPriority() < max_privilege && !it->getOver() && it->getComeTime() <= now_time) {
            max_privilege = it->getPriority();
            ans_index = index;
        }
        index++;
    }
    return ans_index;
}

bool Algorithm::nonPreemptivePrioritySchedulingAlgorithm(vector<Job> jobs, string fileName) {
    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open()) {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "作业\t到达时间\t服务时间\t优先数\t开始时间\t结束时间\t周转时间\t加权周转时间" << endl;

    //非抢占式优先级调度
    int now = 0; // 当前时间
    int begin_time = 0; // 开始时间
    int end_time = 0; // 结束时间
    int all_time = 0; // 周转时间
    float weighted_all_time = 0.0; // 加权周转时间
    int index = find_privilege_job(jobs, now);
    Job job_tmp;
    while (index != -1) {
        job_tmp = jobs[index];
        begin_time = end_time;
        end_time += job_tmp.getServeTime();
        jobs[index].setOver(true);
        all_time = end_time - job_tmp.getComeTime();
        weighted_all_time = (all_time + 0.0) / job_tmp.getServeTime();
        output_file << job_tmp.getJobName() << "\t\t" << job_tmp.getComeTime() << "\t\t" << job_tmp.getServeTime()
                    << "\t\t" << job_tmp.getPriority() << "\t\t" << begin_time << "\t\t" << end_time << "\t\t"
                    << all_time << "\t\t" << weighted_all_time << endl;
        now += job_tmp.getServeTime();
        index = find_privilege_job(jobs, now);
    }
    output_file.close();
    return true;
}