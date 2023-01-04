#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int ans = 0;//用来计数
    int nei;//多少以内
    cin>>nei;
	bool sushu[nei+1];//自然数从0开始，所以多记一个0，要+1

    LARGE_INTEGER t1,t2,tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

	for(int i = 0; i <= nei; i++)
	{
		sushu[i] = 1; //先全部置为真
	}
	sushu[0] = sushu[1] = 0;//1 0 不是素数
 
	for(int i = 2; i <= nei; i++) //从2开始往后筛
	{
		if(sushu[i])
		{
			for(int j = 2 * i; j <= nei; j += i)
			{
				sushu[j] = 0;
			}
		}
		if(sushu[i])
		{
			ans++;//如果是素数 就计数
		}
	}
    QueryPerformanceCounter(&t2);
    double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
    cout << "time = " << time << endl;  //输出时间（单位：ｓ）

	cout << ans;
    //system("pause");
	return 0;
}