/* string_join.c */
# include "string_join.h"

char *string_join(char *s1, char *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char 	*joined_string;

	i = 0;
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	joined_string = calloc(len_s1 + len_s2 + 1, sizeof(*joined_string));
	if (joined_string == NULL)
		return (NULL);
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			joined_string[i] = s1[i];
		else
			joined_string[i] = s2[i - len_s1];
		i++;
	}
	joined_string[i] = '\0';
	return (joined_string);
}