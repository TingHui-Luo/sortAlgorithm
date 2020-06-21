#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void insertSort(int a[],  int length)
{
	for (int i = 1; i <= length; i++)
	{
		for (int j = i - 1; j >= 1 && a[j + 1] < a[j]; j--)
		{
			swap(a[j], a[j + 1]);
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
        insertSort(data,n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}