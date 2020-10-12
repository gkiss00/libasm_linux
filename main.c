/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:22:24 by gkiss             #+#    #+#             */
/*   Updated: 2020/02/01 12:11:39 by gkiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"

void		follow4(void)
{
	char	*str;
	char	*duplicated;

	str = "je vais etre dupliquer";
	printf("*******************\n");
	printf("test      ft_strdup\n");
	printf("*******************\n");
	duplicated = ft_strdup(str);
	printf("la string str => \"%s\" et duplicated => \"%s\" sont les memes\n", str, duplicated);
	free(duplicated);
	duplicated = ft_strdup(NULL);
	printf("la string str => \"%s\" et duplicated => \"%s\" sont les memes\n", NULL, duplicated);
	duplicated = ft_strdup("");
	printf("la string str => \"%s\" et duplicated => \"%s\" sont les memes\n", "", duplicated);
	free(duplicated);
}

void		follow3(void)
{
	char	buff[10];
	printf("*******************\n");
	printf("test       ft_write\n");
	printf("*******************\n");
	write(1, "je suis ecrit par write\n", 24);
	ft_write(1, "je suis ecrit par ft_write\n", 27);
	write(16, "je suis ecrit par write\n", 24);
	printf("%s\n", strerror(errno));
	ft_write(16, "je suis ecrit par ft_write\n", 27);
	printf("%s\n", strerror(errno));
	printf("\n\n\n");
	printf("*******************\n");
	printf("test        ft_read\n");
	printf("*******************\n");
	ft_read(0, buff, 9);
	//ft_read(12, buff, 9);
	//printf("%s\n", strerror(errno));
	buff[9] = '\0';
	ft_write(1, buff, 10);
	printf("\n\n\n");
	follow4();
}

void		follow2(void)
{
	int		r;
	char	*chat;
	char	*chien;

	chat = "chat";
	chien = "chien";
	printf("*******************\n");
	printf("test      ft_strcmp\n");
	printf("*******************\n");
	r = strcmp(chat, chien);
	printf("strcmp    :: la string \"%s\" et \"%s\" ont %d de decalage\n", chat, chien, r);
	r = ft_strcmp(chat, chien);
	printf("ft_strcmp :: la string \"%s\" et \"%s\" ont %d de decalage\n", chat, chien, r);
	r = strcmp(chien, chat);
	printf("strcmp    :: la string \"%s\" et \"%s\" ont %d de decalage\n", chien, chat, r);
	r = ft_strcmp(chien, chat);
	printf("ft_strcmp :: la string \"%s\" et \"%s\" ont %d de decalage\n", chien, chat, r);
	r = strcmp(chat, chat);
	printf("strcmp    :: la string \"%s\" et \"%s\" ont %d de decalage\n", chat, chat, r);
	r = ft_strcmp(chat, chat);
	printf("ft_strcmp :: la string \"%s\" et \"%s\" ont %d de decalage\n", chat, chat, r);
	printf("\n\n\n");
	follow3();
}

void		follow1(void)
{
	char	*source;
	char	dest1[16];
	char	dest2[16];

	source = "on va me copier";
	printf("*******************\n");
	printf("test      ft_strcpy\n");
	printf("*******************\n");
	printf("copie pas encore effectue    => source \"%s\" => dest \"%s\"\n", source, dest1);
	strcpy(dest1, source);
	ft_strcpy(dest2, source);
	printf("strcpy    :: copie effectue               => source \"%s\" dest \"%s\"\n", source, dest1);
	printf("ft_strcpy :: copie effectue               => source \"%s\" dest \"%s\"\n", source, dest2);
	dest1[0] = 'k';
	dest2[0] = 'k';
	printf("strcpy    :: changement sur dest          => source \"%s\" dest \"%s\"\n", source, dest1);
	printf("ft_strcpy :: changement sur dest          => source \"%s\" dest \"%s\"\n", source, dest2);
	printf("\n\n\n");
	follow2();
}

int			main(void)
{
	char	*strfull;
	char	*strvide;

	strfull = "je suis un string de longueur 32";
	strvide = "";
	printf("*******************\n");
	printf("test      ft_strlen\n");
	printf("*******************\n");
	printf("strlen    :: la string \"%s\" a une longueur de %lu\n", strfull, strlen(strfull));
	printf("strlen    :: la string \"%s\" a une longueur de %lu\n", strvide, strlen(strvide));
	printf("ft_strlen :: la string \"%s\" a une longueur de %zu\n", strfull, ft_strlen(strfull));
	printf("ft_strlen :: la string \"%s\" a une longueur de %zu\n", strvide, ft_strlen(strvide));
	printf("\n\n\n");
	follow1();
	return (0);
}
