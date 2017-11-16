#include<stdio.h>
#include<conio.h>                //Select Cell
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#define K_UP 72
#define K_DOWN 80
#define K_LEFT 75
#define K_RIGHT 77
#define K_ESC  27
#define K_RET 13
#define K_SPC 32
#define siz 20
int curCell[20][20]={0},prevCell[20][20]={0};
void dselectCell(int x,int y);
void test();
void makeGrid();
void selectCell(int x,int y);
void putCell(int x ,int y)
{

	setcolor(YELLOW);
	rectangle(x,y,x+siz,y+siz);
	setfillstyle(SOLID_FILL,RED);
	floodfill(x+1,y+1,YELLOW);
	curCell[x/siz][y/siz]=1;

}
void delCell(int x,int y)
{
	setcolor(YELLOW);
	rectangle(x,y,x+siz,y+siz);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(x+1,y+1,YELLOW);
	curCell[x/siz][y/siz]=0;
}
int getN(int x,int y)
{       int n=0;
	n=n+prevCell[x-1][y-1];
	n=n+prevCell[x-1][y+1];
	n=n+prevCell[x-1][y];
	n=n+prevCell[x][y-1];
	n=n+prevCell[x][y+1];
	n=n+prevCell[x+1][y-1];
	n=n+prevCell[x+1][y];
	n=n+prevCell[x+1][y+1];
	return n;



}


void next()
{
	for(int i=1;i<19;i++)
	{
		for(int j=1;j<19;j++)
		{
			if(prevCell[i][j]==0)
			{

				if(getN(i,j)==3)
				{

					putCell(i*siz,j*siz);

				}
			}
			else
			{
				int num=getN(i,j);
				if(num<2||num>3)
				 {
					delCell(i*siz,j*siz);

				 }


			}
		}
	}
	for(i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			prevCell[i][j]=curCell[i][j];
		}
	}

 //	printf("niiiiceee");

}

void main()
{
	int gd=DETECT,gm,c=21,key,p,q;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

	// Set Background colour to GREEN
	setbkcolor(GREEN);

	rectangle(0,0,20*siz,20*siz);
	makeGrid();
 //	selectCell(1,1);
	while(1)
	{


			switch(getch())
			{
			    case K_UP:
				if((c%20)>0)
				{
					if(curCell[c/20][c%20]==0)
					dselectCell((c/20)*siz,(c%20)*siz);
					c--;
					if(curCell[c/20][c%20]==0)
					selectCell((c/20)*siz,(c%20)*siz);

				}
				break;
			    case K_DOWN:
				if((c%20)<19)
				{
					 if(curCell[c/20][c%20]==0)
					dselectCell((c/20)*siz,(c%20)*siz);
					c++;
					if(curCell[c/20][c%20]==0)
					selectCell((c/20)*siz,(c%20)*siz);
				}
				break;
			    case K_LEFT:
				if((c/20)>0)
				{
					if(curCell[c/20][c%20]==0)
					dselectCell((c/20)*siz,(c%20)*siz);
					c=c-20;
					if(curCell[c/20][c%20]==0)
					selectCell((c/20)*siz,(c%20)*siz);
				}
				break;
			    case K_RIGHT:
				if((c/20)<19)
				{       if(curCell[c/20][c%20]==0)
					dselectCell((c/20)*siz,(c%20)*siz);
					c=c+20;
					if(curCell[c/20][c%20]==0)
					selectCell((c/20)*siz,(c%20)*siz);
				}
				break;
			    case K_SPC:

				putCell((c/20)*siz,(c%20)*siz);

				break;
			    case K_RET:
				dselectCell((c/20)*siz,(c%20)*siz);
				for(p=0;p<20;p++)
				{
					for( q=0;q<20;q++)
					{
						prevCell[p][q]=curCell[p][q];
					}
				}


				while(1)
				{       int sw=getch();
					if(sw==K_SPC)
					next();
					else if(sw==K_ESC)
					goto exit1;
				}

			    case K_ESC:
			    break;


			}



	}
     exit1:
     closegraph();
}
void test()
{
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		       { printf("%d ",curCell[i][j]);}
		printf("\n");
	}
}
void makeGrid()
{
		for(int p=0;p<20;p++)
			{
				for(int q=0;q<20;q++)
				{
					setcolor(YELLOW);
					rectangle(p*siz,q*siz,p*siz+siz,q*siz+siz);

				}
			}
}
void selectCell(int x,int y)
{

	setcolor(YELLOW);
	rectangle(x,y,x+siz,y+siz);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(x+1,y+1,YELLOW);

}
void dselectCell(int x,int y)
{

	setcolor(YELLOW);
	rectangle(x,y,x+siz,y+siz);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(x+1,y+1,YELLOW);

}
