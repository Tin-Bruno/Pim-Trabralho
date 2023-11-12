#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Obras {
    char autor[100];
    char titulo[150];
    char descricao[1000];
    char infoGeral[100];
    int avaliacao;
};

void exibirMenu() {
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t...Menu Principal...\t\n");
    printf("\nBem-vindo a Galeria de Arte!\n");
    printf("\t1. Galeria\n");
    printf("\t2. Relatorio de avaliacoes das obras\n");
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
    printf("\nEsta obra foi avaliada em: %d\n", ArteInfo.avaliacao);
    system("Pause");
}

void interacaoVisitante(struct Obras *ArteInfo) {
    printf("\nAvalie esta obra de 1 a 5 (sendo 1 ruim e 5 excelente):\n");
    scanf("%d", &(ArteInfo->avaliacao));
}

void escreverAvaliacaoNoArquivo(int avaliacao, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fprintf(arquivo, "%d\n", avaliacao);
    fclose(arquivo);
}

float calcularMediaAvaliacoes(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        return -1;
    }

    int totalAvaliacoes = 0;
    int somaAvaliacoes = 0;
    int avaliacao;

    while (fscanf(arquivo, "%d\n", &avaliacao) == 1) {
        totalAvaliacoes++;
        somaAvaliacoes += avaliacao;
    }

    fclose(arquivo);

    if (totalAvaliacoes > 0) {
        return (float)somaAvaliacoes / totalAvaliacoes;
    } else {
        return 0.0;
    }
}

int main() {
    
    setlocale(LC_ALL, "Portuguese");
    int menu, escolha;
    float media;

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
                do
                {
                    const char *nomeArquivo = "avaliacoes.txt";
                    printf("\n\t...Avaliacao de uma obra...\n");
                    printf("\nQual obra gostaria de avaliar?\n");
                    printf("\t1. 100 anos da semana da arte moderna\n");
                    printf("\t2. 150 anos de Santos Durmont\n");
                    printf("\t3. Jogos olimpicos em Paris 2024.\n");
                    printf("\t4. 2 Guerra Mundial.\n");
                    printf("\t5. Calcular media de avaliacoes\n");
                    printf("\t6. Voltar\n");
                    scanf("%d", &escolha);

                    switch (escolha)
                    {
                    case 1:
                        semana_art_1.avaliacao = 0;
                        printf("\n\t..Avaliacao da Galeria '100 anos da semana da arte moderna'..\n");
                        interacaoVisitante(&semana_art_1);
                        InfoObra(semana_art_1);
                        escreverAvaliacaoNoArquivo(semana_art_1.avaliacao, nomeArquivo);
                        media = calcularMediaAvaliacoes(nomeArquivo);
                        break;

                    case 2:
                        santos_durmont_1.avaliacao = 0;
                        printf("\n\t..Avaliacao da Galeria '150 anos de Santos Durmont'..\n");
                        interacaoVisitante(&santos_durmont_1);
                        InfoObra(santos_durmont_1);
                        escreverAvaliacaoNoArquivo(santos_durmont_1.avaliacao, nomeArquivo);
                        media = calcularMediaAvaliacoes(nomeArquivo);
                        break;
                    
                    case 3:
                        jogos_olimp_1.avaliacao = 0;
                        printf("\n\t..Avaliacao da Galeria 'Jogos olimpicos em Paris 2024'..\n");
                        interacaoVisitante(&jogos_olimp_1);
                        InfoObra(jogos_olimp_1);
                        escreverAvaliacaoNoArquivo(jogos_olimp_1.avaliacao, nomeArquivo);
                        media = calcularMediaAvaliacoes(nomeArquivo);
                        break;

                    case 4:
                        guerra_mundial_1.avaliacao = 0;
                        printf("\n\t..Avaliacao da Galeria '2 Guerra Mundial.'..\n");
                        interacaoVisitante(&guerra_mundial_1);
                        InfoObra(guerra_mundial_1);
                        escreverAvaliacaoNoArquivo(guerra_mundial_1.avaliacao, nomeArquivo);
                        media = calcularMediaAvaliacoes(nomeArquivo);
                        break;

                    case 5:
                        media = calcularMediaAvaliacoes(nomeArquivo);
                        if (media >= 0) {
                        printf("\nmedia de avaliacoes gerais: %.2f\n", media);
                        } else {
                        printf("\nErro ao calcular a madia de avaliacoes.\n");
                        }
                    default:
                        printf("\nOpcao invalida.\n");
                        break;
                    }

                } while (escolha != 6);
                
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
