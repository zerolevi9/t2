#ifndef FILA_H
#define FILA_H

typedef struct node Node;
typedef struct lista Lista;
typedef struct fila Fila;
typedef struct paciente Paciente;
typedef struct hospital Hospital;

// Estruturas e funções relacionadas à Lista Encadeada

// Função para inicializar uma lista encadeada vazia
Lista *inicia_Lista();

// Função para adicionar um elemento no início da lista encadeada
void insere_Lista(Lista *lista, void *dados);

// Função que remove um valor da lista
void remove_dados_lista(Lista *l, void *val);

// Função para liberar a memória alocada para a lista encadeada
void liberaLista(Lista *lista);

// Estruturas e funções relacionadas à Fila

// Função para inicializar uma fila vazia
Fila *inicia_Fila();

// Função que remove um valor da fila
void remove_dados_fila(Fila *fila);

// Função para liberar a memória alocada para a fila
void liberaFila(Fila *fila);

// Estruturas e funções relacionadas ao Hospital

// Função para inicializar a estrutura do hospital
Hospital *inicia_Hospital();

// Função que libera a memória alocada para a estrutura do hospital
void liberaHospital(Hospital *hospital);

// Funções relacionadas à probabilidade

// Função que determina se haverá paciente
int probabilidade_paciente();

// Função que determina a patologia do paciente
int *probabilidade_patologia();

// Funções relacionadas a probabilidades de tempo para exames

// Gera um número entre 5 e 10, em unidades de tempo, para pegar o raio-x
int probabilidade_raiox();

// Gera um número entre 10 e 30, em unidades de tempo, para pegar o laudo
int probabilidade_laudo();

// Funções relacionadas à geração aleatória de informações pessoais

// Gera aleatoriamente um nome
char *gerarNome();

// Gera aleatoriamente um CPF
char *gerarCPF();

// Gera aleatoriamente uma idade entre 18 e 99 anos
int gerarIdade();

// Gera aleatoriamente um paciente
Paciente *gerarPaciente(int ID);

// Funções relacionadas ao atendimento nas filas

// Coloca na fila do raio-x
void fila_atendimento_raiox(Fila *fila_SE, Fila *raiox, Hospital *hospital, int unidade_de_tempo);

// Atualiza o tempo para terminar o raio-x
void fila_atendimento_laudo(Fila *fila_raiox, Fila *laudo, Hospital *hospital, int unidade_de_tempo);

// Atualiza o tempo para terminar o raio-x e verifica se o exame terminou
void atualiza_tempo_raiox(Hospital *hospital);

// Atualiza o tempo para terminar o laudo e verifica se terminou o atendimento
void atualiza_tempo_laudo(Hospital *hospital);

// Atualiza o tempo de saída do paciente no raio-x e o retira do raio-x
void atualiza_raiox(Hospital *hospital, Fila *fila_raiox, int unidade_de_tempo);

// Atualiza o tempo de saída do paciente da sala de laudo e o retira da sala de laudo
void atualiza_laudo(Hospital *hospital, Fila *fila_laudo, int unidade_de_tempo);

// Funções de verificação de disponibilidade de recursos

// Verifica se há máquina de raio x disponível
int verifica_raiox(Hospital *hospital);

// Verifica se há médico disponível e se o paciente já passou no raio x
int verifica_laudo(Hospital *hospital);

// Função para atualizar a contagem de tempo dos pacientes
void atualiza_lista_controle(Fila *fila_laudo, Lista *lista_controle);

// Funções relacionadas a métricas e estatísticas

// Pega a média de tempo para se ter o laudo
float media_laudo(Lista *controle);

// Pega a média de tempo para se ter o laudo por patologia
void media_patologias(Lista *controle, Hospital *hospital);

// Retorna o número de exames que demoraram mais de 7200 U.T (Unidades de Tempo)
int exames_apos_tempo(Lista *controle);

// Função que imprime as métricas
void printa_metrica(Lista *controle, Hospital *hospital);

// Função para inserir paciente ordenadamente na fila pela gravidade
void insere_ordenado(Fila *lista, Paciente *novo_paciente);
#endif
