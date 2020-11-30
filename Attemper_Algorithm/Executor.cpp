#include "Executor.h"

int Executor::exe(int chose) {
    if (chose == 0) {
        cout << "Bye!" << endl;
        return 0;
    }

    string fileName;
    string outputFileName;

    vector<Job> jobs = Utils::getJobsFromFile(fileName);
    switch (chose) {
        case 1:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::FCFSAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 2:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::SJFAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 3:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::HRRNAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 4:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::RRAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 5:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::SPFAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 6:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::SRTAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 7:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::nonPreemptivePrioritySchedulingAlgorithm(jobs, outputFileName) ? 1 : -1;
        case 8:
            cout << "请输入文件名：";
            cin >> fileName;
            cout << "请输入输出文件名：";
            cin >> outputFileName;
            return Algorithm::preemptivePrioritySchedulingAlgorithm(jobs, outputFileName) ? 1 : -1;
        default:
            cout << "输入不合法" << endl;
            return -1;
    }
}
