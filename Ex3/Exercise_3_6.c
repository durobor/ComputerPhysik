#include <stdio.h>

int d;
int m;

int getWeekday(){
	if(3>m){
		return (31*(m-1)+d)%7;
	}
	else if(9>m){
		return (31+29+30*(m-3)+(m-2)/2+d)%7;
	}
	else{
		return (31+29+30*(m-3)+(m-1)/2+d)%7;
	}
}

void printWeekday(){
	switch(getWeekday()){
		case 1: printf("friday.\n");
						break;
		case 2: printf("saturday.\n");
						break;
		case 3: printf("sunday.\n");
						break;
		case 4: printf("monday.\n");
						break;
		case 5: printf("tuesday.\n");
						break;
		case 6: printf("wednesday.\n");
						break;
		default: printf("thursday.\n");
						 break;
	}
}

int main(){
	printf("Enter a valid date in the year 2016 (dd.mm): ");
	scanf("%d.%d",&d,&m);

	printf("The Date %d.%d.2016 was a ",d,m);
	printWeekday();

	return 0;
}
