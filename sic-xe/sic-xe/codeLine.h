#include <vector>
#include <string>
using namespace std;
class codeLine
{
  int pc; // pc value before this line
  bool mode;
public:
  int lineNo;
  int address;
  string line;
  vector<int> errorIds;
  codeLine(string &line, int lineNo);
  void setMode(bool mode);
  void loadPc(int pc); 
  void validate(); // validates line for errors and saves its address
  void validateFreeFormat();
  void validateFixedFormat();
  int getNewPc(); // return the new pc 
}; 
