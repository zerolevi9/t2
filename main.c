#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

int main(){
  Lista *lista_controle = inicia_Lista(); //Lista não ordenada
  Fila *fila_SE = inicia_Fila(); //Fila sala de espera já ordenada
  Fila *fila_raiox = inicia_Fila();//Fila de quem vai fazer ou está fazendo raio-X já ordenado
  Fila *fila_laudo = inicia_Fila();//Fila de quem vai fazer ou está fazendo raio-X já ordenado
  Hospital *hospital = inicia_Hospital();//Váriavel que controla os equipamentos e funcionários do hospital
  srand(time(NULL));
  
  for (int Unidade_de_tempo = 1; Unidade_de_tempo < 43200; Unidade_de_tempo++) {
      // Verifica se um novo paciente chega com base na probabilidade
      if (probabilidade_paciente()) {
          // Gera um novo paciente e o adiciona à lista de controle e à fila ordenada
          Paciente *paciente = gerarPaciente(Unidade_de_tempo);
          insere_Lista(lista_controle, paciente);
          insere_ordenado(fila_SE, paciente);
      }

      // Atualiza o tempo para os serviços de raio-X e laudo
      atualiza_tempo_raiox(hospital);
      atualiza_tempo_laudo(hospital);

      // Atualiza o status dos serviços de raio-X e laudo, bem como as filas
      atualiza_raiox(hospital, fila_raiox, Unidade_de_tempo);
      atualiza_laudo(hospital, fila_laudo, Unidade_de_tempo);

      // Verifica se há vagas disponíveis na fila de raio-X
      if (verifica_raiox(hospital)) {
          // Move pacientes da fila ordenada de espera para a fila de raio-X
          fila_atendimento_raiox(fila_SE, fila_raiox, hospital, Unidade_de_tempo);
      }

      // Verifica se o raio-X foi concluído e a sala de consulta está disponível
      if (verifica_laudo(hospital)) {
          // Move pacientes da fila de raio-X para a fila de laudo
          fila_atendimento_laudo(fila_raiox, fila_laudo, hospital, Unidade_de_tempo);
      }

      // Atualiza a lista de controle com entradas e saídas de pacientes
      atualiza_lista_controle(fila_laudo, lista_controle);

      // Imprime métricas a cada 10 unidades de tempo
      if ((Unidade_de_tempo % 10) == 0) {
          printa_metrica(lista_controle, hospital);
      }
  }

// Liberando memória
liberaLista(lista_controle);  // Libera a memória da lista de controle
liberaFila(fila_raiox);       // Libera a memória da fila de raio-X
liberaFila(fila_laudo);        // Libera a memória da fila de laudo
liberaFila(fila_SE);           // Libera a memória da fila de sala de espera
liberaHospital(hospital);      // Libera a memória da estrutura Hospital

return 0; // Indica que o programa foi executado com sucesso
}
