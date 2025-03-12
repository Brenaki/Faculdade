//
//  Programa utilizado para criar o arquivo com notas para processamento.
//
//  gcc grava_notas.c -o grava_notas -D N_NOTAS=1000

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef N_NOTAS
   #define N_NOTAS  200
#endif

void main( int argc, char *argv[] )
{
  int i, fd, n_notas = N_NOTAS;

  printf( "%s ==> Criando o arquivo notas.lst.../n", argv[ 0 ] );
  fd = open( "notas.lst", O_WRONLY | O_CREAT | O_TRUNC, 0666 );
  
  if( fd < 0 ) {
    printf( "ERRO:Erro na criacao do arquivo\n" );
    exit( fd );
  }
  
  if( argc > 1 )
    n_notas = atoi( argv[ 1 ] );

  printf( "%s ==> O arquivo resultante contera: %d notas\n", argv[ 0 ], n_notas );

  for( i = 1; i <= n_notas; ++i ) {
    float n1, n2, n3;

    n1 = rand()%100/10.0;
    n2 = rand()%100/10.0;
    n3 = rand()%100/10.0;
    dprintf( fd, "%d\t%4.1f\t%4.1f\t%4.1f\n", i, n1, n2, (n1 + n2 >= 14.0) ? 0.0 : n3 );
    printf( "%d\t%4.1f\t%4.1f\t%4.1f\r", i, n1, n2, n3 );
  }
  printf("\n\nO programa %s terminou!\n* * * FIM * * *\n", argv[ 0 ] );
  close( fd );
}
