#include <iostream>
#include<vector>
#include <windows.h>
using namespace std;

int main()
{
	int ans = 0;//��������
    int nei;//��������
	cout << "������Ҫ����������ڵ�����������";
    cin >>nei;
	vector<int> sushu (nei+1,1);//��Ȼ����0��ʼ�����Զ��һ��0��Ҫ+1

	//��ʱģ��
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
	//��ʱģ��

	sushu[0] = sushu[1] = 0;//1 0 ��������
	for(int i = 3; i <= nei; i=i+2) //��2��ʼ����ɸ
	{
		if(sushu[i])
		{
			ans++;//��������� �ͼ���
			for(int j = 2 * i; j <= nei; j += i)
			{
				sushu[j] = 0;
			}
		}
	}

	//��ʱģ��
    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
	//��ʱģ��

	cout << nei << " ������ " << ans+1 << " ������" <<endl;//�����������
	cout << "�����ʱ " << time << " ��" << endl;//���ʱ�䣨��λ����
    system("pause");//������
	return 0;
}