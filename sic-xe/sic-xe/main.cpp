#include "assembler.h"

int main()
{
  char* readFilePath = "fileName.txt";
  char* writeFilePath = "fileName.txt";
  assembler *a = new assembler(0, readFilePath, writeFilePath);
  cout <<"RUN SUCCESSFULLY";
  return 0;
}
