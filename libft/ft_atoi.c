/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:10:24 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 16:10:40 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == '\n' || ch == ' ')
		return (1);
	return (0);
}

static int	math(char *str, int minus)
{
	long long	out;
	int			n;

	n = 0;
	out = 0;
	while ((*str >= 48 && *str < 58))
	{
		n++;
		out = out * 10 + (*str - 48);
		if (n >= 10)
		{
			if (out * minus > 2147483647)
				return (-1);
			else if (out * minus < -2147483648)
				return (0);
		}
		str++;
	}
	return ((int)out * minus);
}

int	ft_atoi(const char *nptr)
{
	char		*s;
	int			n;
	long long	out;
	int			minus;

	s = (char *)nptr;
	n = 0;
	out = 0;
	minus = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
	{
		s++;
		minus *= -1;
	}
	else if (*s == '+')
		s++;
	return (math(s, minus));
}

/*int main(int argv, char **argc)
{
	printf("%d\n", atoi(argc[1]));
	printf("%d\n", ft_atoi(argc[1]));   
}*/
