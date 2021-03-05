CC     = gcc
RM     = rm -f
OBJS   = conta.o \
         main.o

LIBS   =
CFLAGS =

.PHONY: conta.exe clean clean-after

all: conta.exe

clean:
	$(RM) $(OBJS) conta.exe

clean-after:
	$(RM) $(OBJS)

conta.exe: $(OBJS)
	$(CC)  -o $@ $(OBJS) $(LIBS)

conta.o: conta.c conta.h
	$(CC)  -c $< -o $@ $(CFLAGS)

main.o: main.c conta.h
	$(CC)  -c $< -o $@ $(CFLAGS)

