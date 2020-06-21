
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


void quick_Sort(int left, int right,int arr[])
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quick_Sort(left, i - 1, arr);//递归左边
	quick_Sort(i + 1, right, arr);//递归右边
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
        quick_Sort(1,n,data);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}