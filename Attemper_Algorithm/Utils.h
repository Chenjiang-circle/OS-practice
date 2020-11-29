#ifndef ATTEMPER_ALGORITHM_UTILS_H
#define ATTEMPER_ALGORITHM_UTILS_H

#include "Job.h"

/**
 * 工具类
 */
class Utils {
public:
    /**
     * 按某种格式分割字符串
     * @param line 待分割字符串
     * @param pattern 分割的模式
     * @return 返回分割后的字符串集
     */
    static vector<string> stringToken(string line, string pattern);

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
