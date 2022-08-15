#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
int main()
{
	int h, m, s, l;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char*)"");
	for(h = 0;; h++)//This loop controls the hour hand needle of the clock
	{
		line(getmaxx()/2, getmaxy()/2, 120*sin(3.14/30*h*5)+getmaxx()/2, -120*cos(3.14/30*h*5)+getmaxy()/2);
		for(m = 0; m < 60; m++)//This loop controls the minute hand needle of the clock
			{
				for(s = 0; s < 60;s++)//This loop controls the second hand needle of the clock
					{
						cleardevice();
						circle(getmaxx()/2, getmaxy()/2, 210);//These two circles will be the border
						circle(getmaxx()/2, getmaxy()/2, 200);//of our clock
						circle(getmaxx()/2, getmaxy()/2, 3);
						for(l = 0; l < 60; l++)//This loop will create graduations of our clock
						{	if(l%5==0)
								//The graduation lines which lie in positions that are multiple of 5 are also the hour position 
								//so we will make those graduations a bit bigger than the other graduation lines same like how it is in real life clock
								line( 177*sin(3.14/30*l)+getmaxx()/2, -177*cos(3.14/30*l)+getmaxy()/2, 190*sin(3.14/30*l)+getmaxx()/2, -190*cos(3.14/30*l)+getmaxy()/2);
							else
								line( 187*sin(3.14/30*l)+getmaxx()/2, -187*cos(3.14/30*l)+getmaxy()/2, 190*sin(3.14/30*l)+getmaxx()/2, -190*cos(3.14/30*l)+getmaxy()/2);
						}
						//This is the needle for second switch
						line(getmaxx()/2, getmaxy()/2, 170*sin(3.14/30*s)+getmaxx()/2, -170*cos(3.14/30*s)+getmaxy()/2);
						//This is the needle for minute switch
						line(getmaxx()/2, getmaxy()/2, 150*sin(3.14/30*m)+getmaxx()/2, -150*cos(3.14/30*m)+getmaxy()/2);
						//This is the needle for hour switch
						line(getmaxx()/2, getmaxy()/2, 120*sin(3.14/30*h*5)+getmaxx()/2, -120*cos(3.14/30*h*5)+getmaxy()/2);
						delay(1000);//This will suspend or delay our code for 1 sec because we want our second hand needle to move in every 1 second.
					}
			}
		//We don't have any terminating condition for our hour loop cause I want the clock to keep running until the user terminates the program. For that
		if(h == 11)//w will have to reach same point in clock after 12 hr. So we set the hour to -1 which will become 0 after going in the increment part of that for loop of h
			h=-1;
	}
	getch();
	closegraph();
	return 0;
}
/*If you want to know about that trigonometric formula part then it's a formula that I came up after doing some paper maths:
We know that inorder to draw we need the co-ordinates of two end points of the line. For the hour, minute and second hand needle
one endpoint is always fixed i.e. the center of the circle or the center of clock. In our case the center of clock lies in the middle
of the screen. So the other end point is given by the formula:
x = r*sin(pi/30*i) + getmaxx()/2;
y  = -r*cos(pi/30*i) + getmaxy()/2;
where r is radius of circle and i is any integer 0,1 ,2, 3, 4....
In our case total angle of circle is 2pi. So our 'i' will go upto 60 since pi/30*60=2pi
*/
