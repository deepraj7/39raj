#include <stdio.h>
main()
{
  int n;

  printf("Enter the no. of processes: ");

  scanf("%d", &n);

  int id[n], bt[n], wt[n], tat[n], i, j, temp;

  for (i = 0; i < n; i++)

  {
    printf("Enter process %d id: ", i + 1);

    scanf("%d", &id[i]);

    printf("Enter process %d burst time: ", i + 1);

    scanf("%d", &bt[i]);
  }

  for (i = 0; i < n; i++)

  {
    for (j = i + 1; j < n; j++)

    {
      if (bt[i] > bt[j])

      {
        temp = bt[i];

        bt[i] = bt[j];

        bt[j] = temp;

        temp = id[i];

        id[i] = id[j];

        id[j] = temp;
      }
    }

    wt[i] = 0;
  }

  for (i = 0; i < n; i++)

  {
    for (j = 0; j < i; j++)

    {
      wt[i] = wt[i] + bt[j];
    }

    tat[i] = wt[i] + bt[i];
  }

  float avwt = 0, avtat = 0;

  printf("Process\tBT\tWT\tTAT\n");

  for (i = 0; i < n; i++)

  {
    printf("%d\t%d\t%d\t%d\n", id[i], bt[i], wt[i], tat[i]);

    avwt = avwt + wt[i];

    avtat = avtat + tat[i];
  }
  avwt = avwt / n;
  avtat = avtat / n;

  printf("Average Waiting Time: %f\n", avwt);

  printf("\nAverage Turnaround Time: %f", avtat);
}
