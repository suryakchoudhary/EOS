# Linux Commands

- size filename : TO find size of .bss, .data, .txt files in Executable and Linkable File.

- cat : To view the contents of file and directories.

- ls -al : To display all the contents(hidden) of root directory.

- touch filename : To create new file.

- ssh pi@ipaddress_of_raspberry_pi : To access shell of raspberry pi in linux terminal and use "exit" to exit from raspberry_pi.

- file * : Shows the detail of file such as binary file of what.

- mv filename directoryname : To move file to a perticular directory when your pwd is where the file is present.

- ar x filename : To extract file.

- rm *.extension : To delete file with extensions.

- objdump -S objectfile.o : Display information from object file.



# Command For Creating Library
- export LD_LIBRARY_PATH=.  :If checking for library then also check the current directory. 

- echo $LD_LIBRARY_PATH   :To check for the above done command i.e. "export LD_LIBRARY_PATH=." .



## Command For Making Static Library

### Step- 1

- gcc -c filename. -o filenamre.o : To create object file(.o file).

### Step- 2

- ar rcs lib_name.a filename1.o filename2.o OR ar -cr lib_name.a filename1.o filename2.o

### Step- 3

- gcc -o filename filename.c -L. lib_library_name.a  OR  gcc -o filename filename.c -llibrary_name -L. : Linking main file to static library.
    Eg.. gcc -o main main.c -L. libcalc.a   OR gcc -o main main.c -lcalc -L. 
    If the library is in same directory then use -L. else -L(write path instead of ".")

### Step- 4

- ./main :Run executable file.



## Command For Making Dynamic Library

### Step- 1

- gcc -c filename. -o filenamre.o : To create object file(.o file)  : Creating object files(.o) files.

### Step- 2

- gcc -o libname.so -shared -fPIC filename.o filename1.o  OR gcc -o libname.so -shared -fpic *.o  : Creating dynamic lib. (.so) and grouping object files in a 
  single dynamic lib.

### Step- 3
 
- gcc -o main main.c -L. libname.so OR gcc -o main main.c -L_location_of _libname.so libname.so  : Linking main program to lib.

### Step- 4

- export LD_LIBRARY_PATH=.  :If checking for library then also check the current directory. 

- echo $LD_LIBRARY_PATH   :To check for the above done command i.e. "export LD_LIBRARY_PATH=." .

### Step- 5

- ./main :Run executable file.



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