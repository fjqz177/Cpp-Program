#include <iostream>
#include<vector>
#include <windows.h>
using namespace std;

int main()
{
	int ans = 0;//用来计数
    int nei;//多少以内
	cout << "请问你要计算多少以内的质数个数：";
    cin >>nei;
	vector<int> sushu (nei+1,1);//自然数从0开始，所以多记一个0，要+1

	//计时模块
    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
	//计时模块

	sushu[0] = sushu[1] = 0;//1 0 不是素数
	for(int i = 3; i <= nei; i=i+2) //从2开始往后筛
	{
		if(sushu[i])
		{
			ans++;//如果是素数 就计数
			for(int j = 2 * i; j <= nei; j += i)
			{
				sushu[j] = 0;
			}
		}
	}

	//计时模块
    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
	//计时模块

	cout << nei << " 以内有 " << ans+1 << " 个质数" <<endl;//输出质数个数
	cout << "计算耗时 " << time << " 秒" << endl;//输出时间（单位：ｓ）
    system("pause");//防闪退
	return 0;
}