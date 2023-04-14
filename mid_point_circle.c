#include <stdio.h>
#include <graphics.h>

void drawCircle(int x0, int y0, int radius)
{
    int x = radius, y = 0;
    int decisionOver2 = 1 - x;

    while (y <= x)
    {
        putpixel(x + x0, y + y0, YELLOW);
        putpixel(y + x0, x + y0, YELLOW);
        putpixel(-x + x0, y + y0, YELLOW);
        putpixel(-y + x0, x + y0, YELLOW);
        putpixel(-x + x0, -y + y0, YELLOW);
        putpixel(-y + x0, -x + y0, YELLOW);
        putpixel(x + x0, -y + y0, YELLOW);
        putpixel(y + x0, -x + y0, YELLOW);
        y++;

        if (decisionOver2 <= 0)
        {
            decisionOver2 += 2 * y + 1;
        }
        else
        {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 250, y0 = 250, radius = 100;
    drawCircle(x0, y0, radius);

    getch();
    closegraph();
    return 0;
}
