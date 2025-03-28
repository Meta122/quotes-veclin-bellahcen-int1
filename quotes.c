// quotes.c
#include "quotes.h"

void print_quote(char **quotes, int index) {
    if (index >= 0)
        printf("%s\n", quotes[index]);
}

void print_random_quote(char **quotes, int count) {
    if (count > 0) {
        int index = rand() % count;
        print_quote(quotes, index);
    }
}

void add_quote(char **quotes, int *count, char *new_quote) {
    if (*count < MAX_QUOTES) {
        quotes[*count] = malloc(strlen(new_quote) + 1);
        strcpy(quotes[*count], new_quote);
        (*count)++;
    } else {
        printf("Quote list is full!\n");
    }
}

void remove_quote(char **quotes, int *count, int index) {
    if (index >= 0 && index < *count) {
        free(quotes[index]);
        for (int i = index; i < *count - 1; i++) {
            quotes[i] = quotes[i + 1];
        }
        (*count)--;
    } else {
        printf("Invalid index!\n");
    }
}

void display_quotes(char **quotes, int count) {
    if (count == 0) {
        printf("No quotes available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i, quotes[i]);
    }
}

void menu(char **quotes, int *count) {
    int choice;
    int index;
    do {
        char quote[MAX_LENGTH];
        printf("\nMenu:\n");
        printf("1. Display all quotes\n");
        printf("2. Add a quote\n");
        printf("3. Remove a quote\n");
        printf("4. Display a random quote\n");
        printf("5. Exit\n");
        printf("Choose an option :");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                display_quotes(quotes, *count);
                break;
            case 2:
                printf("Enter new quote: ");
                scanf("%s", quote);
                add_quote(quotes, count, quote);
                break;
            case 3:
                printf("Enter index to remove: ");
                scanf("%d", &index);
                remove_quote(quotes, count, index);
                break;
            case 4:
                print_random_quote(quotes, *count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 5);
}