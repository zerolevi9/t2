#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logging.h"

struct hospital{
  int raioX[5][3]; //col1 = se está disponivel, col2 = tempo que será usada, col3 = id do paciente
  int laudo[3][3]; //col1 = se está disponivel, col2 = tempo que será usada, col3 = id do paciente
};
struct paciente {
  char nome[50];
  char cpf[15];
  int idade;
  int id;
  int doença[2]; //id da doença e a gravidade
  int entrada, entrada_raiox, saida_raiox, entrada_laudo, saida;
};
struct node {
  void *data;
  Node *next;
  Node *prev;
};
struct lista {
  Node *First;
  Node *Last;
  int size;
};

struct fila {
  Node *Front;
  Node *Rear;
  int size;
};

/*-----------------------------------------------------------------
                            Lista
-----------------------------------------------------------------*/

Lista *init_Lista(){
    Lista *list = (Lista *)malloc(sizeof(Lista));
    list->First = NULL;
    list->Last = NULL;
    list->size = 0;
    return list;
}
void append(Lista *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = list->Last;
    newNode->next = NULL;
    if(list->size != 0) {
      list->Last->next = newNode;
    }
    else{
      list->First = newNode;
    }
    list->Last = newNode;
    list->size++;
}
void remove_data(Lista *l, void *val) {
  Node *temp = l->First;
  Node *prev = NULL;
  Node *aux;
  while (temp != NULL) {
    if (temp->data == val) {
      aux = temp;
      if (prev != NULL) {
        prev->next = temp->next;
        if (temp->next == NULL) {
          l->Last = prev;
        }
      } else {
        l->First = temp->next;
        if (temp->next == NULL) {
          l->Last = NULL;
        }
      }
      temp = temp->next;
      free(aux);
    } 
    else {
      prev = temp;
      temp = temp->next;
    }
  }
  l->size--;
}
void freeLista(Lista *list) {
    Node *current = list->First;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
void print_list(Lista *l){
   for (Node *p = l->First; p != NULL; p = p->next)
   {
     void *a = p->data;
      print_p(a); 
   }
   printf("\n"); 
}

/*----------------------------------------------------------------
                            Fila
-----------------------------------------------------------------*/

Fila *init_Fila(){
  Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->Rear = NULL;
    fila->Front = NULL;
    fila->size = 0;
    return fila;
}
void append_f(Fila *fila, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = fila->Rear;
    newNode->next = NULL;
    if(fila->size != 0) {
      fila->Rear->next = newNode;
    }
    else{
      fila->Front = newNode;
    }
    fila->Rear = newNode;
    fila->size++;
}

void remove_data_f(Fila *f) {
    if (f->Front == NULL) {
        fprintf(stderr, "Erro: Fila vazia\n");
        return;
    }
    Node *temp = f->Front;
    f->Front = f->Front->next;
    // Se a fila ficar vazia após a remoção
    if (f->Front == NULL) {
        f->Rear = NULL;
    } 
    else {
        f->Front->prev = NULL;
    }
    free(temp);              // Liberar o nó removido
    f->size--;
}
void freeFila(Fila *fila) {
    Node *current = fila->Front;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(fila);
}
void print_fila(Fila *f){
   for (Node *p = f->Front; p != NULL; p = p->next)
   {
     void *a = p->data;
      print_p(a); 
   }
   printf("\n"); 
}

/*---------------------------------------------------------------
                              TAD
---------------------------------------------------------------*/

Hospital *init_Hospital(){
  Hospital *h = (Hospital *)malloc(sizeof(Hospital));
  return h;
}
int prob_pac(){
  int prob = rand() % 100;
  if(prob < 20){
    return 1;
  }
  return 0;
}
int prob_pat(){
  int prob = rand() % 100;
  int SAUDE_NORMAL = 1;
  int BRONQUITE = 2;
  int PNEUMONIA = 3;
  int FRATURA_DE_FEMUR = 4;
  int APENDICITE = 4;

  if(prob < 30 ){
    return SAUDE_NORMAL;
  }
  else if (prob >= 30 && prob < 50){
    return BRONQUITE;
  }
  else if (prob >= 50 && prob < 70){
    return PNEUMONIA;
  }
  else if (prob >= 70 && prob < 85){
    return FRATURA_DE_FEMUR;
  }
  else if (prob >= 85){
    return APENDICITE;
  }
  return 0;
}
int prob_raiox(){
  int k = 5 + (rand() % 6);
  return k;
}
int prob_laudo(){
  int k = 10 + rand() % 21;
  return k;
}
char* gerarNome() {
    char* nomes[] = {"Joao", "Maria", "Carlos", "Ana", "Pedro", "Julia", "Lucas", "Mariana", "Guilherme"};
    // Gera um índice aleatório para escolher um nome da lista
    int indice = rand() % (sizeof(nomes) / sizeof(nomes[0]));
    // Aloca memória para o nome
    char* nome = strdup(nomes[indice]);
    return nome;
}
char* gerarCPF() {
    char cpf[15];
    // Gera números aleatórios para o CPF
    sprintf(cpf, "%03d.%03d.%03d-%02d", rand() % 1000, rand() % 1000, rand() % 1000, rand() % 100);
    // Aloca memória para o CPF
    char* resultado = strdup(cpf);
    return resultado;
}
int gerarIdade() {
  return rand() % 100;
}
Paciente *gerarPaciente(int ID){
  Paciente *paciente = (Paciente *)malloc(sizeof(Paciente));
  if (paciente == NULL) {
    fprintf(stderr, "Erro ao alocar memória para Paciente\n");
    exit(EXIT_FAILURE);
  }
  // Gera aleatoriamente o nome, CPF e idade
  strcpy(paciente->nome, gerarNome());
  strcpy(paciente->cpf, gerarCPF());
  paciente->idade = gerarIdade();
  paciente->id = ID;
  paciente->doença[1] = prob_pat();
  paciente->entrada = ID;
  return paciente;
}
void print_p(Paciente *p){
  printf("Nome: %-9s ", p->nome);
  printf("CPF: %-15s ", p->cpf);
  printf("Idade: %-3d ", p->idade);
  printf("Id: %0.5d ", p->id);
  printf("Gravidade: %-1.d\n", p->doença[1]);
  printf("entrada: %-5d entrada_raiox: %-5d saida_raiox: %-5d entrada_laudo: %-5d saida: %-5d\n", p->entrada, p->entrada_raiox, p->saida_raiox, p->entrada_laudo, p->saida);
}
void appendf(Lista *list, Paciente *p){
  Node *newNode = (Node*)malloc(sizeof(Node));
  int *aux = (int*)malloc(sizeof(int));
  *aux = p->id;
  newNode->data = aux;
  newNode->prev = list->Last;
  newNode->next = NULL;
  if(list->size != 0) {
    list->Last->next = newNode;
  }
  else{
    list->First = newNode;
  }
  list->Last = newNode;
  list->size++;
}
void swap(Node *a, Node *b) {
  if (a == NULL || b == NULL || a == b) {
      return;  
  }
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = a->data;
  a->data = b->data;
  b->data = temp->data;
}
void insere_ordenado(Fila *fila, Paciente *novo_paciente) {
    // Aloca memória para o novo nó
    Node *novo_node = (Node *)malloc(sizeof(Node));
    if (novo_node == NULL) {
        fprintf(stderr, "Erro ao alocar memória para novo_node\n");
        exit(EXIT_FAILURE);
    }
    if (novo_paciente == NULL) {
      free(novo_node); // Libera o nó alocado se o paciente for nulo
      return;
    }
    // Configuração do novo nó
    novo_node->data = novo_paciente;
    novo_node->prev = NULL;
    novo_node->next = NULL;
    // Caso especial: fila vazia
    if (fila->Front == NULL) {
        fila->Front = novo_node;
        fila->Rear = novo_node;
        fila->size++;
        return;
    }
    // Procura a posição correta para inserir o novo paciente
    Node *atual = fila->Front;
    while (atual != NULL && novo_paciente->doença[1] >= ((Paciente *)atual->data)->doença[1]) {
        atual = atual->next;
    }
    // Insere o novo_node na posição correta
    if (atual != NULL) {
        Node *anterior = atual->prev;
        novo_node->next = atual;
        novo_node->prev = anterior;
        if (anterior != NULL) {
            anterior->next = novo_node;
        } 
        else {
            // Se anterior é nulo, então o novo_node se torna o novo Front
            fila->Front = novo_node;
        }
        atual->prev = novo_node;
    } 
    else {
        // Se chegou ao final da fila, insere no final
        Node *ultimo = fila->Rear;
        novo_node->prev = ultimo;
        ultimo->next = novo_node;
        fila->Rear = novo_node; // Atualiza o Rear
    }
    fila->size++;
}
void fila_atendimento_raiox(Fila *fila_SE, Fila *raiox, Hospital *h, int j){
  if(fila_SE->Front == NULL){
    return;
  }
  Paciente *aux = (Paciente*)fila_SE->Front->data;
  for (int i = 0;i<5;i++){
    if(h->raioX[i][0] == 0){
      h->raioX[i][0] = 1;
      h->raioX[i][1] = prob_raiox();
      h->raioX[i][2] = aux->id;
      aux->entrada_raiox = j;
      remove_data_f(fila_SE);
      insere_ordenado(raiox, aux);
      return;
    }
  }
}
void fila_atendimento_laudo(Fila *fila_raiox, Fila *laudo, Hospital *h, int j){
  if (fila_raiox->Front == NULL) {
    return; // Não há pacientes no raio-x, portanto, não é possível ir para o laudo
  }

  Paciente *aux = (Paciente *)fila_raiox->Front->data;
  if (aux->saida_raiox == 0) {
    return; // O paciente ainda não passou pelo raio-x, então não pode ir para o laudo
  }

  for (int i = 0; i < 3; i++) {
    if (h->laudo[i][0] == 0) {
      h->laudo[i][0] = 1;
      h->laudo[i][1] = prob_laudo();
      h->laudo[i][2] = aux->id;
      aux->entrada_laudo = j;
      remove_data_f(fila_raiox);
      insere_ordenado(laudo, aux);
      return;
    }
  }
}
void atualiza_tempo_raiox(Hospital *h){
  for(int i = 0;i<5;i++){
    if(h->raioX[i][1] != 0){
      h->raioX[i][1]--;
    }
    if(h->raioX[i][1] == 0){
      h->raioX[i][0] = 0;
    }
  }
}
void atualiza_tempo_laudo(Hospital *h){
  for(int i = 0;i<3;i++){
    if(h->laudo[i][1] != 0){
      h->laudo[i][1]--;
    }
    if(h->laudo[i][1] == 0){
      h->laudo[i][0] = 0;
    }
  }
}
void atualiza_raiox(Hospital *h, Fila *fila_raiox, int j){
  for(int i = 0;i<5;i++){
    if(h->raioX[i][1] == 0){
      Node *k = fila_raiox->Front;
      Paciente *paciente;
      while (k != NULL) {
        paciente = (Paciente *)k->data;
        if (paciente->id == h->raioX[i][2]) {
          paciente->saida_raiox = j;
          h->raioX[i][2] = 0;
          return;
        }
        k = k->next;
      }
    }
  }
}
void atualiza_laudo(Hospital *h, Fila *fila_laudo, int j){
  for(int i = 0;i<3;i++){
    if(h->laudo[i][1] == 0){
      Node *k = fila_laudo->Front;
      while (k != NULL) {
        Paciente *paciente = (Paciente *)k->data;
        if (paciente->id == h->laudo[i][2]) {
          paciente->saida = j;
          h->laudo[i][2] = 0;
          return;
        }
        k = k->next;
      }
    }
  }
}
int verifica_raiox(Hospital *h){
  for (int i = 0; i < 5; i++) {
    if (h->raioX[i][0] == 0) {
      return 1;  // Encontrou uma vaga no raio-x
    }
  }
  return 0; // Não encontrou vaga no raio-x
}
int verifica_laudo(Hospital *h){
  for (int i = 0; i < 3; i++) {
    if (h->laudo[i][0] == 0) {
      return 1;  // Encontrou uma vaga no laudo
    }
  }
  return 0; // Não encontrou vaga no laudo
}
void atualiza_lista_controle(Fila *fila_laudo, Lista *lista_controle){
  if(fila_laudo->Front == NULL || lista_controle->First == NULL){
    return;
  }
  Node *aux = fila_laudo->Front;
  if(((Paciente*)aux->data)->saida == 0) return;
  for(Node *j = lista_controle->First;j != NULL; j = j->next){
    if(((Paciente*)j->data)->id == ((Paciente*)aux->data)->id){
      lista_controle->First->data = j->data; //troca apenas os dados
      remove_data_f(fila_laudo);//tira da fila, já foi atendido
      return;
    }
  }
}

float media_laudo(Lista *controle){
  float k = 0.0;
  int count = 0;
  Node *z = controle->First;
  for (int i = 0; i < controle->size; i++) {
      if (((Paciente *)z->data)->saida != 0) {
        k += ((Paciente *)z->data)->saida - ((Paciente *)z->data)->entrada;
        count++;
      }
      z = z->next;
  }
  // Evita divisão por zero
  if (count != 0) {
    return k / count;
  } 
  return 0.0;
}
  void media_patologias(Lista *controle, float registro_pat[][3]) {
  if (controle->First == NULL) {
      return;
  }
  int j = 5;
  Node *z = controle->First;
  for (int i = 0; i < j; i++) {
    float k = 0.0;
    int count = 0;
    z = controle->First;  // Reinicia o ponteiro para o início da lista
    while (z != NULL) {
      if (((Paciente *)z->data)->saida != 0 && ((Paciente *)z->data)->doença[0] == registro_pat[i][0]) {
        k += ((Paciente *)z->data)->saida - ((Paciente *)z->data)->entrada;
        count++;
      }
      z = z->next;
    }
    if (count != 0) {
        registro_pat[i][1] = k / count;
    }
  }
}
int exames_pos_tempo(Lista *controle, int j){
  float k = 0.0;
  int count = 0;
  Node *z = (Node *)malloc(sizeof(Node));
  z = controle->First;

  for (int i = 0; i < controle->size; i++) {
      if (((Paciente *)z->data)->saida != 0) {
        k = ((Paciente *)z->data)->saida - ((Paciente *)z->data)->entrada;
        if(k>7200){
          count++;
        }
        k = j - ((Paciente *)z->data)->entrada;
        if(k>7200){
          count++;
        }
      }
      z = z->next;
  }
  return count;
} 
/*
void escreve_log(Lista *eventos, const char *filename){
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
      printf("Erro: não foi possível criar o arquivo %s.\n", filename);
      exit(EXIT_FAILURE);
  }
  fprintf(file, "chegada: %f inicio/fim do raio-x: %f/%f inicio/fim do laudo: %f/%f", chegada(), inicio_raiox(),fim_raiox(), inicio_laudo(),fim_laudo());
  fclose(file);
}*/

void printa_metrica(Lista *controle, float registro_pat[][3], int j){
  printf("laudo: %f\n patologias: sn: %f b: %f p: %f ff: %f a: %f fora do tempo: %d\n", media_laudo(controle),  registro_pat[0][1], registro_pat[1][1], registro_pat[2][1], registro_pat[3][1], registro_pat[4][1], exames_pos_tempo(controle, j));
}
void print_h(Hospital *h){
  for(int i = 0; i < 5; i++){
    printf("disponibilidade r: %d tempo: %d id: %d\n", h->raioX[i][0],h->raioX[i][1],h->raioX[i][2]);
  }
  for(int i = 0; i < 3; i++){
    printf("disponibilidade l: %d tempo: %d id: %d\n", h->laudo[i][0],h->laudo[i][1],h->laudo[i][2]);
  }
}