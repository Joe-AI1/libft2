/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:08:11 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 00:25:28 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_atoi(const char *nptr);
void		pushcheck(int ar, char **box);
char		*putstr(char *str);
void		swapbox(char **box, int x);
void		shift_up(char **box, int t);
void		shift_down(char **box, int t);
void		smallswap(char **box, int ar);
void		pushboxlen(char **box, char **box2, int t, int ar);
void		swapboth(char **box, char **box2);
int			checkmin(char **box);
int			checkmax(char **box);
int			locationchecker(char **box, int num);
int			boxlen(char **box);
int			locationamount(char **box, char **box2, int boxnum1, int boxnum2);
void		docommand(char **box, int boxnum1, int t);
int			checktarget(char **box, char **box2);
int			pushbackcheck(char **box, int num);
void		rotatetillperfect(char **box);
void		lastthree(char **box);
int			findnumberfairfont(char **box, int num);
void		smallswap(char **box, int ar);
void		pushback(char **box, char **box2, int ar);
void		docommandforboth(char **box, char **box2, int boxnum1, int boxnum2);
int			commandlencheck(char **box, int boxnum1);
void		shift_downforboth(char **box, char **box2);
void		shift_upforboth(char **box, char **box2);
int			checkchar(char *str);
int			checknum(char **ag, char *str, int ar, char **box);
char		**ft_split(char const *s, char c);
long int	ft_atoilong(const char *nptr);
int			countboxlen(int ar, char **ag);
int			checknumlen(char *str);
int			realchecker(char *str, char **ag, int ar);
char		**givebox(int ar, char **ag);
int			ft_strlen2(char *str);
void		freethedangbox(char **box);
void		fillbox(char **box2, int ar);
int			checkifalreadydone(char **box);
int			howmuchchar(char *s, char c);

#endif