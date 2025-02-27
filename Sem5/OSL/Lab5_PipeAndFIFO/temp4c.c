#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>

#define FIFO_NAME "./fifo"
// #define BUFFER_SIZE PIPE_BUF

int main(){
	int pipe_fd,res;
	int open_mode1 = O_WRONLY, open_mode2 = O_RDONLY;
	// char buffer[BUFFER_SIZE + 1];
	int stock=6;
	if (access(FIFO_NAME, F_OK) == -1) {
		res = mkfifo(FIFO_NAME, 0777);
		if (res != 0) {
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	printf("Communicating with producer...\n");
	while (1){
		pipe_fd = open(FIFO_NAME, open_mode1);
		printf("\nSend demand to producer: 1");
		// fgets(buffer, BUFFER_SIZE, stdin);
		stock--;
		res = write(pipe_fd, &stock, sizeof(stock));
		close(pipe_fd);

		pipe_fd = open(FIFO_NAME, open_mode2);
		printf("\nRestocked by producer ");
		res = read(pipe_fd, &stock, sizeof(stock));
		// if (strstr(buffer, "exit") != NULL)
		// 	break;
		printf("Shelf Content: %d\n", stock);
		close(pipe_fd);
	}
	close(pipe_fd);
	printf("Process %d finished.\n", getpid());
	exit(EXIT_SUCCESS);
}