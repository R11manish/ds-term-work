#include <stdio.h>
#include <stdlib.h>

struct process
{
  int id;
  int burst_time;
  int arrival_time;
  int completion_time;
  struct process *next;
};

struct process *head = NULL;

void insert_process(int id, int burst_time, int arrival_time)
{
  struct process *new_process = malloc(sizeof(struct process));
  new_process->id = id;
  new_process->burst_time = burst_time;
  new_process->arrival_time = arrival_time;
  new_process->completion_time = -1;
  new_process->next = head;
  head = new_process;
}

void print_processes()
{
  struct process *current = head;
  while (current != NULL)
  {
    printf("ID: %d, Burst Time: %d, Arrival Time: %d, Completion Time: %d\n", current->id, current->burst_time, current->arrival_time, current->completion_time);
    current = current->next;
  }
}

void simulate_time_sharing()
{
  int time = 0;
  struct process *current = head;
  while (current != NULL)
  {
    if (current->arrival_time <= time)
    {
      time += current->burst_time;
      current->completion_time = time;
    }
    current = current->next;
  }
}

int main()
{
  int choice;
  int id, burst_time, arrival_time;

  while (1)
  {
    printf("1. Insert Process\n2. Print Processes\n3. Simulate Time Sharing\n4. Exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter process ID: ");
      scanf("%d", &id);
      printf("Enter process burst time: ");
      scanf("%d", &burst_time);
      printf("Enter process arrival time: ");
      scanf("%d", &arrival_time);
      insert_process(id, burst_time, arrival_time);
      break;

    case 2:
      print_processes();
      break;

    case 3:
      simulate_time_sharing();
      break;

    case 4:
      exit(0);
    }
    printf("\n");
  }

  return 0;
}