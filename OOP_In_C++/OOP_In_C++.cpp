#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FristName = "Mohamed";
	string _LastName = "Mostafa";
public :
	clsPerson(string FirstName, string LastName) {
		_FristName = FirstName;
		_LastName = LastName;
	}
	//Copy Construstor
	clsPerson(clsPerson & old_object) {
		_FristName = old_object.FristName;
		_LastName = old_object.LastName;
	}
	// DeConstructor
	~clsPerson() {
		cout << "\nGoooooooooooooooooooooooooooooooood Work\n";
	}

	// Properitie Set
	void SetFirstName(string FrName) {
		_FristName = FrName;
	}
	void SetLastName(string LaName) {
		_LastName = LaName;
	}
	// Properitie Get
	string GetFristName() {
		return _FristName;
	}
	string GetLastName() {
		return _LastName;
	}

	//Porperty Through "="
	__declspec(property(get = GetFristName, put = SetFirstName))string FristName;
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

protected:
	int testProt = 0;
};

class clsCalculator {
private:
	float _Result =0;
	float _PreviousResult = 0;
	float _LastNumber = 0;
	string _LastOperation = "Clear";

	bool _IsZero(float Number) {
		return (Number == 0);
	}

public:
	void Add(float Number) {
		_PreviousResult = _Result;
		_LastNumber = Number;
		_Result += Number;
		_LastOperation = "Adding";
	}
	void Subtract(float Number) {
		_PreviousResult = _Result;
		_LastNumber = Number;
		_Result -= Number;
		_LastOperation = "Subtracting";
	}
	void Divide(float Number) {
		_LastNumber = Number;
		if (_IsZero(Number)) {
			Number = 1;
		}
		_PreviousResult = _Result;
		_Result /= Number;
		_LastOperation = "Dividing";
	}
	void Multiply(float Number) {
		_LastNumber = Number;
		_PreviousResult = _Result;
		_Result *= Number;
		_LastOperation = "Multiplying";
	}
	void Clear() {
		_PreviousResult = _Result;
		_LastNumber = 0;
		_Result = 0;
		_LastOperation = "Clear";
	}
	void CancelLastOperation() {
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation";
		_Result = _PreviousResult;
	}
	float GetFinalResults() {
		return _Result;
	}
	void PrintResult() {
		cout << "\nResult After " << _LastOperation << " " << _LastNumber << " is: " << _Result ;
	}

};

void TestDeconstructor() {
	clsPerson Person1("MoHamed" , "Elamrecy");
	cout << Person1.FristName << endl;
	cout << Person1.LastName << endl;

}
void TestDeconstructorAs_Pointer() {
	clsPerson* Person1 = new clsPerson("MoHamed", "Amricy");
	cout << Person1->FristName << endl;
	cout << Person1->LastName<< endl;
	delete Person1;
}

class clsA {
private:

public:
	int var;
	static int counter;
	clsA() {
		counter++;
	};

	static int Fun1() {
		return 1;
	}
	int Fun2() {
		return 2;
	}
};

int clsA::counter = 0; // Initlisation static Variable / Members


int main()
{

	clsA A1, A2, A3;
	A1.var = 5;
	cout << A1.var  << endl;
	cout << A2.var << endl;
	cout << A3.var << endl;
	// Static Members
	cout << clsA::counter << endl;
	// Static Functoin 
	cout << clsA::Fun1();


	cout << "\n===================================================================\n";

	clsPerson Person1("Mohamed" , "Mostafa");
	Person1.FristName;
	Person1.LastName;
	// Copy Constructor 
	clsPerson Person2 = Person1;
	cout << Person1.FristName << endl;
	cout << Person1.LastName << endl;

	TestDeconstructor();
	TestDeconstructorAs_Pointer();

	cout << "\n===================================================================\n";

	clsCalculator Calculator1;
	Calculator1.Clear();
	Calculator1.PrintResult();

	Calculator1.Add(100);
	Calculator1.PrintResult();

	Calculator1.Subtract(25);
	Calculator1.PrintResult();

	Calculator1.Multiply(2);
	Calculator1.PrintResult();

	Calculator1.Divide(0);
	Calculator1.PrintResult();

	Calculator1.Divide(2);
	Calculator1.PrintResult();

	Calculator1.Clear();
	Calculator1.PrintResult();

	
	

	cout << endl;
	system("pause>0");
}

