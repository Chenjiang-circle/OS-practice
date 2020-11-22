#include "ReadFile.h"

int main() {
    vector<Job> jobs = read_file("/Users/chenjiangchao/Code/GitHub/OS-practice/Attemper_Algorithm/test.txt");
    cout << "main:" << endl;
    for (vector<Job>::iterator it; it!= jobs.end(); it++)
        cout << it->job_name << " " << it->come_time << " " << it->serve_time << endl;
    while (!jobs.empty())
    {
        Job job = jobs.back();
        cout << job.job_name << " " << job.come_time << " " << job.serve_time << endl;
        jobs.pop_back();
    }
    return 0;
}
