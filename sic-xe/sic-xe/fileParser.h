#include "assembler.h"
class fileParser
{
  public:
    vector<string> errorMsg;
    char * path;
    bool mode;
    fileParser(vector<string> errorMsg,bool mode);
    vector<codeLine> readFile(char * path);
    void writeFile(vector<codeLine> &codeLines,char * path);
};
