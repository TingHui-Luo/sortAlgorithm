#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


void shell_Sort(int a[],int len)
{
    int insertNum = 0;int INCRGAP=3;
    unsigned gap = len/INCRGAP + 1; 
    while(gap) 
    {
        for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];
            unsigned j = i;
            while (j >= gap && insertNum < a[j-gap])//寻找插入位置
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap/INCRGAP;
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
        shell_Sort(data,n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}