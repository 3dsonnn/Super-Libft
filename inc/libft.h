/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:02:24 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 14:33:59 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include "printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
<<<<<<< HEAD
=======
# include <sys/time.h>
>>>>>>> tmp

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

//	ctype
extern int			ft_isspace(int c);
extern int			ft_isblank(int c);
extern int			ft_isalnum(int c);
extern int			ft_isalpha(int c);
extern int			ft_isascii(int c);
extern int			ft_isdigit(int c);
extern int			ft_isprint(int c);
extern int			ft_tolower(int c);
extern int			ft_toupper(int c);
extern int			ft_isupper(int c);
extern int			ft_islower(int c);

//	linked_list
int					ft_lstsize(t_list *lst);
void				del(void **content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

//	non_standard
char				*ft_itoa(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *str, char c);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);

//	stdlib
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);

//	string
int					ft_strlen(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int i);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

//	get_next_line
char				*get_next_line(int fd);

//	extras
long long int		ft_atoll(char *str);
int					ft_getpid(void);
int					ft_nbrlen(int n);
int					ft_strnbr(char *str);
int					ft_strint(char *str);
int					ft_mtxlen(char **matrix);
int					ft_longestr_mtx(char **mtx);
int					ft_strcmp(char *s1, char *s2);
int					ft_strspn(char *s, char *accept);
int					ft_strspn_rev(char *s, char *accept);
int					ft_strchr_count(char *str, int c);
int					ft_strcspn(char *s, char *reject);
int					ft_word_count(char const *s, char c);
int					ft_strnfill(char *dest, char *src, int n);
int					ft_countstr_mtx(char **matrix, char *str);
int					ft_str_case_cmp(char *s1, char *s2);
int					ft_map(int old_value, int old_limits[2], int new_limits[2]);
void				ft_mtxfree(char ***matrix);
void				ft_strfree(char **str);
void				ft_swaptr(void **p1, void **p2);
void				ft_replace_char(char *str, char src, char dst);
void				flood_fill(char **tab, t_point size, t_point begin);
char				*ft_strpbrk(char *str, char *accept);
char				*ft_strqbrk(char *str, char *accept);
char				*ft_strcpy(char *dest, char *src);
char				**ft_mtxdup(char **matrix);
char				**ft_addstr_mtx(char ***matrix, char **tmp, char *str);
char				*ft_strndup(char *str, int n);
char				*ft_strjoin(char **str, char **buffer, int flag);
char				**ft_lstmtx(t_list *lst);
void				ft_join(char **new_str, char *str, char *buffer);
char				**ft_realloc(char **matrix, char **tmp, int old_size,
						int new_size);
extern int			ft_origin_point(t_point point);
extern int			ft_negative_point(t_point point, int flag);
extern t_point		ft_center_range(t_point big, t_point lil);
unsigned long long	ft_gettimeofday(void);

>>>>>>> tmp
#endif
