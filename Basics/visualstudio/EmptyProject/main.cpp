#include <iostream>

using namespace std;

int sum_arr(const int arr[], int count = 0) {
	int sum = 0;
	//arr[0] = 0;
	for (int i = 0; i < count; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}
int sum_arr(const int arr[]) {
	return 0;
}

int main() {
	cout << "hello world" << endl;

	int (*ps)(const int arr[], int count);
	int (*ps2)(const int arr[]);
	ps = sum_arr;
	ps2 = sum_arr;


	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;

	int arr[]{ 1,2,3,4 };
	ps(arr,4);

	char* name;
	name = new char[10];
	//delete name;
	delete[] name;

	int t = 1;
	int d = 2;
	const int* bird = &t;
	int const* snaik = &t;
	int* const dick = &t;
	int* simple = &t;

	bird = &d;
	//*bird = 4;

	snaik = &d;
	//*snaik = d;

	//dick = &d;
	*dick = d;

	simple = &d;
	*simple = d;

	//const char* bird = "wren";
	//cout << bird << endl;

	char flower[10] = "rouseaaaa";
	cout << flower << "s are red\n";

	int* p_int = new int[10];
	cout << p_int << endl;
	p_int++;
	cout << p_int << endl;
	cout << &p_int << endl;
	p_int--;
	delete[] p_int;



	const int arSize = 20;
	//char name[arSize];

	enum Suit { D, H, C };
	Suit a = Suit::C;
	cout << "Enter your name:\n";
	cin.get(name, arSize);
	//cout << "for you ," << name << endl;

	int months[3]{ };
	for (int i = 0; i < 3; i++) {
		cout << "months:" << months[i] << endl;
	}
	cout << "array is " << sizeof(months) << endl;
	cout << "int is " << sizeof(int) << " bytes." << n_int << endl;
	cout << "short is " << sizeof(short) << " bytes." << n_short << endl;
	system("pause");
	return 0;
}


