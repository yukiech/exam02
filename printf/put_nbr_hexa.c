#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_nbr_hexa(unsigned int nbr, unsigned int base, char *base_char)
{
	if (nbr >= base)
	{
		put_nbr_hexa(nbr / base, base, base_char);
		put_nbr_hexa(nbr % base, base, base_char);
	}
	else
		ft_putchar(base_char[nbr]);
}


int	main()
{
	put_nbr_hexa(1234, 16, "0123456789abcdef");
}
