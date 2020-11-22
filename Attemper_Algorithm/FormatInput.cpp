//
// Created by 陈江超 on 2020/11/22.
//

#include "FormatInput.h"

/**
 * 将输入的字符串转换为Job类型的结构体
 * @param str
 * @return
 */
Job string_to_job(char* str)
{
    Job job;
    char* job_string[3];
    int i = 0;
    char *tmp;
    // 按空格对读入的字符串进行分割
    tmp = strtok(str, " ");
    while (tmp)
    {
        job_string[i] = tmp;
        i++;
        tmp = strtok(NULL, " ");
    }
    // 分割完成之后
    strcpy(job.job_name, job_string[0]);
    //tring.
    job.come_time = atoi(job_string[1]);
    job.serve_time = atoi(job_string[2]);
//    cout << "job_name com_time serve_time" << endl;
//    cout << job.job_name << " " << job.come_time << " " << job.serve_time << endl;
    return job;
}
