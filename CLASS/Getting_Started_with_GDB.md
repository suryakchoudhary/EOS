# Gettibg Started with GDB

- sudo snap install gdb OR sudo apt-get install gdb

- gcc -o executable_f_name filename.c -g : "-g" include debug information in code and this makes the file a little bigger.

- wc -c executable_file : Command to check the size of file.

- gdb ./executable_f_name

- lay next OR lay n 

- Press enter OR return key tow times.

- break main OR b main : To set the break point at main.

- run : To run the program.

- next OR n : To move to next instruction in .c file.

- nexti OR ni : To move next instruction in assembly code.

- info register : To see information of the registers.
