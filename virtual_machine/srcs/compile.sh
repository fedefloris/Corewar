clear
make -C ../../libft
rm -rf virtual_machine
gcc -o virtual_machine *.c ../../libft/libft.a -I ../includes/ -I ../../libft/includes
