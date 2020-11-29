#include "Utils.h"

/**
 * 从文件中获取作业集
 * @param fileName 文件名
 * @return 作业集
 */
vector<Job> Utils::getJobsFromFile(string fileName) {
    vector<Job> jobs;
    char line[LINE_MAX_LENGTH];
    ifstream file;
    file.open(fileName, ios::in);
    // 判断是否成功打开文件
    if (!file.is_open())
    {
        cout << "can not open the file: " << fileName << endl;
        return jobs;
    }
    // 成功打开之后开始读取数据
    // 忽略第一行数据
    file.getline(line, LINE_MAX_LENGTH);
    while (!file.eof())
    {
        file.getline(line, LINE_MAX_LENGTH);
        Job job(line);
        jobs.push_back(job);
    }
    file.close();
    return jobs;
}

/**
 * 将作业调度结果输出到文件中
 * @param fileName 输出文件名
 * @param jobs 作业调度顺序集
 * @return 输出文件成功返回true，否则返回false
 */
bool Utils::resultToFile(string fileName, queue<Job> jobs) {
    // 打开输出文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }
    output_file << "作业\t到达时间\t服务时间\t开始时间\t结束时间\t周转时间\t加权周转时间" << endl;
    while (!jobs.empty())
    {
        Job job = jobs.front();
        int allTime = job.getOverTime() - job.getComeTime();
        float weightedAllTime = (allTime + 0.0) / job.getServeTime();
        cout << job.getJobName() << "\t\t" << job.getComeTime() << "\t\t" << job.getServeTime() << "\t\t" << job.getStartTime() << "\t\t" << job.getOverTime() << "\t\t" << allTime << "\t\t" << weightedAllTime << endl;
        jobs.pop();
    }
    return true;
}

vector<string> Utils::stringToken(string line, string pattern) {
    string::size_type pos;
    vector<string> result;
    line += pattern;//扩展字符串以方便操作
    int size = line.size();
    for (int i = 0; i < size; i++)
    {
        pos = line.find(pattern, i);
        if (pos < size)
        {
            string s = line.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}
