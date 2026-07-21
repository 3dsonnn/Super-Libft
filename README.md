# Super-Libft

A from-scratch C standard library, built on top of the 42 School Libft project (mandatory part, bonus part, `get_next_line`, and `ft_printf`) and extended with a much larger `extras/` layer of string, matrix, numeric, and coordinate/grid helpers that the subject never asked for. It compiles into a single static library, `libft.a`, that drops into any 42 project's Makefile.

It also bundles [`my_mlx`](https://github.com/3dsonnn/my_mlx) as a git submodule — a small MinilibX helper layer — so graphical projects (`fdf`, `so_long`, `cub3d`, `fract-ol`, ...) get both the C library and the MLX layer from a single clone.

## Why use it

- **The full mandatory + bonus Libft**, reimplemented and norm-compliant: every `ctype`/`string`/`stdlib` function the subject requires, plus the doubly-linked `t_list` operations and the bonus string helpers (`ft_split`, `ft_itoa`, `ft_substr`, `ft_strtrim`, ...).
- **A built-in `ft_printf` / `ft_dprintf`** supporting the common conversions (`%c %s %p %d %i %u %x %X %%`) and flags (`-`, `0`, `+`, space, `#`, width, `.precision`) — no separate printf submodule needed.
- **A multi-fd `get_next_line`**, tracking up to `FD_MAX` (default `1024`) file descriptors independently with a configurable `BUFFER_SIZE` (default `42`), so reading several files or sockets at once just works.
- **A large `extras/` layer beyond the subject**: `char **` matrix helpers (dup, free, join, count, longest string), string helpers not in the subject (`ft_strcmp`, `ft_strjoin`, `ft_strspn`/`ft_strcspn`, `ft_word_count`, ...), and small coordinate/grid helpers (`t_point`, `ft_center_range`, `flood_fill`, `ft_map`) aimed at grid- and MLX-based projects.
- **`-Wall -Wextra -Werror` clean throughout**, and built without `ranlib` — the Makefile uses `ar rcs` to write the archive index directly, since the 42 Libft subject forbids `ranlib`.

## Repository layout

```
.
├── ctype/           # character classification & conversion (ft_isalpha, ft_toupper, ...)
├── string/          # memory & string primitives (ft_memcpy, ft_strlcpy, ...)
├── stdlib/          # ft_atoi, ft_calloc
├── linked_list/     # t_list: create, add, iterate, map, clear
├── non_standard/    # bonus part: ft_split, ft_itoa, ft_substr, fd writers, ...
├── get_next_line/   # get_next_line, multi-fd, configurable BUFFER_SIZE
├── printf/          # ft_printf / ft_dprintf implementation
├── extras/          # everything beyond the subject: string/matrix/point helpers, ...
├── inc/             # public headers (libft.h, printf.h)
├── my_mlx/          # MLX graphics helper library, as a git submodule
└── Makefile         # builds libft.a, then my_mlx's libmymlx.a
```

## Clone

This repository uses a git submodule for `my_mlx`.

```bash
git clone --recurse-submodules git@github.com:3dsonnn/Super-Libft.git
```

If you already cloned the repository, initialize the submodule with:

```bash
git submodule update --init --recursive
```

## Build

```bash
make
```

This compiles everything under the library's own folders into `libft.a`, then builds `my_mlx/libmymlx.a`.

## Using it in another project

Add this repository as a submodule of your project (e.g. under `libs/Super-Libft`), then in your project's Makefile:

```makefile
LIBFT     = libs/Super-Libft

CFLAGS   += -I $(LIBFT)/inc
LDFLAGS  += -L $(LIBFT) -lft

$(NAME): $(LIBFT)/libft.a
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)
```

Then in your source:

```c
#include "libft.h"
```

## Data types (`inc/libft.h`)

| Type | Purpose |
|---|---|
| `t_list` | Doubly linked list node: `content`, `prev`, `next`. |
| `t_point` | 2D `int` coordinate pair (`x`, `y`), used by the point/grid extras (`ft_origin_point`, `ft_center_range`, `flood_fill`, ...). |

## API reference

### ctype

| Function | Description |
|---|---|
| `ft_isalpha(c)` | Non-zero if `c` is an alphabetic character. |
| `ft_isdigit(c)` | Non-zero if `c` is a decimal digit. |
| `ft_isalnum(c)` | Non-zero if `c` is alphanumeric. |
| `ft_isascii(c)` | Non-zero if `c` is a 7-bit ASCII value. |
| `ft_isprint(c)` | Non-zero if `c` is printable (including space). |
| `ft_isupper(c)` / `ft_islower(c)` | Non-zero if `c` is upper/lowercase. |
| `ft_isspace(c)` / `ft_isblank(c)` | Non-zero if `c` is whitespace / a blank (space or tab). |
| `ft_toupper(c)` / `ft_tolower(c)` | Returns the upper/lowercase equivalent of `c`. |

### string

| Function | Description |
|---|---|
| `ft_strlen(str)` | Length of `str`, excluding the terminator. |
| `ft_strdup(s)` | Heap-allocated duplicate of `s`. |
| `ft_strchr(s, c)` / `ft_strrchr(s, c)` | First/last occurrence of `c` in `s`. |
| `ft_strnstr(big, little, len)` | First occurrence of `little` in the first `len` bytes of `big`. |
| `ft_strncmp(s1, s2, n)` | Lexicographic comparison of the first `n` bytes of `s1`/`s2`. |
| `ft_strlcpy(dst, src, size)` / `ft_strlcat(dst, src, size)` | Size-bounded copy/concatenation, returning the total length attempted. |
| `ft_memcpy(dst, src, n)` / `ft_memmove(dst, src, n)` | Copies `n` bytes, with (`memmove`) or without (`memcpy`) overlap safety. |
| `ft_memset(b, c, len)` / `ft_bzero(s, n)` | Fills `len`/`n` bytes with `c` / with zero. |
| `ft_memchr(s, c, n)` | First occurrence of byte `c` in the first `n` bytes of `s`. |
| `ft_memcmp(s1, s2, n)` | Byte-wise comparison of the first `n` bytes of `s1`/`s2`. |

### stdlib

| Function | Description |
|---|---|
| `ft_atoi(str)` | Parses a leading, optionally signed decimal integer out of `str`. |
| `ft_calloc(count, size)` | Zero-initialized allocation of `count * size` bytes. |

### linked_list

| Function | Description |
|---|---|
| `del(content)` | Generic `free`-and-`NULL` deleter, usable as the `del` callback below. |
| `ft_lstnew(content)` | Allocates a new node wrapping `content`. |
| `ft_lstadd_front(lst, new)` / `ft_lstadd_back(lst, new)` | Inserts `new` at the head/tail of `*lst`. |
| `ft_lstsize(lst)` | Number of nodes in the list. |
| `ft_lstlast(lst)` | Last node of the list. |
| `ft_lstiter(lst, f)` | Applies `f` to every node's content. |
| `ft_lstmap(lst, f, del)` | Builds a new list by applying `f` to every node's content, freeing on failure with `del`. |
| `ft_lstdelone(lst, del)` | Frees a single node's content (via `del`) and the node itself. |
| `ft_lstclear(lst, del)` | Frees every node of `*lst` and sets it to `NULL`. |

> **Note:** `del` is declared as `void del(void **content)`, while `ft_lstclear`/`ft_lstdelone` declare their callback parameter as `void (*del)(void *)`. Passing `del` to either directly is a function-pointer type mismatch and won't compile under `-Werror` — a cast (`(void (*)(void *))del`) or a matching custom deleter is currently required.

### non_standard (bonus part)

| Function | Description |
|---|---|
| `ft_itoa(n)` | Heap-allocated decimal string representation of `n`. |
| `ft_substr(s, start, len)` | Heap-allocated substring of `s`, from `start`, up to `len` bytes. |
| `ft_strtrim(s1, set)` | Heap-allocated copy of `s1` with leading/trailing characters in `set` removed. |
| `ft_split(str, c)` | Heap-allocated, `NULL`-terminated array of substrings, split on delimiter `c`. |
| `ft_strmapi(s, f)` | New string built by applying `f(index, char)` to every character of `s`. |
| `ft_striteri(s, f)` | Applies `f(index, char*)` to every character of `s` in place. |
| `ft_putchar_fd(c, fd)` / `ft_putstr_fd(s, fd)` / `ft_putendl_fd(s, fd)` / `ft_putnbr_fd(n, fd)` | Writes a char / string / string-plus-newline / integer directly to `fd`. |

### get_next_line

| Function | Description |
|---|---|
| `get_next_line(fd)` | Returns the next line (including the trailing `\n`, if present) from `fd`, or `NULL` at EOF/error. Tracks up to `FD_MAX` file descriptors independently, reading in `BUFFER_SIZE`-byte chunks. |

### printf

| Function | Description |
|---|---|
| `ft_printf(format, ...)` | Formatted output to `stdout`, returning the number of characters written. |
| `ft_dprintf(fd, format, ...)` | Formatted output to file descriptor `fd`, returning the number of characters written. |

Supported conversions: `%c %s %p %d %i %u %x %X %%`.
Supported flags: `-` (left-justify), `0` (zero-pad), `+` / space (sign), `#` (alternate form), field width, and `.precision`.

### extras — string utilities

| Function | Description |
|---|---|
| `ft_strcmp(s1, s2)` / `ft_str_case_cmp(s1, s2)` | Lexicographic comparison, case-sensitive / case-insensitive. |
| `ft_strcpy(dest, src)` | Copies `src` into `dest` (assumed large enough), returns `dest`. |
| `ft_strndup(str, n)` | Heap-allocated copy of the first `n` bytes of `str`. |
| `ft_strjoin(str, buffer, flag)` | Heap-allocated concatenation of `*str` and `*buffer`; `flag` selects which of the two inputs (if any) get freed. |
| `ft_strnfill(dest, src, n)` | Copies up to `n` bytes of `src` into `dest`, returning the number copied. |
| `ft_strspn(s, accept)` / `ft_strspn_rev(s, accept)` | Length of the leading/trailing run of `s` made up only of characters in `accept`. |
| `ft_strcspn(s, reject)` | Index of the first character of `s` that appears in `reject`. |
| `ft_strpbrk(str, accept)` / `ft_strqbrk(str, accept)` | First character of `str` that is / is not in `accept`. |
| `ft_strchr_count(str, c)` | Number of occurrences of `c` in `str`. |
| `ft_word_count(s, c)` | Number of words in `s`, separated by delimiter `c`. |
| `ft_replace_char(str, src, dst)` | Replaces every occurrence of `src` with `dst` in `str`, in place. |
| `ft_strfree(str)` | Frees `*str` if non-`NULL`. |

### extras — matrices (`char **`)

| Function | Description |
|---|---|
| `ft_mtxlen(matrix)` | Number of strings in a `NULL`-terminated `char **`. |
| `ft_mtxdup(matrix)` | Heap-allocated, deep-copied duplicate of `matrix`. |
| `ft_mtxfree(matrix)` | Frees every string in `*matrix` plus the array itself. |
| `ft_longestr_mtx(mtx)` | Length of the longest string in `mtx`. |
| `ft_countstr_mtx(matrix, str)` | Number of entries in `matrix` equal to `str`. |
| `ft_addstr_mtx(matrix, tmp, str)` | Copies `tmp`'s strings into `*matrix` and appends `str` at the end. |
| `ft_realloc(matrix, tmp, old_size, new_size)` | Grows `matrix` from `old_size` to `new_size` entries, filling the new slots from `tmp`. |
| `ft_lstmtx(lst)` | Heap-allocated `char **` snapshot of a `t_list` of strings. |
| `ft_join(new_str, str, buffer)` | Writes `str` followed by `buffer` into the (pre-allocated) `*new_str`. |

### extras — points & grids (`t_point`)

| Function | Description |
|---|---|
| `ft_origin_point(point)` | Non-zero if `point` is `(0, 0)`. |
| `ft_negative_point(point, flag)` | Non-zero if `point`'s `x` and/or `y` (per `flag`) is negative. |
| `ft_center_range(big, lil)` | Offset to center a `lil`-sized region inside a `big`-sized one. |
| `flood_fill(tab, size, begin)` | Recursively flood-fills the connected region of `tab` (a `size`-bounded 2D char grid) starting at `begin`. |

### extras — numbers & validation

| Function | Description |
|---|---|
| `ft_atoll(str)` | Parses a leading, optionally signed decimal integer out of `str` as `long long`. |
| `ft_nbrlen(n)` | Number of characters needed to print `n` in decimal (including the sign). |
| `ft_strnbr(str)` | Non-zero if `str` is (after trimming whitespace) entirely a valid signed integer. |
| `ft_strint(str)` | Non-zero if `ft_strnbr(str)` holds and the value fits in a 32-bit `int`. |
| `ft_map(old_value, old_limits, new_limits)` | Rescales `old_value` from the `old_limits` range into the `new_limits` range. |

### extras — misc

| Function | Description |
|---|---|
| `ft_gettimeofday(void)` | Current time in milliseconds since the epoch. |
| `ft_swaptr(p1, p2)` | Intended to swap two pointers; **not yet functional** — currently only null-checks its arguments. |
| `ft_getpid(void)` | Intended to return the calling process's PID; **not yet functional** — currently closes fd 0 and always returns `-1`. |

### Macros & constants (`inc/libft.h`)

- `BUFFER_SIZE` (default `42`) — `get_next_line`'s read chunk size; override with `-DBUFFER_SIZE=n` at compile time.
- `FD_MAX` (default `1024`) — number of file descriptors `get_next_line` can track simultaneously.

## Example

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	t_list	*lst;
	char	*line;
	int		fd;

	words = ft_split("Super,Libft,is,handy", ',');
	ft_printf("first word: %s (%d chars)\n", words[0], ft_strlen(words[0]));
	ft_mtxfree(&words);

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("hello"));
	ft_lstadd_back(&lst, ft_lstnew("world"));
	ft_printf("list size: %d\n", ft_lstsize(lst));

	fd = open("data.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		ft_printf("> %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```
