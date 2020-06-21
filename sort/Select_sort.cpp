#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void select_Sort(int a[], int len)
{
 
	int minindex, temp;
	for(int i = 0; i<len-1;i++)
	{
	    minindex = i;
	    for(int j = i+1; j<len; j++)
		{
		    if(a[j]<a[minindex])
				minindex = j;
		
		}
		temp = a[i];
		a[i] = a[minindex];
		a[minindex] = temp;
	}
}


int main()
{
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
        int n;
        cin>>n;
        int * data=new int [n+10];
        for(int i=0;i<=n-1;i++)
        {
                cin>>data[i];
        }
        clock_t start;
        start = clock();//开始时间
        select_Sort(data,n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=0;i<=n-1;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}