#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar_count(char s, int *count)
{
	write(1, &s, 1);
	*count = *count + 1;
}


void	ft_putstr_count(char *str, int *count)
{
	int	i = 0;
	while (str[i])
	{
		ft_putchar_count(str[i], count);
		i++;
	}
}

void	ft_putnbr_base(unsigned int nbr, unsigned int base, char *base_text,int *count)
{
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base, base_text, count);
		ft_putnbr_base(nbr % base, base, base_text, count);
	}
	else
		ft_putchar_count(base_text[nbr], count);
}

void	forest_if(char *str, int i, va_list args,int *count)
{
	int	nbr = 0;
	if (str[i + 1] == 's')
		ft_putstr_count(va_arg(args, char *), count);
	else if (str[i + 1] == 'd')
	{
		nbr = va_arg(args, int);
		if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar_count('-', count);
		}
		ft_putnbr_base(nbr, 10, "0123456789", count);
	
	}
	else if (str[i + 1] == 'x')
	{
		nbr = va_arg(args, unsigned int);
		ft_putnbr_base(nbr, 16, "0123456789abcdef", count);
	}
}


int	ft_printf(char *str, ...)
{
	int	i = 0;
	int	count = 0;
	va_list	args;

	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			forest_if(str, i, args, &count);
			i += 2;
		}
		else
		{
			ft_putchar_count(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main()
{
	char *str = "-1234";
	int	nbr = -1234;
	int	hexa = -1234;
	int	retour_printf = 0;
	int	retour_ftprintf = 0;
	
	retour_printf = printf("s: %s || d: %d || x: %x \n", str, nbr, hexa);
	retour_ftprintf = ft_printf("s: %s || d: %d || x: %x \n", str, nbr, hexa);

	printf("Printf : %d | Ft_Printf : %d\n", retour_printf, retour_ftprintf);
}
