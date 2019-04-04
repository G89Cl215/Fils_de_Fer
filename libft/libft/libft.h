/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:52:06 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:01:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>

# define BUFF_SIZE	1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

size_t				ft_strlen(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
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
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_isin(const char c, const char *charset);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_str_is_alpha(const char *str);
int					ft_str_is_lowercase(const char *str);
int					ft_str_is_numeric(const char *str);
int					ft_str_is_printable(const char *str);
int					ft_str_is_uppercase(const char *str);
char				*ft_strcapitalize(char *s);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *s);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strcasestr(const char *s1, const char *s2);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				ft_printtab(char **tab);
void				ft_strrev(char *s);
int					get_next_line(const int fd, char **line);
void				ft_putchar_err(char c);
void				ft_putstr_err(char *str);
void				ft_putendl_err(char *str);
void				ft_swap(int *a, int *b);
char				*ft_itoa_base(int nb, int base);
int					*ft_range(int start, int end);
void				putnbr_base(int n, int base);
char				*ft_uitoa_base(unsigned int nb, int base);
void				putunbr_base(unsigned int n, unsigned int base);
void				putlnbr_base(long n, short base);
void				putulnbr_base(unsigned long n, unsigned int base);
void				putllnbr_base(long long n, short base);
void				putullnbr_base(unsigned long long n, unsigned int base);
long				ft_atol_base(const char *str, int base);
void				ft_putdouble(double d, unsigned short precision);
char				*ft_dtoa(double d, unsigned short precision);
char				*ft_ldtoa(long double d, unsigned short precision);
char				*ft_ltoa_base(long nb, short base);
char				*ft_ultoa_base(unsigned long nb, short base);
char				*ft_lltoa_base(long long nb, short base);
char				*ft_ulltoa_base(unsigned long long nb, short base);
int					ft_abs(int nb);
void				ft_tabdel(void **tab, size_t size);
char				*ft_strpbrk(const char *s, const char *accept);
int					ft_instr(const char c, const char *accept);
char				*ft_strncpy_safe(char *dest, const char *src, size_t n);
double				ft_pow_ten(double nb, int power);
char				*ft_dtoa_concat(char *s, long l, int sign);
char				*ft_ldtoa_concat(char *s, long long l, int sign);
void				*ft_memjoin(const void *first, size_t size_f,
						const void *second, size_t size_s);
void				*ft_memjoin_free(void *first, size_t size_f, void *second,
						size_t size_s);
char				*ft_strsubfree(char *s, unsigned int start, size_t len);
char				*ft_strjoinfree(char *s1, char *s2);
size_t				ft_arrlen(char **arr);
size_t				ft_intlen(long int n);

#endif
