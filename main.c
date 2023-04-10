#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/wait.h>
int main( int argc, char* argv[], char* envp[])
    { char * s = NULL;
      int n = 0;
  
    pid_t pid = fork();
   assert( pid != -1 );
    if ( pid == 0 )
   {
    s = "child";
    n = 4;
   }
  else
  {
    s = "parent";
    n = 10;

    int val = 0;
    int id = wait(&val);
 
    if ( WIFEXITED(val) )
   {
    printf("id=%d,val=%d\n",id,WEXITSTATUS(val));
  }
  }
  int i = 0;
  
   for(; i < n; i++ )
   {
  printf("pid=%d,s=%s\n",getpid(),s);
   sleep(1);
   }
  
   exit(0);
 }