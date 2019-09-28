#include "../includes/ft_printf.h"
 
static void	evaluate_flags(t_printf_format* frmt)
{
	while ((frmt->temp = get_char_index("# +-0*", *frmt->format)) > -1 && ++frmt->format)
		frmt->flags |= (1 << (unsigned int)frmt->temp);
	((frmt->flags & FLAGS_LEFT) && !(frmt->flags & FLAGS_STAR)) ? frmt->flags &= ~FLAGS_ZEROPAD : 0;
	(frmt->flags & FLAGS_PLUS) ? frmt->flags &= ~FLAGS_SPACE : 0;
	if (frmt->flags & FLAGS_STAR)
	{
		frmt->flags &= ~FLAGS_STAR;
		if ((frmt->temp = (int)va_arg(frmt->ap, int)) < 0)
		{
			frmt->flags |= FLAGS_LEFT;
			frmt->temp = -frmt->temp;
		}
		else
			frmt->flags &= ~FLAGS_LEFT;
		if (!(frmt->flags & FLAGS_PRECISION))
			frmt->min_length = frmt->temp;
		else
		{
			frmt->precision = (!(frmt->flags & FLAGS_LEFT)) ? frmt->temp : 0;
			frmt->flags = (!frmt->temp) ? frmt->flags | FLAGS_PRECISION : frmt->flags & ~FLAGS_PRECISION;
		}
	}
}

static void evaluate_width_and_prec(t_printf_format* frmt)
{
	int str_width;

	if (ft_isdigit(*frmt->format))
	{
		str_width = ft_atoi(frmt->format);
		frmt->min_length = MAX(1, ft_atoi(frmt->format));
		while (ft_isdigit(*frmt->format))
			frmt->format++;
	}
	if (*frmt->format == '.')
	{
		frmt->format++;
		str_width = ft_atoi(frmt->format);
		frmt->precision = str_width & (~(str_width) >> 31);
		while (ft_isdigit(*frmt->format))
			frmt->format++;
		frmt->flags |= FLAGS_PRECISION;
	}
}

static void	evaluate_subspecifiers(t_printf_format *frmt)
{
	while (1)
	{ 
		if (*frmt->format == 'l')
			frmt->flags |= (frmt->format[1] == 'l' && ++frmt->format) ? FLAGS_LONG_LONG : FLAGS_LONG;
		else if (*frmt->format == 'h')
			frmt->flags |= (frmt->format[1] == 'h' && ++frmt->format) ? FLAGS_CHAR : FLAGS_SHORT;
		else if (*frmt->format == 'j')
			frmt->flags |= FLAGS_INTMAX;
		else if (*frmt->format == 'z')
			frmt->flags |= FLAGS_SIZE_T;
		else if (*frmt->format == 'L')
			frmt->flags |= FLAGS_LONG_LONG;
		else
			break ;
		frmt->format++;
	}
}

static void	evaluate_specifiers(t_printf_format* frmt)
{
	frmt->character = *frmt->format;
	if (frmt->character == 's')
		(frmt->flags & FLAGS_LONG || frmt->flags & FLAGS_LONG_LONG) ?
		put_wchar_str(frmt) : put_char_str(frmt);
	else if (ft_strchr("dDi", frmt->character))
		putnbr(frmt);
	else if (frmt->character == 'f' || frmt->character == 'F')
		(frmt->flags & FLAGS_PRECISION && ! frmt->precision) ? putnbr(frmt) : pf_putdouble(frmt);
	else if (frmt->character == 'c' || frmt->character == 'C')
		pf_character(frmt, va_arg(frmt->ap, unsigned));
	else if (ft_strchr("oOuUbBxX", frmt->character))
		pf_putnb_base(ft_strchri_lu(".b..ou..x", frmt->character, -1) << 1, frmt);
	else if (frmt->character == 'S')
		pf_putwstr(frmt);
	else if (frmt->character == 'p')
		print_pointer_address(frmt);
	else if (frmt->character == 'n')
		*va_arg(frmt->ap, int *) = frmt->length;
	else if (frmt->character == 'm')
		ft_printf_putstr(STRERR(errno), frmt);
	else if (frmt->character == '{')
		color(frmt);
	else
		cs_not_found(frmt);
}


void	evaluate_format(t_printf_format *frmt)
{
	frmt->flags = 0U;
	frmt->min_length = 0;
	frmt->precision = 1U;
	evaluate_flags(frmt);
	evaluate_width_and_prec(frmt);
	evaluate_subspecifiers(frmt);
	evaluate_flags(frmt);
	if (frmt->flags & FLAGS_PLUS)
		frmt->flags &= ~FLAGS_SPACE;
	if (ft_strchr("CDSUOBX", *frmt->format))
		frmt->flags |= (*frmt->format != 'X') ? FLAGS_LONG : FLAGS_UPPERCASE;
	evaluate_specifiers(frmt);
}