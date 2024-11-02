#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fd_pwd() {
    char cwd[1024]; // Bufor na ścieżkę katalogu roboczego

    // Pobieramy bieżący katalog roboczy za pomocą getcwd
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd); // Wyświetlamy bieżący katalog
        return 0; // Sukces
    } else {
        perror("my_pwd: błąd przy pobieraniu katalogu"); // Wyświetlamy błąd, jeśli getcwd się nie powiodło
        return 1; // Błąd
    }
}

int main(void) {
    return fd_pwd(); // Wywołujemy naszą funkcję my_pwd
}