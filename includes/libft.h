/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2023/11/23 12:37:24 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 2048

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_strnstr(const char *haystack, const char *needle, size_t len, int ks);
int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *dst, const char *src);

#endif
