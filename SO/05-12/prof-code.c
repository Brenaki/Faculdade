//
//  COPIAR BYTES DE UM ARQUIVO PARA OUTRO....
//
//  Modificar o programa para receber os nomes dos arquivos por linha de comando, 
//  como o comando CP -->   cp <origem> <destino>
//
//  Cuidar para que os nomes dos arquivos não sejam iguais!
//
//  Modificar o programa para fazer uso de um buffer para leitura/gravação com uso
//  das funções fread() e fwrite()
//
//
//  Modificar o programa que grava através de buffer para gravar com multithread, similar ao ROBOCOPY

#include <stdio.h> 
#include <stdlib.h>
  
int main() 
{ 
    FILE *fptr1, *fptr2; 
    char arquivo[100], c; 
  
    printf("Nome do arquivo de entrada: "); 
    scanf("%s", arquivo ); 
  
    fptr1 = fopen( arquivo, "rb"); 
    if (fptr1 == NULL) 
    { 
        printf("Nao pude abrir o arquivo: %s.\n", arquivo ); 
        exit(0); 
    } 
  
    printf("Nome do arquivo de saida: " ); 
    scanf("%s", arquivo ); 
  
    fptr2 = fopen( arquivo, "wb"); 
    if (fptr2 == NULL) 
    { 
        printf("Nao pude criar o arquivo: %s.\n", arquivo ); 
        exit(0); 
    } 
  
    c = fgetc(fptr1); 
    while (c != EOF ) 
    { 
        fputc(c, fptr2); 
        c = fgetc(fptr1); 
    } 
  
    printf("\nConteudo copiado para %s", arquivo ); 
  
    fclose(fptr1); 
    fclose(fptr2); 
    return 0; 

}
