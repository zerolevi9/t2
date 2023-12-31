# Sistema de Atendimento Hospitalar

Este sistema simula o fluxo de atendimento em um hospital, incluindo a chegada de pacientes, a realização de exames de raio-x, a emissão de laudos médicos e métricas de desempenho do atendimento.

## Overview
Este conjunto de códigos em C implementa um sistema de simulação de um hospital, onde são realizados exames médicos e laudos por radiologistas. O sistema simula a chegada de pacientes, a alocação de máquinas para exames, a geração de laudos e métricas relacionadas ao tempo de espera e eficiência do processo.

## Estrutura do Projeto
O projeto é dividido em três arquivos principais: _main.c_, _fila.c_, e _fila.h_. Abaixo está uma breve descrição de cada um desses arquivos:

**main.c**
Este é o arquivo principal que contém a função main. Ele é responsável por inicializar as estruturas de dados, simular a passagem do tempo e chamar funções relacionadas à chegada de pacientes, alocação de máquinas, geração de laudos, entre outras. Também contém a lógica para calcular métricas relacionadas ao tempo médio de laudo, tempo médio por patologia, e a quantidade de exames realizados após o limite de tempo estabelecido.

**fila.c**
Este arquivo contém as implementações das funções relacionadas às estruturas de dados utilizadas no projeto, como a lista de pacientes, fila de exames, lista de máquinas, fila de laudos, lista de radiologistas, entre outras. Ele também contém funções para realizar operações como a alocação de máquinas, geração de laudos, verificação da disponibilidade de máquinas e radiologistas, entre outras.

**fila.h**
Este arquivo contém as definições das estruturas de dados utilizadas no projeto e as assinaturas das funções implementadas em fila.c. Ele serve como uma interface para que as funções em main.c possam utilizar as estruturas e operações definidas em fila.c.

## Compilação e Execução
>[!IMPORTANT]
> Para compilar o projeto, você pode usar um compilador C, e executar o makefile, logo após inserir o nome do documento em _.txt_ presente neste repositório

Certifique-se de que todos os arquivos (main.c, fila.c, fila.h e arquivo de texto) estejam no mesmo diretório.

### Observações
O sistema é uma simulação simplificada e não leva em consideração detalhes específicos de um ambiente hospitalar real.
As métricas e tempos são apresentados a cada 10 unidades de tempo.
O código inclui comentários explicativos para facilitar a compreensão.
