# include "get_next_line.h"

char    *ft_read_line (char *src)
{
    size_t i;
    char *str;

    i = 0;
    if (src == NULL)
        return (NULL);
    while (src[i] != '\0' && src[i] != '\n')
        i++;
    str = malloc(sizeof(*str) * (i + 2)); // why 2 ?? maybe because of '\n' and '\0'
    if (str == NULL)
        return(NULL);
    i = 0;

    while (src[i] != '\0' && src[i] != '\n')
    {
        str[i] = src[i];
        i++;
    }
    if (src[i] == '\n')
        str[i++] = '\n';
    str[i] = '\0';
    return (str);
}