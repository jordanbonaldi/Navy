/*
** main.c for main in /home/Neferett/bin/IMPORT
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:37:57 2017 Jordan Bonaldi
*/

#include "project.h"

int		main(int argc, char **argv)
{
  if (argc == 3)
    {
      if (server(my_getnbr(argv[1]), argv[2]))
	return (84);
    }
  else
    my_printf("Bad number of arguments\n");
  return (0);
}
