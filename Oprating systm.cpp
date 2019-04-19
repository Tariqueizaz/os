#include<stdio.h>
#include<math.h> 
 
int main() 
{ 
      int m, l, total = 0, x, count = 0, quantum; 
      int wtime = 0, tat = 0, atime[10], btime[10], k[10]; 
      float avgwtime, avgtat;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &l); 
      x = l; 
      for(m = 0; m < l; m++) 
      {
            printf("\nEnter Details of Process[%d]\n", m + 1);
            printf("Arrival Time:\t");
            scanf("%d", &atime[m]);
            printf("Burst Time:\t");
            scanf("%d", &btime[m]); 
            k[m] = btime[m];
      } 

	if(l>=1)
	{
		quantum=10;
	}
	else
	{
		quantum=6;
	}
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, m = 0; x != 0;) 
      { 
            if(k[m] <= quantum && k[m] > 0) 
            { 
                  total = total + k[m]; 
                  k[m] = 0; 
                  count = 1; 
            } 
            else if(k[m] > 0) 
            { 
                  k[m] = k[m] - quantum; 
                  total = total + quantum; 
            } 
            if(k[m] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", m + 1, btime[m], total - atime[m], abs(total) - abs(atime[m])- abs(btime[m]));
                  wtime = abs(wtime + total - atime[m] - btime[m]); 
                  tat = tat + total - atime[m]; 
                  count = 0; 
            } 
            if(m == l - 1) 
            {
                  m = 0; 
            }
            else if(atime[m + 1] <= total) 
            {
                  m++;
            }
            else 
            {
                  m = 0;
            }
      } 
      avgwtime = wtime * 1.0 / l;
      avgtat = tat * 1.0 / l;
      printf("\n\nAverage Waiting Time:\t%f", avgwtime); 
      printf("\nAvg Turnaround Time:\t%f\n", avgtat); 
      return 0; 
}
