#include <iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;

const long long size=10000000;
int a[size]={};

void recursion(int n)
{
    if(n==1)
        return;
    else{

        for(int i=0;i<n/2;i++)
            a[i]+=a[n-i-1];
        n=n/2;
        recursion(n);
    }

}
int main()
{
    long long head,tail,freq;
    int n=1024;
    int times=100;
    QueryPerformanceCounter((LARGE_INTEGER *)&freq);
    for(;n<=67108864;n*=2)
    {
        for(int i=0;i<n;i++)
        {
            a[i]=i;
        }
        long long total_time=0;
        for(int num=0;num<times;num++)
        {
            QueryPerformanceCounter((LARGE_INTEGER *)&head);
            recursion(n);
            QueryPerformanceCounter((LARGE_INTEGER *)&tail);
            total_time+=(tail-head);
        }

        cout<< (total_time)/times * 1000.0 / freq<<endl;


    }



    return 0;
}
