/*
64.用ellipse和rectangle画图

题目：利用ellipse and rectangle 画图（在Turbo C中实现）。

程序分析：无。
*/

#include "stdio.h"
#include "graphics.h"
#include "conio.h"

main()
{
  int driver=VGA,mode=VGAHI;
  int i,num=15,top=50;
  int left=20,right=50;
  initgraph(&driver,&mode,"");
  for(i=0;i<num;i++)
  {
    ellipse(250,250,0,360,right,left);
    ellipse(250,250,0,360,20,top);
    rectangle(20-2*i,20-2*i,10*(i+2),10*(i+2));
    right+=5;
    left+=5;
    top+=10;
  }
  getch();
}
