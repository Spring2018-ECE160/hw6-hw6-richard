#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//165 events in past 10 years
#define NUMEVENTS 200

#define FPATH "/home/sysuser1604/Documents/Cooper/ECE160/hw6-hw6-richard/question5/data.csv"
#define MAXLEN 100000
#define MAXLINE 100000

struct EQinfo {

	char *time; //date and time
	double latitude;
	double longitude;
	double depth;
	double magnitude;
	int numStations;
	char *place;
};

int loadData(struct EQinfo ptr_data[], FILE *input);
int maxEQ(struct EQinfo ptr_data[], int numlines);
int hemiCalc(struct EQinfo ptr_data[], int numlines);
double averageDepth(struct EQinfo ptr_data[], int numlines);


int main()  {
	struct EQinfo tenyears[200];
	FILE *input = fopen(FPATH, "r");
	int numlines = loadData(tenyears, input);
	printf("Data on Magnitude 7 and larger earthquakes for the past 10 years: \n\n");
	maxEQ(tenyears, numlines);
	printf("\n");
	hemiCalc(tenyears, numlines);
	printf("\n");
	double avgDepth = averageDepth(tenyears, numlines); //function with a return value, just for variety
	printf("Average Depth of these earthquakes: %f\n", avgDepth);
	fclose(input);
	return 0;
}

int maxEQ(struct EQinfo ptr_data[], int numlines) {
	double max = 0;
	int maxloc[numlines];
	int numMax = 0;
	for(int i = 0; i < numlines; i++) {
		if(ptr_data[i].magnitude >= max) {
			max = ptr_data[i].magnitude;
			maxloc[numMax] = i;
			numMax++;
		}
	}
	printf("The Largest Earthquake(s) were: \n");
	for(int i = 0; i < numMax; i++) {
		 printf("\t%f located in %s on %s UTC\n", max, ptr_data[maxloc[i]].place, ptr_data[maxloc[i]].time);
	}
	printf("\n");
}

double averageDepth(struct EQinfo ptr_data[], int numlines) {
	double avgDepth = 0;	
	for(int i = 0; i < numlines; i++) {
		avgDepth += ptr_data[i].depth;
	}
	avgDepth /= (double)numlines;
	return avgDepth;
}

int hemiCalc(struct EQinfo ptr_data[], int numlines) {
	int northeast = 0, northwest = 0, southeast = 0, southwest = 0, equator = 0, pmeridian = 0, idl = 0;
	for(int i = 0; i < numlines; i++) {
		if(ptr_data[i].latitude > 0 && ptr_data[i].longitude > 0) {
			northeast++;
		}
		else if(ptr_data[i].latitude > 0 && ptr_data[i].longitude < 0) {
			northwest++;
		}
		else if(ptr_data[i].latitude < 0 && ptr_data[i].longitude > 0) {
			southeast++;
		}
		else if(ptr_data[i].latitude < 0 && ptr_data[i].longitude < 0) {
			southwest++;
		}		
		else if(ptr_data[i].latitude = 0) {
			equator++;
		}
		else if(ptr_data[i].longitude = 0) {
			pmeridian++;
		}
		else if(ptr_data[i].longitude = 180) {
			idl++;
		}	
	}
	printf("The number of Magnitude 7 and larger earthquakes in/on the: \n");
	printf("\tNorthern, Western hemisphere: %d\n", northwest);
	printf("\tNorthern, Eastern hemisphere: %d\n", northeast);
	printf("\tSouthern, Western hemisphere: %d\n", southwest);
	printf("\tSouthern, Eastern hemisphere: %d\n", southeast);
	printf("\tEquator: %d\n", equator);
	printf("\tPrime Meridian: %d\n", pmeridian);
	printf("\tInternational Date Line: %d\n", idl);
}

int loadData(struct EQinfo ptr_data[], FILE *input) {
	char str[MAXLEN];
	char *temp;
	int i = 0;
	int numlines = 0;
	while(fgets(str, sizeof(str), input)){
        //load datetime
        temp = strtok(str, ",");
        ptr_data[i].time = strdup(temp);

		//load latitude
		temp = strtok(NULL, ",");
        ptr_data[i].latitude = atof(temp);

		//load longitude
		temp = strtok(NULL, ",");
        ptr_data[i].longitude = atof(temp);

		//load depth
		temp = strtok(NULL, ",");
        ptr_data[i].depth = atof(temp);

		//load magnitude
		temp = strtok(NULL, ",");
        ptr_data[i].magnitude = atof(temp);

		//load number of stations
		temp = strtok(NULL, ","); //skip magType
		temp = strtok(NULL, ",");
        ptr_data[i].numStations = atoi(temp);

		for(int i = 0; i < 5; i++) { //skip next 5 things
			temp = strtok(NULL, ",");
		}

		temp = strtok(NULL, ",");
        ptr_data[i].place = strdup(temp);

		//load the rest into value, but toss it
		temp = strtok(NULL, " \n");

		i++;
	}
	numlines = i;
	return numlines;
}



