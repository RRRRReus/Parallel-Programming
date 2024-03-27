#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int main()
{
    long long head,tail,freq;
    int n=1024,sum1=0,sum2=0,sum=0;
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
            for(int i=0;i<n;i+=2)
            {
                    sum1+=a[i];
                    sum2+=a[i+1];
            }
            sum=sum1+sum2;
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            total_time+=(tail-head);
        }

        cout<< (total_time)/times * 1000.0 / freq<<endl;


    }



    return 0;
}

