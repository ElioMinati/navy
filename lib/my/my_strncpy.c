/*
** EPITECH PROJECT, 2021
** my_strn_copy
** File description:
** function that copies n character from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i <= n; i++) {
        if (i == n){
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    return (dest);
}
