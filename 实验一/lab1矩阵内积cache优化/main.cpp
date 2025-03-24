#include <iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;


int main()
{
    long long head,tail,freq;
    int n=0;
    double times=1;
    QueryPerformanceCounter((LARGE_INTEGER *)&freq);
    for(n=20000;n<=50000;n+=10000)
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
        }//³õÊ¼»¯b[i][j]

        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=i;
        }//³õÊ¼»¯a


        int *sum=new int[n];
        long long total_time=0;
        for(int num=0;num<times;num++)
        {
            QueryPerformanceCounter((LARGE_INTEGER *)&head);

            for(int i=0;i<n;i++)
                sum[i]=0.0;
            for(int j=0;j<n;j++)
                for(int i=0;i<n;i++)
                    sum[i]+=b[j][i]*a[j];

            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            total_time+=(tail-head);
        }
        cout<< (total_time)/times * 1000.0 / freq<<endl;

    }


    return 0;
}
