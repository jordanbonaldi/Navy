/*
** socket_handler.c for socket_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:16:56 2016 Bonaldi Jordan
** Last update Sat Jan 21 19:58:04 2017 Bonaldi Jordan
*/

# include "project.h"

void	create_socket_desc(t_client *sv)
{
  if ((sv->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    my_exit_cl("ERROR: Failed to obtain Socket Descriptor :");
  else
    my_printf("[Server] Socket descriptor obtained successfully.\n");
}
