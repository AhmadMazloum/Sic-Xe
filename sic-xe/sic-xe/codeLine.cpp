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
void codeLine::validate(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels){
  if(mode == 0){ // free format
    validateFreeFormat(mustLabelled, mustUnlabelled, operandPatterns,labels, unknownLabels);
  }
  else { // fixed format
    validateFixedFormat(mustLabelled, mustUnlabelled, operandPatterns,labels, unknownLabels);
  }
}
void codeLine::validateFreeFormat(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels){
}
void codeLine::validateFixedFormat(unordered_set<string> &mustLabelled, unordered_set<string> &mustUnlabelled, map<string,regex> &operandPatterns, unordered_set<string> &labels, unordered_map<string,int> &unknownLabels){
} 
int codeLine::getNewPc(){
  return address;
}
