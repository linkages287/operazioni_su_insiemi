#makefile 

CC = gcc
PARMAIN = -ansi -Wall -O -o
PAROGG  = -ansi -Wall -Werror -O -c -g 
LIBFILE = elemento
MAIN = main

 
all:
	@echo
	@echo Start compiling...I will be done in a moment...
	@echo 
	$(CC) $(PAROGG) $(LIBFILE).c
	$(CC) $(PAROGG) $(MAIN).c
	$(CC) $(PARMAIN) $(MAIN) $(MAIN).o $(LIBFILE).o
        
clean:
	@echo
	@echo Cleaning ...
	@echo
	rm -f $(MAIN).o $(LIBFILE).o
	
