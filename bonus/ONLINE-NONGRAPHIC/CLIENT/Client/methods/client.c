/*
** server.c for server in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:20:30 2016 Bonaldi Jordan
** Last update Sat Jan 21 13:16:25 2017 Bonaldi Jordan
*/

# include "project.h"

void		client(int port, char *msg, int length, int mode)
{
  char		buff[1024];
  t_client	*cl;

  cl = init(port);
  if (mode == 1)
    while (true)
      {
	fgets(buff, 1024, stdin);
	message_handler(cl, buff);
      }
  else if (mode == 2)
    send_file(cl, msg, length);
  else
    while (true)
      recept_file(cl);
}
