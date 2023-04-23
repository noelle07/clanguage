#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

struct antrianATM
{
  char nama[100];
  int umur;
  int prioritas;

  struct antrianATM *prev;
  struct antrianATM *next;
};

struct antrianATM *head, *tail, *cur, *newNode, *del = NULL;

int countData()
{
  if (head == NULL)
  {
    return 0;
  }
  else
  {
    int total = 0;
    struct antrianATM *cur = head;
    while (cur != NULL)
    {
      cur = cur->next;
      total++;
    }
    return total;
  }
}

bool isFull()
{
  return (countData() == MAX);
}

bool isEmpty()
{
  return (countData() == 0);
}

void enqueueData(char nama[], int umur, int prioritas)
{
  if (isFull())
  {
    printf("Antrian penuh\n");
  }
  else
  {
    newNode = (struct antrianATM *)malloc(sizeof(struct antrianATM));
    strncpy(newNode->nama, nama, 100);
    newNode->umur = umur;
    newNode->prioritas = prioritas;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL || prioritas < head->prioritas)
    {
      newNode->next = head;
      if (head != NULL)
      {
        head->prev = newNode;
      }
      else
      {
        tail = newNode;
      }
      head = newNode;
    }
    else
    {
      cur = head;
      while (cur->next != NULL && prioritas >= cur->next->prioritas)
      {
        cur = cur->next;
      }
      newNode->next = cur->next;
      newNode->prev = cur;
      if (cur->next != NULL)
      {
        cur->next->prev = newNode;
      }
      else
      {
        tail = newNode;
      }
      cur->next = newNode;
    }
  }
}

void dequeueData()
{
  if (isEmpty())
  {
    printf("Antrian kosong\n");
  }
  else
  {
    del = head;
    head = head->next;
    if (head != NULL)
    {
      head->prev = NULL;
    }
    else
    {
      tail = NULL;
    }
    del->next = NULL;
    free(del);
  }
}

void destroyData()
{
  if (isEmpty())
  {
    printf("Antrian kosong\n");
  }
  else
  {
    cur = head;
    while (cur != NULL)
    {
      del = cur;
      cur = cur->next;
      del->prev = NULL;
      del->next = NULL;
      free(del);
    }
    head = NULL;
    tail = NULL;
  }
}

void displayData()
{
  if (isEmpty())
  {
    printf("Data kosong\n");
  }
  else
  {
    printf("Jumlah antrian: %d\n", countData());
    cur = head;
    for (int i = 1; i <= MAX; i++)
    {
      if (cur != NULL)
      {
        printf("Antrian ke-%d : %s (%d th)\n", i, cur->nama, cur->umur);
        cur = cur->next;
      }
      else
      {
        printf("Antrian ke-%d : (kosong)\n", i);
      }
    }
    printf("\n");
  }
}

int main()
{
  enqueueData("Andi", 25, 3);
  enqueueData("Budi", 20, 2);
  enqueueData("Caca", 30, 1);
  enqueueData("Dodi", 35, 4);
  enqueueData("Euis", 27, 3);

  displayData();
  printf("\n");

  dequeueData();
  dequeueData();

  displayData();
  printf("\n");

  enqueueData("Fafa", 22, 1);
  enqueueData("Gaga", 28, 4);

  displayData();
  printf("\n");

  destroyData();

  return 0;
}

//priority queue double linked list
