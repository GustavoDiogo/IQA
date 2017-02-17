## Algoritmos e Programação I: Índice de Qualidade da Água(IQA)
#### Bacharelado em Ciências da Computação: 1º Semestre(2016)
A documentação sobre o projeto encontra-se no diretório <b>documentacao/IQA.zip</b>

####Linux(somente):

##### Compilando:

- ######Juntamente à interface gráfica:
  Primeiramente é necessário ter o compilador gcc instalado, caso não tenha, abra o terminal e digite os seguintes códigos:
  
  >  1.  sudo apt-get update 
  >  2.  sudo apt-get upgrade
  >  3.  sudo apt-get install build-essential
  >  4.  gcc -v
  >  5.  make -v

  Após a instalação do compilador gcc, o próximo passo é instalar o **GTK+3** utilizando o comando:
 
  OBS: Para evitar problemas, instale o **glade** pois a interface se encontra em **.xml**.
  > sudo apt-get install libgtk-3-dev
 
  > sudo apt-get install glade
  
  Entre na pasta **gtk** deste repositório utilizando o comando **cd**(exemplo: cd Desktop\bccIQA\gtk), estando dentro da pasta digite: 
  > gcc -o CalculadoraIQA main.c **`**pkg-config --cflags --libs gtk+-3.0**`** -export-dynamic -lm
  
  Por fim, digite **./CalculadoraIQA** e preencha os valores adequados.

- ######Sem interface gráfica:
  Primeiramente é necessário ter o compilador gcc instaldo, caso não tenha, abra o terminal e digite os seguintes códigos:
  >  1.  sudo apt-get update 
  >  2.  sudo apt-get upgrade
  >  3.  sudo apt-get install build-essential
  >  4.  gcc -v
  >  5.  make -v

  Tendo o arquivo **Makefile** em mãos, abra o terminal. Com o terminal aberto, certifique-se em estar localizado na pasta onde contém os arquivos deste repositório, utilize o comando **cd** (exemplo: cd Desktop\bccIQA). Por fim digite o comando: **make all**, gerando assim o executável deste projeto.

  Concluindo os passos anteriores, para executar o programa ainda no terminal, digite **./main** e preencha as informações necessárias para se calcular o IQA.
  
 ####Referências:
  
 https://help.ubuntu.com/community/InstallingCompilers
