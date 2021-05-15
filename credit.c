// Include the libraries
// Please do ignore the random commented printf("") functions throughtout the program. That was just me
// trying to figure out how the program was handling the digits.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompting the user for an input
    long card_num = get_long("Number: ");

    // Getting the length of the card_num
    int length = 0;
    long a = card_num;

    while (a > 0)
    {
        a = a / 10;
        length++;
    }
    //printf("%i\n", length);

    // Calculating the checksum:

    // Initializing some variables
    int set1 = 0;
    int set2 = 0;
    int digit1;
    int digit2;
    int d1;
    int d2;
    long y = card_num;
    int total = 0;

    do
    {
        // Getting the first set where we have to add the numbers without multiplying with 2
        digit1 = y % 10;
        //printf("%i\n", digit1);
        y = y / 10;
        //printf("%i\n", y);
        set1 = set1 + digit1;
        //printf("%i\n", set1);

        // Getting the second set where we have to add the number after multiplying with 2
        digit2 = y % 10;
        //printf("%i\n", digit2);
        y = y / 10;
        //printf("%i\n", y);
        digit2 = digit2 * 2;
        //printf("%i\n", digit2);
        d1 = digit2 % 10;
        //printf("%i\n", d1);
        d2 = digit2 / 10;
        //printf("%i\n", d2);
        set2 = set2 + d1 + d2;
        //printf("%i\n", set2);
    }
    while (y > 0);

    total = set1 + set2;
    //printf("%i\n", total);

    // Validating the card_num on the basis of it's length
    if (length != 16 && length != 15 && length != 13)
    {
        printf("INVALID\n");
        return 0;
    }
    // Checking the Luhn's Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // Getting the starting two digits
    long start_digit = card_num;
    do
    {
        start_digit = start_digit / 10;
    }
    while (start_digit > 100);
    //printf("%li\n", start_digit);

    // Printing the type of card
    if (start_digit == 34 || start_digit == 37)
    {
        printf("AMEX\n");
    }
    else if (start_digit == 51 || start_digit == 52 || start_digit == 53 || start_digit == 54 || start_digit == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (start_digit / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}