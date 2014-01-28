#include <stdio.h>


#define MAX 9

//reads the input
void read(char* pnr) {
	printf("Enter your digits gurl\n");
	scanf("%s", pnr);
}

int control(char* pnr) {

	//converts to digits
	int i;
	for (i=0; i<=MAX; i++) {
		pnr[i] = pnr[i]-'0';
	}

	//concats numbers into month and day
	int month = pnr[2] * 10 + pnr[3];
	int day = pnr[4] * 10 + pnr[5];

	//checks for month/day span
	if (month>=1 && month<=12 && day>=1 && day<=31) {

		//times even numbers with two and odd with one
		int oddeven = 0; // 0=even, 1=odd
		for (i=0; i<=MAX-1; i++) {
			if (oddeven==0) {
				pnr[i] = pnr[i]*2;
				oddeven++;
			}
			else if (oddeven==1) {
				pnr[i] = pnr[i]*1;
				oddeven--;
			}
		}

		//calculates the control number
		int control_number;
		for (i=0; i<=MAX-1; i++) {
			if (pnr[i]>9) {
			control_number += (pnr[i] % 100) / 10;
			control_number += (pnr[i] % 100) % 10;
			}
			else {
				control_number += pnr[i];
			}
		}

		//finds the next number above control_number
		//that is divisible by 10
		int ten = control_number;
		while (ten % 10 != 0) {
			ten++;
		}

		//evaluation with the last digit(10th)
		if (ten-control_number == pnr[MAX]) {
			printf("CORRECT\n"); //everything is ok
		}
		else {
			printf("WRONG CONTROL\n"); //control eval not ok
		}
	}
	else {
		printf("WRONG MMDD\n"); // MMDD eval not ok
	}
}

int main(void) {

	char pnr[MAX];

	while (1) {
	read(pnr);
	if (pnr[0]=='q') {
		break;
	}
	else {
		control(pnr);
	}
	}
}
