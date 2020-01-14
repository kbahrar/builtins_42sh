/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:41:40 by kbahrar           #+#    #+#             */
/*   Updated: 2019/07/11 16:06:01 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFF_SIZE 8

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				**ft_tabjoin(char **tab1, char **tab2, int place);
char				*rem_decal(int place, char ch, char *str);
int					ft_howmanynum(long long int num);
char				*ft_chreplace(char *str, char origin, char cpy);
t_list				*ft_add_link(t_list *lst, void *content,
					size_t content_size);
void				ft_swap(char **a, char **b);
void				ft_print_list(t_list *list);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void**ap);
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strequ(char const *s1, char const *s2);
void				ft_strclr(char *s);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr(long long n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(char const *s);
void				ft_putstr_plus(char *str, char *str2);
char				*ft_strcpy_b(char *dst, const char *src);
char				*ft_pathjoin(char *path, char *dossier);
int					get_next_line(const int fd, char **line);

#endif
