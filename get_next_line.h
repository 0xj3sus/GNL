/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhayyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 07:43:20 by yhayyani          #+#    #+#             */
/*   Updated: 2026/11/27 07:43:22 by yhayyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  42
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 100
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strjoin(const char *s1, const char *s2);
char *extract_line(char *stash);
char *update_stash(char *stash);
char *read_to_stash(int fd, char *stash);
#endif

