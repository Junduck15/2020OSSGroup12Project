Manager : studentinfo.o studentManager.c
	gcc -o $@ $^
clean :
	rm Manager *.o
