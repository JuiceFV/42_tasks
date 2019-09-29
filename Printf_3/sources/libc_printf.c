#include "ft_printf.h"

#define FLAGS_TESTS
#define SPECIFIERS_TESTS

#define SIMPLE_OUT
#define SPEC_D_OR_I
#define SPEC_U
#define SPEC_O 
#define SPEC_LOWER_X
#define SPEC_X
#define SPEC_LOWER_F
#define SPEC_F
#define SPEC_LOWER_E
#define SPEC_E
#define SPEC_LOWER_G
#define SPEC_G
#define SPEC_LOWER_A
#define SPEC_A
#define SPEC_C
#define SPEC_S
#define SPEC_P
#define SPEC_N


#define FLAG_MINUS
#define FLAG_PLUS
#define FLAG_SPACE
#define FLAG_HASH
#define FLAG_ZEROPAD
#define FLAG_PRECISION
#define FLAG_STAR

int main()
{
	#if defined SIMPLE_OUT
		ft_printf("It's just simple output, without any format.\n\n");
	#endif
	#if defined SPECIFIERS_TESTS	
		ft_printf("~SPECIFIERS TESTS~\n\n");
		#if defined SPEC_D_OR_I
			ft_printf("Command:\tft_printf(\"%%d, %%i\", 10, 15)\n\n");
			ft_printf("Description:\tSigned decimal integer.\n\n");
			ft_printf("Output:\t\t%d, %i\n\n", 10, 15);
		#endif
		#if defined SPEC_U
			ft_printf("Command:\tft_printf(\"%%u\", -5); ft_printf(\"%%u\", 7256)\n\n");
			ft_printf("Description:\tUnsigned decimal integer.\n\n");
			ft_printf("Output:\t\t%u\n", -5);
			ft_printf("Output:\t\t%u\n\n", 7256);
		#endif
		#if defined SPEC_O
			ft_printf("Command:\tft_printf(\"%%o\", -7); ft_printf(\"%%o\", 7); ft_printf(\"%%o\", 8)\n\n");
			ft_printf("Description:\tUnsigned octal.\n\n");
			ft_printf("Output:\t\t%o\n", -7);
			ft_printf("Output:\t\t%o\n", 7);
			ft_printf("Output:\t\t%o\n\n", 8);
		#endif
		#if defined SPEC_LOWER_X
			ft_printf("Command:\tft_printf(\"%%x\", -716); ft_printf(\"%%x\", 7); ft_printf(\"%%x\", 716)\n\n");
			ft_printf("Description:\tUnsigned hexadecimal integer.\n\n");
			ft_printf("Output:\t\t%x\n", -716);
			ft_printf("Output:\t\t%x\n", 7);
			ft_printf("Output:\t\t%x\n\n", 716);
		#endif
		#if defined SPEC_X
			ft_printf("Command:\tft_printf(\"%%X\", -716); ft_printf(\"%%X\", 7); ft_printf(\"%%X\", 716)\n\n");
			ft_printf("Description:\tUnsigned hexadecimal integer.\n\n");
			ft_printf("Output:\t\t%X\n", -716);
			ft_printf("Output:\t\t%X\n", 7);
			ft_printf("Output:\t\t%X\n\n", 716);
		#endif
		#if defined SPEC_LOWER_F
			ft_printf("Command:\tft_printf(\"%%f\", -7.35); ft_printf(\"%%f\", 7); ft_printf(\"%%f\", 7.0); ft_printf(\"%%f\", 7.35)\n\n");
			ft_printf("Description:\tDecimal floating point, lowercase.\n\n");
			ft_printf("Output:\t\t%f\n", -7.35);
			ft_printf("Output:\t\t%f\n", 7);
			ft_printf("Output:\t\t%f\n", 7.0);
			ft_printf("Output:\t\t%f\n\n", 7.35);
		#endif
		#if defined SPEC_F
			ft_printf("Command:\tft_printf(\"%%F\", -7.35); ft_printf(\"%%F\", 7); ft_printf(\"%%F\", 7.0); ft_printf(\"%%F\", 7.35)\n\n");
			ft_printf("Description:\tDecimal floating point, uppercase.\n\n");
			ft_printf("Output:\t\t%F\n", -7.35);
			ft_printf("Output:\t\t%F\n", 7);
			ft_printf("Output:\t\t%F\n", 7.0);
			ft_printf("Output:\t\t%F\n\n", 7.35);
		#endif
		#if defined SPEC_LOWER_E
			ft_printf("Command:\tft_printf(\"%%e\", -735000); ft_printf(\"%%e\", 700000); ft_printf(\"%%e\", 0.0000256); ft_printf(\"%%e\", 735000)\n\n");
			ft_printf("Description:\tScientific notation (mantissa/exponent), lowercase.\n\n");
			ft_printf("Output:\t\t%e\n", -735);
			ft_printf("Output:\t\t%e\n", 700);
			ft_printf("Output:\t\t%e\n", 0.0000256);
			ft_printf("Output:\t\t%e\n\n", 735);
			ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
		#endif
		#if defined SPEC_E
			ft_printf("Command:\tft_printf(\"%%E\", -735000); ft_printf(\"%%E\", 700000); ft_printf(\"%%E\", 0.0000256); ft_printf(\"%%E\", 735000)\n\n");
			ft_printf("Description:\tScientific notation (mantissa/exponent), uppercase.\n\n");
			ft_printf("Output:\t\t%E\n", -735000);
			ft_printf("Output:\t\t%E\n", 700000);
			ft_printf("Output:\t\t%E\n", 0.0000256);
			ft_printf("Output:\t\t%E\n\n", 735000);
		#endif
		#if defined SPEC_LOWER_G
			ft_printf("Command:\tft_printf(\"%%g\", -735000); ft_printf(\"%%g\", 700000); ft_printf(\"%%g\", 0.0000256); ft_printf(\"%%g\", 735000)\n\n");
			ft_printf("Description:\tUse the shortest representation: %%e or %%f.\n\n");
			ft_printf("Output:\t\t%g\n", -735000);
			ft_printf("Output:\t\t%g\n", 700000);
			ft_printf("Output:\t\t%g\n", 0.0000256);
			ft_printf("Output:\t\t%g\n\n", 735000);
		#endif
		#if defined SPEC_G
			ft_printf("Command:\tft_printf(\"%%G\", -735000); ft_printf(\"%%G\", 700000); ft_printf(\"%%G\", 0.0000256); ft_printf(\"%%G\", 735000)\n\n");
			ft_printf("Description:\tUse the shortest representation: %%E or %%F.\n\n");
			ft_printf("Output:\t\t%G\n", -735000);
			ft_printf("Output:\t\t%G\n", 700000);
			ft_printf("Output:\t\t%G\n", 0.0000256);
			ft_printf("Output:\t\t%G\n\n", 735000);
		#endif
		#if defined SPEC_LOWER_A
			ft_printf("Command:\tft_printf(\"%%a\", -18.35); ft_printf(\"%%a\", 18); ft_printf(\"%%a\", 18.0); ft_printf(\"%%a\", 18.35)\n\n");
			ft_printf("Description:\tHexadecimal floating point, lowercase.\n\n");
			ft_printf("Output:\t\t%a\n", -18.35);
			ft_printf("Output:\t\t%a\n", 18);
			ft_printf("Output:\t\t%a\n", 18.0);
			ft_printf("Output:\t\t%a\n\n", 18.35);
		#endif
		#if defined SPEC_A
			ft_printf("Command:\tft_printf(\"%%A\", -18.35); ft_printf(\"%%A\", 18); ft_printf(\"%%A\", 18.0); ft_printf(\"%%A\", 18.35)\n\n");
			ft_printf("Description:\tHexadecimal floating point, upperrcase.\n\n");
			ft_printf("Output:\t\t%A\n", -18.35);
			ft_printf("Output:\t\t%A\n", 18);
			ft_printf("Output:\t\t%A\n", 18.0);
			ft_printf("Output:\t\t%A\n\n", 18.35);
		#endif
		#if defined SPEC_C
			ft_printf("Command:\tft_printf(\"%%c\", \'a\')\n\n");
			ft_printf("Description:\tCharacter.\n");
			ft_printf("Output:\t\t%c\n\n", 'a');
		#endif
		#if defined SPEC_S
			ft_printf("Command:\tft_printf(\"%%s\", \"This\\tis a string\")\n\n");
			ft_printf("Description:\tString.\n\n");
			ft_printf("Output:\t\t%s\n\n", "This\tis a string");
		#endif
		#if defined SPEC_P
			int var = 0;
			ft_printf("Command:\tft_printf(\"%%p\", &var)\n\n");
			ft_printf("Description:\tPointer address.\n\n");
			ft_printf("Output:\t\t%p\n\n", &var);
		#endif
		#if defined SPEC_N
			char count [] = " asshole!";
			ft_printf("Command:\tft_printf(\"%%n\", \"OK\")\n\n");
			ft_printf("Description:\tNothing printed.\n\t\tThe corresponding argument must be a pointer to a signed int.\n\t\tThe number of characters written so far is stored in the pointed location.\n\n");
			ft_printf("Output:\t\tFuck yeah,%n bitch!\n\n", &count);
			/**/
			ft_printf("%s",count);
		#endif
	#endif

	#if defined FLAGS_TESTS
		ft_printf("~FLAGS TESTS~\n\n");
		#if defined FLAG_SPACE
			ft_printf("Command:\tft_printf(\"|%%10d\\n\", 10')\n\n");
			ft_printf("Description:\tIf no sign is going to be written, a blank space is inserted before the value.\n\n");
			ft_printf("Output:\t\t|%10d\n\n", 10);
		#endif 
		#if defined FLAG_MINUS
			ft_printf("Command:\tft_printf(\"|%%-10d\\n\", 10')\n\n");
			ft_printf("Description:\tLeft-justify within the given field width; Right justification is the default (see width sub-specifier).\n\n");
			ft_printf("Output:\t\t|%-10d\n\n", 10);
		#endif
		#if defined FLAG_PLUS
			ft_printf("Command:\tft_printf(\"%%+d\\n\", 10'); ft_printf(\"%%+d\\n\", -10')\n\n");
			ft_printf("Description:\tForces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.\n\t\tBy default, only negative numbers are preceded with a - sign.\n\n");
			ft_printf("Output:\t\t%+d\n", 10);
			ft_printf("Output:\t\t%+d\n\n", -10);
		#endif
		#if defined FLAG_HASH
			ft_printf("Command:\tft_printf (\"Output:\\t%%d %%x %%o %%#x %%#o\", 100, 100, 100, 100, 100)\n\n");
			ft_printf("Description:\tUsed with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than\n\t\tzero.\n\t\tUsed with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow.\n\t\tBy default, if no digits follow, no decimal point is written.\n\n");
			ft_printf ("Output:\t\t%d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
		#endif
		#if defined FLAG_ZEROPAD
			ft_printf("Command:\tft_printf(\"%%010d\\n\", 10')\n\n");
			ft_printf("Description:\tLeft-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).\n\n");
			ft_printf("Output:\t\t%010d\n", 10);
		#endif
		#if defined FLAG_STAR
			ft_printf("Command:\tft_printf(\"|%%*d\", 5, 10)\n\n");
			ft_printf("Description:\tThe width is not specified in the format string,\n\t\tbut as an additional integer value argument preceding the argument that has to be formatted.\n\n");
			ft_printf("Output:\t\t|%*d\n\n", 5, 10);
		#endif
		#if defined FLAG_PRECISION
			ft_printf("Command:\tft_printf(\"%%+.2f\", 10.365); ft_printf(\"%%+.6d\", 1015); ft_printf(\"%%+.8d\", 1015); ft_printf(\"%%+.8s\", \"String wich will cut\")\n\n");
			ft_printf("Description:\tFor integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written.\n\t\tIf the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer.\n\t\tA precision of 0 means that no character is written for the value 0.\n\t\tFor a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6).\n\t\tFor g and G specifiers: This is the maximum number of significant digits to be printed.\n\t\tFor s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.\n\t\tIf the period is specified without an explicit value for precision, 0 is assumed.\n\n");
			ft_printf("Output:\t\t%.2f\n", 10.365);
			ft_printf("Output:\t\t%.6d\n", 1015);
			ft_printf("Output:\t\t%.8f\n", 10.365);
			ft_printf("Output:\t\t%.8s\n\n", "String wich will cut");
		#endif
	#endif
}
