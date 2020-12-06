#ifndef ATTEMPER_ALGORITHM_BASE_H
#define ATTEMPER_ALGORITHM_BASE_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define LINE_MAX_LENGTH 1024
#define MAX 2147483647

/**
 * 按某种格式分割字符串
 * @param line 待分割字符串
 * @param pattern 分割的模式
 * @return 返回分割后的字符串集
 */
vector<string> stringToken(string line, string pattern);


#endif //ATTEMPER_ALGORITHM_BASE_H
