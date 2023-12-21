#include <iostream>
#include <ctime>

using namespace std;

class Father
{
public:
	Father() {}

	Father(string newFirstName, string newLastName, int newBirthYear)
		: firstName(newFirstName), lastName(newLastName), birthYear(newBirthYear) {}

	Father(string newFirstName, string newLastName) : firstName(newFirstName), lastName(newLastName) {}

	void SetFirstName(string newFirstName) {
		this->firstName = newFirstName;
	}

	void SetLastName(string newLastName) {
		this->lastName = newLastName;
	}

	/*void SetAge(int newAge) {
		this->age = newAge;
	}*/

	string GetFirstName() {
		return this->firstName;
	}

	string GetLastName() {
		return this->lastName;
	}

	// IMPORTANT THING ABOUT HOW TO GET CURRENT TIME
	int GetAge() {
		time_t currentTime = time(NULL);            // retunr current time of system
		tm timeInfo;								// here will save splited date_time
		localtime_s(&timeInfo, &currentTime);		// obj time_t is converting to structure tm(y, m, d, h, m) and ---> go to timeInfo
		return timeInfo.tm_year + 1900 - birthYear; 
	}
	// If you don't add 1900, you get the number of years that have passed SINCE 1900, not the year itself.

	virtual void ShowInfo() {
		cout << "---Father info---" << endl;
		cout << "First name: " << firstName << endl;
		cout << "Last name: " << lastName << endl;
		cout << "Age: " << GetAge() << endl;
	}

private:
	string firstName = "";
	string lastName = "";
	int birthYear{};
};

class Child : public Father
{
public:
	Child() {}

	Child(string newFirstName, int newAge, Father& father)
		: Father(father.GetFirstName(), father.GetLastName()), age(newAge), firstName(newFirstName) {}

		
	void ShowInfo() override {
		cout << "---Child info---" << endl;
		cout << "First name: " << firstName << endl;
		cout << "Father's name: " << GetFirstName() << endl;
		cout << "Last name: " << GetLastName() << endl;
		cout << "Age: " << age << endl;
	}

private:
	string firstName = "";
	string lastName = "";
	string fathersName = "";
	int age{};

};

int main()
{

	Father father1("Alex", "Sharp", 2005);
	father1.ShowInfo();
	
	cout << "\n-------------------\n\n";

	Child child1("Stephe", 10, father1);
	child1.ShowInfo();
}

// якщо не використовувати модифікатор virtual - використовується раннє зв'язування з об'єктом класу