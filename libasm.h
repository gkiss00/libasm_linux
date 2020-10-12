/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:28:56 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 11:37:03 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>

/*
** stdio to declare ssize_t
*/

ssize_t         ft_write(int fd, char *buf, int n);
ssize_t         ft_read(int fd, char *buf, int n);
size_t          ft_strlen(const char *str);
char            *ft_strcpy(char *dst, const char *src);
int             ft_strcmp(const char *s1, const char *s2);
char            *ft_strdup(const char *str);

#endif