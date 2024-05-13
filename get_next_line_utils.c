#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i; // counter

	i = 0;
	while (s[i])
		i++; //increment while it isnt \0
	return (i); //return it

}

int	ft_strchr(const char *s, int c)
{
	while (*s) //while it isnt \0
	{
		if (*s == (char)c) // if it is the char im looking
			return (1); //return POSITIVE (1)
		else
			s++; // if it inst keep looking
	}
	return (0); //if not found return NEGATIVE (0)
}

char    *ft_strcalloc(size_t nitems, size_t size)
{
        char   *pstr;
		int		i;

		i = 0;
        pstr = (char *)malloc(nitems * size); // size of each item * nintems
        if (pstr == NULL) //error check
                return (NULL);
        while (nitems > 0)
        {
                pstr[i] = 0; //setting every byte to 0
                i++;
                nitems--; // reducing the amount of itens left to 0
        }
        return (pstr); //return the pointer to the allocated memory
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

	slen = ft_strlen((s)); //get the len of my string
	if ((slen < start) || *s == 0) //if the start is out of the string or if i dont have any string left
		return (ft_strcalloc(1, sizeof(char))); // return an empty string
	if (len > ft_strlen(s + start)) // if my len is less than the rest of the string
		len = ft_strlen(s + start); // set the len to the rest of the len of the string
	substr = (char *)malloc(sizeof(char) * (len + 1)); //allocate that len + 1
	if (!substr) // error check
		return (NULL);
	i = 0;
	while (i < len) // while i doenst reach len
	{
		substr[i] = s[start + i]; //copy to my newstring my substring starting at start and incrementing i each time to the next char
		i++;
	}
	substr[i] = 0; // null terminate it
	return (substr); // return it
}
