//
// Programa de demonstração para cálculo de média através de processos filhos, 
// e processamento no processo pai.
//
//  gcc calcula_media.c -o calcula_media -D N=1000
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#ifndef N
  #define N 30  
#endif

typedef  struct {
             int filho,
                 pid,
                 media;
         } vet_filhos;
vet_filhos pid_filhos[ N ];

int comp( const void *aa, const void *bb )
{
  const vet_filhos *a = aa, *b = bb;

  #ifdef DEBUG_QSORT
    printf( "%d %d %d - %d %d %d\n", a->filho, a->pid, a->media, b->filho, b->pid, b->media  );
  #endif

  if(  a->media < b->media )
    return +1;
  else if( a->media > b->media )
    return -1;
  else
    return 0;
}


int main( void )
{
  int i , id;
  float n1, n2, n3;
  FILE *fd;

  for( i = 0; i < N; ++i )
    pid_filhos[ i ].filho = i+1;

  for( i = 0; i < N; ++i ) {
    printf( "Criando filho %d\r", i+1 );
    switch ( pid_filhos[ i ].pid = fork() ) {
      case -1 : printf( "Erro na criacao do processo filho\n" );
                exit( -1 );
                break;

      case  0 : //
		// Processo filho....
		//
		fd = fopen( "notas.lst", "r" );
                if( fd == NULL ) {
                  printf( "Erro na abertura do arquivo\n" );
                  return -1;
                }
                id = -1;
                #ifdef DEBUG
                  printf( "\nFilho %d(%d) procurando %d\n", i+1, getpid(), i+1 );
                #endif
                while( !feof( fd ) && id != i+1 ) {
                  fscanf( fd, "%d %f %f %f\n", &id, &n1, &n2, &n3 );
                  #ifdef DEBUG
                    printf( "Filho %d(%d) Lendo %d %f %f %f\r", i+1, getpid(), id, n1, n2, n3  );
                  #endif
                }
                fclose( fd );
                if( n1 + n2 <= 14.0 )
                   return ((n1+n2+n3)/3.0)*10;
                else
	           return ((n1+n2)/2.0)*10;
                break;
    }
  }

  printf( "\nPai (%d) aguardando %d filhos\n", getpid(), N );
  for( i = 0; i < N; ++i ) {
    #ifdef DEBUG
       printf( "Pai (%d) aguardando %d(%d)\r", getpid(), pid_filhos[ i ].filho, pid_filhos[ i ].pid );
    #endif
       waitpid( pid_filhos[ i ].pid, &pid_filhos[ i ].media, 0 ); 
  }

  for( i = 0; i < N; ++i ) 
       printf( "Media: %3d(%d) %4.1f\n", pid_filhos[ i ].filho, pid_filhos[ i ].pid, WEXITSTATUS( pid_filhos[ i ].media )/10.0 );

  printf( "\nORDENANDO...\n\n" );
  qsort( pid_filhos, N, sizeof( vet_filhos ), comp);

  for( i = 0; i < N; ++i ) 
       printf( "Media: %3d(%d) %4.1f\n", pid_filhos[ i ].filho, pid_filhos[ i ].pid, WEXITSTATUS( pid_filhos[ i ].media )/10.0 );
  exit( 0 );
}
