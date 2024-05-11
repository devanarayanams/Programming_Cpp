#include <iostream>
#include <string>
using namespace std;

class TextBox {
public:
	virtual void accept(string text) { cout << "Text Box" << endl; }

};

class NumTB : public TextBox {
public:
	void accept(string text) override { // override will check if the baseclass is virtual or not
		cout << "NumTB" << endl;
	}
};


class MaskedTextBox: public TextBox {
public:
	void accept(string text) override { // override will check if the baseclass is virtual or not
		cout << "MaskedTB" << endl;
	}
};

int main () {
	TextBox name;
	name.accept("tom");

	NumTB namenum;
	namenum.accept("22");

	TextBox* basePtr = &namenum; // don't do this until and unless the accept is marked as virtual, then substition will fail to check this "override" is there in c++ 
	// here the basePtr can point to TextBox or NumTB -> run time polymorphism - late binding
	basePtr->accept("34");

	MaskedTextBox phoneNumberTB;
	basePtr = &phoneNumberTB;

	basePtr->accept("+9121311313");// accept has many forms here which points to different class specific methods - run time polymorphism - Function Overriding

	return 0;
}
