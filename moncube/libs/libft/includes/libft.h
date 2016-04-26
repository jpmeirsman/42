/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:01:19 by gsimeon           #+#    #+#             */
/*   Updated: 2016/03/30 19:44:48 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <wchar.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**							MEMORY USAGE
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**							STRINGS USAGE
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_boardset(int x, int y, char c);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
char				*ft_wtoc(wchar_t w);
char				*ft_wstrtostr(wchar_t *str);
void				ft_strtoupper(char *str);

/*
**							LIST USAGE
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstend(t_list **lst, t_list *new);
size_t				ft_lstinser(t_list **lst, t_list *src, size_t n);
size_t				ft_lstlen(t_list *lst);
t_list				*ft_lstshift(t_list **lst);

/*
**							DISPLAY USAGE
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, size_t n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, size_t l, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_boardprint(char **tab, int x, int y);
int					ft_isprint(int c);
int					ft_gnl(int const fd, char **line);
int					ft_printf(const char *str, ...);

/*
**							INTEGER USAGE
*/

char				*ft_itoa(int n);
int					ft_isdigit(int c);
int					ft_isnumber(int c);
int					ft_pwr(int n, int p);
int					**ft_intboardset(int x, int y, int c);

/*
**							OTHER USAGE
*/

size_t				ft_atoi_base(const char *str, int base);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isspace(char	s);
void				ft_swap(int *a, int* b);

/*
**							PRINTF USAGE
*/

int					pf_solve_flags(char **src, int *width, int *precision, va_list *ap);
char				*pf_apply_flags(char **str, void *ptr, va_list *ap);
char				*pf_itoa(void *ptr, char output, int flags);

typedef 			struct TList List;
struct 				TList
{
	void			*first;
};

List				*initialisation();
void				realloc_str(char ** Source, long long len, long long lenmore);

#endif
