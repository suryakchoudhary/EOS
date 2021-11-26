# Linux Commands

- size filename : TO find size of .bss, .data, .txt files in Executable and Linkable File.

- cat : To view the contents of file and directories.

- ls -al : To display all the contents(hidden) of root directory.

- touch filename : To create new file.

- ssh pi@ipaddress_of_raspberry_pi : To access shell of raspberry pi in linux terminal and use "exit" to exit from raspberry_pi.

- file * : Shows the detail of file such as binary file of what.

- mv filename directoryname : To move file to a perticular directory when your pwd is where the file is present.

# Command For Making Static Library

- gcc -c filename. -o filenamre.o : To create object file(.o file).

- ar rcs lib_name.a filename1.o filename2.o OR ar -cr lib_name.a filename1.o filename2.o

# Git Commands

- git config --global user.name "user_name"

- git config --global user.name "user_name"

- git branch branch_name

- git checkout branch_name : To switch to branch_name.

- git merge feature 

- git config -l : To see the your credentials entered in git.

- git commit -m "statement"

- git push -u origin master

# Raspberry Pi Commands

- hostname -I : To view ip address and detail.