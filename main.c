#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logging.h"

/*#ifdef  _WIN64
    #include <Windows.h>
#else
    #include <unistd.h>
#endif
*/
int main() {
  int con = 0;
  Lista *lista_controle = init_Lista(); //lista não ordenada
  Fila *fila_SE = init_Fila(); //fila da sala de espera (já ordenada)
  Fila *fila_raiox = init_Fila();
  Fila *fila_laudo = init_Fila();
  Hospital *h = init_Hospital();
  float registro_pat[5][3];//patologia, tempo e id
  srand(time(NULL));
  
  for(int c = 1;c<4320;c++){
    if(prob_pac()){  
      Paciente *paciente = gerarPaciente(c);
      append(lista_controle, paciente);
      //coloca já ordenado na fila, por ordem de gravidade da doença
      insere_ordenado(fila_SE, paciente);
    }
    //sequência de verificações para olhar o tempo da consulta e as máquinas desocupadas
    atualiza_tempo_raiox(h);
    atualiza_tempo_laudo(h);
    atualiza_raiox(h, fila_raiox, c);
    atualiza_laudo(h, fila_laudo, c);
    //con++;
    //printf("%d ", verifica_raiox(h));
    //printf("%d\n", verifica_laudo(h));
    //print_h(h);
    if(verifica_raiox(h)){
      fila_atendimento_raiox(fila_SE, fila_raiox, h, c);
    }
    if(verifica_laudo(h)){
      fila_atendimento_laudo(fila_raiox, fila_laudo, h, c);
    }
    atualiza_lista_controle(fila_laudo, lista_controle);
    if((c%10) == 0){
      //Sleep(1);
      printa_metrica(lista_controle, registro_pat, c);
    }
  }
  //printf("%d\n", size(lista_controle));
  //print_list(lista_controle);
  //print_fila(fila_SE);
  freeLista(lista_controle);
  freeFila(fila_raiox);
  freeFila(fila_laudo);
  freeFila(fila_SE);
  free(h);
  return 0;
}
