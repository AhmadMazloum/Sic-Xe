#include "assembler.h"

int main()
{
  char* readFilePath = "fileName.txt";
  char* writeFilePath = "fileName.txt";
  assembler *a = new assembler(0, readFilePath, writeFilePath);
  a->run();
  cout <<"RUN SUCCESSFULLY";
  return 0;
}
