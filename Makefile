CFLAGS+=-std=c11 -Wall -Werror -Wno-deprecated -Wextra -Wstack-usage=1024 -pedantic

.PHONY: clean

poker: poker.o card.o deck.o


clean:
	-rm poker *.o
