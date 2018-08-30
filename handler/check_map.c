/*
** check_map.c for navy in /home/benki/Bureau/PSU_2016_navy
**
** Made by Lucas Benkemoun
** Login   <lucas.benkemoun@epitech.eu>
**
** Started on  Sun Feb  5 18:31:14 2017 Lucas Benkemoun
** Last update Sun Feb 12 12:37:23 2017 Jordan Bonaldi
*/

#include "project.h"

int		check_str(char *str)
{
  if (str[0] != '2' && str[0] != '3' && str[0] != '4' && str[0] != '5')
    return (1);
  if (str[1] != ':')
    return (1);
  if (str[4] != ':')
    return (1);
  if (!((my_isalpha(str[2]) && my_isnum(str[3])) ||
	(my_isalpha(str[3]) && my_isnum(str[2]))))
    return (1);
  if (!((my_isalpha(str[5]) && my_isnum(str[6])) ||
	(my_isalpha(str[6]) && my_isnum(str[5]))))
    return (1);
  return (0);
}

int		check_length(char *b)
{
  boolean      	three;
  boolean      	two;
  boolean	four;
  boolean	five;
  int		i;
  int		ret;

  if (!(i = -1) && !(three = 0) && !(two = 0) &&
      !(four = 0) && !(five = 0)) {}
  while (++i < 4)
    {
      if (b[i * 8 + 2] >= '0' && b[i * 8 + 2] <= '9')
      	my_swap_char(&b[i * 8 + 2], &b[i * 8 + 3]);
      if (b[i * 8 + 5] >= '0' && b[i * 8 + 5] <= '9')
      	my_swap_char(&b[i * 8 + 5], &b[i * 8 + 6]);
      if ((b[i * 8] == '2') && (ret = ch_bl(b, i, 1)) && (two = 1)) {}
      if ((b[i * 8] == '3') && (ret = ch_bl(b, i, 2)) && (three = 1)) {}
      if ((b[i * 8] == '4') && (ret = ch_bl(b, i, 3)) && (four = 1)) {}
      if ((b[i * 8] == '5') && (ret = ch_bl(b, i, 4)) && (five = 1)) {}
      if (ret == 0)
	break;
    }
  if (two && three && four && five)
    return (0);
  return (1);
}

int		ch_bl(char *buffer, int i, int length)
{
  if (buffer[i * 8 + 2] == buffer[i * 8 + 5])
    {
      if ((buffer[i * 8 + 6] - buffer[i * 8 + 3]) == length)
	return (1);
      if ((buffer[i * 8 + 3] - buffer[i * 8 + 6]) == length)
	return (1);
    }
  if (buffer[i * 8 + 3] == buffer[i * 8 + 6])
    {
      if ((buffer[i * 8 + 5] - buffer[i * 8 + 2]) == length)
	return (1);
      if ((buffer[i * 8 + 2] - buffer[i * 8 + 5]) == length)
	return (1);
    }
  return (0);
}

int		check_map(char *path)
{
  int		fd;
  char		buffer[35];
  int		size;
  int		i;

  if ((fd = open(path, O_RDONLY)) < 0 ||
      (size = read(fd, buffer, 35)) < 0)
    return (1);
  buffer[size] = 0;
  i = -1;
  if (my_strlen(buffer) < 31 || my_strlen(buffer) > 32)
    return (1);
  while (++i < 4)
    if (check_str(&buffer[i * 8]))
      return (1);
  if (check_length(my_strupcase(buffer)))
    return (1);
  return (0);
}
