#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>

using namespace std;
 
void Merge(int *a, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	int i, j, k;
	
	for (i=0; i<n1; i++){
		L[i] = a[p+i];
	}
	for (j=0; j<n2; j++){
		R[j] = a[q+j+1];
	}
	L[n1] = 10000000;
	R[n2] = 10000000;
 
	for (i=0, j=0, k=p; k<=r; k++)
	{
		if (L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}
 
	delete []L;
	delete []R;
}
 
void Merge_Sort(int *a, int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		Merge_Sort(a, p, q);
		Merge_Sort(a, q+1, r);
		Merge(a, p, q, r);
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
        Merge_Sort(data,0,n-1);
        printf("%lf\n",(double)(clock() - start) / CLK_TCK);//结束时间 - 开始时间
        for(int i=1;i<=n;i++)
        {
                cout<<data[i]<<" ";
        }
        return 0;
}