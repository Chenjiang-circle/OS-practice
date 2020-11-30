#include "Executor.h"

int main() {
    int chose = Utils::choseAlgorithm();
    while (Executor::exe(chose) != 0)
    {
        chose = Utils::choseAlgorithm();
    }
    return 0;
}