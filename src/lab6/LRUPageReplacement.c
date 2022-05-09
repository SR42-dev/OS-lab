#include <stdio.h>

int main()
{
	int i, j, n, f, next, min, pf;
	int rs[32], m[32], flag[32], count[32];

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
		for(j = 0; j < f; j++) 
		{
		
			if (m[j] == rs[i])
			{
				flag[i] = 1;
				count[j] = next;
				next++;
			}
		}
		
		if(flag[i] == 0)
		{
			if(i < f)
			{
				m[i] = rs[i];
				count[i] = next;
				next++;
			}
			
			else
			{
				min = 0;
				
				for(j = 1; j < f; j++) if(count[min] > count[j]) min = j;
				
				m[min] = rs[i];
				count[min] = next;
				next++;
			}
			
			pf++; 
		}
		
		for(j = 0; j < f; j++) printf("\t %d", m[j]);
		printf("\n");
		
		if(flag[i] == 0) printf("PF number : %d", pf);
		printf("\n");
	}
	
	printf("the total number of page faults using LRU : %d\n", pf);

	return 0;
}
