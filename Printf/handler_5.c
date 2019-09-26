void pass_to_ntoa_ll(t_printf_format frmt, long long value)
{
  frmt.neg = value < 0;
  ntoa_long_long(frmt, (unsigned long long)(value > 0 ? value : 0 - value));
}

void pass_to_ntoa_l(t_printf_format frmt, long value)
{
  frmt.neg = value < 0;
  ntoa_long(frmt, (unsigned long)(value > 0 ? value : 0 - value));
}

void pass_to_ntoa_int(t_printf_format frmt, int value)
{
  frmt.neg = value < 0;
  ntoa_long(frmt, (unsigned int)(value > 0 ? value : 0 - value));
}
