#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

bool lbbl(int n, vector<int> pl) // �ж��Ƿ�Ϊ�����ĺ���
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
    // ��ʱģ��
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
    // ��ʱģ��
    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

    cout << "time = " << time << " s" << endl;                           // ���ʱ�䣨��λ����
    cout << "ǰ" << geshu << "�ڹ��� " << pl.size() << "������" << endl; // ������е���������
    system("pause");                                                     // ��ֹ����
    return 0;
}