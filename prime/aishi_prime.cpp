#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
// ����ָ�� g++ -O3 aishi_prime.cpp -o aishi_prime.exe
int main() {
    int ans = 0; // ��������
    int nei;     // ��������
    cout << "������Ҫ����������ڵ�����������";
    cin >> nei;
    vector<bool> sushu(nei + 1, true); // ��Ȼ����0��ʼ�����Զ��һ��0��Ҫ+1

    // ��ʱģ��
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    sushu[0] = sushu[1] = false;             // 1 0 ��������
    for (int i = 3; i <= nei; i = i + 2) // ��2��ʼ����ɸ
    {
        if (sushu[i]) {
            ans++; // ��������� �ͼ���
            for (int j = 2 * i; j <= nei; j += i) {
                sushu[j] = false;
            }
        }
    }
    vector<bool>().swap(sushu); //�ͷ��ڴ�
    
    // ��ʱģ��
    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;

    cout << nei << " ������ " << ans + 1 << " ������" << endl; // �����������
    cout << "�����ʱ " << time << " ��" << endl;              // ���ʱ�䣨��λ����
    system("pause");                                           // ������
    return 0;
}