#include "calc.h"

#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Internal functions

void resetBuffer(CalcStatePtr state) {
  int i;
  for(i=0; i<MAXDIGITS; i++)
    state->buffer[i] = '\0';
  state->bufferNegative = 0;
}

void reset(CalcStatePtr state) {
  resetBuffer(state);
  state->bufferActive = 1;
  state->err = 0;
  state->op = NoOp;
  state->operand = 0;
  state->hasOperand = 0;
}

inline int isDigit(char c) {
  return c >= '0' && c <= '9';
}

inline int valueOf(char digit) {
  return (int) (digit - '0');
}

char* firstAvailableBufferPos(CalcStatePtr state) {
  char* ptr = state->buffer;
  while(isDigit(*ptr))
    ptr++;
  return ptr;
}

int bufferPosIsValid(CalcStatePtr state, char* pos) {
  return pos - state->buffer < MAXDIGITS;
}

int getBufferVal(CalcStatePtr state) {
  char* currPos = state->buffer;
  int value = 0;
  
  if(state->err)
    return 0;

  while(isDigit(*currPos)) {
    value = value*10 + valueOf(*currPos);
    currPos++;
  }
  
  if(state->bufferNegative)
    value = -value;
  return value;
}

void setBufferVal(CalcStatePtr state, int val) {
  if(val < 0) {
    state->bufferNegative=1;
    val = -val;
  } else {
    state->bufferNegative=0;
  }

  sprintf(state->buffer, "%d", val);
}

void doMemorizedOp(CalcStatePtr state) {
  int temp;

  if(state->hasOperand) {
    switch(state->op) {
    case Plus:
      state->operand += getBufferVal(state);
      break;

    case Minus:
      state->operand -= getBufferVal(state);
      break;

    case Times:
      state->operand *= getBufferVal(state);
      break;

    case Div:
      temp = getBufferVal(state);
      if(temp == 0) {
	state->err = 1;
      } else {
	state->operand /= temp;
      }
      break;

    default:
      break;
    }
    state->bufferActive=0;
    setBufferVal(state, state->operand);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Interface functions

CalcStatePtr mkCalcState() {
  CalcStatePtr state = (CalcStatePtr) malloc(sizeof CalcState);
  reset(state);
  return state;
}

void freeCalcState(CalcStatePtr state) {
  free(state);
}

const char* getBuffer(CalcStatePtr state) {
  static char errStr[] = "[error]";
  static char* bufferCopy;
  if(state->err) {
    return errStr;
  } else {
    bufferCopy = malloc(MAXDIGITS+2);
    if(state->bufferNegative)
      sprintf(bufferCopy, "-%s", state->buffer);
    else
      sprintf(bufferCopy, "%s", state->buffer);
    return bufferCopy;
  }
}

void pressDigit(CalcStatePtr state, char digit) {
  char* bufferPos;

  if(!state->bufferActive) {
    if(state->hasOperand) {
      resetBuffer(state);
      state->bufferActive=1;
    } else {
      reset(state);
    }
  }

  bufferPos = firstAvailableBufferPos(state);
  if(!bufferPosIsValid(state, bufferPos)) {
    state->err = 1;
  } else {
    *bufferPos = digit;
    *(bufferPos+1) = '\0';
  }
}

void pressOp(CalcStatePtr state, enum CalcOp op) {
  if(state->bufferActive) {
    doMemorizedOp(state);
    state->bufferActive = 0;
    state->op = op;
    state->operand = getBufferVal(state);
    state->hasOperand=1;
  }
}

void pressPlus(CalcStatePtr state) {
  pressOp(state, Plus);
}

void pressMinus(CalcStatePtr state) {
  pressOp(state, Minus);
}

void pressMult(CalcStatePtr state) {
  pressOp(state, Times);
}

void pressDiv(CalcStatePtr state) {
  pressOp(state, Div);
}

void pressExec(CalcStatePtr state) {
  doMemorizedOp(state);
  state->hasOperand = 0;
  state->op = NoOp;
}

void pressReset(CalcStatePtr state) {
  reset(state);
}

