#ifndef __calc_h_
#define __calc_h_

/////////////////////////////////////////////////////////////////////////////
// Implementation of a calculator for integers                             //
// (functionality should be fairly standard for a simple calculator)       //
//                                                                         //
// The calculator has the following buttons:                               //
//    digits:     0-9                                                      //
//    operations: +-*/                                                     //
//    execute:    =                                                        //
//    reset       C                                                        //
//                                                                         //
// Conceptually, the calculuator has the following state holding elements: //
//   A buffer of digits                                                    //
//   Possibly an operand (which is an integer)                             //
//   Possibly a memorized operation (which is one of add, subtract,        //
//      multiply, and divide)                                              //
//                                                                         //
// The functionality of the calculator is as follows                       //
//   - The buffer is continuously displayed on the screen                  //
//   - Initially, the buffer is empty, and there is neither an operand nor //
//     an operation memorized. Whenever reset is pressed, the calculator   //
//     goes back to this state.                                            //
//   - When any digit button is pressed, the digit is added to the end of  //
//     the buffer.                                                         //
//   - If an operation button is pressed while there is no operation in    //
//     memory, then the number currently in the buffer is stored in the    //
//     operand, and the operand of the button is memorized. The buffer     //
//     remains unchanged, but at next digit button press, the buffer is    //
//     emptied before the digit is added to the buffer.                    //
//   - If '=' is pressed while there is an operand and a memorized         //
//     operation, the operand and the buffer values are replaced by the    //
//     sum, difference, product, or quote of the operand and the buffer    //
//     (depending on which operation is memorized). The memorized          //
//     operation and operand is hereby deleted.                            //
//   - If an operation button is pressed while there is an operand and     //
//     operation memorized, the calculator acts as if '=' was pressed      //
//     before the operation button.                                        //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

// Defining the calculator state type
struct CalcStateStruct;
typedef struct CalcStateStruct *CalcStatePtr;

// Creating and deleting calculator states
CalcStatePtr mkCalcState();
void freeCalcState(CalcStatePtr state);

// Getting the buffer out
const char* getBuffer(CalcStatePtr state);
// Returns a pointer to the current buffer (as a string).
// This string remains unchanged until next call to getBuffer.

// Button presses:
void pressDigit(CalcStatePtr state, char digit);
// digit must be in the range '0' through '9'

void pressPlus(CalcStatePtr state);
void pressMinus(CalcStatePtr state);
void pressMult(CalcStatePtr state);
void pressDiv(CalcStatePtr state);

void pressExec(CalcStatePtr state);
void pressReset(CalcStatePtr state);



/////////////////////////////////////////////////////////////////////////////
// Internal representation of calculator state

#define MAXDIGITS 15

enum CalcOp {NoOp, Plus, Minus, Times, Div};

struct CalcStateStruct {
  char buffer[MAXDIGITS+1];
  int bufferNegative;
  int bufferActive;
  int err;
  enum CalcOp op;
  int operand;
  int hasOperand;
} CalcState;

#endif

