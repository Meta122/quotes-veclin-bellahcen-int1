#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUOTES 100  // Définition d'une taille maximale

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc((length + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Erreur d'allocation mémoire");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

char **table_creation(char *file_to_read) {
    char **quote_table = (char **)malloc(sizeof(char *) * MAX_QUOTES);
    if (quote_table == NULL) {
        perror("Erreur d'allocation mémoire");
        return NULL;
    }

    char *buffer = read_file(file_to_read);
    if (buffer == NULL) {
        free(quote_table);
        return NULL;
    }

    int i = 0, j = 0;
    while (buffer[j] != '\0' && i < MAX_QUOTES) {
        char transfer_data[256];  // Stockage temporaire d'une ligne
        int k = 0;

        while (buffer[j] != '\n' && buffer[j] != '\0' && k < 255) {
            transfer_data[k++] = buffer[j++];
        }

        transfer_data[k] = '\0';  // Terminaison de la ligne

        if (buffer[j] == '\n') {
            j++;  // Sauter le '\n'
        }

        quote_table[i] = (char *)malloc((strlen(transfer_data) + 1) * sizeof(char));
        if (quote_table[i] == NULL) {
            perror("Erreur d'allocation mémoire");
            break;
        }

        strcpy(quote_table[i], transfer_data);
        i++;
    }

    quote_table[i] = NULL; // Marquer la fin du tableau
    free(buffer);
    return quote_table;
}
