#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>

using namespace std;
 
void adjust_heap(int* a, int node, int size)
{
        int left = 2*node + 1;
        int right = 2*node + 2;
        int max = node;
        if( left < size && a[left] > a[max])
                max = left;
        if( right < size && a[right] > a[max])
                max = right;
        if(max != node)
        {
                swap( a[max], a[node]);
                adjust_heap(a, max, size);
        }
}
 
void heap_sort(int* a, int len)
{
        for(int i = len/2 -1; i >= 0; --i)
                adjust_heap(a, i, len);
 
        for(int i = len - 1; i >= 0; i--)
        {
                swap(a[0], a[i]);           // 将当前最大的放置到数组末尾
                adjust_heap(a, 0 , i);              // 将未完成排序的部分继续进行堆排序
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
        heap_sort(data,n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}