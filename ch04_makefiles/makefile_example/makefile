objects = encrypt.o checksum.o
src=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(src))

test_code: test_code.c encrypt.o checksum.o
	gcc test_code.c encrypt.o checksum.o -o test_code

#encrypt.o: encrypt.c encrypt.h
#	gcc -c encrypt.c -o encrypt.o

#checksum.o: checksum.c checksum.h
#	gcc -c checksum.c -o checksum.o
#checksum.o : 

%.o:%.c
	$(CC) -c $< -o $@
	echo $@
	echo $<

.PHONY: clean
clean :
	-rm test_code $(objects)

allh=$(wildcard *.h)

.PHONY: print
print :encrypt.c checksum.c
	echo $(CC) $(CFLAGS) $(LDFLAGS)
	echo $(src)
	echo $(obj)
	echo $@
	echo $<
	echo $^
	echo $(allh)
