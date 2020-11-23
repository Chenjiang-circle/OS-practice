#include "ReadFile.h"
#include "SortJobs.h"
#include "ExecuteAlgorithm.h"

int main() {
    bool flag = true;
    char file_in_name[LINE_MAX_LENGTH];
    char file_out_name[LINE_MAX_LENGTH];
    int select = 0;
    while (flag)
    {
        cout << "请选择要执行的调度算法：" << endl;
        cout << "0. exit" << endl;
        cout << "1. FCFS Algorithm" << endl;
        cout << "2. SJF Algorithm" << endl;
        cout << "3. HRRN Algorithm" << endl;
        cout << "4. SRT Algorithm" << endl;
        cin >> select;
        if (select == 0)
        {
            flag = false;
        }
        else
        {
            cout << "请输入输入文件名：";
            cin >> file_in_name;
            cout << "请输入输出文件名：";
            cin >> file_out_name;
            vector<Job> jobs = read_file(file_in_name);
            if (jobs.empty())
                continue;
            vector<Job> jobs_vector = sort_jobs(jobs);
            execute_algorithm(jobs, select, file_out_name);
        }
    }

    return 0;
}
