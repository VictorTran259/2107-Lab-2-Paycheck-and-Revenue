//Victor Tran, 9/2/22, CIS 2107
//Lab 2 Revenue
//Write a C program called revenue to calculate the revenue from a sale based on the unit price and quantity of a product input by
//the user.
//• The discount rate is
//o 0% for the quantity purchased between 1 and 49 units.
//o 10% for the quantity purchased between 50 and 99 units.
//o 15% for the quantity purchased between 100 and 149 units.
//o 25% for the quantity purchased greater than or equal 150 units.
//• Catch any invalid inputs (Negative numbers or Zeroes, or invalid entry format), output a warning message and end the
//program.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double itemPrice, quantity, intPart, fractPart, cost, discount, discountAmount, total;

    printf("Welcome to \"TEMPLE\" store\n");
    printf("\n\tEnter item price: ");
    scanf("%lf", &itemPrice);

    //Throws an error message if the item price is negative or zero and terminates the program.
    if(itemPrice < 1) {
        printf("\n\tThis is not a valid item price.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        exit(1);
    }

    printf("\tEnter quantity: ");
    scanf("%lf", &quantity);
    fractPart = modf (quantity, &intPart);

    //Throws an error message if the quantity is negative, zero, or a decimal and terminates the program.
    if(quantity < 1 || fractPart != 0){
        printf("\n\tThis is not a valid quantity order.\n\tPlease run the program again\n\nThank You for using \"Temple\" store\n");
        exit(1);
    }

    cost = itemPrice * quantity;

    //Determines the discount amount based on the quantity.
    if(quantity <= 49) {
        discount = 0;
    }
    else if(quantity >= 50 && quantity <= 99) {
        discount = .10;
    }
    else if(quantity >= 100 && quantity <= 149) {
        discount = .15;
    }
    else if(quantity >= 150) {
        discount = .25;
    }
    discountAmount = cost * discount;
    discount *= 100;
    total = cost - discountAmount;

    printf("\n\tThe item price is: $%0.1lf", itemPrice);
    printf("\n\tThe order is: %d item(s)", (int)quantity);
    printf("\n\tThe cost is: $%0.1lf", cost);
    printf("\n\tThe discount is %0.1lf%%", discount);
    printf("\n\tThe discount amount is: $%0.1lf", discountAmount);
    printf("\n\tThe total is: $%0.1lf", total);

    printf("\n\nThank You for using \"Temple\" store\n");

    return 0;
}
