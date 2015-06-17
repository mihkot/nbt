CFLAGS:= -Wall -std=c99

LDFLAGS:=

SRC     := main.c
OBJ     := $(patsubst %.c, %.o, $(SRC))

all: helloworld

$(OBJ): %.o : %.c
	$(CC) -c $(<) $(I) $(CFLAGS)

helloworld:  $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(^) -o $(@)
	strip helloworld

clean:
	rm -f *.o helloworld
