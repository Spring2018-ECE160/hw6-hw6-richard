#include <stdio.h>
#include <string.h>
//for some reason including stdlib to get rid of the compiler
//warnin for atof causes my data to be wrong.

//165 events in past 10 years
#define NUMEVENTS 200

#define FPATH "./data.csv"
#define MAXLEN 100000
#define MAXLINE 100000

//the following line causes errors for some reason...
//int loadData(struct EQinfo ptr_data[], FILE *input);

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
	struct EQinfo *ptr_data = &tenyears;
	FILE *input = fopen(FPATH, "r");
	loadData(tenyears, input);
	char str[MAXLEN];
	char *temp;

	printf("%s\n", tenyears[0].place);

	return 0;
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



