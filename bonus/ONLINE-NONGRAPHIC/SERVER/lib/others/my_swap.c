/*
** my_swap.c for my_swap in /home/Neferett/CPool_Day04
** 
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
** 
** Started on  Thu Oct  6 08:59:02 2016 Bonaldi Jordan
** Last update Wed Feb  1 15:37:25 2017 Jordan Bonaldi
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  if (*a > *b)
    {
      temp = *a;
      *a = *b;
      *b = temp;
    }
  return (0);
}
