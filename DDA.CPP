#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void main(){
  int gd = DETECT, gm, x1, y1, x2, y2, dx, dy ,len, x, y, i;
  initgraph(&gd,&gm,"C:\\Turboc3\\bgi");

  printf("Enter the four coordinate : ");
  scanf("%d%d%d%d",&x1 ,&y1, &x2, &y2);

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);

  if(dx >= dy){
    len = dx;
  }
  else{
    len = dy;
  }

  dx = (x2 - x1)/len;
  dy = (y2 - y1)/len;
  x = x1 + 0.5;
  y = y1 + 0.5;

 i = 1;
  while(i <= len){
  putpixel(x,y,15);
    x = x + dx;
    y = y + dy;
    i++;
    delay(100);
  }

  getch();
  closegraph();
}