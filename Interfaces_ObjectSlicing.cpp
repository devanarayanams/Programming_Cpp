#include <string>
#include <iostream>
using namespace std;

// Interface for Employee behavior
class IEmployee {
public:
	// Pure virtual function for professional behavior
	virtual void professional() = 0;
};

// Interface for FamilyMember behavior
class IFamilyMember {
public:
	// Pure virtual function for casual behavior
	virtual void casual() = 0;
	// Pure virtual function for cranky behavior
	virtual void cranky() = 0;
};

// Person class implements both IEmployee and IFamilyMember interfaces
class Person : public IEmployee, public IFamilyMember {
public:
	// Implementation of casual behavior
	void casual() override {
		cout << "Casual behavior" << endl;
	}

	// Implementation of professional behavior
	void professional() override {
		cout << "Professional behavior" << endl;
	}

	// Implementation of cranky behavior
	void cranky() override {
		cout << "Cranky behavior" << endl;
	}
};

// OfficeContext class
class OfficeContext {
public:
	// Method for entering office context
	void Enter(IEmployee* obj) {
		obj->professional(); // Calling professional behavior
	}
};

// FamilyContext class
class FamilyContext {
public:
	// Method for entering family context
	void Enter(Person* obj) {
		obj->casual(); // Calling casual behavior
		obj->cranky(); // Calling cranky behavior
	}
};

// Main function
int main() {
	// Create a Person object named 'dev'
	Person dev;

	// Create FamilyContext and OfficeContext objects
	FamilyContext fContext;
	OfficeContext oContext;

	// Enter family context for 'dev'
	fContext.Enter(&dev);

	// Enter office context for 'dev'
	oContext.Enter(&dev);

	// Object Slicing Example
	IEmployee baseObj = dev; // Object slicing: Assigning derived class object to base class object
	baseObj.professional(); // Only calls base class implementation

	return 0;
}
