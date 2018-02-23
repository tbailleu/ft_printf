/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailleu <tbailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:43:20 by tbailleu          #+#    #+#             */
/*   Updated: 2018/01/06 10:53:50 by tbailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFF_SIZE 32
# define FD_MAX 12000
# define TRUE 1
# define FALSE 0
# define PRINTF_FLAGS "#0- +"
# define PRINTF_TYPES "sSpdDioOuUxXcCb"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdarg.h>
# include <errno.h>
# include <assert.h>
# include <wchar.h>
# include <inttypes.h>

typedef struct s_list		t_list;

struct			s_list
{
	void		*content;
	size_t		content_size;
	t_list		*next;
};

typedef struct	s_data
{
	int			prefix;
	int			zero_pad;
	int			right_pad;
	int			force_sign;
	int			no_sign;
	int			got_width;
	int			got_accuracy;
	uint32_t	width;
	uint32_t	accuracy;
	uint32_t	length;
}				t_data;

char			*ft_printf_parse_flags(char **fmt, t_data *data);
char			*ft_printf_parse_width(char **fmt, va_list *vl, t_data *data);
char			*ft_printf_parse_accuracy(char **fmt, va_list *vl, t_data *dat);
char			*ft_printf_parse_length(char **fmt, t_data *data);
int				ft_printf(const char *fmt, ...);
int				my_printf(const char *fmt, va_list *vl, int length);
intmax_t		ft_printf_get_signed_from_length(va_list *vl, t_data *data);
ssize_t			ft_printf_handle_wchar(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_char(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_str(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_wstr(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_long(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_longer(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_int(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_octal(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_hexa(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_ptr(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_percent(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_handle_null(char **fmt, va_list *vl, t_data *data);
ssize_t			ft_printf_nbrprefix(uintmax_t nb, char *b, t_data *d, char *p);
ssize_t			ft_printfu(uintmax_t nb, t_data *data, char *b, char *p);
typedef ssize_t	(*t_handler)(char**, va_list*, t_data*);
t_handler		ft_printf_get_handler(char c);
uintmax_t		ft_printf_get_unsigned_from_length(va_list *vl, t_data *data);
unsigned int	ft_printf_maxstrlen(uintmax_t nb, char *b, char *p, t_data *d);
unsigned int	ft_nbrlen_base(uintmax_t nb, char *base);
void			ft_printf_width_pad(int nbrstrlen, int width, char padwith);

size_t			ft_wcslen(const wchar_t *s);
int				ft_wcscmp(const wchar_t *s1, const wchar_t *s2);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
void			*ft_malloc(size_t size);
void			*ft_realloc(void *data, int size);
void			*ft_calloc(size_t nelem, size_t elsize);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strcat_swap(char *s1, const char *s2);
char			*ft_strrev(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strsubfree(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplitfree(char const *s, char c);
void			ft_putchar(char c);
int				ft_putnchar(char c, int *n);
void			ft_putwchar(wchar_t c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_puttendl(const char **tab);
void			ft_putnbr(long n);
void			ft_putnbrbase(uintmax_t nbr, char *base);
void			ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putwchar_fd(wchar_t c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(long n, int fd);
void			ft_putbin(uint64_t nb, const char sep, size_t n, size_t sl);
int				ft_isspace(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t			ft_strcnt_sep(const char *s, char c);
size_t			ft_nbrlen(int n);
size_t			ft_wcharlen(wchar_t w);
size_t			ft_wstrlen(wchar_t *wstr);
unsigned		ft_minmax(unsigned m, unsigned a, unsigned b);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
char			*ft_readfile(const int fd);
int				ft_sqrt(int nb);
int				get_next_line(const int fd, char **line);
void			ft_throw_error(int bool, char *s);
int				ft_getnbr(char *str);
int				ft_nbline_file(char *file);
#endif
