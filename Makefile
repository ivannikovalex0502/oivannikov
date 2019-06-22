all: get_src get_inc  install clear 

get_src:
	cp src/*.c .
get_inc:      
	cp inc/*.h . 
install: 
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o race04 *.c
uninstall:
	rm race04
clear:
	rm -rf *.c
	rm -rf *.h
reinstal:
	unistall  all 
     
       
       

