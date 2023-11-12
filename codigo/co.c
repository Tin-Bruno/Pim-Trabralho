#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Obras {
    char autor[100];
    char titulo[150];
    char descricao[2000];
    char infoGeral[100];
};

void exibirMenu() {
    setlocale(LC_ALL, "Portuguese");
    printf("\nMenu:\n");
    printf("1. Galeria\n");
    printf("2. Avaliações\n");
    printf("4. Sair\n");
}

void InfoGaleria() {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem-vindo à Galeria de Arte!\n");
    printf("Qual galeria você gostaria de ir primeiro:\n");
    printf("\t1. 100 da semana da arte moderna\n");
    printf("\t2. 150 anos de Santos Durmont\n");
    printf("\t3. Jogos olímpicos em Paris 2024.\n");
    printf("\t4. 2 Guerra Mundial.\n");
}

void InfoArt(struct Obras ArteInfo) {
    setlocale(LC_ALL, "Portuguese");
    printf("Informações Gerais: %s\n", ArteInfo.infoGeral);
    printf("Autor: %s\n", ArteInfo.autor);
    printf("Titulo: %s\n", ArteInfo.titulo);
    printf("Descrição: %s\n", ArteInfo.descricao);
    printf("Ano em que a Obra foi feita\n");
}

int main() {

    int escolha;

    do
    {
        setlocale(LC_ALL, "Portuguese");

        struct Obras art_1;
        strcpy(art_1.autor, "");
        strcpy(art_1.titulo, "100 da semana da arte moderna");
        strcpy(art_1.descricao, "");
        strcpy(art_1.infoGeral, "");

        struct Obras art_2;
        strcpy(art_2.autor, "");
        strcpy(art_2.titulo, "150 anos de Santos Durmont");
        strcpy(art_2.descricao, "");
        strcpy(art_2.infoGeral, "");

        struct Obras art_3;
        strcpy(art_3.autor, "");
        strcpy(art_3.titulo, "Jogos olímpicos em Paris 2024.");
        strcpy(art_3.descricao, "");
        strcpy(art_3.infoGeral, "");

        struct Obras art_4;
        strcpy(art_4.autor, "");
        strcpy(art_4.titulo, "2 Guerra Mundial.");
        strcpy(art_4.descricao, "");
        strcpy(art_4.infoGeral, "");

        exibirMenu();
        scanf("%d", &escolha);

        // Exibir informações com base na escolha do usuário
        switch (escolha) {
            case 1:
                exibirInformacoes(art_1);
                break;
            case 2:
                exibirInformacoes(art_2);
                break;
            case 3:
                exibirInformacoes(art_3);
                break;
            case 4:
                exibirInformacoes(art_4);
                break;
            default:
                printf("Opção inválida.\n");
            }
        } while (escolha != 5);

    return 0;
}