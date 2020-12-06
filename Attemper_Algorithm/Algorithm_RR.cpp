#include "Algorithm.h"

bool Algorithm::RRAlgorithm(vector<Job> jobs, string fileName) {
    int everytime = 1; //时间片，需要用户输入
    cout << "输入时间片：";
    cin >> everytime;

    // 打开要读入的文件
    ofstream output_file;
    output_file.open(fileName);
    // 判断文件是否打开
    if (!output_file.is_open())
    {
        cout << "ERROR: can not open " << fileName << "!" << endl;
        return false;
    }

    queue<Job> que;
    que.push(jobs[0]); //首先运行第一个作业
    jobs[0].setOver(true);
    double time = max(0, jobs[0].getComeTime());
    int Njobs = jobs.size();

    bool vis[Njobs];     //表示这个进程有没有在完成，完成使用true表示
    queue<Job> AnsQue; //存放序列

    for (int i = 0; i < Njobs; i++)
    {
        while (!que.empty())
        {
            Job tempJob = que.front();
            que.pop();
            tempJob.setStartTime(time);
            tempJob.setOverTime(tempJob.getServeTime() >= everytime ? time + everytime : time + tempJob.getServeTime());
            for (int j = 0; j < Njobs; j++)
            {
                if (!vis[j] && jobs[j].getComeTime() <= tempJob.getOverTime())
                {
                    vis[j] = 1;
                    que.push(jobs[j]);
                }
            }
            if (tempJob.getServeTime() > everytime) //本次还没有运行完
            {
                tempJob.setServeTime(tempJob.getServeTime() - everytime);
                que.push(tempJob);
                time += everytime;
            }
            else
            {
                time += tempJob.getServeTime();
            }
            AnsQue.push(tempJob);
        }

        bool flag = false;
        for (int j = 0; j < Njobs; j++)
        {
            if (!vis[j])
            {
                vis[j] = 1;
                que.push(jobs[j]);
                time = jobs[j].getComeTime();
                flag = false;
                break;
            }
        }
        if (flag)
            break; //直到所有进程运行完成才退出
    }
    output_file << "进程的运行顺序为：" << endl;
    for (int i = 0; i < Njobs; i++)
    {
        output_file << jobs[i].getJobName() << " ";
    }
    output_file << endl;
    output_file << "作业\t到达时间\t服务时间\t开始时间\t结束时间" << endl;
    for (int i = 0; i < Njobs; i++)
    {
        output_file << jobs[i].getJobName() << "\t\t" << jobs[i].getComeTime() << "\t\t"
        << jobs[i].getServeTime() << "\t\t" << jobs[i].getOverTime() << "\t\t" << endl;
    }

    //最终输出
    return true;
}