clear
make -C ../../libft
rm -rf virtual_machine
gcc -fsanitize=address -o virtual_machine *.c operations/*.c parse/*.c op_tools/*.c control/*.c system/*.c ../../libft/libft.a -I ../includes/ -I ../../libft/includes
