#include "../includes/Hotrace.h"

void	error_print(int error)
{
	if (error == MALLOC_ERROR)
		write(2, "MESSAGGIO ERRORE", 1);
	if (error == SYNTAX_ERROR)
		write(2, "MESSAGGIO ERRORE", 1);
}