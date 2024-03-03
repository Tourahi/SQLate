#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Logs */
#include "log.h"

typedef struct {
  char* buffer;
  size_t bufferLenght;
  ssize_t inputLenght;
} InptBuffer;

InptBuffer* newInptBuffer() {
  logInfo("Creating new input buffer.");
  InptBuffer* inptBuffer = (InptBuffer*)malloc(sizeof(InptBuffer));
  inptBuffer->buffer = NULL;
  inptBuffer->bufferLenght = 0;
  inptBuffer->inputLenght = 0;
  return inptBuffer;
}


int main(int argc, char const *argv[])
{
  newInptBuffer();
  return 0;
}
