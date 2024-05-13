#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);

}

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		else
			s++;
	}
	return (0);
}

char    *ft_strcalloc(size_t nitems, size_t size)
{
        char   *pstr;
		int		i;

		i = 0;
        pstr = (char *)malloc(nitems * size);
        if (pstr == NULL)
                return (NULL);
        while (nitems > 0)
        {
                pstr[i] = 0;
                i++;
                nitems--;
        }
        return (pstr);
}

char	*strjoin(char *s1, char *s2) //s1 big buffer s2 small buffer
{
	char	*nstr;
	size_t	i;

	// 				malloc				size of big buffer   size of small buffer
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nstr) // malloc check
		return (nstr = NULL, NULL);
	i = 0;
	//ft_strcpy(nstr, s1);
	while (*s1)
		nstr[i++] = *(s1++); // cpy the first string
	//ft_strcat(nstr, s2);
	while (*s2)
		nstr[i++] = *(s2++); // cat the second string
	nstr[i] = 0;
	return (nstr); // update the new buffer
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	slen = ft_strlen((s));
	if ((slen < start) || *s == 0)
		return (ft_strcalloc(1, sizeof(char)));
	if (len > slen + start)
		len = slen + start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
