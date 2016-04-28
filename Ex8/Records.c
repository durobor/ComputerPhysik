#include <stdio.h>

#define NAMEL 30
#define MAGIC_ARRAY_LENGTH 7
#define DATA_FILE "records.txt"

typedef struct{
	unsigned int date;
	char firstname[NAMEL];
	char lastname[NAMEL];
	unsigned int year;
	char nation[NAMEL];
	float time;
	float wind;
}record;

void readFromRecordList(FILE*, record*);
void printRecords(record*, int);
void printRecordOfYoungestPerson(record*);
void calculateTailWindAdvantage(record*);

int main(){
	record records[MAGIC_ARRAY_LENGTH];
	FILE *file = fopen(DATA_FILE, "r");
	readFromRecordList(file, records);
	printRecords(records, MAGIC_ARRAY_LENGTH);
	printRecordOfYoungestPerson(records);
	calculateTailWindAdvantage(records);

	return 0;
}

void readFromRecordList(FILE* file, record* records){
	int i;
	for(i=0;i<MAGIC_ARRAY_LENGTH;++i){
		fscanf(file, "%du", &(records[i].date));
		char c;
		int indx=0;
		fscanf(file, "%c", &c);
		while(' '==c || '\t'==c) fscanf(file, "%c", &c);
		while(' '!=c && '\t'!=c){
			*((records[i].firstname)+indx++)=c;
			fscanf(file, "%c", &c);
		}
		*(records[i].firstname+indx++)='\0';
		while(' '==c || '\t'==c) fscanf(file, "%c", &c);
		indx=0;
		while(' '!=c && '\t'!=c){
			*(records[i].lastname+indx++)=c;
			fscanf(file, "%c", &c);
		}
		*(records[i].lastname+indx++)='\0';
		fscanf(file, "%du", &(records[i].year));
		indx=0;
		while(' '==c || '\t'==c) fscanf(file, "%c", &c);
		while(' '!=c && '\t'!=c){
			*(records[i].nation+indx++)=c;
			fscanf(file, "%c", &c);
		}
		*(records[i].nation+indx++)='\0';
		fscanf(file, "%f", &(records[i].time));
		fscanf(file, "%f", &(records[i].wind));
	}
}

void printRecords(record* records, int arrLength){
	int i;
	for(i=0;i<arrLength;++i){
		printf("%du\n", records[i].date);
		printf("%s\n", records[i].firstname);
		printf("%s\n", records[i].lastname);
		printf("%du\n", records[i].year);
		printf("%s\n", records[i].nation);
		printf("%.2f\n", records[i].time);
		printf("%.2f\n", records[i].wind);
		printf("\n");
	}
}

void printRecordOfYoungestPerson(record* records){
	int i, indx, age, youngest=records[0].date-records[0].year;
	for(i=0;i<MAGIC_ARRAY_LENGTH;++i){
		age=records[i].date-records[i].year;
		if(youngest>age){
			youngest=age;
			indx=i;
		}
	}
	printf("Youngest record holder:\n");
	printRecords((records+indx), 1);
}

void calculateTailWindAdvantage(record* records){
	int i, fastest;
	float tailWindSpeedBuff[MAGIC_ARRAY_LENGTH], speed[MAGIC_ARRAY_LENGTH];
	for(i=0; i<MAGIC_ARRAY_LENGTH;++i){
		speed[i]=100./records[i].time;
		tailWindSpeedBuff[i]=0.1*records[i].wind;
	}
	for(i=0; i<MAGIC_ARRAY_LENGTH;++i){
		printf("Speed measured: %.3fm/s\n", speed[i]);
		printf("Speed corrected: %.3fm/s\n\n", speed[i]-tailWindSpeedBuff[i]);
	}
}
