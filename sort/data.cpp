#include <iostream>
#include <stdio.h>
#include <ctime> 
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
        freopen("1.in","r",stdin);
        freopen("data.in","w",stdout);
        int n;
        cin>>n;
        cout<<n<<endl;
        srand(time(NULL));
        for(int i=1;i<=n;i++)
        cout<<rand()<<" ";
        return 0;
}
