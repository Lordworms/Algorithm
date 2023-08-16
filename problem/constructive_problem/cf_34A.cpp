#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
 
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[2101];
        int ii,jj;
        int cha;
        int min = 100000;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(i!=1)
            {
                cha = fabs(a[i] - a[i-1]);
                if(min > cha)
                {
                    min  = cha;
                    ii = i-1;
                    jj = i;
                }
            }
 
        }
        cha = fabs(a[1] - a[n]);
        if(min > cha)
        {
            min  = cha;
            ii = n;
            jj = 1;
        }
        printf("%d %d\n",ii,jj);
    }
    return 0;
}