CC = clang
CFLAGS  = -g -Wall -std=c11 -pedantic

$(shell mkdir -p obj)

all: graph_color

graph_color: obj/main.o obj/graph.o
	$(CC) $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	$(RM) graph_color obj/*.o