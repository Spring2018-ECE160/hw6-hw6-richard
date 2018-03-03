#include <stdio.h>
#include <string.h>
//for some reason including stdlib to get rid of the compiler
//warnin for atof causes my data to be wrong.

//165 events in past 10 years
#define NUMEVENTS 200

#define FPATH "./data.csv"
#define MAXLEN 100000
#define MAXLINE 100000

//int loadData(*ptr_data, input);

struct EQinfo {

	char *time; //date and time
	double latitude;
	double longitude;
	double depth;
	double magnitude;
	int numStations;
	char *place;
};

int main()  {
	struct EQinfo tenyears[200];
	struct EQinfo *ptr_data = &tenyears
	FILE *input = fopen(FPATH, "r");
//	loadData(*ptr_data, input);
	char str[MAXLEN];
	char *temp;
	int i = 0;

	while(fgets(str, sizeof(str), input)){
        //load datetime
        temp = strtok(str, ",");
        tenyears[i].time = strdup(temp);

		//load latitude
		temp = strtok(NULL, ",");
        tenyears[i].latitude = atof(temp);

		//load longitude
		temp = strtok(NULL, ",");
        tenyears[i].longitude = atof(temp);

		//load depth
		temp = strtok(NULL, ",");
        tenyears[i].depth = atof(temp);

		//load magnitude
		temp = strtok(NULL, ",");
        tenyears[i].magnitude = atof(temp);

		//load number of stations
		temp = strtok(NULL, ","); //skip magType
		temp = strtok(NULL, ",");
        tenyears[i].numStations = atoi(temp);

		for(int i = 0; i < 5; i++) { //skip next 5 things
			temp = strtok(NULL, ",");
		}

		temp = strtok(NULL, ",");
        tenyears[i].place = strdup(temp);

		//load the rest into value, but toss it
		temp = strtok(NULL, " \n");

		i++;
	}

//	printf("%s\n", tenyears[0].place);

	return 0;
}
/*
int loadData(*ptr_data, input) {
	char str[MAXLEN];
	char *temp;
	int i = 0;
	while(fgets(str, sizeof(str), input)){
        //load datetime
        temp = strtok(str, ",");
        tenyears[i].time = strdup(temp);

		//load latitude
		temp = strtok(NULL, ",");
        tenyears[i].latitude = atof(temp);

		//load longitude
		temp = strtok(NULL, ",");
        tenyears[i].longitude = atof(temp);

		//load depth
		temp = strtok(NULL, ",");
        tenyears[i].depth = atof(temp);

		//load magnitude
		temp = strtok(NULL, ",");
        tenyears[i].magnitude = atof(temp);

		//load number of stations
		temp = strtok(NULL, ","); //skip magType
		temp = strtok(NULL, ",");
        tenyears[i].numStations = atoi(temp);

		for(int i = 0; i < 5; i++) { //skip next 5 things
			temp = strtok(NULL, ",");
		}

		temp = strtok(NULL, ",");
        tenyears[i].place = strdup(temp);

		//load the rest into value, but toss it
		temp = strtok(NULL, " \n");

		i++;
	}
}
*/


