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
using namespace std;
int pc;
class instruction
{
    int memory;
    int line;
    string operation;
    string operand;
    string label;
    string comment;
    string registers;
    bool errors[14];
    instruction()
    {
        for (int i = 0; i <= 14 ; i++)
        {
            errors[i] = false;
        }
    }
};

void check(instruction &n){
    char arr[6]={'a','b','x','s','t','\0'}
    bool found=false;
 if(n.operation=="RMO"){
        pc+=2;
        n.memory=pc;
       if(n.operand[1]!=','){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand[0]==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand[2]==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
    }
else if(!strcasecmp(n.operation,"+RMO")){
        pc+=4;
        n.memory=pc;
       n.errors[11]=true;

    }

///

 else if(!strcasecmp(n.operation,"ADDR")){
        pc+=2;
        n.memory=pc;
       if(n.operand.at(1)!=','){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(0))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(2))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
    }
else if(!strcasecmp(n.operation,"+ADDR")){
        pc+=4;
        n.memory=pc;
       n.errors[11]=true;

    }
///
else if(!strcasecmp(n.operation,"SUBR")){
        pc+=2;
        n.memory=pc;
       if(n.operand.at(1)!=','){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(0))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(2))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
    }
else if(!strcasecmp(n.operation,"+SUBR")){
        pc+=4;
        n.memory=pc;
       n.errors[11]=true;

    }
///
else if(!strcasecmp(n.operation,"COMPR")){
        pc+=2;
        n.memory=pc;
       if(n->operand.at(1)!=','){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(0))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
       for(int i=0;i<6;i++){
        if(tolower(n.operand.at(2))==arr[i]){found=true;break;}

       }
       if(found==false){n.errors[9]=true;}
    }
else if(!strcasecmp(n.operation,"+COMPR")){
        pc+=4;
        n.memory=pc;
       n.errors[11]=true;

    }
///
else if(!strcasecmp(n.operation,"TIXR")){
        pc+=2;
        n.memory=pc;
        if()

    }
else if(!strcasecmp(n.operation,"+TIXR")){
        pc+=4;
        n.memory=pc;
       n.errors[11]=true;

    }
///

}
int main(int argc, const char * argv[])
{

    //
    return 0;
}
