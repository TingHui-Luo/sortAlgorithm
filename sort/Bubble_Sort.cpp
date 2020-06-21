#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void Bubble_Sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
                std::swap(arr[j],arr[j+1]);
        }
    }
}
int main()
{
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
        int n;
        cin>>n;
        int * data=new int [n+10];
        for(int i=1;i<=n;i++)
        {
                cin>>data[i];
        }
        clock_t start;
        start = clock();//开始时间
        Bubble_Sort(data,n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}