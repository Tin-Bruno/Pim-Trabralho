#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Obras {
    char autor[100];
    char titulo[150];
    char descricao[4000];
    char infoGeral[100];
    char tema[50];
};

void exibirMenu() {
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t...Menu Principal...\t\n");
    printf("\nBem-vindo a Galeria de Arte!\n");
    printf("\t1. Galeria\n");
    printf("\t2. Relatorio das obras\n");
    printf("\t3. Sair\n");
}

void MenuGaleria() {
    setlocale(LC_ALL, "Portuguese");
    printf("\nQual galeria voce gostaria de ir:\n");
    printf("\t1. 100 anos da semana da arte moderna\n");
    printf("\t2. 150 anos de Santos Durmont\n");
    printf("\t3. Jogos olimpicos em Paris 2024.\n");
    printf("\t4. 2 Guerra Mundial.\n");
    printf("\t5. Voltar\n");
}

void InfoObra(struct Obras ArteInfo) {
    setlocale(LC_ALL, "Portuguese");
    printf("\nTitulo: %s\n", ArteInfo.titulo);
    printf("Descricao: %s\n", ArteInfo.descricao);
    printf("Autor: %s\n", ArteInfo.autor);
    printf("Informacoes Gerais: %s\n", ArteInfo.infoGeral);
    system("Pause");
}

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    int menu, escolha;

    do
    {
        setlocale(LC_ALL, "Portuguese");

        struct Obras semana_art_1;
        strcpy(semana_art_1.autor, "Foto tirada por Mario de Andrade.");
        strcpy(semana_art_1.titulo, "Foto do primeiro evento registrado da 'Semana de Arte Moderna'");
        strcpy(semana_art_1.descricao, "A imagem exposta no quadro se refere ao primeiro evento registrado da 'Semana de arte moderna', Com diversas exposicoes como musica, poesia, pintura, danca dentre outros.");
        strcpy(semana_art_1.infoGeral, "Foto tirada em 1942.");

        struct Obras santos_durmont_1;
        strcpy(santos_durmont_1.autor, "Edvard Munch");
        strcpy(santos_durmont_1.titulo, "Quadro do artista Much, nomeado 'O Grito'");
        strcpy(santos_durmont_1.descricao, "Para exemplificar o conteudo, foi exposto um quadro 'O Grito' do pintor “Much” que foi pintado em 1893. A Obra fala sobre a realidade sofrida, fragil e violenta de cada ruptura cotidiana. Este quadro foi pintado por Munch em 1893 e atualmente e uma grande referencia quando se trata da influencia da Semana de Arte Moderna");
        strcpy(santos_durmont_1.infoGeral, "Obra pintada em 1893");

        struct Obras jogos_olimp_1;
        strcpy(jogos_olimp_1.autor, "Nome do autor");
        strcpy(jogos_olimp_1.titulo, "Projeto do estádio dos jogos de Paris 2024");
        strcpy(jogos_olimp_1.descricao, "Foi disponibilizado aos visitantes uma foto do projeto do estadio olimpico de Paris 2024. A foto deste projeto foi disponibilizada pelos próprios resposavel pela criação do estádio de Paris 2024.");
        strcpy(jogos_olimp_1.infoGeral, "ano 1000");

        struct Obras guerra_mundial_1;
        strcpy(guerra_mundial_1.autor, "Nome do autor");
        strcpy(guerra_mundial_1.titulo, "Exposição mostrando como era a vida na cidade de Stalingrado");
        strcpy(guerra_mundial_1.descricao, "Exemplos e imagens mostrando a cidade de Stalingrado (atual  Volgogrado) nas margens do rio Volvos, foi um grande combate travado entre a Wehrmacht (o exército da Alemanha Nazista) e seus aliados do Eixo contra as tropas da União Soviética, A batalha foi um dos pontos de virada da guerra na Frente Oriental, marcando o limite da expansão alemã no território soviético, a partir de onde o Exército Vermelho empurraria as forças alemãs ate Berlim.");
        strcpy(guerra_mundial_1.infoGeral, "Foto tirada entre 23 de agosto de 1942");

        exibirMenu();
        scanf("%d", &menu);

        switch (menu) {

            case 1:
                do
                {
                    MenuGaleria();
                    scanf("%d", &escolha);

                    switch (escolha)
                    {
                    case 1:
                        do
                        {
                            printf("\n..Bem-vindo a Galeria '100 anos da semana da arte moderna..'\n");
                            printf("Qual obra voce gostaria de visitar\n");
                            printf("\t1.Primeiro evento da 'Semana da arte Moderna'\n");
                            printf("\t3. Voltar\n");
                            scanf("%d", &escolha);

                            switch (escolha)
                            {
                            case 1:
                                InfoObra(semana_art_1);
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }
                        } while (escolha != 3);
                        break;

                    case 2:
                        do
                        {
                            printf("\n..Bem-vindo a Galeria '150 anos de Santos Durmont'\n");
                            printf("Qual obra voce gostaria de visitar\n");
                            printf("\t1. Quadro 'O Grito'\n");
                            printf("\t3. Voltar\n");
                            scanf("%d", &escolha);

                            switch (escolha)
                            {
                            case 1:
                                InfoObra(santos_durmont_1);
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }
                        } while (escolha != 3);
                        break;
                    
                    case 3:
                        do
                        {
                            printf("\n..Bem-vindo a Galeria 'Jogos olímpicos em Paris 2024.'\n");
                            printf("Qual obra voce gostaria de visitar\n");
                            printf("\t1. Foto Do Estadio'\n");
                            printf("\t3. Voltar\n");
                            scanf("%d", &escolha);

                            switch (escolha)
                            {
                            case 1:
                                InfoObra(jogos_olimp_1);
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }
                        } while (escolha != 3);
                        break;

                    case 4:
                        do
                        {
                            printf("\n..Bem-vindo a Galeria '2 Guerra Mundial.'\n");
                            printf("Qual obra voce gostaria de visitar\n");
                            printf("\t1. Batalha de Stalingrado'\n");
                            printf("\t3. Voltar\n");
                            scanf("%d", &escolha);

                            switch (escolha)
                            {
                            case 1:
                                InfoObra(guerra_mundial_1);
                                break;

                            default:
                                printf("\nOpcao invalida.\n");
                                break;
                            }
                        } while (escolha != 3);
                        break;

                    default:
                        printf("\nOpcao invalida.\n");
                        break;
                    }

                } while (escolha != 5);
                break;

            case 2:
                break;

            case 3:
                printf("\nSaindo do programa. Adeus!\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
            }
        } while (menu != 3);

    return 0;
}
