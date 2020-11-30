#include "Utils.h"

/**
 * 定义对Job的比较
 * @param a
 * @param b
 * @return
 */
bool compare_jobs_by_come_time(Job a, Job b)
{
    return a.getComeTime() < b.getComeTime();
}

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
//        cout << "Utils getJobFromFile: 1" << line << endl;
        Job job(line);
        jobs.push_back(job);
    }
    file.close();
    // 对作业进行排序
    sort(jobs.begin(), jobs.end(), compare_jobs_by_come_time);
    vector<Job>::iterator it;
//    // 调试
//    for (it = jobs.begin();  it != jobs.end() ; it++) {
//        cout << it->getJobName();
//    }
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


int Utils::choseAlgorithm() {
    cout << "============第五组 调度算法============" << endl;
    cout << "* 0. exit\t退出程序" << endl;
    cout << "* 1. FCFS\t先来先服务算法" << endl;
    cout << "* 2. SJF\t最短作业有限算法" << endl;
    cout << "* 3. HRRN\t最高相应比有限调度算法" << endl;
    cout << "* 4. RR\t\t时间片轮转调度算法" << endl;
    cout << "* 5. SPF\t最短进程调度算法（非抢占式）" << endl;
    cout << "* 6. SRT\t最短剩余时间调度算法" << endl;
    cout << "* 7. 非抢占式优先级调度算法" << endl;
    cout << "* 8. 抢占式优先级调度算法" << endl;
    cout << "* 请选择想要执行的算法前的数字：";
    int chose;
    cin >> chose;
    return chose;
}
