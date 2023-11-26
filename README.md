# Sistema de Atendimento Hospitalar

Este sistema simula o fluxo de atendimento em um hospital, incluindo a chegada de pacientes, a realização de exames de raio-x, a emissão de laudos médicos e métricas de desempenho do atendimento.

## Funcionalidades Principais

1. Geração de Pacientes
Utiliza funções para gerar aleatoriamente nomes, CPFs, idades e informações de pacientes.

Função de Geração de Nomes Aleatórios:
A função é responsável por gerar aleatoriamente nomes para os pacientes. A lista de nomes pré-definida é utilizada, e um índice aleatório é escolhido para selecionar um nome da lista.

Função de Geração de CPFs Aleatórios:
A função gerarCPF é responsável por gerar aleatoriamente CPFs para os pacientes. Números aleatórios são utilizados para criar partes do CPF, simulando a diversidade de números presentes nos CPFs reais. 

Função de Geração Aleatória de Idades:
A função gerarIdade é responsável por gerar aleatoriamente idades para os pacientes. Um número aleatório é gerado e limitado ao intervalo entre 18 e 99 anos, representando uma faixa etária diversificada.

Função de Geração de Pacientes Aleatórios:
A função gerarPaciente é responsável por criar um paciente com informações geradas aleatoriamente. Essa função utiliza as funções anteriores para gerar nomes, CPFs e idades, criando um paciente com dados variados.

2. Atendimento na Sala de Espera
Pacientes são adicionados à fila de espera e ordenados por gravidade da doença.

Inicialização da Fila de Espera:
A fila de espera é inicializada como uma lista encadeada vazia, preparada para receber os pacientes.

Adição à Fila de Espera:
A função insere é responsável por adicionar pacientes à fila de espera de forma ordenada pela gravidade da doença. Os pacientes são adicionados de forma ordenada, garantindo que aqueles com maior gravidade da doença ocupem as posições iniciais da fila. 

Ordenação por Gravidade da Doença:
A ordenação é realizada com base na gravidade da doença do paciente, que é representada pela coluna na estrutura do paciente. A função de comparação utilizada na ordenação compara a gravidade da doença dos pacientes.

3. Atendimento no Raio-X
Pacientes são encaminhados para a máquina de raio-X quando disponível. A matriz raioX do hospital registra o status das máquinas.

Encaminhamento para Máquina de Raio-X:
A função fila de atendimento é responsável por encaminhar pacientes da fila de sala de espera para a máquina de raio-X quando esta está disponível. Essa função é chamada periodicamente para verificar a disponibilidade de máquinas de raio-X e encaminhar pacientes conforme necessário.

Registro na Matriz de Raio-X:
O hospital utiliza uma matriz para registrar o status das máquinas de raio-X. Quando um paciente é encaminhado para a máquina de raio-X, o sistema atualiza a matriz de raio-X com informações relevantes.

Atualização de Tempo:
O sistema atualiza dinamicamente o tempo de uso de cada máquina de raio-X na matriz, refletindo o progresso do exame. Quando o tempo de uso de uma máquina de raio-X atinge zero, indicando a conclusão do exame, o sistema atualiza o status da máquina e o remove da fila de raio-X.

4. Atendimento no Laudo
Pacientes são encaminhados para a sala de laudo quando o raio-X é concluído. A matriz laudo do hospital registra o status das salas de laudo.

Encaminhamento para Sala de Laudo:
Quando um paciente completa o procedimento de raio-X, o sistema verifica a disponibilidade na sala de laudo e o encaminha para lá. Essa função é chamada periodicamente para verificar se há pacientes na fila de raio-X que podem ser encaminhados para a sala de laudo.

Registro na Matriz de Laudo:
O hospital utiliza uma matriz para registrar o status das salas de laudo. Quando um paciente é encaminhado para a sala de laudo, o sistema atualiza a matriz de laudo com informações relevantes.

Atualização de Tempo:
O sistema atualiza dinamicamente o tempo de uso de cada sala de laudo na matriz, refletindo o progresso do atendimento. Quando o tempo de uso de uma sala de laudo atinge zero, indicando a conclusão do laudo, o sistema atualiza o status da sala e o remove da fila de laudo. 

5. Controle de Tempo e Métricas
O sistema controla o tempo de espera e o tempo de atendimento em cada etapa. Calcula métricas, como a média de tempo para laudo, média de tempo por patologia e número de exames fora do tempo.

Controle de Tempo de Atendimento
O tempo de atendimento é controlado em cada etapa do processo:

Chegada na Sala de Espera:
Ao entrar na sala de espera, o sistema registra o timestamp de entrada do paciente.

Atendimento no Raio-X:
Quando um paciente é encaminhado para o raio-X, o sistema registra o tempo de entrada na fila de raio-X.
O tempo de saída da fila de raio-X é registrado quando o paciente inicia o procedimento de raio-X.

Atendimento no Laudo:
O tempo de entrada na fila de laudo é registrado quando o paciente é encaminhado para a sala de laudo.
O tempo de saída da fila de laudo é registrado quando o médico conclui o laudo.
