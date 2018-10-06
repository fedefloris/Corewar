# Libft - 42Born2Code
My implementation of some of the Standard C Library functions + some additional ones.

## What is libft?
The goal of this project is to re-implement some standard C library functions + some additional ones that we gonna use in every 42 project written in C.

For more details look at the [subject](subject.pdf).

## How do I use the library?
```
git clone https://github.com/fedefloris/Libft.git && cd Libft && make
```
Now you should see a '*libft.a*' file in the root folder.
```
gcc your_file.c libft.a -I includes
```
Example of '*your_file.c*':
```
#include "libft.h"

int main(void)
{
  ft_printf("Hello %d\n", 42);
  return (0);
}
```

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.
