#include <stdio.h>
#include <math.h>

#define FILENAME "weather.txt"
#define NMBR_OF_MEAS 1440

void readReport();
void calcAverages();

#define FILENAME "weather.txt"
#define NMBR_OF_MEAS 1440

void readReport();
void calcAverages();
void calcStandardDev();

float tempBer[NMBR_OF_MEAS], tempZur[NMBR_OF_MEAS], tempGen[NMBR_OF_MEAS], tempBas[NMBR_OF_MEAS];
float humBer[NMBR_OF_MEAS], humZur[NMBR_OF_MEAS], humGen[NMBR_OF_MEAS], humBas[NMBR_OF_MEAS];
int measBer=0, measZur=0, measGen=0, measBas=0;
float averageTempBer=0, averageTempZur=0, averageTempGen=0, averageTempBas=0;
float averageHumBer=0, averageHumZur=0, averageHumGen=0, averageHumBas=0;
float stdDevTempBer=0, stdDevTempZur=0, stdDevTempGen=0, stdDevTempBas=0;
float stdDevHumBer=0, stdDevHumZur=0, stdDevHumGen=0, stdDevHumBas=0;

int main(){
	int i;
	for(i=0;i<NMBR_OF_MEAS-1;++i){
		tempBer[i]=tempZur[i]=tempGen[i]=tempBas[i]=-275;
		humBer[i]=humZur[i]=humGen[i]=humBas[i]=-275;
	}

	readReport();
	calcAverages();
	calcStandardDev();

	printf("Bern:\nAverage temperature: \t%.1f\t(stdDev: %.3f)\nAverage humidity:\t%.1f\t(stdDev: %.3f)\nEfficiency:\t\t%.0f%%\n",
			averageTempBer, stdDevTempBer, averageHumBer, stdDevHumBer, (float)measBer/NMBR_OF_MEAS*100);
	printf("\nZurich:\nAverage temperature:\t%.1f\t(stdDev: %.3f)\nAverage humidity:\t%.1f\t(stdDev: %.3f)\nEfficiency:\t\t%.0f%%\n",
			averageTempZur, stdDevTempZur, averageHumZur, stdDevHumZur, (float)measZur/NMBR_OF_MEAS*100);
	printf("\nGeneva:\nAverage temperature:\t%.1f\t(stdDev: %.3f)\nAverage humidity:\t%.1f\t(stdDev: %.3f)\nEfficiency:\t\t%.0f%%\n",
			averageTempGen, stdDevTempGen, averageHumGen, stdDevHumGen, (float)measGen/NMBR_OF_MEAS*100);
	printf("\nBasel:\nAverage temperature:\t%.1f\t(stdDev: %.3f)\nAverage humidity:\t%.1f\t(stdDev: %.3f)\nEfficiency:\t\t%.0f%%\n",
			averageTempBas, stdDevTempBas, averageHumBas, stdDevHumBas, (float)measBas/NMBR_OF_MEAS*100);

	return 0;
}

void readReport(){
	FILE *report = fopen(FILENAME, "r");
	int timestamp, nmbrOfMeas, location, iBer=0, iZur=0, iGen=0, iBas=0;
	enum locations {BERN=1, ZURICH, GENEVA, BASEL};

	fscanf(report, "%d %d", &timestamp, &nmbrOfMeas);
	while(!feof(report)){
		while(0<nmbrOfMeas--){
			fscanf(report, "%d", &location);
			switch(location){
				case BERN: fscanf(report, "%f %f", &tempBer[iBer], &humBer[iBer]);
									 ++iBer;
									 break;
				case ZURICH: fscanf(report, "%f %f", &tempZur[iZur], &humZur[iZur]);
										 ++iZur;
										 break;
				case GENEVA: fscanf(report, "%f %f", &tempGen[iGen], &humGen[iGen]);
										 ++iGen;
										 break;
				case BASEL: fscanf(report, "%f %f", &tempBas[iBas], &humBas[iBas]);
										++iBas;
										break;
				default: break;
			}
		}
		fscanf(report, "%d %d", &timestamp, &nmbrOfMeas);
	}
}

void calcAverages(){
	int i;
	for(i=0;tempBer[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		averageTempBer+=tempBer[i];
		averageHumBer+=humBer[i];
		++measBer;
	}
	averageTempBer=averageTempBer/measBer;
	averageHumBer=averageHumBer/measBer;

	for(i=0;tempZur[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		averageTempZur+=tempZur[i];
		averageHumZur+=humZur[i];
		++measZur;
	}
	averageTempZur=averageTempZur/measZur;
	averageHumZur=averageHumZur/measZur;

	for(i=0;tempGen[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		averageTempGen+=tempGen[i];
		averageHumGen+=humGen[i];
		++measGen;
	}
	averageTempGen=averageTempGen/measGen;
	averageHumGen=averageHumGen/measGen;

	for(i=0;tempBas[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		averageTempBas+=tempBas[i];
		averageHumBas+=humBas[i];
		++measBas;
	}
	averageTempBas=averageTempBas/measBas;
	averageHumBas=averageHumBas/measBas;
}

void calcStandardDev(){
	int i;
	for(i=0;tempBer[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		stdDevTempBer+=pow(tempBer[i]-averageTempBer,2);
		stdDevHumBer+=pow(humBer[i]-averageHumBer,2);
	}
	stdDevTempBer=sqrt(stdDevTempBer/measBer);
	stdDevHumBer=sqrt(stdDevHumBer/measBer);

	for(i=0;tempZur[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		stdDevTempZur+=pow(tempZur[i]-averageTempZur,2);
		stdDevHumZur+=pow(humZur[i]-averageHumZur,2);
	}
	stdDevTempZur=sqrt(stdDevTempZur/measZur);
	stdDevHumZur=sqrt(stdDevHumZur/measZur);

	for(i=0;tempGen[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		stdDevTempGen+=pow(tempGen[i]-averageTempGen,2);
		stdDevHumGen+=pow(humGen[i]-averageHumGen,2);
	}
	stdDevTempGen=sqrt(stdDevTempGen/measGen);
	stdDevHumGen=sqrt(stdDevHumGen/measGen);

	for(i=0;tempBas[i]>-274 && i<NMBR_OF_MEAS-1;++i){
		stdDevTempBas+=pow(tempBas[i]-averageTempBas,2);
		stdDevHumBas+=pow(humBas[i]-averageHumBas,2);
	}
	stdDevTempBas=sqrt(stdDevTempBas/measBas);
	stdDevHumBas=sqrt(stdDevHumBas/measBas);
}
