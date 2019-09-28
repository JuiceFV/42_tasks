cmake_minimum_required(VERSION 3.14)
project(ft_printf)

set(ft_printf_VERSION_MAJOR 1)
set(ft_printf_VERSION_MINOR 0)
set(ft_printf_VERSION ${ft_printf_VERSION_MAJOR}.${ft_printf_VERSION_MINOR})

set(SOURCE ./sources/ft_printf.c ./sources/ft_vsnprintf.c ./sources/ft_option_handler.c ./sources/utils.c ./sources/string_handler.c ./sources/number_handler.c ./sources/bonus.c)
set(HEADERS ./includes/ft_printf.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})