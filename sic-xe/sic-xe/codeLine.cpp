#include "codeLine.h"
#include <math.h>
#include <sstream>
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
void codeLine::validate(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels){
  if(mode == 0){ // free format
    validateFreeFormat(mustLabelled, mustUnlabelled, operandPatterns,labels, unknownLabels);
  }
  else { // fixed format
    validateFixedFormat(mustLabelled, mustUnlabelled, operandPatterns,labels, unknownLabels);
  }
}
void codeLine::validateFreeFormat(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels){
    
}
void codeLine::validateFixedFormat(set<string> &mustLabelled, set<string> &mustUnlabelled, map<string,regex> &operandPatterns, set<string> &labels, map<string,int> &unknownLabels){
        string op_code,operand,label,comment;
        stringstream ss(line);
        string token;
        vector<string> tokens;
        unsigned long n=line.length();
        int i=0;
        if(line[i]==' ')
        {
            //misplaced label
            errorIds.push_back(1);
        }
        while(getline(ss,token,' '))
        {
            if(token==""&&tokens.size()!=0)
            {
                continue;
            }
            while(token.find('\t')!=std::string::npos)
            {
                token.erase(token.find('\t'));
            }
            tokens.push_back(token);
        }
        while(tokens.size()<4)
        {
            tokens.push_back("");
        }
        label=line.substr(0,9);
        if(n>=9)
        {
            op_code=line.substr(9,8);
        }
        if(n>=17)
        {
            operand=line.substr(17,8);
        }
        if(n>=25)
        {
            comment=line.substr(25,41);
        }
        if(label!=tokens[0])
        {
            //misplaced label
            errorIds.push_back(1);
        }
        if(op_code!=tokens[1])
        {
            //misplaced op_code
            errorIds.push_back(2);
        }
        if(operand!=tokens[2])
        {
            //misplaced operand
            errorIds.push_back(3);
        }
        if(comment!=tokens[3])
        {
            //misplaced comment
        }
} 
int codeLine::getNewPc(){
  return address;
}
int codeLine::hex2dec(string hex)
{
    int dec = 0;
    int x;
    unsigned long n = hex.length()-1;
    for(int i = 0 ; i <= n ; i++)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
            dec += (hex[i]-'0') * pow(16,n-i);
        else
        {
            x = hex[i] - 'a';
            x += 10;
            dec += x *pow(16,n-i);
        }
            
    }
    return dec;
}
string codeLine::dec2hex(int dec)
{
    stringstream ss;
    ss << std::hex << dec;
    return ss.str();
}
string codeLine::getHexAddress()
{
    int pc=getNewPc();
    return dec2hex(pc);
}
