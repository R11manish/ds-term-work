#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insert(struct Node **head, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void display(struct Node *head)
{
  if (head == NULL)
  {
    printf("Linked list is empty.\n");
    return;
  }

  struct Node *temp = head;
  printf("Linked list elements: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void removeDuplicates(struct Node **head)
{
  if (*head == NULL)
    return;

  struct Node *current = *head;
  struct Node *next_next;

  while (current->next != NULL)
  {
    if (current->data == current->next->data)
    {
      next_next = current->next->next;
      free(current->next);
      current->next = next_next;
    }
    else
    {
      current = current->next;
    }
  }
}

int main()
{
  struct Node *head = NULL;
  int choice;

  do
  {
    printf("Menu:\n");
    printf("1. Insert element into linked list\n");
    printf("2. Remove duplicate nodes\n");
    printf("3. Display linked list\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
      int data;
      printf("Enter the element to insert: ");
      scanf("%d", &data);
      insert(&head, data);
      printf("Element inserted into the linked list.\n");
      break;
    }
    case 2:
    {
      removeDuplicates(&head);
      printf("Duplicate nodes removed from the linked list.\n");
      break;
    }
    case 3:
    {
      display(head);
      break;
    }
    case 4:
    {
      printf("Exiting...\n");
      break;
    }
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }

    printf("\n");
  } while (choice != 4);

  return 0;
}
