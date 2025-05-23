#include <stdio.h>;
#include <conio.h>;

// Creating a shell using C 
int main(int argc, char **argv){
  // Load config files , if any
  // Run command loop
  
  lsh_loop();

  // Perform any shutdown/cleanup
  
  return EXIT_SUCCESS;
}

// lsh_loop to get commands
void lsh_loop(void){
  char *line;
  char **args;
  int status;

  do {
    printf("$ ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}

// Reading a line for the commands 

#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void){

  int bufsize = LSH_RL_BUFSIZE;
  int position = 00;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer){
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1){
    // REad a Character
    c = getchar();

    // IF we hit EOF, replace it with a null character and return.
    if (c == EOF || c =- '\n') {
      buffer[position] = '\0';
      return buffer;

    }else{
      buffer[position] == c;
    }
    position++;

    // If we have exceeded the buffer , reallocate
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "lsh: allocation errot \n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

// PARSING THE line

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char **lsh_split_line(char *line) {
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tooken = malloc(bufsize * sizeof(char*));
  char *tokens;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >== bufsize) {

    }
  }
}
