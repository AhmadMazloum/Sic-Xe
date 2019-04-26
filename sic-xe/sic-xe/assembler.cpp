#include "fileParser.h"
assembler::assembler(bool mode, char* readFilePath, char* writeFilePath)
{
  this->mode = mode;
  this->readFilePath = readFilePath;

  loadOperandPatterns();
  loadMustLabelled();
  loadMustUnlabelled();
  loadErrorMsg();
}
void assembler::loadOperandPatterns()
{
  regex rr("(a|b|l|x|s|t),(a|b|l|x|s|t)");
  regex r("(a|b|l|x|s|t)");
  regex m("(@|#)?(([a-z](.*))|([0-9]+)|([0-9a-f]+h))(,x)?");
  regex res_b_w("[0-9]+"); 
  regex start_org("[0-9a-f]{1,4}");
  regex byte_word_equ("([0-9]+)|(c'(.)+')|(x'([a-f0-9]+)')");
  regex base("");
  regex end("([a-z](.*))*");

  operandPatterns["rmo"] = rr;
  operandPatterns["addr"] = rr; 
  operandPatterns["subr"] = rr; 
  operandPatterns["compr"] = rr; 
  operandPatterns["tixr"] = r;
  operandPatterns["ldr"] = m;
  operandPatterns["str"] = m;
  operandPatterns["ldch"] = m;
  operandPatterns["stch"] = m;
  operandPatterns["add"] = m;
  operandPatterns["sub"] = m;
  operandPatterns["comp"] = m;
  operandPatterns["j"] = m; 
  operandPatterns["jeq"] = m; 
  operandPatterns["jlt"] = m; 
  operandPatterns["jgt"] = m;
  operandPatterns["tix"] = m;
  operandPatterns["start"] = start_org;
  operandPatterns["org"] = start_org;
  operandPatterns["equ"] = byte_word_equ; 
  operandPatterns["resb"] = res_b_w;
  operandPatterns["resw"] = res_b_w;
  operandPatterns["byte"] = byte_word_equ;  
  operandPatterns["word"] = byte_word_equ;
  operandPatterns["base"] = base; 
  operandPatterns["end"] = end;           
}
void assembler::loadMustLabelled(){
  mustLabelled.insert("equ");
  mustLabelled.insert("byte");
  mustLabelled.insert("word");
}
void assembler::loadMustUnlabelled(){
  mustUnlabelled.insert("org");
  mustUnlabelled.insert("base");
  mustUnlabelled.insert("end");  
}
void assembler::loadErrorMsg(){

}
void assembler::run(){
  fileParser fp;
  codeLines = fp.readFile(readFilePath);
  for(codeLine line : codeLines){
    line.setMode(mode);
    line.loadPc(pc);
    line.validate();
    pc = line.getNewPc();
  }
  fp.writeFile(writeFilePath, codeLines);
}
