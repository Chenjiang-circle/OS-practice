#include "ReadFile.h"

int main() {
    vector<Job> jobs = read_file("test.txt");
    cout << "main:" << endl;
    while (!jobs.empty())
    {
        Job job = jobs.back();
        cout << job.job_name << " " << job.come_time << " " << job.serve_time << endl;
        jobs.pop_back();
    }
    return 0;
}
