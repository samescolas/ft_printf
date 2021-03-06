/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:24:45 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/12 13:18:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 32

# define DEFAULT "\x1B[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	int				fd;
	char			buffer[BUFF_SIZE + 1];
	struct s_file	*next;
}					t_file;

ssize_t				ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_ceil(int a, int b);
int					ft_countwords(const char *s, char c);
int					ft_exp(int base, int power);
void				ft_fatal(char *s);
int					ft_isalnum(int n);
int					ft_isalpha(int n);
int					ft_isascii(int n);
int					ft_isdigit(int n);
int					ft_isprime(int n);
int					ft_isprint(int n);
char				*ft_itoa_base(intmax_t n, short base, char base_case);
char				*ft_itoa_base_u(uintmax_t n, short base, char base_case);
void				ft_lstadd(t_list **alst, t_list *new_node);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_numlen(intmax_t n, short base);
size_t				ft_numlen_u(uintmax_t n, short base);
int					ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(intmax_t n);
void				ft_putnbr_u(uintmax_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_padstr(const char *s, int offset, char *color);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
int					ft_sqrt(int n);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strcount(char *str, char c);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
wchar_t				*ft_wstrdup(const wchar_t *s1);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strfind(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_wstrlen(const wchar_t *str);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_wrap(char *str, char c);
int					get_next_line(const int fd, char **line);

#endif
