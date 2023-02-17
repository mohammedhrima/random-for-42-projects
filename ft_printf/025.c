#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int ft_putchar(int c)
{
	int i;

	i = (int)write(1, &c, 1);
	return (i);
}

int ft_putstr(char *str, int n)
{
	int i;
	int j;
	int k;
	int len;

	i = 0;
	j = 0;

	if(n >= 0)
		len = n;
	else
		len = ft_strlen(str);
	if (!str)
		return (j+= ft_putstr("(null)",-1));
	while (i < len && str[i])
	{
		j += ft_putchar(str[i]);
		if (j < 0)
			return (-1);
		i++;
	}

	return (j);
}

char	*ft_strchr(char *str, char to_find)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == to_find)
			return(str + i);
		i++;
	}
	return (NULL);
}

int ft_putnbr(long int num)
{
	int i;
	int j;

	i = 0;
	if (num < 0)
	{
		j = ft_putchar('-');
		if (j < 0)
			return (-1);
		i += j;
		num = -num;
	}
	if (num >= 0 && num < 10)
	{
		j = ft_putchar('0' + num);
		if (j < 0)
			return (-1);
		i += j;
	}
	if (num >= 10)
	{
		j = ft_putnbr(num / 10);
		if (j < 0)
			return (-1);
		i += j;
		j = ft_putchar(num % 10 + '0');
		if (j < 0)
			return (-1);
		i += j;
	}
	return (i);
}

int ft_putunsignednbr(unsigned int num)
{
	int i;
	int j;

	i = 0;
	if (num >= 0 && num < 10)
	{
		j = ft_putchar('0' + num);
		if (j < 0)
			return (-1);
		i += j;
	}
	if (num >= 10)
	{
		j = ft_putunsignednbr(num / 10);
		if (j < 0)
			return (-1);
		i += j;
		j = ft_putchar(num % 10 + '0');
		if (j < 0)
			return (-1);
		i += j;
	}
	return (i);
}

int ft_atoi(const char *s)
{
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	neg = 1;
	while (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = 10 * res + s[i] - '0';
		i++;
	}
	return (neg * res);
}

int lend(long int num) // doesn't count the minus sign
{
	int i;

	i = 0;
	if (!num)
		return (1);
	if (num < 0)
	{
		num = -num;
		i++;
	}
	if(num >=0 && num < 10)
		i++;
	if(num >= 10)
		i += lend(num / 10) + 1;
	return (i);
}

int lenX(unsigned int num)
{
	int i;
	int j;

	i = 0;
	if (num >= 0 && num < 16)
		i++;
	if (num >= 16)
		i += lenX(num / 16) + 1;
	return (i);
}

int lenP(unsigned long long p)
{
	int i;
	int j;

	i = 0;
	if (p >= 0 && p < 16)
		i++;
	if (p >= 16)
		i += lenP(p / 16) + 1;
	return (i);
}

int lenU(unsigned num)
{
	int i;

	i = 0;
	if (!num)
		return (1);
	if(num >=0 && num < 10)
		i++;
	if(num >= 10)
		i += lenU(num / 10) + 1;
	return (i);
}

int printSpace(int *addSpace)
{
	int i;

	i = 0;
	while ((*addSpace)-- > 0)
		i += ft_putchar(' ');
	return (i);
}

int convertfromDec_P(unsigned long long num)
{
	int i;
	int j;
	i = 0;
	char *to;

	to = "0123456789abcdef";
	if (num >= 0 && num < 16)
	{
		j = ft_putchar(to[num]);
		if (j < 0)
			return (-1);
		i += j;
	}
	if (num >= 16)
	{
		j = convertfromDec_P(num / 16);
		if (j < 0)
			return (-1);
		i += j;
		j = ft_putchar(to[num % 16]);
		if (j < 0)
			return (-1);
		i += j;
	}
	return (i);
}

int convertfromDec_X(unsigned int num, char x)
{
	
	int i;
	int j;
	char *to;

	i = 0;
	if(x == 'x')
		to = "0123456789abcdef";
	if(x == 'X')
		to = "0123456789ABCDEF";
	if (num < 0)
	{
		num *= -1;
		j = ft_putchar('-');
		i += j;
	}
	if (num >= 0 && num < 16)
	{
		j = ft_putchar(to[num]);
		if (j < 0)
			return (-1);
		i += j;
	}
	if (num >= 16)
	{
		j = convertfromDec_X(num / 16, x);
		if (j < 0)
			return (-1);
		i += j;
		j = ft_putchar(to[num % 16]);
		if (j < 0)
			return (-1);
		i += j;
	}
	return (i);
}

int ft_printf(const char *conv, ...)
{
	int		i;
	int		j;
	int		minus;
	int		zero;
	int		addOx;
	int		space;
	int		plus;
	int		preci;
	int		c;
	char	*s;
	long int d;
	unsigned long u;
	unsigned long long p;
	unsigned int x;
	va_list args;

	va_start(args, conv);
	i = 0;
	j = 0;
	while (i < ft_strlen(conv))
	{
		//printf("step 1");
		minus = -1;//add space after
		zero = -1;
		addOx = 0;
		space = 0;
		plus = 0;
		preci = -1;
		if(conv[i] == '%')
		{
			i++;
			while(conv[i] && ft_strchr("-+# 0.", conv[i]))
			{
				if(conv[i] == '-')
				{
					zero = -1;
					while(conv[i] == '-')
						i++;
					minus = ft_atoi(conv + i);
					if(conv[i] >= '0' && conv[i] <= '9')
						i += lend((long)minus);
		
				}
				else if(conv[i] == '+')
				{
					space = 0;
					plus = 1;
					i++;
				}
				else if(conv[i] == '0')
				{
					zero = ft_atoi(conv+i+1);
					i += lend(zero) + 1;
				}
				else if(conv[i] == '.')
				{
					i++;
					preci = ft_atoi(conv + i);
					if(conv[i] >= '0' && conv[i] <= '9')
						i += lend((long)preci);
					//printf("conv[%d]->%c | preci=%d\n",i,conv[i],preci);
				}
				else if(conv[i] == '#')
				{
					addOx = 1;
					i++;
				}
				else if(conv[i] == ' ') //check + sign because it make some change to space
				{
					space = 1;
					while(conv[i] == ' ')
						i++;
				}	
		
			}
			if(conv[i] == 'c')
			{
				c = va_arg(args,int);
				j += ft_putchar(c);
				minus -= 1;//len of char
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			else if (conv[i] == 's')
			{
				s = va_arg(args, char *);
				//printf("string is %s\n\n",s);
				j += ft_putstr(s,preci);
				minus -= ft_strlen(s);
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			if(conv[i] == 'p')
			{
				p = (unsigned long long)va_arg(args, void*);
				j += ft_putstr("0x",-1) + convertfromDec_P(p);
				minus -= (lenP(p) + 2);
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			if(conv[i] == 'x' || conv[i] == 'X')
			{
				x = (unsigned int)va_arg(args, void *);
				if(addOx && x)
				{
					j += ft_putchar('0');
					j += ft_putchar(conv[i]);
				}
				preci -= lenX(x);
				while(preci-- > 0)
					j += ft_putchar('0');
				zero -= lenX(x);
				while(zero-- > 0)
					j += ft_putchar('0');
				j += convertfromDec_X(x,conv[i]);
				minus -= lenX(x);
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			if(conv[i] == 'd' || conv[i] == 'i')
			{
				d = (long int)va_arg(args, int);
				minus -= lend(d);
				if(d >= 0 && space )
					j += ft_putchar(' ');
				if(plus>0 && d >= 0)
					j += ft_putchar('+');
				if(d < 0)
				{
					j += ft_putchar('-');
					d = -d;
					zero--;
				}
				zero -= lend(d);
				while(zero-- > 0)
					j += ft_putchar('0');
				preci -= lend(d);
				while(preci-- > 0)
					j += ft_putchar('0');
				j += ft_putnbr(d);
				
				while(minus-- > 0)
					j += ft_putchar(' ');		
			}
			if (conv[i] == 'u')
			{
				u = va_arg(args, unsigned);
				if(plus>0)
					j+= ft_putchar('+');
				zero -= lenU(u);
				while(zero-- > 0)
					j += ft_putchar('0');
				preci -= lenU(u);
				while(preci-- > 0)
					j += ft_putchar('0');
				j += ft_putunsignednbr(u);
				minus -= lenU(u);
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			
			if (conv[i] == '%')
			{
				j += ft_putchar('%');
				minus -= 1;//len of char
				while(minus-- > 0)
					j += ft_putchar(' ');
			}
			i++;
		}
		else
		{
		//	ft_putchar('\\');
			j += ft_putchar(conv[i]);
			//printf("\nI did write %d char \n", j);
			//j += ft_putchar('x');
		//	ft_putchar('\\');
			i++;
		}
	}
	
	va_end(args);
	return(j);
}

int main(void)
{
	int n,m;
	//n = printf("|%5%|");
	//printf("\n");
	//m = ft_printf("|%5%|");
	//printf("\n");
	//printf("n=%d m=%d\n",n,m);
	//printf("\n=============================\n\n");
	n = printf("|%+5%|");
	printf("\n");
	m = ft_printf("|%+5%|");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%-05%|");
	printf("\n");
	m = ft_printf("|%-05%|");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	// n = printf("|%23s|", NULL);
	// printf("\n");
	// m = ft_printf("|%23s|", NULL);
	// printf("\n");
	// printf("n=%d m=%d\n",n,m);
	// printf("\n=============================\n\n");
	n = printf("|%.s|", NULL);
	printf("\n");
	m = ft_printf("|%.s|", NULL);
	printf("\n");
	printf("|n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	// n = printf("|%32s|", "abc");
	// printf("\n");
	// m = ft_printf("|%32s|", "abc");
	// printf("\n");
	// printf("n=%d m=%d\n",n,m);
	// printf("\n=============================\n\n");
	// n = printf("|%16s|", "nark nark");
	// printf("\n");
	// m = ft_printf("|%16s|", "nark nark");
	// printf("\n");
	// printf("n=%d m=%d\n",n,m);
	// printf("\n=============================\n\n");
	// n = printf("|%5s|", "goes over");
	// printf("\n");
	// m = ft_printf("|%5s|", "goes over");
	// printf("\n");
	// printf("n=%d m=%d\n",n,m);
	// printf("\n=============================\n\n");
	n = printf("|%.5s%.7s|", "yo", "boi");
	printf("\n");
	m = ft_printf("|%.5s%.7s|", "yo", "boi");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.5s|", "yolo");
	printf("\n");
	m = ft_printf("|%.5s|", "yolo");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.5s|", "bombastic");
	printf("\n");
	m = ft_printf("|%.5s|", "bombastic");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.5s|", "tubular");
	printf("\n");
	m = ft_printf("|%.5s|", "tubular");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	m = ft_printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	m = ft_printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	m = ft_printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	m = ft_printf("|%.7s%.7s|", "hello", "world");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
	n = printf("|%.3s%.7s|", "hello", "world");
	printf("\n");
	m= ft_printf("|%.3s%.7s|", "hello", "world");
	printf("\n");
	printf("n=%d m=%d\n",n,m);
	printf("\n=============================\n\n");
}