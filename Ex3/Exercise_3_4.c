#include <stdio.h>

int d1;
int d2;
int m1;
int m2;
int y1;
int y2;

int main(){
	printf("Enter the first date (dd.mm.yy): ");
	scanf("%d.%d.%d", &d1, &m1, &y1);
	printf("Enter the second date (dd.mm.yy): ");
	scanf("%d.%d.%d", &d2, &m2, &y2);

	if(y1<y2){
		y1=y2;
		m1=m2;
		d1=d2;
	}
	else if(y1==y2){
		if(m1<m2){
			m1=m2;
			d1=d2;
		}
		else if(m1==m2){
			if(d1<d2){
				d1=d2;
			}
		}
	}

	printf("Date %d.%d.%d is the more recent one.\n", d1, m1, y1);

	return 0;
}
