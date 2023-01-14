#include<iostream>
using namespace std;

class binary { //I created a class ,because i wanted to use counter member in different functions to store the binary size. 
	public:

		int binary_Arr[50];
		int counter = 0;

int *decToBin(int num) {
	counter = 0;  
	while (num > 0) {
		if (num % 2 == 0) { //Checking if the number is divisible by two whether or not to convert binary.
			binary_Arr[counter] = 0;
			counter++;
			num = num / 2;

		}
		else if (num % 2 == 1) { //Checking if the number is divisible by two whether or not to convert binary.
			binary_Arr[counter] = 1;
			counter++;
			num = num / 2;
		}
	}
	return binary_Arr;

}
int modExp(int b, int e, int m) {

	int x = 1;
	int temp_p,temp_x;
	int power = b % m;
	for (int i = 0; i < counter; i++) {
		
		if (binary_Arr[i] == 1) { //From pseudocode
			temp_x = x;
			x = (x * power) % m;
	}
		temp_p = power; //To hold the previous power value
		power = (power * power) % m;
		if (binary_Arr[i] == 1 && i!= counter -1) { //Checking if the binaries one or zero and 'i' doesn't need to include this condition ,because i's binary value is 1 at the same time.

			cout << "Because b" << i << " is " << binary_Arr[i] << " , we have x = " << "(" << temp_x << " * " << temp_p << ")" << " and power = " << temp_p << " ^ 2"<< " mod " << m << " = " << power << endl;
		
		}
		else if (i == counter-1) { //To check if it's the last part of the code

			cout << "Because b" << counter-1 << " is " << binary_Arr[counter-1] << " , we have x = " << "(" << temp_x << " * " << temp_p << ")" << " mod " << m << " ==> " << endl << endl;
		}
		else{ //If the binary is zero
			
		cout << "Because b" << i << " is " << binary_Arr[i] << " , we have x = " << x << " and power = " << temp_p << " ^ 2" <<" mod "<< m << " = " << power << endl;
		}
	}
	return x;
}
};
	int main() {
		
		binary obj1;
		int base, exp, mod;

		cout << "MODULAR EXPONENTIATION CALCULATOR" << endl;
		cout << "(a^b mod m solver)" << endl << endl;
		cout << "Enter Base (a): ";
		cin >> base;
		cout << "Enter Exponent (b): ";
		cin >> exp;
		cout << "Enter Modulus (m):";
		cin >> mod;
		cout << endl;

		cout << exp << " is equivalent to (" ;

		obj1.decToBin(exp); //To launch counter
		int i = obj1.counter; //Then counter will be equal i.

		do{ //To print from last index to first index.

		cout << obj1.decToBin(exp)[i-1]; 
		i--;
		} while (i > 0);
		cout << ")" << " as binary number..." << endl << endl;
		cout <<"Modular Exponentiation of ("<< base << "^" << exp << ")" <<" mod "<< "(" << mod << ") = " << obj1.modExp(base,exp,mod);

	return 0;
}