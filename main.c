// main.c
#include "quotes.h"
#include "memory.h"

int main() {
    int count = 10 ;
    char** jokes = table_creation("../quotes.txt");

    srand(time(NULL));
    menu(jokes, &count);

    for (int i = 0; i < count; i++) {
        free(jokes[i]);
    }

    return 0;
}
