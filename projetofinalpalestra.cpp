#include <iostream>
#include <map>
#include <windows.h>

using namespace std;

int main() {
    map<string, float> cardapio;
    cardapio["Coca-Cola"] = 3.50;
    cardapio["Fanta"] = 3.00;
    cardapio["Guarana"] = 2.50;
    cardapio["Sprite"] = 2.00;
    cardapio["Agua"] = 1.50;
    cardapio["Hamburguer"] = 10.00;
    cardapio["Pizza"] = 15.00;
    cardapio["Salada"] = 5.50;

    map<string, int> carrinho;
    float totalCompra = 0.0;
    char item[50];
    int quantidade;
    int opcao, opcao1, opcaopagamento, opcaoparcela;
    float parcela1 = 0.0;
    float troco = 0.0;

    printf("\n\n\t\tDesenvolvido por Joao Pedro, Kaylan Henrique e Victor Octavio da turma de Eletronica.");
    Sleep(2500);
    system("cls");
    printf("\n\t\t  _____ ______ _____ _____  	");
    printf("\n\t\t |_   _|  ____/ ____|  _  \\ 	");
    printf("\n\t\t   | | | |__ | (___ | |__) |	");
    printf("\n\t\t   | | |  __| \\__  \\|  ___/ 	");
    printf("\n\t\t  _| |_| |    ____) | |     	");
    printf("\n\t\t |_____|_|   |_____/|_|     		");
    printf("\n\n\t");
    printf("\n\n\tLogin automatico pela rede do instituto...");

    Sleep(2000);

    while (true) {
        system("cls");
        printf("\n\t\t  _____ ______ _____ _____  	");
        printf("\n\t\t |_   _|  ____/ ____|  _  \\ 	");
        printf("\n\t\t   | | | |__ | (___ | |__) |	");
        printf("\n\t\t   | | |  __| \\__  \\|  ___/ 	");
        printf("\n\t\t  _| |_| |    ____) | |     	");
        printf("\n\t\t |_____|_|   |_____/|_|     		");
        printf("\n\n\t");

        printf("Bem-vindo(a) ao nossa lanchonete exclusiva do IFSP.");
        printf("\n\t Escolha uma das opcoes: \n");
        printf("\n\t 1. Adicionar itens ao carrinho");
        printf("\n\t 2. Exibir o carrinho");
        printf("\n\t 3. Finalizar compra");
        printf("\n\t 4. Sair");
        printf("\n\n\t Escolha uma: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("\n\t======= Cardapio =======\n");
                for (const auto& it : cardapio) {
                    printf("\t%s - R$ %.2f\n", it.first.c_str(), it.second);
                }
                printf("\t========================\n");

                printf("\n\tDigite o nome do item: ");
                scanf("%s", item);

                if (cardapio.count(item) > 0) {
                    printf("\n\tDigite a quantidade: ");
                    scanf("%d", &quantidade);

                    carrinho[item] += quantidade;
                    totalCompra += cardapio[item] * quantidade;

                    printf("\n\tItem adicionado ao carrinho com sucesso!\n");
                    Sleep(2000);
                } else {
                    printf("\n\tItem nao encontrado no cardapio.\n");
                    Sleep(2000);
                }

                break;

            case 2:
                system("cls");
                printf("\n\t======= Carrinho =======\n");
                for (const auto& it : carrinho) {
                    printf("\t%s - Quantidade: %d\n", it.first.c_str(), it.second);
                }
                printf("\t========================\n");

                printf("\n\tTotal da compra: R$ %.2f\n", totalCompra);
                Sleep(5000);
                break;

            case 3:
                system("cls");
                printf("\n\tEscolha a forma de pagamento:\n");
                printf("\n\t1. Dinheiro");
                printf("\n\t2. Cartao de credito");
                printf("\n\n\tEscolha uma: ");
                scanf("%d", &opcaopagamento);

                while (opcaopagamento != 1 && opcaopagamento != 2) {
                	system("cls");
                    printf("\n\tOpcao de pagamento invalida.\n");
                    Sleep(2000);
                    printf("\n\tEscolha a forma de pagamento:\n");
                    printf("\n\t1. Dinheiro");
                    printf("\n\t2. Cartao de credito");
                    printf("\n\n\tEscolha uma: ");
                    scanf("%d", &opcaopagamento);
                }

                if (opcaopagamento == 1) {
                    system("cls");
                    printf("\n\tTotal da compra: R$ %.2f\n", totalCompra);
                    printf("\n\tDigite o valor em dinheiro: R$ ");
                    scanf("%f", &parcela1);

                    if (parcela1 < totalCompra) {
                        printf("\n\tValor insuficiente. Pagamento nao realizado.\n");
                        Sleep(2000);
                        break;
                    }

                    troco = parcela1 - totalCompra;
                    system("cls");
                    printf("\n\tPagamento realizado com sucesso!\n");
                    printf("\n\n\tDADOS DO PEDIDO: ");
                    for (const auto& it : carrinho) {
                    printf("\n\t%s - Quantidade: %d\n", it.first.c_str(), it.second);
                	}
                    printf("\n\tTotal do pedido: R$ %.2f", totalCompra);
                    printf("\n\tPagamento: dinheiro");
                    printf("\n\tTroco: %.2f", troco);
                    printf("\n\tEm 30 minutos, busque o seu pedido na cantina.");
                    Sleep(5000);
                    carrinho.clear();
                    totalCompra = 0.0;
                    Sleep(5000);
                    break;
                } else if (opcaopagamento == 2) {
                    system("cls");
                    printf("\n\tTotal da compra: R$ %.2f\n", totalCompra);
                    printf("\n\tEscolha o numero de parcelas: ");
                    scanf("%d", &opcaoparcela);

                    if (opcaoparcela <= 0) {
                        printf("\n\tNumero de parcelas invalido. Pagamento nao realizado.\n");
                        Sleep(2000);
                        break;
                    }

                    float valorParcela = totalCompra / opcaoparcela;
                    system("cls");
                    printf("\n\tPagamento realizado com sucesso!\n");
                    printf("\n\n\tValor da parcela: R$ %.2f\n", valorParcela);
                    printf("\n\tDADOS DO PEDIDO: ");
                	for (const auto& it : carrinho) {
                    printf("\n\t%s - Quantidade: %d\n", it.first.c_str(), it.second);
                	}
                    printf("\n\tTotal do pedido: R$ %.2f", totalCompra);
                    printf("\n\tValor da parcela: R$ %.2f\n", valorParcela);
                    printf("\n\tEm 30 minutos, busque o seu pedido na cantina.");
                    Sleep(5000);
                    carrinho.clear();
                    totalCompra = 0.0;
                    Sleep(5000);
                    break;
                }

            case 4:
                system("cls");
                printf("\n\tObrigado por utilizar nossa lanchonete!\n");
                Sleep(2000);
                exit(0);
                break;

            default:
                printf("\n\tOpcao invalida.\n");
                Sleep(2000);
                break;
        }
    }

    return 0;
}
