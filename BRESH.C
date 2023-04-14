#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

void main()
{
  int i, j = 0, gd = DETECT, gm;
  int dx, dy, x1, x2, y1, y2, x, y, e;

  initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

  printf("Enter the four coordinates :\n");
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);

  e = 2 * dy - dx;
  x =  x1;
  y = y1;

  i = 1;
  do{
    putpixel(x, y, 15);
    while(e >= 0)
    {
      y = y + 1;
      e = e - 2 * dx;
    }

    x = x + 1;
    e = e + 2 * dy;
    i = i + 1;
  }
  while(i <= dx);

  getch();
  closegraph();

}