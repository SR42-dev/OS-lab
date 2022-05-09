#include<stdio.h>
#include<string.h>

int main()
{
    int a[10],b[10],x[10];
    int i,j,smallest,count=0,time,n;
    int wt[10],tat[10],finish[10];
    double avg=0,tt=0,end;
    char pn[10][10];

    printf("Enter the number of process: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Process #, ArraivalTime,BurstTime: ");
        scanf("%s %d %d",pn[i],&a[i],&b[i]);
    }

    for(i = 0;i<n;i++)
    {
        x[i] = b[i];
    }
        b[9] = 9999;
        for(time=0;count!=n;time++)
        {
            smallest =9;
            for(i=0;i<n;i++)
            {
                if(a[i]<=time && b[i]<b[smallest] && b[i]>0)
                    smallest = i;
            }
            b[smallest]--;
            if(b[smallest] == 0)
            {
                count++;
                end = time + 1;
                finish[smallest] = end;
                wt[smallest] = end - a[smallest] - x[smallest];
                tat[smallest] = end - a[smallest];
            }

        }
         printf("\nProcess\t\tArraivalTime\tBurstTime\tWaitTime\tTurnAroundTime\tFinishing Time");
    printf("\n--------\t----------\t--------\t----------\t------------\t---------");

    for(i=0;i<n;i++)
    {
        printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%6d\t\t%6d\n",pn[i],a[i],b[i],wt[i],tat[i],finish[i]);
        avg = avg +wt[i];
        tt = tt + tat[i];
    }

    printf("\nTotal Waiting Time is: %f", (float)avg/n);
    printf("\nTotal Turn Around Time is: %f",(float)tt/n);
    return 0;
}
