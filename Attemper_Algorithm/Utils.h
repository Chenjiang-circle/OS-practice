#ifndef ATTEMPER_ALGORITHM_UTILS_H
#define ATTEMPER_ALGORITHM_UTILS_H

#include "Job.h"

/**
 * 工具类
 */
class Utils {
public:

    /**
     * 在控制台打印用户提示信息，返回用户输入的选择结果
     * @return 用户输出的选择结果
     */
    static int choseAlgorithm();

    /**
     * 从文件中获取作业集
     * @param fileName 文件名
     * @return 作业集
     */
    static vector<Job> getJobsFromFile(string fileName);

    /**
     * 将作业调度结果输出到文件中
     * @param fileName 输出文件名
     * @param jobs 作业调度顺序集
     * @return 输出文件成功返回true，否则返回false
     */
    static bool resultToFile(string fileName, queue<Job> jobs);
};


#endif //ATTEMPER_ALGORITHM_UTILS_H
