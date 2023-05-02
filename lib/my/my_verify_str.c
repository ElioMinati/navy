/*
** EPITECH PROJECT, 2021
** verify_str
** File description:
** verify is an str is a number or not
*/

int my_is_num_char(char c);

int verify_is_str_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_num_char(str[i]) == 1 || str[i] == '-' || str[i] == '.') {
            continue;
        } else {
            return 1;
        }
    }
    return 0;
}
