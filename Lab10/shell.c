#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_LEN 100
#define HISTORY_SIZE 10

char* history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(const char *cmd) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(cmd);
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(cmd);
    }
}

void free_history() {
    for (int i = 0; i < history_count; i++) {
        free(history[i]);
    }
}

void execute_command(char **args) {
    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        free_history();
        exit(0);
    }

    if (strcmp(args[0], "history") == 0) {
        for (int i = 0; i < history_count; i++) {
            printf("%d %s\n", i + 1, history[i]);
        }
        return;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return;
    }

    if (pid == 0) { // Child process
        execvp(args[0], args); // execvp function searches for the command in the directories listed in the PATH environment variable.
        perror("exec failed");
        exit(1);
    } else {
        wait(NULL); // Wait for child to finish
    }
}

void handle_pipes(char *cmd) {
    char *commands[MAX_ARG_LEN];
    int num_commands = 0;

    char *token = strtok(cmd, "|");
    while (token != NULL) {
        commands[num_commands++] = token;
        token = strtok(NULL, "|");
    }

    int pipe_fds[2 * (num_commands - 1)];

    for (int i = 0; i < num_commands - 1; i++) {
        if (pipe(pipe_fds + i * 2) < 0) {
            perror("pipe failed");
            exit(1);
        }
    }

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0) {
            if (i > 0) {
                dup2(pipe_fds[(i - 1) * 2], STDIN_FILENO);
            }

            // If this is not the last command, output to the next pipe
            if (i < num_commands - 1) {
                dup2(pipe_fds[i * 2 + 1], STDOUT_FILENO);
            }
            
            for (int j = 0; j < 2 * (num_commands - 1); j++) {
                close(pipe_fds[j]);
            }

            // Prepare arguments for execvp
            char *args[MAX_ARG_LEN];
            char *arg_token = strtok(commands[i], " ");
            int arg_count = 0;
            while (arg_token != NULL && arg_count < MAX_ARG_LEN - 1) {
                args[arg_count++] = arg_token;
                arg_token = strtok(NULL, " ");
            }
            args[arg_count] = NULL;
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        }
    }

    for (int i = 0; i < 2 * (num_commands - 1); i++) {
        close(pipe_fds[i]);
    }

    for (int i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}

int main() {
    char command[MAX_CMD_LEN];

    while (1) {
        printf("my_shell> ");
        if (fgets(command, MAX_CMD_LEN, stdin) == NULL) {
            break; // Exit on Ctrl+D
        }

        // Remove newline character from command
        // strcspn() calculates the length of the number of characters before the 1st occurrence of character present in both the string.
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) > 0) {
            add_to_history(command);
        }

        if (strchr(command, '|')) {
            handle_pipes(command);
        } else {
            char *args[MAX_ARG_LEN];
            char *token = strtok(command, " "); // strtok() for splitting a string by some delimiter.
            int i = 0;

            while (token != NULL && i < MAX_ARG_LEN - 1) {
                args[i++] = token; 
                token = strtok(NULL, " "); // The strtok() method splits str[] according to given delimiters and returns the next token.
            }
            args[i] = NULL;

            execute_command(args);
        }
    }

    free_history();
    return 0;
}

