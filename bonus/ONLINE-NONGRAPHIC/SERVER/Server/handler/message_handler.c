/*
** message_handler.c for messages_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Thu Dec 15 21:55:01 2016 Bonaldi Jordan
** Last update	Thu Feb 16 15:31:32 2017 Jordan Bonaldi
*/

# include "project.h"

char		*receive_message(t_server *sv)
{
  int		size;
  char		*message;

  if (!(message = malloc(4096)))
    exit(84);
  size = recv(sv->nfd, message, 4096, 0);
  message[size] = 0;
  return (message);
}

boolean		send_message(t_server *sv, char *msg)
{
  if (!sv->nfd)
    return (false);
  write(sv->nfd, msg, my_strlen(msg));
  return (true);
}
