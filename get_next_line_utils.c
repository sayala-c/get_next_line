size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = len_s1;
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
  free (s1);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i++;
	}
	if ((s[i] == 0) && (s[i] == ((char)c)))
		return ((char *)&s[i]);
	return (NULL);
}
char    *dup_gnl(char *content, char *line)
{
    int    i;

    i = 0;
    while (content[i] != '\n' && content[i] != '\0')
    {
        line[i] = content[i];
        i++;
    }
    return (line);
}
