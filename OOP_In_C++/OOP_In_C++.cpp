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

	//Property Through "="
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



class clsPerson1 {
private:
	int _ID;
	string _FirstName;
	string _LastName;
	string _FullName;
	string _Email;
	string _Phone;

public:
	clsPerson1(int ID , string FirstName , string LastName , string Email , string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}
	// Propertys Set
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	void SetEmail(string Email) {
		_Email = Email;
	}
	void SetPhone(string Phone) {
		_Phone = Phone;
	}

	// Properties Get
	int ID() {
		return _ID;
	}
	string FirstName() {
		return _FirstName;
	}
	string LastName() {
		return _LastName;
	}
	string FullName() {
		_FullName = _FirstName + " " + _LastName;
		return _FullName;
	}
	string Email() {
		return _Email;
	}
	string Phone() {
		return _Phone;
	}

	
	void SendEmail(string Subject , string Body){
		cout << "\nThe following massege sent successfully to Email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}
	void SendSMS(string Body) {
		cout << "\nThe following massege sent successfully to Phone: " << _Phone << endl;
		cout << Body << endl;
	}
	void Print() {
		cout << "\n Info\n";
		cout << "__________________________________\n";
		cout << "ID         : " << _ID << endl;
		cout << "FirstName  : " << _FirstName << endl;
		cout << "LastName   : " << _LastName << endl;
		cout << "FullName   : " << FullName() << endl;
		cout << "Email      : " << _Email << endl;
		cout << "Phone      : " << _Phone << endl;
		cout << "__________________________________\n";
	}

};
class clsEmployes  : public clsPerson1 {
private:
	string _Title;
	string _Department;
	double _Salary;

public:
	clsEmployes(int ID , string FirstName , string LastName , string Email , string Phone , string Title , string Department , double Salary): 
		clsPerson1(ID , FirstName , LastName , Email , Phone){
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}
	// Propertys Set
	void SetTitle(string Title) {
		_Title = Title;
	}
	void SetDepartment(string Department) {
		_Department = Department;
	}
	void SetSalary(double Salary) {
		_Salary = Salary;
	}


	// Properties Get
	string Title() {
		return _Title;
	}
	string Department() {
		return _Department;
	}
	double Salary() {
		return _Salary;
	}

	//Function Overriding
	void Print() {
		cout << "\n Info\n";
		cout << "__________________________________\n";
		cout << "ID         : " << ID() << endl;
		cout << "FirstName  : " << FirstName() << endl;
		cout << "LastName   : " << LastName() << endl;
		cout << "FullName   : " << FullName() << endl;
		cout << "Email      : " << Email() << endl;
		cout << "Phone      : " << Phone() << endl;
		cout << "Title      : " << _Title << endl;
		cout << "Department : " << _Department << endl;
		cout << "Salary     : " << _Salary << endl;
		cout << "__________________________________\n";
	}

};


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

	cout <<"\n=========================================================\n";
	// Info Person Exercise
	clsPerson1 Info1(1 , "Mohamed" , "Mostafa" , "My@gmial.com" , "39999093209");
	Info1.Print();
	Info1.SendEmail("Hi", "How are you? ");
	Info1.SendSMS("How are you? ");

	//  Homework - Employee Exercise
	clsEmployes Employee1(1 , "Mohamed" , "Mostafa" , "My@gmial.com" , "39999093209" ,"Software Eng" , "Full Stack" , 10000);
	Employee1.Print();
	Employee1.SendEmail("Hi", "How are you? ");
	Employee1.SendSMS("How are you? ");

	Employee1.Print();

	cout << endl;
	system("pause>0");
}

