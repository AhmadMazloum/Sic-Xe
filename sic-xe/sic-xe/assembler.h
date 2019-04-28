#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<regex>
#include "codeLine.h"

using namespace std;
class assembler
{
  int pc = 0; 
  set<string> mustLabelled; //byte,word,equ
  set<string> mustUnlabelled; //end,origin,base
  map<string,regex> operandPatterns;
  set<string> labels;
  map<string,int> unknownLabels;
  vector<string> errorMsg;
  vector<codeLine> codeLines;
public:
  assembler(bool mode, char* readFilePath, char* writeFilePath);
  void run();
private:
  bool mode;
  char* readFilePath;
  char* writeFilePath;
  void loadOperandPatterns();
  void loadMustLabelled();
  void loadMustUnlabelled();
  void loadErrorMsg();
};
