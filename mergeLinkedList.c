#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insert(struct Node **head, int elements[], int size)
{
  for (int i = 0; i < size; i++)
  {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = elements[i];
    newNode->next = *head;
    *head = newNode;
  }
}

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
  if (list1 == NULL)
    return list2;
  if (list2 == NULL)
    return list1;

  struct Node *mergedList = NULL;

  if (list1->data <= list2->data)
  {
    mergedList = list1;
    mergedList->next = mergeSortedLists(list1->next, list2);
  }
  else
  {
    mergedList = list2;
    mergedList->next = mergeSortedLists(list1, list2->next);
  }

  return mergedList;
}

void printList(struct Node *head)
{
  if (head == NULL)
  {
    printf("\nEmpty linked list\n");
    return;
  }

  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  struct Node *linkedList1 = NULL;
  struct Node *linkedList2 = NULL;
  struct Node *mergedList = NULL;
  int choice;

  do
  {
    printf("Menu:\n");
    printf("1. Insert elements into the first linked list\n");
    printf("2. Insert elements into the second linked list\n");
    printf("3. Merge the linked lists\n");
    printf("4. Print the merged list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
      int size;
      printf("Enter the number of elements to insert into the first linked list: ");
      scanf("%d", &size);
      int *elements = (int *)malloc(size * sizeof(int));
      printf("Enter the elements: ");
      for (int i = 0; i < size; i++)
      {
        scanf("%d", &elements[i]);
      }
      insert(&linkedList1, elements, size);
      free(elements);
      printf("Elements inserted into the first linked list.\n");
      break;
    }
    case 2:
    {
      int size;
      printf("Enter the number of elements to insert into the second linked list: ");
      scanf("%d", &size);
      int *elements = (int *)malloc(size * sizeof(int));
      printf("Enter the elements: ");
      for (int i = 0; i < size; i++)
      {
        scanf("%d", &elements[i]);
      }
      insert(&linkedList2, elements, size);
      free(elements);
      printf("Elements inserted into the second linked list.\n");
      break;
    }
    case 3:
    {
      mergedList = mergeSortedLists(linkedList1, linkedList2);
      printf("Lists merged successfully.\n");
      break;
    }
    case 4:
    {
      printf("Merged Linked List: ");
      printList(mergedList);
      break;
    }
    case 5:
    {
      printf("Exiting...\n");
      break;
    }
    default:
      printf("Invalid choice. Please try again.\n");
    }

    printf("\n");
  } while (choice != 5);

  return 0;
}