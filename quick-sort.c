#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

int partition(char arr[], int low, int high)
{
  char pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(char arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(char arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

void printMenu()
{
  printf("\nCharacter Sorting Menu:\n");
  printf("1. Sort characters\n");
  printf("2. Exit\n");
}

int main()
{
  char sequence[100];
  int choice;

  while (1)
  {
    printMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter a sequence of characters: ");
      scanf(" %[^\n]s", sequence);

      int length = strlen(sequence);
      quickSort(sequence, 0, length - 1);

      printf("Sorted sequence: ");
      printArray(sequence, length);
      break;

    case 2:
      printf("Exiting...\n");
      exit(0);

    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
