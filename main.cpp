#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int endfunc(int e);
int main(){
    int gd,gm,rx=200,ry=200,x,y,d/*dirction*/,f=1/*Food eaten*/,dir=1/*direction*/;
   // srand(time(NULL));
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setfillstyle(1,1);//(style,color)
    x=200,y=200;

d=1;

delay(5000);
for(;;){

    setfillstyle(1,0);
        bar(0,0,640,480);
        setfillstyle(1,2);
   bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
   // food taken?
   if(x==rx && y==ry ){

        f=f+1;
    setfillstyle(1,0);
    bar(rx,ry,rx+10,ry+10);

    //make food
   do {
	rx = (1+rand()%630);
	ry = (1+rand()%470);
    }while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);
    rx=rx/10;
    rx=rx*10;
    ry=ry/10;
    ry=ry*10;
        setfillstyle(1,2);

          }
    bar(rx,ry,rx+10,ry+10);

    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
   else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
   else{d=0;}
    int n;

    switch(d){
    case 0:
      if(dir==1){x=x+10;}
      else if(dir==2){x=x-10;}
      else if(dir==3){ y=y-10;}
      else if(dir==4) {y=y+10;}
      else{d=0;}
        break;
    case 1:
           x=x+10;
           dir=1;
           break;
    case 2:
         x= x-10;
         dir=2;
          break;
    case 3:
        dir=3;
        y=y-10;
        break;
    case 4:
        dir=4;
       y= y+10;
        break;
    }
bar(x,y,x+10,y+10);
delay(100);
printf("%d     %d    %d   %d   \n",x,y,rx,ry);
if(x>=640 || x<=0|| y<=0 || y>=480){
    endfunc(f);
    break;
}
}
}
int endfunc(int e){
    setfillstyle(1,5);
    e=e-2;
    bar(0,0,640,470);
    system("cls");
    printf("You died outside the boundary!!!\n");
    printf("Your score is : %d\n", e);
    getch();
}
