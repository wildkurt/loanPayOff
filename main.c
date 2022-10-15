#include <stdio.h>
#include <math.h>

/**Loan formula: N=-[(log(1-((i*A)/P))]/log(1+i)
 * N is number of payments
 * i is the interest rate
 * A is the amount owed
 * P is the size of each payment*/

float calculateNumberOfMonths(double interestrate, double amountowed, double paymentAmount){
    double calc1 = 0.0, calc2 = 0.0, calc3 = 0.0, calc4 = 0.0, calc5 = 0.0, calc6 = 0.0,
    calc7 = 0.0, calc8 = 0.0;
    interestrate = interestrate / 12;
    // A * i
    calc1 = amountowed * interestrate;
    // (A * i)/P
    calc2 = calc1/paymentAmount;
    // 1 - (i * A) / P
    calc3 = 1 - calc2;
    //log(1 - (i * A) / P)
    if(calc3 < 0){
        return 0;
    }
    calc4 = log(calc3);
    // 1 + i
    calc5 = 1 + interestrate;
    // log(1 + i)
    calc6 = log(calc5);
    // -log(1 - (i * A) / P)
    calc7 = -1 * calc4;
    // -log(1 - (i * A) / P)/log(1 + i)
    calc8 = calc7 / calc6;
   return calc8;
}
int main() {
    double interestrate = 0.0, numberofpayments = 0.0, amountowed = 0.0, paymentAmount = 0.0;
    printf("This program will give the number of months and years it will take to pay a loan off.\n");
    printf("Do not input any special characters suck as \"$\". Enter the interest without the \"%%\" symbol\n");
    printf("Input the loan amount: ");
    scanf("%lf", &amountowed);
    printf("Input the annual interest rate: ");
    scanf("%lf", &interestrate);
    printf("Input the monthly payment: ");
    scanf("%lf", &paymentAmount);

    interestrate = interestrate/100.0;

    while(paymentAmount != 0) {
        numberofpayments = calculateNumberOfMonths(interestrate, amountowed, paymentAmount);
        if(numberofpayments == 0){
            printf("Please input a higher payment amount\n");
            scanf("%lf",&paymentAmount);
        }
        else{
            printf("The number of months is: %f\n", numberofpayments);
            printf("The number of years is: %f\n", numberofpayments / 12);
            printf("Please enter a different monthly payment amount or enter 0 to quit: ");
            scanf("%lf",&paymentAmount);
        }
    }
    printf("Thank you for using the program, good bye\n");
    return 0;
}
