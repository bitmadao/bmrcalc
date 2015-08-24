/* main application file for bmrcalc */
#include <stdio.h>

int main(void) {
	/* defining variables */
	char gender ; /* Algorithm changes depending on gender (M/F. No third gender, sorry)*/
	int age ;
	double weight ;
	double height ;
	double bmrInKj ;
	double bmrInKcal ;
	
	/* fetching data */
	printf("bmrcalc can calculate your BasalMetabolicRate\nLet's start off with you telling us your gender, m(ale) or f(emale), and age (years):") ;
	
	FINDGENDER: /* in case of unrecognized gender, user must goto this marker */
	
	scanf("%c%d", &gender, &age) ;
	
	if(gender != 'm' && gender != 'f') {
		printf("bmrcalc did not recognize that gender, please use m/f (lowercase):") ;
		goto FINDGENDER ;
	}
	
	printf("Please provide your vitals, weight (in kg), then height (in cm, decimals are supported):") ;
	
	scanf("%lf%lf", &weight, &height) ;
	
	/* crunching numbers */
	if(gender == 'f') {
		bmrInKj = ((42 * weight) + (26.3 * height) - (20,7 * age) - 676.2) ; /* Female calculation */
	} else {
		bmrInKj = ((42 * weight) + (26.3 * height) - (20,7 * age) + 697.2 - 676.2) ; /* Male calculation */
	}
	
	bmrInKcal = bmrInKj / 4.2 ;
	
	/* presenting data */
	
	printf("The numbers have been crunched!\nYour BMR is %lfkcal (%lfkj).\nGood health to you!\n", bmrInKcal, bmrInKj) ;
	return 0 ;
}
