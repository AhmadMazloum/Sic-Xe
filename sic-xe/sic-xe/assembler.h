#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<math.h>
#include<regex>
#include "codeLine.h"
using namespace std;
class assembler
{
  int pc = 0; 
  unordered_set<string> mustLabelled; //byte,word,equ
  unordered_set<string> mustUnlabelled; //end,origin,base
  map<string,regex> operandPatterns;
  unordered_map<int,string> errorMsg;
  unordered_set<string> labels;
  unordered_map<string,int> unknownLabels;
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
