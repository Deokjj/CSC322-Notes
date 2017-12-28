//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define SUPER 'S'
#define QUITE 'Q'
#define MIAMI 'M'
#define AVERAGE 'A'
#define REAL 'R'
#define POOR 'P'
//-----------------------------------------------------------------------------
float computeTaxable(float income, float deduc);
char findGroup(float taxable);
float computeTax(float taxable, char group);
void displayOutput(float income, float deductions, float taxable, char group, float tax);
//-----------------------------------------------------------------------------
void inputHandler(float *income, float *deductions){
	float input;
	do{
		input = 0;
		printf("Enter next amount : ");
		scanf("%f", &input);
		if(input>0)
			*income += input;
		else if(input<0)
			*deductions += input;
	} while(input != 0);	
}
//-----------------------------------------------------------------------------	
int main(void) {
	float income = 0 , deductions = 0, taxable = 0, tax = 0;
	char taxGroup;

	inputHandler(&income, &deductions);
	taxable = computeTaxable( income, deductions );
	taxGroup = findGroup(taxable);
	tax = computeTax(taxable, taxGroup);
	
	displayOutput(income,deductions,taxable,taxGroup,tax);	
	return(EXIT_SUCCESS);                   
}
//-----------------------------------------------------------------------------
float computeTaxable(float income, float deduc) {
	float taxable = income + deduc;
	if(taxable>0)
		return taxable;
	else
		return 0;
}
//-----------------------------------------------------------------------------
char findGroup(float taxable){
	if(taxable >= 500000)
		return SUPER;
	else if(taxable >= 200000)
		return QUITE;
	else if(taxable >= 100000)
		return MIAMI;
	else if(taxable >= 50000)
		return AVERAGE;
	else if(taxable >= 20000)
		return REAL;
	else 
		return POOR;
}
//-----------------------------------------------------------------------------
float computeTax(float taxable, char group){
	float tax = 0;
	switch (group)
	{
		case SUPER:
		case QUITE:
			tax = taxable*0.25;
			break;
		case MIAMI:
			tax = taxable*0.1;
			break;
		case AVERAGE:
		case REAL:
			tax = taxable*0.03;
			break;
	}
	if(tax > 50000)
		return 50000;
	else 
		return tax;
}
//-----------------------------------------------------------------------------
void displayOutput(float income, float deductions, float taxable, char group, float tax) {
	printf("\nIncome         = $%.2f", income);
	printf("\nDeductions     = $%.2f", deductions);
	printf("\nTaxable Income = $%.2f", taxable);
	printf("\nTax group      = %c", group);
	printf("\nTax owed       = $%.2f\n", tax);
}
//-----------------------------------------------------------------------------
