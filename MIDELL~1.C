#include <stdio.h>
#include <graphics.h>

void drawEllipse(int x, int y, int a, int b) {
   int gm = DETECT, gd, d1,d2, dx,dy;
     int x0 = 0, y0 = b;
   initgraph(&gm, &gd, "C:\\Turboc3\\bgi");


    d1 = (b*b) - (a*a*b) + (0.25*a*a);
    dx = 2*b*b*x0, dy = 2*a*a*y0;

   while (dx < dy) {
      putpixel(x+x0, y+y0, WHITE);
      putpixel(x-x0, y+y0, WHITE);
      putpixel(x+x0, y-y0, WHITE);
      putpixel(x-x0, y-y0, WHITE);

      if (d1 < 0) {
	 x0++;
	 dx += 2*b*b;
	 d1 += dx + (b*b);
      } else {
	 x0++;
	 y0--;
	 dx += 2*b*b;
	 dy -= 2*a*a;
	 d1 += dx - dy + (b*b);
      }
   }

    d2 = ((b*b)*(x0+0.5)*(x0+0.5)) + ((a*a)*(y0-1)*(y0-1)) - (a*a*b*b);

   while (y0 >= 0) {
      putpixel(x+x0, y+y0, WHITE);
      putpixel(x-x0, y+y0, WHITE);
      putpixel(x+x0, y-y0, WHITE);
      putpixel(x-x0, y-y0, WHITE);

      if (d2 > 0) {
         y0--;
         dy -= 2*a*a;
         d2 += (a*a) - dy;
      } else {
         y0--;
         x0++;
         dx += 2*b*b;
         dy -= 2*a*a;
         d2 += dx - dy + (a*a);
      }
   }

   getch();
   closegraph();
}

int main() {
   int x = 250, y = 250, a = 100, b = 50;
   drawEllipse(x, y, a, b);
   return 0;
}
