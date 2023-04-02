/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumnakan <robynmao@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:57:04 by yumnakan          #+#    #+#             */
/*   Updated: 2023/04/01 16:26:32 by yumnakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = 0;
	return (joined);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
