/*
** my_exit.c for lib in /home/Neferett/wolf3d
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Sun Jan  1 20:02:18 2017 Bonaldi Jordan
** Last update Sun Jan  1 20:22:49 2017 Bonaldi Jordan
*/

# include "lib.h"

void		my_exit(int exitid, int line, char *file, char *process)
{
  my_printf("Error at line %d of %s for %s ===> Exit (%d)\n",
	    line, file, process, exitid);
  exit(exitid);
}
