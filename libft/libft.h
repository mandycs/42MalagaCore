/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:40:24 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/08 16:43:20 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_isdigit(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strchr(const char *s, unsigned int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strlen_2(const char **s);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnrcmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isxdigit(int c);
int					ft_isgraph(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_ispunct(int c);
int					ft_iscntrl(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(char *str);
double				ft_sqrt(double x);
double				ft_double(double x, double y);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_invert(char *s1);
int					ft_numlen(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);
int					ft_indexchar(const char *s, char c);
int					ft_count_words(const char *s, char c);
char				**ft_fill_array(char **str, char const *s, char c);
t_list				*ft_lstnew(void *content);
#endif