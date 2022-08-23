# include "get_next_line.h"


size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
		i++;
	return (i);
}


char	*ft_strchr(char *str, int c)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] == c)
		{
			return ((char *)str + j);
		}
		j++;
	}
	if (str[j] == c)
	{
		return ((char *)str + j);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

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
    str = malloc(sizeof(*str) * (ft_strlen(src) - i + 1)); //str is everything apart from previous line
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
