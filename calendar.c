/***********************************************************************
 * Homework 1: Loopy Conditionals 
 ***********************************************************************/

/* Procedure to print desired calendar month
 *
 * Part 1: Initializing the desired month and first day of the week in the month as integers.  
 * Part 2: Prints the calendar month. 
 * Part 3: Prints statement giving information about month and starting day below calendar month. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

/* Procedure to print the numbers in the calendar month. */
void
print_calendar_numbers(int month, int leap_year, int start_day_of_month) 
{
    int number_of_days_in_month;

    switch (month) /* Assigning the number of days to the month. */
    { 
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        number_of_days_in_month = 31;
        break; 

        case 2:
        {if (leap_year == 0) number_of_days_in_month = 28;
            else number_of_days_in_month = 29; }; 
        break;

        case 4: case 6: case 9: case 11:
        number_of_days_in_month = 30;
        break;
    }
    
    for (int i = 1; i <= number_of_days_in_month; i++) /* Prints the numbers in the calendar. */
    { 
        if ((i + start_day_of_month) % 7 == 1) printf("%2d", i);
        else printf("%3d", i);
        if ((i != number_of_days_in_month) && ((i + start_day_of_month)% 7 == 0)) printf("\n"); /* Starts a newline. */
    }
} //print_calendar_numbers

/* Procedure to print the month depeneding on the number given. */
void
print_month_name (int month) 
{
    switch (month) {
        case 1: printf ("(January)"); break; 
        case 2: printf ("(February)"); break; 
        case 3: printf ("(March)"); break; 
        case 4: printf ("(April)"); break; 
        case 5: printf ("(May)"); break; 
        case 6: printf ("(June)"); break; 
        case 7: printf ("(July)"); break; 
        case 8: printf ("(August)"); break; 
        case 9: printf ("(September)"); break; 
        case 10: printf ("(October)"); break; 
        case 11: printf ("(November)"); break; 
        case 12: printf ("(December)"); break; 
        }
} // print_month_name

/* Procedure to print the day the month starts depeneding on the number given. */
void
print_day_name (int start_day_of_month)
{
    switch (start_day_of_month) 
    {
        case 0: printf ("(Sunday).\n"); break; 
        case 1: printf ("(Monday).\n"); break; 
        case 2: printf ("(Tuesday).\n"); break; 
        case 3: printf ("(Wednesday).\n"); break; 
        case 4: printf ("(Thursday).\n"); break; 
        case 5: printf ("(Friday).\n"); break; 
        case 6: printf ("(Saturday).\n"); break; 
    }
} // print_day_name

/* Main program entry */
int
main (void)
{
    int month, leap_year, start_day_of_month;

    /* Part 1: Initializing the desired month and first day of the week in the month as integers. */
    month = 2; 
    start_day_of_month = 5; 
    leap_year = 0; /* 0 if it is not a leap year, 1 if it is a leap year. */

    if (month < 1 || month > 12) {
        printf("Illegal entry, start again.\n"); 
        exit(0);} /* Condition if the entered month is not in the range. */

    if (start_day_of_month < 0 || start_day_of_month > 6) {
        printf("Illegal entry, start again.\n");
        exit (0);} /* Condition if the entered day is not in the range. */

    /* Part 2: Prints the calendar month. */
    printf("Su  M  T  W Th  F  S\n"); 
    printf("  ");
    for (int i = 1; i < start_day_of_month; i++) printf("   "); /* Prints empty spaces. */
    print_calendar_numbers(month, leap_year, start_day_of_month); /* Prints all the numbers in the month. */

    /* Part 3: Prints statement giving information about month and starting day below calendar month. */
    printf ("\nMonth %d ", month);
    print_month_name(month); /* Prints the month depeneding on the number entered. */
    printf (" with the first day %d ", start_day_of_month);
    print_day_name (start_day_of_month); /* Prints the day the month starts depeneding on the number entered. */

    return 0;
} // main