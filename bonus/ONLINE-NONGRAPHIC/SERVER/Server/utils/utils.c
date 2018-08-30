/*
** utils.c for utils in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 09:52:59 2016 Bonaldi Jordan
** Last update Sat Jan 21 12:54:10 2017 Bonaldi Jordan
*/

# include "project.h"

void	my_exit_server(char *str)
{
  perror(str);
  exit(84);
}
