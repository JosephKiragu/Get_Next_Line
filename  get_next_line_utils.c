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


char    *ft_save(char *src)
{
    size_t  i;
    size_t  j;
    char    *str;

    i = 0;
    while (src[i] != '\0' && src[i] != '\n')
        i++;
    if (src[i] == '\0')
    {
        free(src);
        return (0);
    } // this statement returns if the line is the last one in the file
    str = malloc(sizeof(*char) * (ft_strlen(src) - i + 1)); //str is everything apart from previous line
    if (str == NULL)
        return (NULL);
    i = i + 1;
    j = 0;
    while (src[i] != '\0')
        str[j++] = src[i++];
    str[j] = '\0';
    free(src); //src is freed here before being created in another loop.
    return(str); 
    

}
