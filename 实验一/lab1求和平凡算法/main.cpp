#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long head,tail,freq;
    int n=524288;
    long long sum=0;
    int times=100;
    QueryPerformanceCounter((LARGE_INTEGER *)&freq);
    for(;n<=536870912;n*=2)
    {
        int* a=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=i;
        }
        long long total_time=0;
        for(int num=0;num<times;num++)
        {
            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            for(int i=0;i<n;i++)
            {
                sum+=a[i];
            }
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            total_time+=(tail-head);
        }

        cout<< (total_time)/times * 1000.0 / freq<<endl;

    }



    return 0;
}
