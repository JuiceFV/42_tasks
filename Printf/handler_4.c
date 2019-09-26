# include "ft_printf.h"

static void converter_signed(const char **format, t_printf_format *frmt,
                              va_list va)
{
  const long long value_ll;
  const long value_l;
  const int value_i;
  const int temp_value_i;

  if (frmt->flags & FLAGS_LONG_LONG)
  {
        value_ll = va_arg(va, long long);
        frmt->index = pass_to_ntoa_ll(*frmt, value_ll);
  }
  else if (frmt->flags & FLAGS_LONG)
  {
    value_l = va_arg(va, long);
    frmt->index = pass_to_ntoa_l(*frmt, value_l);
  }
  else
  {
    if (!(frmt->flags & FLAGS_CHAR))
      temp_value_i = (frmt->flags & FLAGS_SHORT) ? (short int)va_arg(va, int) :
                                                              va_arg(va, int);
    value_i = (frmt->flags & FLAGS_CHAR) ? (char)va_arg(va, int) : temp_value_i;
    frmt->index = pass_to_ntoa_int(frmt, value);
  }
}

static void some_flags_checker(const char **format, t_printf_format *frmt,
                                va_list va)
{
  if (**format == 'X')
      frmt->flags |= FLAGS_UPPERCASE;
  if ((**format != 'i') && (**format != 'd'))
      frmt->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
  if (frmt->flags & FLAGS_PRECISION)
      frmt->flags &= ~FLAGS_ZEROPAD;
  if ((**format == 'i') || (**format == 'd'))
  {
    converter_signed(format, frmt, va);
  }
  else
  {
    
  }
}

void evaluate_specifier(const char **format, t_printf_format *frmt, va_list va)
{
  if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x'
      || **format == 'X' || **format == 'o' || **format == 'b')
  {
    if (**format == 'x' || **format == 'X')
        frmt->base = 16U;
    else if (**format == 'o')
        frmt->base = 8U;
    else if (**format == 'b')
        frmt->base = 2U;
    else
    {
        frmt->base = 10U;
        frmt->flags &= ~FLAGS_HASH;
    }
    some_flags_checker(format, frmt, va)

  }
}
