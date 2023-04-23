#include "stdio.h"
#include <unistd.h>
const int H = 6, W = 10;
char map[H + 1][W + 1] = {
    "##########",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "##########",
};
void printMap()
{
  for (int i = 0; i < H; i++)
  {
    printf("%s\n", map[i]);
  }
}
void floodFill(int y, int x)
{
  if (map[y][x] == ' ')
  {
    system("cls");
    usleep(250000);
    printMap();
    map[y][x] = 'O';
    floodFill(y + 1, x);
    floodFill(y - 1, x);
    floodFill(y, x + 1);
    floodFill(y, x - 1);
  }
}
int main()
{
  printMap();
  floodFill(1, 1);
  system("cls");
  printMap();
}
