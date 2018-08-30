/*
** utils.c for main in /home/Neferett/bin/IMPORT
**
** Made by Bonaldi Jordan
** Login   <Neferett@epitech.net>
**
** Started on  Mon Nov 14 14:04:13 2016 Bonaldi Jordan
** Last update	Thu Feb 16 23:52:04 2017 Jordan Bonaldi
*/

# include "project.h"

t_string		*signal_str;

static void	sig(int signal, siginfo_t *siginfo, void *ucontext)
{
  static char 	c;
  static int		j;

  (void)ucontext;
  c = c | ((signal == SIGUSR2) << j);
  if (++j > 7 && c && !(j = 0))
    {
      signal_str->recreate(signal_str,
        my_strcatc(signal_str->str, c));
      c = 0;
    }
  else if (j > 7 && !c && !(j = 0) && !(c = 0))
    signal_str->end = '\n';
  usleep(1000);
  kill((int)siginfo->si_pid, SIGUSR1);
}

char				*recept_handler()
{
  struct sigaction	sa;

  sa.sa_sigaction = sig;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO | SA_ONSTACK;
  if (!signal_str)
    signal_str = init_string("0");
  else
    signal_str->recreate(signal_str, "0");
  if (sigaction(SIGUSR1, &sa, NULL) < 0)
    my_printf("There's a problem with SIGUSR1\n");
  if (sigaction(SIGUSR2, &sa, NULL) < 0)
    my_printf("There's a problem with SIGUSR2\n");
  while (true)
    {
      if (signal_str->size > 1 && signal_str->end == '\n')
	      return (++signal_str->str);
      pause();
    }
  return (NULL);
}

static void		lol(int signal)
{
  (void)signal;
}
static void		send_bin_char(int pid, char str)
{
  int		i;

  i = -1;
  while (++i < 8)
    {
      usleep(1000);
      kill(pid, ((str >> i) & 1) == 0 ? SIGUSR1 : SIGUSR2);
      signal(SIGUSR1, lol);
      pause();
    }
}

boolean		send_bin(int pid, char *str)
{
  while (*str)
    send_bin_char(pid, *str++);
  send_bin_char(pid, 0);
  return (true);
}
