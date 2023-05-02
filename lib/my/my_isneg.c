/*
** EPITECH PROJECT, 2021
** Check if a number is positive, Null or negative
** File description:
** display N if number is negative and P if number is null or positive
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
