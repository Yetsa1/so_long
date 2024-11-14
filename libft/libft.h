/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetsabe <yetsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:14:39 by yeparra-          #+#    #+#             */
/*   Updated: 2024/09/09 21:59:31 by yetsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_isalpha(int number_received);
int		ft_isdigit(int digito);
int		ft_isalnum(int alpha_digit);
int		ft_isascii(int ascii);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s, const void *ct, size_t n);
void	*ft_memmove(void *s, const void *ct, size_t n);
size_t	ft_strlcpy(char *s, const char *ct, size_t n);
size_t	ft_strlcat(char *s, const char *ct, size_t n);
int		ft_toupper(int letter);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s, const char *t, size_t n);
void	*ft_memchr(const void *cs, int c, size_t n);
int		ft_memcmp(const void *cs, const void *ct, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
void	ft_striteri(char *s, void (*f) (unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);

#endif
