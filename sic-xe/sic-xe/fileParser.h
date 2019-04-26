#include "assembler.h"
class fileParser
{
  public:
    vector<codeLine> readFile(char*path);
    void writeFile(char*path,vector<codeLine> &codeLines);
};
