/*
** main.c for main in /home/Neferett/bin/IMPORT
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:34:41 2017 Jordan Bonaldi
*/

#include "project.h"

int		main(int argc, char **argv)
{
  if (argc == 4)
    {
      if (client(my_getnbr(argv[1]), argv[2], argv[3]))
	return (90);
    }
  else
    my_printf("Bad number of arguments\n");
  return (0);
}
