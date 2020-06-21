#include<stdio.h>
#include<algorithm>
#include<vector>
#include <iostream>
#include <time.h>
using namespace std;

const int bucket_num = 10;    //桶的数量
int interval = 0;    //桶的容量
const long long maxn = 1e6;        //数字的最大值
vector<int>buckets[bucket_num];    //每个桶
 int n, arr[maxn];
void Bucket_Sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        buckets[arr[i] / interval].push_back(arr[i]);
    for (int i = 0; i < bucket_num; i++)  if (buckets[i].size())
        sort(buckets[i].begin(), buckets[i].end());
  
}

int main()
{
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
   
    cin>>n;
    interval=(n/bucket_num)+1;   
    for (int i = 0; i < n; i++)  cin>>arr[i];
 
    clock_t start;
        start = clock();//开始时间
    Bucket_Sort(arr, n);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
          for (int i = 0; i < bucket_num; i++)  if (buckets[i].size())
        for (int j = 0; j < buckets[i].size(); j++)
            printf("%d ", buckets[i][j]);
    printf("\n");
    return 0;
}
