target = elliptical

vpath %.h ./includes

$(target): elliptical.o libhfcal.so
	gcc elliptical.o -L./libs -lhfcal -o $(target)

libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o ./libs/libhfcal.so

hfcal.o: hfcal.c
	gcc -I./includes -fPIC -c hfcal.c

elliptical.o:elliptical.c
	gcc -I./includes -c elliptical.c

.PHONY: clean
clean :
	-rm $(target) hfcal.o elliptical.o

