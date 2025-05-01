#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int valor1;
    int valor2;
    int resultado;
    int operacao;
    int dificuldade;
} calcular;

void jogar();
void mostrar_info(calcular calc);
int pontos = 0;
int somar(int resposta, calcular calc);
int subtracao(int resposta, calcular calc);
int multiplicacao(int resposta, calcular calc);

int main() {
    srand(time(NULL));
    jogar();
    return 0;
}

void jogar() {
    calcular calc;
    int dificuldade;
    printf("informe o valor da dificuldade da operacao matematica [1, 2, 3 ou 4]:\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;
    calc.operacao = rand() % 3;

    if (calc.dificuldade == 1) {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    } else if (calc.dificuldade == 2) {
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    } else if (calc.dificuldade == 3) {
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    } else if (calc.dificuldade == 4) {
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    } else {
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }

    printf("digite o resultado para a seguinte operacao:\n");
    int resposta;

    if (calc.operacao == 0) {
        printf("qual o valor de %d + %d: ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (somar(resposta, calc)) {
            pontos++;
            printf("voce tem %d pontos.\n", pontos);
        }
    } else if (calc.operacao == 1) {
        printf("qual o valor de %d - %d: ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (subtracao(resposta, calc)) {
            pontos++;
            printf("voce tem %d pontos.\n", pontos);
        }
    } else if (calc.operacao == 2) {
        printf("qual o valor de %d * %d: ", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        if (multiplicacao(resposta, calc)) {
            pontos++;
            printf("voce tem %d pontos.\n", pontos);
        }
    } else {
        printf("a operacao %d nao e reconhecida.\n", calc.operacao);
    }

    int continuar;
    printf("Voce gostaria de continuar o jogo [1-sim , 2-nao]? ");
    scanf("%d", &continuar);
    if (continuar == 1) {
        jogar();
    } else {
        printf("voce finalizou com %d pontos", pontos);
        exit(0);
    }
}

void mostrar_info(calcular calc) {
    char op[25];
    if (calc.operacao == 0) {
        sprintf(op, "somar");
    } else if (calc.operacao == 1) {
        sprintf(op, "subtracao");
    } else if (calc.operacao == 2) {
        sprintf(op, "multiplicacao");
    } else {
        sprintf(op, "operacao invalida");
    }
    printf("valor1: %d\n  valor2: %d\n  dificuldade: %d\n  operacao: %s\n", calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, calcular calc) {
    calc.resultado = calc.valor1 + calc.valor2;
    if (resposta == calc.resultado) {
        printf("A resposta esta correta!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 1;
    } else {
        printf("A resposta esta errada!\n");
        printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

int subtracao(int resposta, calcular calc) {
    calc.resultado = calc.valor1 - calc.valor2;
    if (resposta == calc.resultado) {
        printf("A resposta esta correta!\n");
        printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 1;
    } else {
        printf("A resposta esta errada!\n");
        printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}

int multiplicacao(int resposta, calcular calc) {
    calc.resultado = calc.valor1 * calc.valor2;
    if (resposta == calc.resultado) {
        printf("A resposta esta correta!\n");
        printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 1;
    } else {
        printf("A resposta esta errada!\n");
        printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
        return 0;
    }
}
