#include "ExecuteAlgorithm.h"

/**
 * 根据参数执行相应的算法
 * @param jobs 作业向量
 * @param select 用户输入的参数
 * @param output_file 用户指定的文件输出路径
 */
int execute_algorithm(vector<Job> jobs, int select, char* output_file)
{
    int result = 0;
     switch (select)
     {
         case 1:
             result = FCFS_Algorithm(jobs, output_file);
             break;
         case 2:
             result = SJF_Algorithm(jobs, output_file);
             break;
         case 3:
             result = HRRN_Algorithm(jobs, output_file);
             break;
         case 4:
             result = SRT_Algorithm(jobs, output_file);
             break;
         default:
             cout << "输入无效，请重新输入！" << endl;
     }
    return result;
}