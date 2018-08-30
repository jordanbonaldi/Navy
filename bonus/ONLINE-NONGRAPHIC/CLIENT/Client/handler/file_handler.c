/*
** file_handler.c for file_handler in /home/Neferett/Server
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Dec 12 10:28:16 2016 Bonaldi Jordan
** Last update Sat Jan 21 19:57:25 2017 Bonaldi Jordan
*/

# include "project.h"

void	send_file(t_client *sv, char *file, int length)
{
  FILE  *fs;

  if (!(sv->filebuf = malloc(length)))
    my_exit("ERROR: ");
  sv->file = file;
  my_printf("[Client] Sending %s ...\n", sv->file);
  if (!(fs = fopen(sv->file, "r")))
    my_exit("ERROR: Problem with file:");
  bzero(sv->filebuf, length);
  while ((sv->fs = fread(sv->filebuf, 1, 512, fs)) > 0)
    if (send(sv->fd, sv->filebuf, sv->fs, 0) < 0)
      my_exit("ERROR: Failed to send the file :");
    else
      bzero(sv->filebuf, length);
  my_printf("[Client] File sent successfully.\n");
}
