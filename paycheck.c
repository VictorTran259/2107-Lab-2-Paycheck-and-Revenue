//Victor Tran, 9/2/22, CIS 2107
//Lab 2 Revenue
//Write a C program called paycheck to calculate the paycheck for a Temple employee based on the hourlySalary, weeklyTime
//(working for maximum 40 hours) and overtime (working for more than 40 hours).
//• If the employee works for 40 hours and less, then there is no overtime, and the NetPay = weekly time * hourly salary.
//• If the employee works for more than 40 hours, let’s say 50 hours, then her
//NetPay = 40 hours*regularPay + 10 hours* overtime. OR
//NetPay = 40 hours*regularPay + 10 hours* (1.5 * regular pay).
//• Where the overtime =. 1.5 * regular pay
//• Catch any invalid inputs (Negative numbers or Zeroes, or invalid format for an entry), output a warning message and end
//the program.
//• Be consistent, the following output message should be displayed for all employees, whether they had overtime or not.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double employeeNumber, intPart, fractPart, hourlySalary, weeklyTime, regularPay, overtimePay, netPay;

    printf("Welcome to \"TEMPLE HUMAN RESOURCES\"\n\n");
    printf("\tEnter Employee Number: ");
    scanf("%lf", &employeeNumber);
    fractPart = modf (employeeNumber, &intPart);

    //Throw error message if the employee number is negative, zero, or a decimal and terminates the program.
    if(employeeNumber < 1 || fractPart != 0) {
        printf("\n\tThis is not a valid Employee Number.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    printf("\tEnter Hourly Salary: ");
    scanf("%lf", &hourlySalary);

    //Throws error message if the hourly salary is negative or zero and terminates the program.
    if(hourlySalary < 1) {
        printf("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    printf("\tEnter Weekly Time: ");
    scanf("%lf", &weeklyTime);

    //Throws error message if the weekly time is negative or zero and terminates the program.
    if(weeklyTime < 1) {
        printf("\n\tThis is not a weekly time.\n\tPlease run the program again\n\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");
        exit(1);
    }

    printf("\t==============================");
    printf("\n\tEmployee #: %d", (int)employeeNumber);
    printf("\n\tHourly Salary: $%0.1lf", hourlySalary);
    printf("\n\tWeekly Time: %0.1lf", weeklyTime);

    //Calculates the regular pay by multiplying the hourly salary and weekly time and also the overtime pay by multiplying how many extra hours worked by 1.5 times the hourly salary.
    if(weeklyTime < 40) {
        regularPay = hourlySalary * weeklyTime;
    }
    else {
        regularPay = hourlySalary * 40;
        overtimePay = (weeklyTime - 40) * (1.5 * hourlySalary);
    }
    printf("\n\tRegular Pay: $%0.1lf", regularPay);
    printf("\n\tOvertime Pay: $%0.1lf", overtimePay);
    netPay = regularPay + overtimePay;
    printf("\n\tNet Pay: $%0.1lf", netPay);

    printf("\n\t==============================\nThank you for using \"TEMPLE HUMAN RESOURCES\"\n");

    return 0;
}
