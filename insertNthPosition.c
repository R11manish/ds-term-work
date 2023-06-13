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

void insertNth(struct Node **head, int data, int position)
{
  if (*head == NULL)
  {
    printf("Linked list is empty. Cannot insert at the specified position.\n");
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  struct Node *temp = *head;
  int count = 1;

  while (temp != NULL && count < position)
  {
    temp = temp->next;
    count++;
  }

  if (temp == NULL)
  {
    printf("Invalid position. Cannot insert at the specified position.\n");
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;

  printf("Node inserted successfully.\n");
}

int main()
{
  struct Node *head = NULL;
  int choice;

  do
  {
    printf("Menu:\n");
    printf("1. Insert element into linked list\n");
    printf("2. Insert node after a specified node\n");
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
      int data, position;
      printf("Enter the element to insert: ");
      scanf("%d", &data);
      printf("Enter the position after which to insert the node: ");
      scanf("%d", &position);
      insertNth(&head, data, position);
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
