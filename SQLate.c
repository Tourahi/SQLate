#define _GNU_SOURCE
#define DEBUG_ON false

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
  if (DEBUG_ON) logInfo("Creating new input buffer.");
  InptBuffer* inptBuffer = (InptBuffer*)malloc(sizeof(InptBuffer));
  inptBuffer->buffer = NULL;
  inptBuffer->bufferLenght = 0;
  inptBuffer->inputLenght = 0;
  return inptBuffer;
}

void readInpt(InptBuffer* inptBuffer) {
  ssize_t bytesRead =
    getline(&(inptBuffer->buffer), &(inptBuffer->bufferLenght), stdin);

  if (bytesRead <= 0) {
    logError("Error reding input");
    exit(EXIT_FAILURE);
  }

  // Ignore trailing newLine
  inptBuffer->inputLenght = bytesRead - 1;
  inptBuffer->buffer[bytesRead - 1];
}

void closeInptBuffer(InptBuffer* InptBuffer) {
  free(InptBuffer->buffer);
  free(InptBuffer);
}

void printPrompt() { printf("db > "); }

int main(int argc, char const *argv[])
{
  InptBuffer* inptBuffer = newInptBuffer();
  while (true) {
    printPrompt();
    readInpt(inptBuffer);
    if (strcmp(inptBuffer->buffer, "exit\n") == 0) {
      closeInptBuffer(inptBuffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'.\n", inptBuffer->buffer);
    }
  }
  return 0;
}
