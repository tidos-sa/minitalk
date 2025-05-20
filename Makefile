CC=cc -Wall -Wextra -I ./ -ggdb
FILES= ./src/generic.o ./src/string.o 

CLIENT=client
CLIENT_FILES= $(FILES) ./src/client.o

SERVER=server
SERVER_FILES= $(FILES) ./src/server.o

all: $(CLIENT) $(SERVER)
bonus: $(CLIENT_B) $(SERVER_B)

$(CLIENT):$(CLIENT_FILES)
	$(CC) $^ -o $@

$(SERVER):$(SERVER_FILES)
	$(CC) $^ -o $@


.o: .c
	$(CC) -c $< -o $@

clean:
	rm -f $(CLIENT_FILES) $(SERVER_FILES)
	rm -f $(CLIENT_FILES_B) $(SERVER_FILES_B)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	rm -f $(CLIENT_B) $(SERVER_B)

re: clean all

