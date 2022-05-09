#include <stdio.h>

int main()
{
	int i, j, k, f, n;
	int pf = 0, count = 0;
	int rs[25], m[10];

	printf("input the length of the reference string : ");
	scanf("%d", &n);
	
	printf("input the reference integer array : ");
	for(i = 0; i < n; i++) scanf("%d", &rs[i]);
	
	printf("input the number of frames : ");
	scanf("%d", &f);
	
	for(i = 0; i < f; i++) m[i] = -1;
	
	printf("page replacement process : \n");
	for(i = 0; i < n; i++)
	{
		for(k = 0; k < f; k++) if (m[k] == rs[i]) break;
		
		if(k == f) 
		{
			m[count++] = rs[i];
			pf++;
		}
		
		for(j = 0; j < f; j++) printf("\t %d", m[j]);
		printf("\t");
		
		if(k == f) printf("PF number : %d", pf);
		printf("\n");
		
		if(count == f) count = 0;
	}
	
	printf("the total number of page faults using FIFO : %d\n", pf);

	return 0;
}
