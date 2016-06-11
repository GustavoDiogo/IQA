### Índice de Qualidade da Águas(IQA) - 1º Semestre(2016) BCC Senac.
####Linux(somente):

Para executar o programa basta abrir o executável **main.exe**.

##### Compilando:

- ######Juntamente à interface gráfica:(TEXTO FUTURO)

- ######Sem interface gráfica:
  Primeiramente é necessário ter o compilador gcc instaldo, caso não tenha, abra o terminal e digite os seguintes códigos:
  >  1.  sudo apt-get update 
  >  2.  sudo apt-get upgrade
  >  3.  sudo apt-get install build-essential
  >  4.  gcc -v
  >  5.  make -v

  Tendo o arquivo **Makefile** em mãos, abra o terminal. Com o terminal aberto, certifique-se em estar localizado na pasta onde contém os arquivos deste repositório, utilize o comando **cd** (exemplo: cd Desktop\IQA). Por fim digite o comando: **make all**, gerando assim o executável deste projeto.

  Concluindo os passos anteriores, para executar o programa ainda no terminal, digite **./main** e preencha as informações necessárias para se calcular o IQA.
  
####Referências:
  
https://help.ubuntu.com/community/InstallingCompilers
