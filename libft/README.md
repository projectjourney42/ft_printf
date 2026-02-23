*This project has been created as part of the 42 curriculum by **haranivo**.*

# Libft
## Description
The **Libft** is a fundamental project in the **42 curriculum**, the aim of which is to create your own library of functions in the ***C language***.  
This C library, **libft.a** brings together a selection of standard *libc functions*, as well as *additional functions*, and *linked list function*, reimplemented from scratch.

**The main goals of the project are to**:
- Understand the inner workings of standard C functions
- Learn how to write robust, reusable, and well-structured code
- Lay a solid foundation for future projects in the 42 curriculum

At the end of the project, the `libft.a` library can be reused in many other projects.
___

## Library contents
The libft library was organized in some different categories.  
Here's the list of functions in the libft library.



### Part 1 - Libc functions
Reimplemented set of functions from the libc. This version have exactly
the same prototypes and behaviors as the originals, adhering strictly to their definitions
in the man page.
| Function | Description |
|----|-------------|
| **ft_isalpha** | *checks  for  an  alphabetic  character*
| **ft_isdigit** | *checks for a digit (0 through 9)*
| **ft_isalnum** | *checks for an alphanumeric character*
| **ft_isascii** | *checks whether c is a value that fits into the ASCII character set*
| **ft_isprint** | *checks for any printable character including space*
| **ft_strlen** | *calculate the length of a string*
| **ft_memset** | *fill memory with a constant byte*
| **ft_bzero** | *sets all bytes in a memory area to zero*
| **ft_memcpy** | *copies a specified number of bytes from one memory area to another*
| **ft_memmove** | *copies bytes from one memory area to another, safely handling overlapping memory regions*
| **ft_strlcpy** | *opies a string to a destination buffer the total length of the string*
| **ft_strlcat** | *appends a string to a destination buffer while preventing buffer overflow*
| **ft_toupper** | *converts a lowercase letter to its uppercase equivalent*
| **ft_tolower** | *converts an uppercase letter to its lowercase equivalent*
| **ft_strchr** | *locates the first occurrence of a character in a string*
| **ft_strrchr** | *locates the last occurrence of a character in a string*
| **ft_strncmp** | *compares two strings up to a specified number of characters*
| **ft_memchr** | *searches for a byte value within a block of memory*
| **ft_memcmp** | *compares two blocks of memory byte by byte*
| **ft_strnstr** | s*earches for a substring within a string, limited to a specified number of characters*
| **ft_atoi** | *converts a string representing a number into an integer*
| **ft_calloc**  | *allocates memory for an array*
| **ft_strdup**  | *duplicates a string*

### Part 2 - Additinal functions
In this second part, there is a set of functions that are either not included in
the libc, or exist in a different form.
| Function            | Description |
|---------------------|-------------|
| **ft_substr**           | *Creates and returns a substring from a given string.* |
| **ft_strjoin**          | *Allocates and returns a new string resulting from the concatenation of two strings.* |
| **ft_strtrim**          | *Removes specified characters from the beginning and end of a string.* |
| **ft_split**            | *Splits a string into an array of strings using a specified delimiter.* |
| **ft_itoa**             | *Converts an integer into its string representation.* |
| **ft_strmapi**          | *Applies a function to each character of a string and creates a new resulting string.* |
| **ft_striteri**         | *Applies a function to each character of a string, modifying it in place.* |
| **ft_putchar_fd**       | *Writes a single character to a given file descriptor.* |
| **ft_putstr_fd**        | *Writes a string to a given file descriptor.* |
| **ft_putendl_fd**       | *Writes a string followed by a newline to a given file descriptor.* |
| **ft_putnbr_fd**        | *Writes an integer to a given file descriptor.* |
### Part 3 - Linked list
In this third part, there is an implementation of functions using a structure to manipulate linked
list.
| Function           | Description |
|--------------------|-------------|
| **ft_lstnew**          | *Creates a new list element and initializes it with the given content.* |
| **ft_lstadd_front**    | *Adds a new element at the beginning of a list.* |
| **ft_lstsize**         | *Counts the number of elements in a list.* |
| **ft_lstlast**         | *Returns the last element of a list.* |
| **ft_lstadd_back**     | *Adds a new element at the end of a list.* |
| **ft_lstdelone**       | *Deletes a single list element using a given function.* |
| **ft_lstclear**        | *Deletes and frees all elements of a list.* |
| **ft_lstiter**         | *Applies a function to the content of each list element.* |
| **ft_lstmap**          | *Creates a new list by applying a function to each element of an existing list.* |
---
## Instructions
### Compilation
To run the libft's functions a *Makefile* was created as a usefull tool for compilation.
**`make`** : compiles all functions and generates the static library. **libft.a**

>`make all` : *compiles every files to create the **libft.a**, create the main cible of the project*  
>`make clean` : 	*deletes object files*  
>`make fclean` : *deletes object files + libft.a*  
>`make re` : *recompiles everything from scratch (fclean + all)*  

### Usage
To use those functions in libft library, you must call the library itself.  
To do so, you need to :   
`#include "libft.h"`   
in your main.c file.  
After the `make` you can compile your main with :  
**`cc main.c -L. -lft`**


### Example of main tester

```
#include "libft.h"
#include <fcntl.h>

int main(void)
{
    int fd;

    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
        return (1);

    ft_putnbr_fd(123456789, fd);

    close(fd);
    return (0);
}
```
***
## Resources
1. **Linux manual pages (man) :** Used to understand the exact behavior and specifications of standard C functions, allowing us to reimplement them faithfully.   

2. - [**`KooR`**](https://koor.fr/)**:** Reference for syntax and examples of C functions.  
    - [**`man7`**](man7.org) **:** Helpful for understanding function expectations, behavior, and return values in detail.  
    - [**`W3Schools C tutorials`**]() **:** Useful for quickly testing the original functions and verifying their behavior.  


*These are all legitimate learning resources that helped ensure correct implementation.*
***
### Use of AI
- AI tools were used to gain a deeper understanding of the purpose and behavior of each function.

- AI was used only to clarify concepts and debug results.
***
---