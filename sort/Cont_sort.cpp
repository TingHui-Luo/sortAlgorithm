#include <iostream>
#include <stdio.h>
#include <time.h>
#include <algorithm>

using namespace std;
int maxn;
int *f;

void count_sort(int a[],int len)
{
         f=new int [maxn];
         for(int i=0;i<=maxn;i++) f[i]=0;
    for(int i=0;i<=len-1;i++)
    {
        f[a[i]]++;
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
                maxn=max(maxn,data[i]);
        }
        clock_t start;
 
        start = clock();//开始时间
        count_sort(data,n);
        
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=0;i<=maxn;i++)
        {
                if(f[i]==0) continue;
                for(int j=1;j<=f[i];j++)
                cout<<i<<" ";
        }
        return 0;
}
 
