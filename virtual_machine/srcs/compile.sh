clear
make -C ../../libft
rm -rf virtual_machine
gcc -fsanitize=address -o virtual_machine *.c operations/*.c parse/*.c ../../libft/libft.a -I ../includes/ -I ../../libft/includes
