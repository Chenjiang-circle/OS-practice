#ifndef ATTEMPER_ALGORITHM_ALGORITHM_H
#define ATTEMPER_ALGORITHM_ALGORITHM_H

#include "Job.h"

class Algorithm {
public:
    /**
     * 先来线服务算法
     * @param jobs 按找到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功返回true，否则返回false
     */
    static bool FCFSAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 最短作业有限算法
     * @param jobs 按找到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功返回true，否则返回false
     */
    static bool SJFAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 高响应比有限调度算法
     * @param jobs 按找到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功返回true，否则返回false
     */
    static bool HRRNAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 最短剩余时间调度算法
     * @param jobs 按照到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool SRTAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 最短进程有限调度算法（非抢占式）
     * @param jobs 按照到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool SPFAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 时间片轮转调度算法
     * @param jobs 按照到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool RRAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 非抢占式优先级调度算法
     * @param jobs 按照到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool nonPreemptivePrioritySchedulingAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 抢占式优先级调度算法
     * @param jobs 按照到达时间顺序排好顺序的作业集
     * @param fileName 输出结果的文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool preemptivePrioritySchedulingAlgorithm(vector<Job> jobs, string fileName);

    /**
     * 非抢占式调度方式用于非周期实时任务
     * @param jobs 按到达时间排序的任务集
     * @param fileName 结果输出文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool nonPreemptiveEDF(vector<Job> jobs, string fileName);

    /**
     * 抢占式调度方式用于周期实时任务
     * @param jobs 按到达时间排序的任务集
     * @param fileName 结果输出文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool preemptiveEDF(vector<Job> jobs, string fileName);

    /**
     * 最低松弛度优先算法
     * @param jobs 按到达时间排序的任务集
     * @param fileName 结果输出文件名
     * @return 成功执行返回true，否则返回false
     */
    static bool LLFAlgorithm(vector<Job> jobs, string fileName);
};

#endif //ATTEMPER_ALGORITHM_ALGORITHM_H
