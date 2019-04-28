#include "fileParser.h"
fileParser::fileParser(vector<string> errorMsg)
{
    this->errorMsg=errorMsg;
}
vector<codeLine> fileParser::readFile(char * path){
  vector<codeLine> codeLines;
    int count=1;
    ifstream inFile;
    inFile.open(path);
    string line;
    while (!inFile.eof()) {
        getline(inFile,line);
        codeLine * code_line= new codeLine(line,count);
        codeLines.push_back(* code_line);
        count++;
    }
    inFile.close();
  return codeLines;
}
void fileParser::writeFile(vector<codeLine> &codeLines,char * path){
    ofstream outFile;
    outFile.open(path);
    if(mode==1)
    {
        cout<<"Line no.\t\tAddress\tLabel\tMnemonic\tOperands\tComments\n";
    }
    for(auto itr = codeLines.begin(); itr != codeLines.end(); itr++)
    {
        for(auto itr2=(itr->errorIds).begin();itr2!=(itr->errorIds).end();itr2++)
        {
            outFile<<errorMsg[*itr2]<<endl;
        }
        outFile<<itr->lineNo<<"\t\t"<<itr->getHexAddress()<<"\t"<<itr->line<<endl;
    }
}
