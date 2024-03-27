#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long head,tail,freq;
    int n=0;
    double times=100;
    QueryPerformanceCounter((LARGE_INTEGER *)&freq);
    for(;n<=1000;n+=100)
    {
        int **b=new int*[n];
        for(int i=0;i<n;i++)
        {
            b[i]=new int[n];
        }
        for(int i=0;i<n;i++)
        {

            for(int j=0;j<n;j++)
            {
                b[i][j]=i+j;
            }
        }//初始化b[i][j]

        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=i;
        }//初始化a


        int *sum=new int[n];
        long long total_time=0;
        for(int num=0;num<times;num++)
        {
            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            for(int i=0;i<n;i++)//平凡算法
            {
                sum[i]=0.0; //类型有关系吗？
                for(int j=0;j<n;j++)
                    sum[i]+=b[j][i]*a[j];
            }
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            total_time+=tail-head;
        }
        cout<< (total_time)/times * 1000.0 / freq<<endl;
    }
    return 0;
}
