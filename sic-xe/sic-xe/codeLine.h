#include <vector>
#include <string>
#include <algorithm>
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
  int getNewPc(); // return the new pc
private:
  void validateFreeFormat();
  void validateFixedFormat();
}; 
