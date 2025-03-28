// main.c
#include "quotes.h"

int main() {
    char *quotes[MAX_QUOTES];
    int count = 10;

    char *initial_quotes[MAX_QUOTES] = {
        "Programmer - An organism that turns caffeine into code",
        "Why do programmers prefer dark mode? Because light attracts bugs.",
        "If debugging is the process of removing software bugs, then programming must be the process of putting them in.",
        "I don't always test my code, but when I do, I do it in production.",
        "Why do programmers always mix up Christmas and Halloween? Because Oct 31 == Dec 25!",
        "Why did the programmer quit his job? Because he didn't get arrays.",
        "Why do programmers prefer iOS development? Because the Swift.",
        "Why do programmers prefer dogs over cats? Because dogs have fetch and cats have catch.",
        "Why do programmers hate nature? It has too many bugs.",
        "There are only 10 types of people in the world: Those who understand binary and those who don't."
    };

    for (int i = 0; i < count; i++) {
        quotes[i] = malloc(strlen(initial_quotes[i]) + 1);
        strcpy(quotes[i], initial_quotes[i]);
    }

    srand(time(NULL));
    menu(quotes, &count);

    for (int i = 0; i < count; i++) {
        free(quotes[i]);
    }

    return 0;
}
