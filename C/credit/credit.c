#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validity(long int card_num, char *type);
char *card_type(long int card_num);

int main(void)
{
    long int number = get_long("Number: ");
    char *type = card_type(number);
    bool check = validity(number, type);
    if (check)
    {
        printf("%s", type);
    }

    else
    {
        printf("INVALID\n");
    }
}

bool validity(long card_num, char *type)
{
    int count = 0;
    long int card_num_2 = card_num;
    int sum_all = 0, numbers[10], i, sum_2 = 0, count_holder = 0;

    while (card_num_2 != 0)
    {
        sum_all += card_num_2 % 10;
        card_num_2 /= 10;
        count++;
    }

    count_holder = count / 2;

    for (i = 0; 0 < count_holder; count_holder--, i++)
    {
        card_num /= 10;
        numbers[i] = (card_num % 10);
        card_num /= 10;
    }

    for (int j = 0; j < i; j++)
    {
        if (numbers[j] != 0)
        {
            sum_all -= numbers[j];
            numbers[j] *= 2;
            if (numbers[j] / 10 != 0)
            {
                sum_2 += numbers[j] % 10;
                numbers[j] /= 10;
                sum_2 += numbers[j];
            }
            else
            {
                sum_2 += numbers[j];
            }
        }
    }

    if ((sum_all + sum_2) % 10)
    {
        return false;
    }

    else
    {
        if (!strcmp(type, "AMEX\n") && count == 15)
        {
            return true;
        }

        else if (!strcmp(type, "MASTERCARD\n") && count == 16)
        {
            return true;
        }

        else if (!strcmp(type, "VISA\n") && (count == 16 || count == 13))
        {
            return true;
        }

        else
        {
            return false;
        }
    }
}

char *card_type(long int card_num)
{
    char number_str[20];

    // convert int to str
    sprintf(number_str, "%li", card_num);

    // extract the first two num
    char first_two_num_str[3];
    strncpy(first_two_num_str, number_str, 2);
    first_two_num_str[2] = '\0';

    int first_two_num = strtol(first_two_num_str, NULL, 10);

    if (first_two_num == 34 || first_two_num == 37)
    {
        return "AMEX\n";
    }

    else if (first_two_num == 51 || first_two_num == 52 || first_two_num == 53 ||
             first_two_num == 54 || first_two_num == 55)
    {
        return "MASTERCARD\n";
    }

    else if (first_two_num >= 40 && first_two_num <= 49)
    {
        return "VISA\n";
    }

    else
    {
        return "UNKNOWN\n";
    }
}
