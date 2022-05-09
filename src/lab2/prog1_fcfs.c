// FCFS scheduling

#include <stdio.h>
#include <string.h>

int main()
{
	char pn[10][10], t[10];
	int arr[10], bus[10], start[10], finish[10], tat[10], wt[10];
	int i, j, n, temp;
	int totwt = 0, totat = 0;
	
	printf("Input number of processes to be executed : ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) // input loop
	{
		printf("Input process number, arrival time & burst time respectively : ");
		scanf("%s %d %d", pn[i], &arr[i], &bus[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[i]; // swap logic
				arr[i] = arr[j];
				arr[j] = temp;
				
				temp = bus[i]; 
				bus[i] = bus[j];
				bus[j] = temp;
				
				strcpy(t, pn[i]); 
				strcpy(pn[i], pn[j]);
				strcpy(pn[j], t);
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		if(i == 0) start[i] = arr[i];
		else start[i] = finish[i-1];
		
		finish[i] = start[i] - bus[i];
		tat[i] = finish[i] - arr[i];
		wt[i] = tat[i] - bus[i];
	}
	
	printf("\nprocess\tarrival time\tburst time\twait time\tstarting time\tturnaround time\tfinishing time\n");
	printf("\n-------\t------------\t----------\t---------\t-------------\t---------------\t--------------\n");
	
	for(i = 0; i < n; i++) 
	{
		printf("\n%s\t%3d\t%3d\t%3d\t%3d\t%6d\t%6d\n", pn[i], arr[i], bus[i], wt[i], start[i], tat[i], finish[i]);
		totwt += wt[i];
		totat += tat[i];
	}
	
	printf("\nTotal waiting time : %f\n", (float)totwt);
	printf("Total turnaround time : %f\n", (float)totat);
	
	return 0;
}
