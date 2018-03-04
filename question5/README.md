## Question 5

Find an interesting statistic and create a structure in C storing those statistics. Write 2 functions that does interesting analystics for those statistics. Be sure to print out these analytics.

For example, the top 25 snow storms in NYC can be stored in a structure containing the month, day, year and the number of inches it snowed. Two functions could be to find the average of the top snow storms and to sort the snowstorms starting with the most recent.

Note: You may hard code these statistics in a global or in your main.

Bonus (+5 points): Find an actual data file that you ingest with your program using functions like fopen from chapter7.

Compile Steps:

	gcc q5.c -o out5

Output:

	Data on Magnitude 7 and larger earthquakes for the past 10 years: 
	
	The Largest Earthquake(s) were: 
		9.100000 located in near the east coast of Honshu: Japan on 2011-03-11T05:46:24.120Z UTC
	
	The number of Magnitude 7 and larger earthquakes in/on the: 
		Northern, Western hemisphere: 23
		Northern, Eastern hemisphere: 51
		Southern, Western hemisphere: 35
		Southern, Eastern hemisphere: 56
		Equator: 0
		Prime Meridian: 0
		International Date Line: 0
	
	Average Depth of these earthquakes: 97.790648
	
	Average Number of Stations that detect these earthquakes: 300.703030



