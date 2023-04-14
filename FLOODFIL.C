#include<stdio.h>
#include<graphics.h>
#include<dos.h>

void Floodfill(x, y, old_color, new_color)
{
  if(getpixel(x, y) == old_color)
  {
    putpixel(x, y, new_color);
    Floodfill(x + 1, y, old_color, new_color);
    Floodfill(x, y + 1, old_color, new_color);
    Floodfill(x - 1, y, old_color, new_color);
    Floodfill(x, y - 1, old_color, new_color);
  }
}

void main()
{
  int x, y, r, gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

  printf("Enter the value for circle x and y : \n");
  scanf("%d%d", &x, &y);

  printf("Enter the radius for the circle : \n");
  scanf("%d", &r);

  circle(x, y, r);
  Floodfill(x, y, 0, 14);
  delay(5000);
  closegraph();
}