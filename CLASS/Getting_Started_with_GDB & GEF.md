# Gettibg Started with GDB

- sudo snap install gdb OR sudo apt-get install gdb

- gcc -o executable_f_name filename.c -g : "-g" include debug information in code and this makes the file a little bigger.

- wc -c executable_file : Command to check the size of file.

- gdb ./executable_f_name

- lay next OR lay n 

- Press enter OR return key two times.

- break main OR b main : To set the break point at main.

- run : To run the program.

- next OR n : To move to next instruction in .c file.

- nexti OR ni : To move next instruction in assembly code.

- info register : To see information of the registers.


# Gettibg Started with GEF
- Installing GEF in Linux

    - wget -O ~/.gdbinit-gef.py -q http://gef.blah.cat/py

    - echo source ~/.gdbinit-gef.py >> ~/.gdbinit

    - gdb -q /path/to/my/bin

- gcc -o executable_f_name filename.c -g : "-g" include debug information in code and this makes the file a little bigger.

- wc -c executable_file : Command to check the size of file.

- gdb -q ./executable_f_name

- start 

- break main OR b main : To set the break point at main.

- run : To run the whole program at once.

- next OR n : To move to next instruction in .c file.

- nexti OR ni : To move next instruction in assembly code.

- info register : To see information of the registers.

- info breakpoint : To see all breakpoints.