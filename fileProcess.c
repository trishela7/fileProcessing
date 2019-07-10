#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* 
    PATRICIA SHATZ
*/


/* Purpose of this program:
	to get data from file name DATA.TXT 
	one line at a time and ouput 
	only the name, SSN, and grade 
	to file name RESULTS.TXT
*/	   


char getGrade(double x);

int main()
{
	char name[11];
	char ssn[12];
	char g;
	double t1,t2,t3,t4,t5;
	
	/* 
		declare a FILE * variable
	 */
	FILE * infile;
	FILE * outfile;

	/*
		open the file: 
		associating the variable with
		an actual file allows you to 
		open it in "read" mode
	*/
	infile = fopen("data.txt","r");
	if(infile == NULL)
	{
		printf("File does not exist\n");
		exit(0);
	}
	/*
		associating the variable with an
		actual file allows you to open it
		in "write" mode
	*/
	outfile = fopen("results.txt","w");
	
	fprintf(outfile,"List of Student grade\n*****************\n");
	
	/*
		using I/O in this loops allows you
		to read in data from infile and write 
		it to outfile
		*/
	while(fscanf(infile,"%10s %12s %lf %lf %lf %lf %lf"
	,name,ssn,&t1,&t2,&t3,&t4,&t5)!=EOF)
	{
		
		g = getGrade(0.15*t1 +0.15*t2 +0.4*t3 +0.1*t4 +0.2*t5);
		
		fprintf(outfile,"%-10s %12s %c \n",name,ssn,g);
	
	}
	printf("It is Done..\n");
	
	/* using flcose closes the files
	 */
	fclose(infile);
	fclose(outfile);
	
	return 0;
	
		
}

char getGrade(double x)
{
	
	if ( x >=90)
		return 'A';
	else if(x >=80)
		return 'B';
	else if(x >=70)
		return 'C';
	else if(x >=60)
		return 'D';
	else
		return 'F';
}










