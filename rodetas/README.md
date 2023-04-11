# Processo Seletivo - Rodetas Robô Clube - UFOP
Esse repositório armazena o código desenvolvido para a segunda etapa do Rodetas. As classes simulam os módulos de estratégia e transmissão dos robôs. A classe de Estratégia gera dois valores aleatórios de PWM, no intervalo [0,255]. A transmissão recebe e trata esses valores, enviando-os para a classe do Embarcado, que os executa.
Existe um arquivo Makefile com as diretivas "all" e "run"

## Execução
### Para compilar
```
make all
```
### Para executar
```
make run
```
