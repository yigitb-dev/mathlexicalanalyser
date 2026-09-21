#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int is_operator;
  int number_value;
  char operator_value;
} Token;

typedef struct {
  Token *items;
  int size;
  int capacity;
} TokenArray;

void token_pars(char *usr_input, TokenArray *token_array) {
  int start = 0;
  int len = strlen(usr_input);
  int token_array_size = sizeof(*token_array);

  while (start < len) {
    int i;
    Token token;
    for (i = start; i < len; i++) {
      if (usr_input[i] == ' ' || usr_input[i] == '\n') {
        break;
      }
    }

    int current_index = token_array->size;

    int j;
    char holder[1000];
    int holder_counter = 0;
    for (j = start; j < i; j++) {
      if (usr_input[j] != '+' && usr_input[j] != '-' && usr_input[j] != '*' &&
          usr_input[j] != '/') {
        holder[holder_counter] = usr_input[j];
        holder_counter++;
        token_array->items[current_index].is_operator = 0;
      }

      else {
        if (token.is_operator == 0) {
          printf("Invalid Syntax");
        }
        token.is_operator = 1;
        token.operator_value = usr_input[j];
      }
      token.number_value = atoi(holder); // BUG: atoi() returns 0 when string is
                                         // empty or the conversion fails
    }
    token_array->size++;
    start = i + 1;
  }
}

int compile_tokens() { return 0; }

int main(void) {

  char temp[100];
  printf("Enter your operation:\n");
  fgets(temp, sizeof(temp), stdin);

  int len = strlen(temp);
  char *usr_input = malloc((len + 1) * sizeof(char));
  if (usr_input == NULL) {
    return 1;
  }

  strcpy(usr_input, temp);

  TokenArray token_array;
  token_array.capacity = len;
  token_array.size = 0;
  token_array.items = malloc(token_array.capacity * sizeof(Token));

  free(usr_input);
}
