#include <stdio.h>
#include <stdlib.h>
typedef int bool;

#define true 1
#define false 0

struct Node
{
  int data;
  struct Node *next;
};

struct Graph
{
  int V;
  struct Node **adjList;
};

void initGraph(struct Graph *graph, int V)
{
  graph->V = V;
  graph->adjList = (struct Node **)malloc(sizeof(struct Node *) * V);
  for (int i = 0; i < V; i++)
  {
    graph->adjList[i] = NULL;
  }
}

void addEdge(struct Graph *graph, int src, int dest)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = dest;
  newNode->next = graph->adjList[src];
  graph->adjList[src] = newNode;
}

void BFS(struct Graph *graph, int src)
{
  bool *visited = (bool *)malloc(sizeof(bool) * graph->V);
  for (int i = 0; i < graph->V; i++)
  {
    visited[i] = false;
  }

  // Create a queue and enqueue the source vertex
  struct Node *queue = NULL;
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = src;
  ptr->next = NULL;
  queue = ptr;

  visited[src] = true;

  while (queue != NULL)
  {
    // Dequeue the front element of the queue and print it
    ptr = queue;
    queue = queue->next;
    printf("%d ", ptr->data);

    // Iterate through all the adjacent vertices of the dequeued vertex
    struct Node *temp = graph->adjList[ptr->data];
    while (temp != NULL)
    {
      // If the adjacent vertex is not visited, then mark it visited and enqueue it
      if (!visited[temp->data])
      {
        visited[temp->data] = true;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = queue;
        queue = newNode;
      }
      temp = temp->next;
    }
  }
}

int main()
{
  int noOfVertices, noOfEdges, choice;
  int source, destination, startVertex;
  struct Graph *graph;

  while (1)
  {
    printf("\nBFS MENU");
    printf("\n 1. create a Graph");
    printf("\n 2. Traverse a Graph");
    printf("\n 3. Exit");
    printf("\n Enter the choice :");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter the number of vertices :");
      scanf("%d", &noOfVertices);
      printf("\n Enter the number of edges :");
      scanf("%d", &noOfEdges);
      graph = (struct Graph *)malloc(sizeof(struct Graph));
      initGraph(graph, noOfVertices);
      for (int i = 0; i < noOfEdges; i++)
      {
        printf("\n enter the souce vertices for edge :");
        scanf("%d", &source);
        printf("\n enter the destination vertices for edge :");
        scanf("%d", &destination);
        addEdge(graph, source, destination);
      }
      break;
    case 2:
      if (graph == NULL)
      {
        printf("First create the Graph");
        break;
      }
      printf("Enter the starting vertex for traversal :");
      scanf("%d", &startVertex);
      BFS(graph, startVertex);
      break;
    case 3:
      printf("\nExiting...");
      exit(0);
      break;
    default:
      printf("\nEntered the wrong option");
      break;
    }
  }
  return 0;
}