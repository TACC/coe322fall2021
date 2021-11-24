CC = icpc
OBJS = main.o lib.o
prog : ${OBJS}
	${CC} -o $@ ${OBJS}
CSTANDARD=17
%.o : %.cxx
	${CC} -c $< -std=c++${CSTANDARD}
main.o lib.o : lib.h

clean :
	rm -f *.o prog *~

