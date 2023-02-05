#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

bool lbbl(int n, vector<int> pl) // 判断是否为质数的函数
{
    int i = 1;
    while ((pl[i - 1]) * (pl[i - 1]) <= n) {
        if (n % (pl[i - 1]) == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int n = 3;
    int geshu;
    cin >> geshu;
    int geshu2 = int(geshu / 2);
    vector<int> pl = {2};
    // 计时模块
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    for (int z = 0; z < geshu2 - 1; z++) {
        if (lbbl(n, pl)) {
            pl.push_back(n);
            // cout << n <<endl;
        }
        n += 2;
    }
    // 计时模块
    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

    cout << "time = " << time << " s" << endl;                           // 输出时间（单位：ｓ）
    cout << "前" << geshu << "内共有 " << pl.size() << "个质数" << endl; // 输出共有的质数数量
    system("pause");                                                     // 防止闪退
    return 0;
}