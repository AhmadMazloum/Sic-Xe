#include "codeLine.h"
codeLine::codeLine(string &line, int lineNo){
  this->line = line;
  transform(this->line.begin(), this->line.end(), this->line.begin(), ::tolower); 
  this->lineNo = lineNo;
}
void codeLine::setMode(bool mode){
  this->mode = mode;
}
void codeLine::loadPc(int pc){
  this->pc = pc;
}
void codeLine::validate(){
  if(mode == 0){ // free format
    validateFreeFormat();
  }
  else { // fixed format
    validateFixedFormat();
  }
}
void codeLine::validateFreeFormat(){
}
void codeLine::validateFixedFormat(){
} 
int codeLine::getNewPc(){
  return address;
}
