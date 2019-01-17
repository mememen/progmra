/*
 ============================================================================
 Name        : DDeVotoTestScoreStats.c
 Author      : Dominic De Voto
 Version     :
 Copyright   :
 Description : Returns various statistics related to inputted scores
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	char buffer[BUFSIZ];
	float score;
	float min;
	float max;
	float avg;
	float standev;
	float count;
	float sum;
	float sumsquared;

	printf("Please enter one score per line. Press Enter to exit.\n");
	fgets(buffer, BUFSIZ, stdin);
	score = atof(buffer);
	min = score;
	if (score > 0)
		count++;

	do {

		fgets(buffer, BUFSIZ, stdin);
		score = atof(buffer);

		if (score == 0)
			break;
		else
		{
			if (score < min)
				min = score;
			if (score > max)
				max = score;

			count++;
			sum += score;
			sumsquared += (sum * sum);
			avg = sum / count;
			standev = sqrt((sumsquared - ((sum * sum) / count)) / count);
		}

	} while (score != 0);


	printf("%i", (int) count);
	printf("\t");

	printf("%f", min);
	printf("\t");

	printf("%f", max);
	printf("\t");

	printf("%.2f", avg);
	printf("\t");

	printf("%.2f", standev);
	printf("\n");
}
