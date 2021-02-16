/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0; 
  int STDIN = 0;  
  byte checksum; 
  byte complement;
  int remainder;
  int quotient;
  byte header[10];

  /* the following is the prototype for the read system call */
  //int read(int fildes, void *buf, size_t nbyte); 

  read(STDIN, &header, count);

  for(int i = 0; i < count; i++)
  {
    if( i == 5)
    {
      checksum = header[i];
      header[i] = 0;
    }
  }

  for(int i = 0; i < count; i++)
  {
    sum += header[i];
  }

  quotient = sum / (max_int+1);
  remainder = sum % (max_int+1);
  sum = quotient + remainder;

  complement = max_int - sum;


  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}