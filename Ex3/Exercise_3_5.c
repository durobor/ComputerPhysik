#include <stdio.h>
#include <math.h>

int x;
int y;

int f(int _x, int _y){
	if(1>=_y) return _x;
	else return pow(10,_y-1)*_x+f(_x,_y-1);
}

int main(){
	while(0>=x||9<x||0>=y||9<y){
		printf("Enter two single digit numbers greater than zero.\n");
		printf("x = ");
		scanf("%d",&x);
		printf("y = ");
		scanf("%d",&y);
		if(0>=x||9<x||0>=y||9<y){
			printf("Don't be silly!\n");
			y=-1;
		}
		else printf("f(%d,%d) => %d\n",x,y,f(x,y));
	}
	
	return 0;
}
