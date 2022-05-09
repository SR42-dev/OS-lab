// SRTF scheduling

#include <stdio.h>
#include <string.h>

int main()
{
	char pn[10][10];
	int a[10], b[10], x[10];
	int finish[10], tat[10], wt[10];
	int i, j, smallest, time, n, end;
	int count = 0, avg = 0, tt = 0;
	
	printf("Input number of processes to be executed : ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) // input loop
	{
		printf("Input process number, arrival time & burst time respectively : ");
		scanf("%s %d %d", pn[i], &a[i], &b[i]);
	}
	
	for(i = 0; i < n; i++) x[i] = b[i];
	b[9] = 9999;
	
	for(time = 0; count != 0; time++)
	{
		smallest = 9;
		for(i = 0; i < n; i++) if(a[i] <= time && b[i] <= b[smallest] && b[i] > 0) smallest = i; // finding smallest process
		b[smallest]--; // decrementing as in the next iteration smallest will be reinitialized back to 9
		
		if(b[smallest] == 0)
		{
			count++;
			end = time + 1;
			finish[smallest] = end;
			wt[smallest] = end - a[smallest] - x[smallest];
			tat[smallest] = end - a[smallest];
		}
	}
	
	printf("\nprocess\tarrival time\tburst time\twait time\tturnaround time\tfinishing time\n");
	printf("\n-------\t------------\t----------\t---------\t---------------\t--------------\n");
	
	for(i = 0; i < n; i++) 
	{
		printf("\n%s\t\t%3d\t\t%3d\t\t%3d\t\t%6d\t\t%6d\n", pn[i], a[i], b[i], wt[i], tat[i], finish[i]);
		avg += wt[i];
		tt += tat[i];
	}
	
	printf("\nTotal waiting time : %f\n", (float)avg/n);
	printf("Total turnaround time : %f\n", (float)tt/n);
	
	return 0;
}
