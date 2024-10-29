#include "minishell.h"

static int	count_string(const char *str)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] == '"')
		{
			len++;		
			while (str[len] && str[len] != '"')
				len++;
			count++;
			len++;
		}
		while (str[len] && (str[len] == 32 || (str[len] >=9 && str[len] <= 13)))
			len++;
		if (str[len] == '"')
		{
			len++;
			while (str[len] && str[len] != '"')
				len++;
			count++;
			len++;
		}
		while (str[len] && (str[len] == 32 || (str[len] >=9 && str[len] <= 13)))
			len++;
		if (!str[len])
			break ;		
		while (str[len] && (str[len] != 32 && !(str[len] >=9 && str[len] <= 13)))
			len++;
		count++;
	}
	return (count);
}

static int	count_char(const char *str)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	if (str[len] == '"')
	{
		len++;
		count++;
		while (str[len] && str[len] != '"')
		{
			len++;
			count++;
		}
		count++;
		return (count);
	}
	while (str[len] && (str[len] == 32 || (str[len] >=9 && str[len] <= 13)))
		len++;
	if (str[len] == '"')
	{
		len++;
		count++;
		while (str[len] && str[len] != '"')
		{		
			len++;
			count++;
		}
		count++;
		return (count);
	}
	while (str[len] && (str[len] != 32 && !(str[len] >=9 && str[len] <= 13)))
	{		
		len++;
		count++;
	}
	return (count);
}

static char	*get_string(const char *str, int *i)
{
	int	len;
	int	j;
	char	*temp;
	
	len = count_char(str);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	j = 0;
	if (str[(*i)] == '"')
	{
		temp[j++] = str[(*i)++];
		while (str[(*i)] && str[(*i)] != '"')
			temp[j++] = str[(*i)++];
		if (str[(*i)])
			temp[j++] = str[(*i)++];
		temp[j] = '\0';			
		return (temp);
	}
	while (str[(*i)] == 32 || (str[(*i)] >=9 && str[(*i)] <= 13))
		(*i)++;
	if (str[(*i)] == '"')
	{
		temp[j++] = str[(*i)++];
		while (str[(*i)] && str[(*i)] != '"')
			temp[j++] = str[(*i)++];
		if (str[(*i)])
			temp[j++] = str[(*i)++];
		temp[j] = '\0';			
		return (temp);
	}
	while (str[(*i)] && str[(*i)] != '"' && (str[(*i)] != 32 && !(str[(*i)] >=9 && str[(*i)] <= 13)))
		temp[j++] = str[(*i)++];
	temp[j] = '\0';
	return (temp);
}	
	

char	**fft_split(const char *str)
{
	int	len;
	int	i;
	int	count;
	char	**split;
	
	count = count_string(str);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	len = 0;
	while (len < count)
	{
		split[len] = get_string(str, &i);
		len++;
	}
	split[len] = NULL;
	return (split);
}