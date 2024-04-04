#include <stdio.h>

void afficher_variables_environnement(char *envp[]) {
    // Parcours et affichage des variables d'environnement
    int i = 0;
    while (envp[i] != NULL) {
        printf("%s\n", envp[i]);
        i++;
    }
}

int main(int argc, char *argv[], char *envp[]) {
    // Appel de la fonction avec envp en tant qu'argument
    afficher_variables_environnement(envp);

    return 0;
}
