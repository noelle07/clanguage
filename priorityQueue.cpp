#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

struct node
{
  char name[100];
  int age;
  int priority;
  struct node *next;
};

struct node *head = NULL;

void enqueue(char name[], int age, int priority)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  strncpy(new_node->name, name, 100);
  new_node->age = age;
  new_node->priority = priority;
  new_node->next = NULL;

  if (head == NULL || priority < head->priority)
  {
    new_node->next = head;
    head = new_node;
  }
  else
  {
    struct node *cur = head;
    while (cur->next != NULL && priority >= cur->next->priority)
    {
      cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
  }
}

void dequeue()
{
  if (head == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    struct node *temp = head;
    head = head->next;
    printf("Dequeued: %s\n", temp->name);
    free(temp);
  }
}

void display()
{
  if (head == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Priority Queue:\n");
    struct node *cur = head;
    while (cur != NULL)
    {
      printf("Name: %s, Age: %d, Priority: %d\n", cur->name, cur->age, cur->priority);
      cur = cur->next;
    }
    printf("\n");
  }
}

int main()
{
  enqueue("John", 30, 2);
  enqueue("Jane", 25, 1);
  enqueue("Mary", 40, 3);
  display();
  dequeue();
  display();
  enqueue("Bob", 35, 2);
  enqueue("Alice", 50, 4);
  enqueue("David", 45, 3);
  display();
  dequeue();
  dequeue();
  display();
  return 0;
}

//priority queue single linked list
