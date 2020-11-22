//
// Created by 陈江超 on 2020/11/22.
//

#include "ReadFile.h"

/**
 * 读取文件
 * @param file_name 读取的文件名
 * @return 作业列表
 */
vector<Job> read_file(char* file_name)
{
    vector<Job> jobs;
    char line[LINE_MAX_LENGTH];
    ifstream file;
    file.open(file_name);
    // 判断是否成功打开文件
    if (!file.is_open())
    {
        cout << "can not open the file: " << file_name << endl;
        return jobs;
    }
    Job job;
    // 成功打开之后开始读取数据
    while (!file.eof())
    {
        file.getline(line, LINE_MAX_LENGTH);
        // 调试：
        cout << line << endl;
        job = string_to_job(line);
        jobs.push_back(job);
    }
    file.close();
    return jobs;
}