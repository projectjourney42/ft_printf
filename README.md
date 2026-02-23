*This project has been created as part of the 42 curriculum by **haranivo***

___

# ft_printf

## Description

**ft_printf** is a C project that aims to recreate the functionality of the standard `printf()` function from the C library. This project is a fundamental exercise in the 42 curriculum that teaches low-level programming concepts such as variadic functions, string manipulation, and formatted output.

### Project goals

The main objectives of **ft_printf** are to:
- Understand how variadic functions work using `va_list`, `va_start()`, `va_arg()`, and `va_end()`
- Implement type conversion and base conversion algorithms (decimal, hexadecimal)
- Build a reusable library that integrates with the custom `libft` library

### Overview

This project implements a subset of `printf()` that supports the following format specifiers:
- `%c` → character
- `%s` → string
- `%p` → pointer address (hexadecimal)
- `%d` / `%i`→ signed decimal integer
- `%u` → unsigned decimal integer
- `%x` / `%X` → unsigned hexadecimal (lowercase/uppercase)
- `%%` → literal percent sign

The implementation correctly handles edge cases such as `NULL` pointers, `INT_MIN`/`INT_MAX`, and returns the number of characters written.

### Library contents

The libftprintf library was created from well-visualized and structured functions   
Here's the list of functions in the libftprinft library.

| Function | Description |
|----|-------------|
| **ft_printf** | *The main function calling the all other functions* |
| **ft_count_long** | *Used to count long for the return* |
| **ft_printf_address** | *To print the address putting "0x" before the hexadecimal address* |
| **ft_printf_hexa** | *To converse decimal number to hexadecimal* |
| **ft_printf_lhexa** | *To converse decimal long integer to hexadecimal*|
| **ft_printf_number** | *To print the number* |
| **ft_printf_string** | *To print the string* |
| **ft_printf_unsigned_nbr** | *To print the unsigned number* |
| **ft_rev_char** | *To reverse the result of hexa conversion* |

## Algorithm and visualization

### Architecture overview

The project is organized into modular functions, each handling a specific format specifier:

```
ft_printf.c (main dispatcher)
    ↓
ft_which_print() (format specifier router)
    ├→ ft_printf_string.c (%s)  ⇒ call libft/ft_putstr_fd()
    ├→ ft_printf_address.c (%p) ⇒ call ft_printf_lhexa which call ft_count_long and ft_rev_char
    ├→ ft_printf_number.c (%d, %i) ⇒ call libft/ft_putnbr_fd()
    ├→ ft_printf_unsigned_nbr.c (%u) ⇒ call ft_printf_unsigned_nbr
    ├→ ft_printf_hexa.c (%x, %X) ⇒ call ft_rev_char
    └→ libft functions
```

### Core algorithms

#### 1. **Variadic argument processing** ([`ft_printf.c`](ft_printf.c))

```
Algorithm: Parse format string and extract arguments
─────────────────────────────────────────────────────
1. Initialize va_list using va_start(print, format)
2. Iterate through format string character by character
3. When '%' is found:
   - Check next character for format specifier
   - Call appropriate handler function
   - Increment length counter with return value
4. When regular character:
   - Write character to output
   - Increment length counter
5. Clean up with va_end(print)
6. Return total character count
```
**Key decision:** Using a dispatcher function (`ft_which_print`) allows for clean, scalable code. Adding new format specifiers only requires adding a new case.

#### 2. **Integer to string conversion** ([`ft_printf_number.c`](ft_printf_number.c)) & [`ft_printf_unsigned_nbr.c`](ft_printf_unsigned_nbr.c)) 

```
Algorithm: Convert signed integer to decimal string
──────────────────────────────────────────────────
1. Handle special case: INT_MIN = -2147483648
2. Handle zero as special case
3. Use ft_putnbr_fd() to recursively:
   - If n > 9: divide by 10 and recurse, then print remainder
   - If n <= 9: print digit + '0'
4. Count total digits:
   - If negative: +1 for sign
   - Repeatedly divide by 10 until 0
5. Return digit count
```
#### 3. **Base conversion (hexadecimal)** ([`ft_printf_hexa.c`](ft_printf_hexa.c) & [`ft_printf_lhexa.c`](ft_printf_lhexa.c))

```
Algorithm: Convert unsigned integer to hexadecimal
──────────────────────────────────────────────────
1. Allocate memory for hexs string
2. Use modulo 16 to extract each hex digit:
   - hex = nbr % 16
   - nbr = nbr / 16
   - Map: 0-9 → '0'-'9', 10-15 → 'a'-'f' or 'A'-'F'
3. Digits are generated in reverse order
4. Reverse the string using ft_rev_char()
5. Output and free allocated memory
6. Return digit count
```
**Why we reverse?** When dividing by base, we extract digits from least significant to most significant. We build the string backwards, then reverse it for correct output.

#### 4. **Pointer address handling** ([`ft_printf_address.c`](ft_printf_address.c))

```
Algorithm: Format pointer address in hexadecimal
──────────────────────────────────────────────
1. Check if pointer is NULL:
   - Print "(nil)" and return (5)
2. Cast void* to unsigned long (preserves all bits)
3. Prepend "0x" to output
4. Call ft_printf_lhexa() to convert to hex
5. Return total length: 2 (for "0x") + hexa digits
```
#### 5. **String padding and null handling** ([`ft_printf_string.c`](ft_printf_string.c))

```
Algorithm: Output string with null-pointer check
──────────────────────────────────────────────
1. If pointer is NULL:
   - Output "(null)" string
   - Return length 6
2. Otherwise:
   - Use ft_putstr_fd() to output
   - Return string length via ft_strlen()
```
___

### Technical choices

#### Why libft dependency?

The project reuses the [libft library](libft/) to avoid code duplication:
- `ft_strlen()` - String length calculation
- `ft_putchar_fd()` - Character output to file descriptor
- `ft_putstr_fd()` - String output to file descriptor
- `ft_putnbr_fd()` - Number output (base 10)
___

### Project structure

```
ft_printf/
├── ft_printf.c                 # Main dispatcher and argument parsing
├── ft_printf.h                 # Header file with function declarations
├── ft_printf_string.c          # %s specifier handling
├── ft_printf_address.c         # %p specifier handling
├── ft_printf_number.c          # %d, %i specifiers
├── ft_printf_unsigned_nbr.c    # %u specifier
├── ft_printf_hexa.c            # %x, %X specifiers
├── ft_printf_lhexa.c           # Helper for large hex conversion
├── ft_count_long.c             # Digit counting helper
├── ft_rev_char.c               # String reversal helper
├── Makefile                    # Build configuration
├── libft/                      # Custom C library (dependency)
│   ├── libft.h
│   ├── Makefile
│   └── ft_*.c                  # ~43 utility functions
└── README.md                   # This file
```
___

## Data structure: 

Rather than allocating all output, this implementation:
- **Writes directly to stdout** using file descriptor 1
- **Uses write() system call** for each operation
- **Tracks character count** manually

**Advantages:**
- Simple, no memory overhead
- Immediate output (useful for debugging)
- Mimics real `printf()` behavior

## Error handling

```
Edge Cases Addressed:
────────────────────
1. NULL string argument → Prints "(null)"
2. NULL pointer argument → Prints "(nil)"
3. INT_MIN value → Special string
4. Zero values → Handled separately
```
___

## Instructions

### Compilation

The project uses a **Makefile** for easy compilation and management.

#### Available make commands

```bash
make              # Compiles libft and ft_printf, generates libftprintf.a
make all          # Same as make (default target)
make libft        # Compiles libft, run the make on libft
make clean        # Deletes all object files (.o)
make fclean       # Deletes object files and the static library
make re           # Cleans and recompiles everything from scratch
```

#### Building the library

To compile the project:

```bash
make all
```

This will:
1. Compile the `libft` library (dependency)
2. Compile all `ft_printf` source files (*ft_\*.c*)
3. Create the static library `libftprintf.a`

### Installation & usage

To use `ft_printf` in your C project:

1. **Include the header file** in your source code:

```c
#include "ft_printf.h"
```


### Example Uuage

```c
#include "ft_printf.h"

int main(void)
{
    unsigned int	nude = 15056565;
	unsigned int	purple = 8732829;
	int				number = 42;
	int				*pointer_to_number = &number;

	/* ==================== */
	/*     %u %i %d         */
	/* ==================== */

	ft_printf("Got an %i in math.\n", -143);
	ft_printf("That represents %d %% off.\n\n", -20);

    /* ===================== */
	/*  return of ft_printf  */
	/* ===================== */

	ft_printf("==>%d\n", ft_printf("I am %u years old.\nI am at my %dth grades.\n", 18, 4));     /*  ⟹ 42  */

	/* ==================== */
	/*     %c %s %%         */
	/* ==================== */

	ft_printf("Hello everyone my name is %s.\n", "Tia");
	ft_printf("My initial is %c.\n", 't');
	ft_printf("That represents 100%% effort!\n\n");

	/* ==================== */
	/*     %p %x %X         */
	/* ==================== */

	ft_printf("My fav color is #%x.\n", purple);
	ft_printf("Or #%X.\n", nude);
	ft_printf("Address of number: %p\n", (void *)&number);
	ft_printf("Pointer value: %p\n", (void *)pointer_to_number);

    return (0);
}
```
2. **Link the library** when compiling:

```bash
cc main.c -L. -lftprintf
```

Or if you need to specify the full path:

```bash
cc main.c ./libftprintf.a
```

### Execution

After compilation and linking:

```bash
./a.out
```

Expected output:
```
Got an -143 in math.
That represents -20 % off.

I am 18 years old.
I am at my 4th grades.
==>42
Hello everyone my name is Tia.
My initial is t.
That represents 100% effort!

My fav color is #85409d.
Or #E5BEB5.
Address of number: 0x7ffc1bf13ec0
Pointer value: 0x7ffc1bf13ec0
```

___

## Features

### Supported format specifiers

| Specifier | Type | Example | Output |
|-----------|------|---------|--------|
| `%c` | Character | `ft_printf("%c", 65)` | `A` |
| `%s` | String | `ft_printf("%s", "hello")` | `hello` |
| `%p` | Pointer | `ft_printf("%p", ptr)` | `0x7fff...` |
| `%d` | Integer | `ft_printf("%d", -42)` | `-42` |
| `%i` | Integer | `ft_printf("%i", 42)` | `42` |
| `%u` | Unsigned | `ft_printf("%u", 42u)` | `42` |
| `%x` | Hex (lower) | `ft_printf("%x", 255)` | `ff` |
| `%X` | Hex (upper) | `ft_printf("%X", 255)` | `FF` |
| `%%` | Percent | `ft_printf("%%")` | `%` |

### Edge cases handled

- `NULL` pointers → displays `(nil)`
- `NULL` strings → displays `(null)`
- `INT_MIN` (-2147483648) → correctly handled
- Hexadecimal conversion for all unsigned values
- Proper return value (number of characters printed)

___

## Resources

### Documentation & references

1. **Manual Pages (man)**
   - `man 3 printf` - Standard printf behavior and return values
   - `man va_list` - Variadic function documentation
   - `man 3 stdarg` - Variadic function *include* documentation
   ⟹ For a better understanding on which tool and how to use
2. **C Standard Library References**
   - [man7.org](https://man7.org/linux/man-pages/) - Linux man pages online
   ⟹ For better understanding and for visualisation

3. **42 Curriculum Resources**
   - Peer discussions and code reviews

4. **C original printf() test**
   - [W3schools](https://www.w3schools.com/c/tryc.php?filename=demo_ref_stdio_printf) - C demo
   ⟹ To understand and test all possible conditions in order to better manage errors

### Use of AI

AI tools were utilized for the following aspects of this project:

#### Tasks where AI was used

1. **Algorithm optimization**
   - Help with visualizing the progress of the project.
   - Clarifying base conversion logic for hexadecimal

2. **Testing strategy**
   - Generating test cases for values
   - Comparing return values for correctness

3. **Documentation** 
   - Structuring this README
   - Clarifying architecture decisions

___
