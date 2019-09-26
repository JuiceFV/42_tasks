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

void	evaluate_options(t_printf_format *frmt)
{
	frmt->flags = 0U;
	frmt->min_length = 0;
	frmt->precision = 1U;
	evaluate_flags(frmt);

}