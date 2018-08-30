/*
** utils_char.c for utils_char in /home/neferett/EPITECH/PSU_2016_navy
** 
** Made by Jordan Bonaldi
** Login   <neferett@epitech.eu>
** 
** Started on  Sun Feb 12 12:34:32 2017 Jordan Bonaldi
** Last update Sun Feb 12 12:36:10 2017 Jordan Bonaldi
*/

# include "project.h"

char            my_isnum(char c)
{
  if (c >= '1' && c <= '8')
    return (1);
  else
    return (0);
}

char            my_isalpha(char c)
{
  if ((c >= 'A' && c <= 'H') ||
      (c >= 'a' && c <= 'h'))
    return (1);
  else
    return (0);
}
