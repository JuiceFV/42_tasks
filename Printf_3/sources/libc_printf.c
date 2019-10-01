#include <stdio.h>

//#define FLAGS_TESTS
//#define SPECIFIERS_TESTS

//#define SIMPLE_OUT
//#define SPEC_D_OR_I
//#define SPEC_U
//#define SPEC_O 
//#define SPEC_LOWER_X
//#define SPEC_X
//#define SPEC_LOWER_F
//#define SPEC_F
//#define SPEC_LOWER_E
//#define SPEC_E
//#define SPEC_LOWER_G
//#define SPEC_G
//#define SPEC_LOWER_A
//#define SPEC_A
//#define SPEC_C
//#define SPEC_S
//#define SPEC_P
//#define SPEC_N


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
		printf("It's just simple output, without any format.\n\n");
	#endif
	#if defined SPECIFIERS_TESTS	
		printf("~SPECIFIERS TESTS~\n\n");
		#if defined SPEC_D_OR_I
			printf("Command:\tprintf(\"%%d, %%i\", 10, 15)\n\n");
			printf("Description:\tSigned decimal integer.\n\n");
			printf("Output:\t\t%d, %i\n\n", 10, 15);
		#endif
		#if defined SPEC_U
			printf("Command:\tprintf(\"%%u\", -5); printf(\"%%u\", 7256)\n\n");
			printf("Description:\tUnsigned decimal integer.\n\n");
			printf("Output:\t\t%u\n", -5);
			printf("Output:\t\t%u\n\n", 7256);
		#endif
		#if defined SPEC_O
			printf("Command:\tprintf(\"%%o\", -7); printf(\"%%o\", 7); printf(\"%%o\", 8)\n\n");
			printf("Description:\tUnsigned octal.\n\n");
			printf("Output:\t\t%o\n", -7);
			printf("Output:\t\t%o\n", 7);
			printf("Output:\t\t%o\n\n", 8);
		#endif
		#if defined SPEC_LOWER_X
			printf("Command:\tprintf(\"%%x\", -716); printf(\"%%x\", 7); printf(\"%%x\", 716)\n\n");
			printf("Description:\tUnsigned hexadecimal integer.\n\n");
			printf("Output:\t\t%x\n", -716);
			printf("Output:\t\t%x\n", 7);
			printf("Output:\t\t%x\n\n", 716);
		#endif
		#if defined SPEC_X
			printf("Command:\tprintf(\"%%X\", -716); printf(\"%%X\", 7); printf(\"%%X\", 716)\n\n");
			printf("Description:\tUnsigned hexadecimal integer.\n\n");
			printf("Output:\t\t%X\n", -716);
			printf("Output:\t\t%X\n", 7);
			printf("Output:\t\t%X\n\n", 716);
		#endif
		#if defined SPEC_LOWER_F
			printf("Command:\tprintf(\"%%f\", -7.35); printf(\"%%f\", 7); printf(\"%%f\", 7.0); printf(\"%%f\", 7.35)\n\n");
			printf("Description:\tDecimal floating point, lowercase.\n\n");
			printf("Output:\t\t%f\n", -7.35);
			printf("Output:\t\t%f\n", 7);
			printf("Output:\t\t%f\n", 7.0);
			printf("Output:\t\t%f\n\n", 7.35);
		#endif
		#if defined SPEC_F
			printf("Command:\tprintf(\"%%F\", -7.35); printf(\"%%F\", 7); printf(\"%%F\", 7.0); printf(\"%%F\", 7.35)\n\n");
			printf("Description:\tDecimal floating point, uppercase.\n\n");
			printf("Output:\t\t%F\n", -7.35);
			printf("Output:\t\t%F\n", 7);
			printf("Output:\t\t%F\n", 7.0);
			printf("Output:\t\t%F\n\n", 7.35);
		#endif
		#if defined SPEC_LOWER_E
			printf("Command:\tprintf(\"%%e\", -735000); printf(\"%%e\", 700000); printf(\"%%e\", 0.0000256); printf(\"%%e\", 735000)\n\n");
			printf("Description:\tScientific notation (mantissa/exponent), lowercase.\n\n");
			printf("Output:\t\t%e\n", -735);
			printf("Output:\t\t%e\n", 700);
			printf("Output:\t\t%e\n", 0.0000256);
			printf("Output:\t\t%e\n\n", 735);
			printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
		#endif
		#if defined SPEC_E
			printf("Command:\tprintf(\"%%E\", -735000); printf(\"%%E\", 700000); printf(\"%%E\", 0.0000256); printf(\"%%E\", 735000)\n\n");
			printf("Description:\tScientific notation (mantissa/exponent), uppercase.\n\n");
			printf("Output:\t\t%E\n", -735000);
			printf("Output:\t\t%E\n", 700000);
			printf("Output:\t\t%E\n", 0.0000256);
			printf("Output:\t\t%E\n\n", 735000);
		#endif
		#if defined SPEC_LOWER_G
			printf("Command:\tprintf(\"%%g\", -735000); printf(\"%%g\", 700000); printf(\"%%g\", 0.0000256); printf(\"%%g\", 735000)\n\n");
			printf("Description:\tUse the shortest representation: %%e or %%f.\n\n");
			printf("Output:\t\t%g\n", -735000);
			printf("Output:\t\t%g\n", 700000);
			printf("Output:\t\t%g\n", 0.0000256);
			printf("Output:\t\t%g\n\n", 735000);
		#endif
		#if defined SPEC_G
			printf("Command:\tprintf(\"%%G\", -735000); printf(\"%%G\", 700000); printf(\"%%G\", 0.0000256); printf(\"%%G\", 735000)\n\n");
			printf("Description:\tUse the shortest representation: %%E or %%F.\n\n");
			printf("Output:\t\t%G\n", -735000);
			printf("Output:\t\t%G\n", 700000);
			printf("Output:\t\t%G\n", 0.0000256);
			printf("Output:\t\t%G\n\n", 735000);
		#endif
		#if defined SPEC_LOWER_A
			printf("Command:\tprintf(\"%%a\", -18.35); printf(\"%%a\", 18); printf(\"%%a\", 18.0); printf(\"%%a\", 18.35)\n\n");
			printf("Description:\tHexadecimal floating point, lowercase.\n\n");
			printf("Output:\t\t%a\n", -18.35);
			printf("Output:\t\t%a\n", 18);
			printf("Output:\t\t%a\n", 18.0);
			printf("Output:\t\t%a\n\n", 18.35);
		#endif
		#if defined SPEC_A
			printf("Command:\tprintf(\"%%A\", -18.35); printf(\"%%A\", 18); printf(\"%%A\", 18.0); printf(\"%%A\", 18.35)\n\n");
			printf("Description:\tHexadecimal floating point, upperrcase.\n\n");
			printf("Output:\t\t%A\n", -18.35);
			printf("Output:\t\t%A\n", 18);
			printf("Output:\t\t%A\n", 18.0);
			printf("Output:\t\t%A\n\n", 18.35);
		#endif
		#if defined SPEC_C
			printf("Command:\tprintf(\"%%c\", \'a\')\n\n");
			printf("Description:\tCharacter.\n");
			printf("Output:\t\t%c\n\n", 'a');
		#endif
		#if defined SPEC_S
			printf("Command:\tprintf(\"%%s\", \"This\\tis a string\")\n\n");
			printf("Description:\tString.\n\n");
			printf("Output:\t\t%s\n\n", "This\tis a string");
		#endif
		#if defined SPEC_P
			int var = 0;
			printf("Command:\tprintf(\"%%p\", &var)\n\n");
			printf("Description:\tPointer address.\n\n");
			printf("Output:\t\t%p\n\n", &var);
		#endif
		#if defined SPEC_N
			char count [] = " asshole!";
			printf("Command:\tprintf(\"%%n\", \"OK\")\n\n");
			printf("Description:\tNothing printed.\n\t\tThe corresponding argument must be a pointer to a signed int.\n\t\tThe number of characters written so far is stored in the pointed location.\n\n");
			printf("Output:\t\tFuck yeah,%n bitch!\n\n", &count);
			/**/
			printf("%s",count);
		#endif
	#endif

	#if defined FLAGS_TESTS
		printf("~FLAGS TESTS~\n\n");
		#if defined FLAG_SPACE
			printf("Command:\tprintf(\"|%%10d\\n\", 10')\n\n");
			printf("Description:\tIf no sign is going to be written, a blank space is inserted before the value.\n\n");
			printf("Output:\t\t|%10d\n\n", 10);
		#endif 
		#if defined FLAG_MINUS
			printf("Command:\tprintf(\"|%%-10d\\n\", 10')\n\n");
			printf("Description:\tLejustify within the given field width; Right justification is the default (see width sub-specifier).\n\n");
			printf("Output:\t\t|%-10d\n\n", 10);
		#endif
		#if defined FLAG_PLUS
			printf("Command:\tprintf(\"%%+d\\n\", 10'); printf(\"%%+d\\n\", -10')\n\n");
			printf("Description:\tForces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.\n\t\tBy default, only negative numbers are preceded with a - sign.\n\n");
			printf("Output:\t\t%+d\n", 10);
			printf("Output:\t\t%+d\n\n", -10);
		#endif
		#if defined FLAG_HASH
			printf("Command:\tprintf (\"Output:\\t%%d %%x %%o %%#x %%#o\", 100, 100, 100, 100, 100)\n\n");
			printf("Description:\tUsed with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than\n\t\tzero.\n\t\tUsed with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow.\n\t\tBy default, if no digits follow, no decimal point is written.\n\n");
			printf ("Output:\t\t%d %x %o %#x %#o \n\n", 100, 100, 100, 100, 100);
		#endif
		#if defined FLAG_ZEROPAD
			printf("Command:\tprintf(\"%%010d\\n\", 10')\n\n");
			printf("Description:\tLepads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).\n\n");
			printf("Output:\t\t%010d\n", 10);
		#endif
		#if defined FLAG_STAR
			printf("Command:\tprintf(\"|%%*d\", 5, 10)\n\n");
			printf("Description:\tThe width is not specified in the format string,\n\t\tbut as an additional integer value argument preceding the argument that has to be formatted.\n\n");
			printf("Output:\t\t|%*d\n\n", 5, 10);
		#endif
		#if defined FLAG_PRECISION
			printf("Command:\tprintf(\"%%+.2f\", 10.365); printf(\"%%+.6d\", 1015); printf(\"%%+.8d\", 1015); printf(\"%%+.8s\", \"String wich will cut\")\n\n");
			printf("Description:\tFor integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written.\n\t\tIf the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer.\n\t\tA precision of 0 means that no character is written for the value 0.\n\t\tFor a, A, e, E, f and F specifiers: this is the number of digits to be printed ar the decimal point (by default, this is 6).\n\t\tFor g and G specifiers: This is the maximum number of significant digits to be printed.\n\t\tFor s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.\n\t\tIf the period is specified without an explicit value for precision, 0 is assumed.\n\n");
			printf("Output:\t\t%.2f\n", 10.365);
			printf("Output:\t\t%.6d\n", 1015);
			printf("Output:\t\t%.8f\n", 10.365);
			printf("Output:\t\t%.8s\n\n", "String wich will cut");
		#endif
	#endif
}
