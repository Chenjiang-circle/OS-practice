#include "BASE.h"

vector<string> stringToken(string line, string pattern) {
    string::size_type pos;
    vector<string> result;
    line += pattern;//扩展字符串以方便操作
    int size = line.size();
    for (int i = 0; i < size; i++)
    {
        pos = line.find(pattern, i);
        if (pos < size)
        {
            string s = line.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}