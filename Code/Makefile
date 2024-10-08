CC=gcc
CFLGAS=-Wall -Werror -Wfatal-errors -I include/

src/qlearning		: src/qlearning.o src/functions.o src/mazeEnv.o
	$(CC) $(CFLGAS) -g -o src/qlearning src/qlearning.o src/functions.o src/mazeEnv.o

src/qlearning.o		: src/qlearning.c include/qlearning.h
	$(CC) $(CFLGAS) -g -o src/qlearning.o -c src/qlearning.c

src/dfs         : src/dfs.o src/functions.o src/mazeEnv.o
	$(CC) $(CFLGAS) -g -o src/dfs src/dfs.o src/functions.o src/mazeEnv.o

src/dfs.o       : src/dfs.c  include/dfs.h
	$(CC) $(CFLGAS) -g -o src/dfs.o -c src/dfs.c

src/functions.o : src/functions.c include/functions.h
	$(CC) $(CFLGAS) -g -o src/functions.o -c src/functions.c

src/mazeEnv.o   : src/mazeEnv.c include/mazeEnv.h
	$(CC) $(CFLGAS) -g -o src/mazeEnv.o -c src/mazeEnv.c

clean		:
	rm -f src/qlearning.o src/qlearning src/dfs src/dfs.o src/functions.o src/mazeEnv.o 