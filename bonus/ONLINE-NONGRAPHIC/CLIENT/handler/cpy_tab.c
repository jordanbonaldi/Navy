/*
** cpy_tab.c for navy in /home/lucas99.06/PSU_2016_navy
** 
** Made by Lucas Benkemoun
** Login   <benke_l@epitech.net>
** 
** Started on  Tue Jan 31 17:21:29 2017 Lucas Benkemoun
** Last update Tue Jan 31 17:22:58 2017 Lucas Benkemoun
*/

#include "project.h"

char             **init_tab(char **tab)
{
  tab[0] = my_strdup(" |A B C D E F G H");
  tab[1] = my_strdup("-+---------------");
  tab[2] = my_strdup("1|. . . . . . . .");
  tab[3] = my_strdup("2|. . . . . . . .");
  tab[4] = my_strdup("3|. . . . . . . .");
  tab[5] = my_strdup("4|. . . . . . . .");
  tab[6] = my_strdup("5|. . . . . . . .");
  tab[7] = my_strdup("6|. . . . . . . .");
  tab[8] = my_strdup("7|. . . . . . . .");
  tab[9] = my_strdup("8|. . . . . . . .");
  tab[10] = NULL;
  return (tab);
}
