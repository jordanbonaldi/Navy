/*
** message_handler.c for message_handler in /home/Neferett/Client
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Fri Dec 16 11:21:22 2016 Bonaldi Jordan
** Last update Sat Feb  4 15:25:42 2017 Jordan Bonaldi
*/

# include "project.h"

boolean		send_message(t_client *cl, char *msg)
{
  if (send(cl->fd, msg, my_strlen(msg), 0) < 0)
    {
      close(cl->fd);
      return (false);
    }
  return (true);
}

char    *receive_message(t_client *cl)
{
  int   size;
  char  *message;

  if (!(message = malloc(4096)))
    exit(84);
  size = recv(cl->fd, message, 4096, 0);
  message[size] = 0;
  return (message);
}
