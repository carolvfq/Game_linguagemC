#include <stdio.h>
typedef struct{
    int valor1;
    int valor2;
    int resultado;
    int operacao;
    int dificuldade;
}calcular;

void jogar();
void mostrar_info(calcular calc);
int pontos=0;

int main(){
srand(time(NULL));
jogar();

    return 0;
}

void jogar(){

}

void mostrar_info(calcular calc){
   char op[25];
   if (calc.operacao == 0){
     sprintf(op, "somar");
   }
   else if (calc.operacao == 1){
    sprintf(op, "subtracao");
  }
   else if (calc.operacao == 2){
    sprintf(op, "multiplicacao");
  }
  else {
    sprintf(op, "operacao invalida");
  }

  printf("valor1: %d\n , valor2: %d\n, dificuldade: %d\n , operacao: %s\n", calc.valor1, calc.valor2, calc.dificuldade,op);
}

soma(int respostas,calcular calc){
  int resultado = calc.valor1 + calc.valor2;
  calc.resultado= resultado;
  int certo = 0; 
  if(resultado == calc.resultado){
    printf("A resposta esta correta!\n");
    certo= 1;
  }
  else{
   printf("A resposta esta errada!\n");
  }
printf("%d + %d = %d", calc.valor1, calc.valor2, calc.resultado);
return certo;

}

subtracao(int respostas,calcular calc){

}

multiplicacao(int respostas,calcular calc){

}