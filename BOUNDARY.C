#include<stdio.h>
#include<graphics.h>
#include<dos.h>

void Boundaryfill(x, y, f, b)
{
  if(getpixel(x, y) != f || getpixel(x, y) != b)
  {
    putpixel(x, y, f);
    Boundaryfill(x + 1, y, f, b);
    Boundaryfill(x, y + 1, f, b);
    Boundaryfill(x - 1, y, f, b);
    Boundaryfill(x, y - 1, f, b);
  }
}

void main()
{
  int x, y, r, gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

  printf("Enter the value x, y and radius for the circle : \n");
  scanf("%d%d%d",&x, &y, &r);

  circle(x, y, r);
  Boundaryfill(x, y, 0, 14);
  getch();
  closegraph();
}