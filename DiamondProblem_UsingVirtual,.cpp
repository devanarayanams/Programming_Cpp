// The diamond problem occurs when two superclasses of a class have a common base class.


#include <iostream>
#include <string>
using namespace std;

class Device {
private:
    string name;
    string model;
    string version;
protected: // from public to protected -> re used but can't be reinstantiated
    Device(string nameArg, string modelArg, string versionArg) : name{ nameArg }, model{ modelArg }, version{ versionArg } {
        cout << "Device Instantiated" << endl;
    }
    ~Device() {
        cout << "Device Destructed" << endl;
    }

};

class Printer : virtual public Device { // virtual is added to solve the diamond problem

public:
    Printer() : Device{ "","","" } {
        cout << "Printer Instantiated" << endl;
    }
    ~Printer() {
        cout << "Printer Destructed" << endl;
    }

    void print(string content) {
        cout << "Print" << content << endl;
    }
};

class Scanner : virtual public Device { // virtual is added to solve the diamond problem

public:
    Scanner() : Device{ "","","" } {
        cout << "Scanner Instantiated" << endl;
    }
    ~Scanner() {
        cout << "Scanner Destructed" << endl;
    }
    void scan(string content) {
        cout << "Scan" << content << endl;
    }
};

class PrintScanner: public Device {
    Printer printerObj;
    Scanner scannerObj;


public:
    void print(string content) {
        this->printerObj.print(content); // since the print method is not available in PS, it is delegated to the printer via printObj
    }
    void scan(string content) {
        this->scannerObj.scan(content); // since the scan method is not available in PS, it is delegated to the scanner via scannerObj
    }

    PrintScanner(string n, string m, string v) : Device{ n, m, v } {
        cout << "PrintScanner Instantiated" << endl;
    }
    ~PrintScanner() {
        cout << "PrintScanner Destructed" << endl;
    }

};

class TaskManager {
public:

    void invokePrintTask(PrintScanner* printScannerPtr, string content) {
        printScannerPtr->print(content);
    }

    void invokePrintTask(Printer* printerPtr, string content) {
        printerPtr->print(content);
    }


    void invokeScanTask(Scanner* scannerPtr, string content) {
        scannerPtr->scan(content);
    }
};

int main()
{
    Printer hpPrinter;
    Scanner hpScanner;
    TaskManager taskmgr;

    PrintScanner hpPrintScanner("HP Printer", "1234", "v1.0");

    taskmgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
    taskmgr.invokePrintTask(&hpPrinter, "doc.pdf");
    taskmgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
    taskmgr.invokeScanTask(&hpScanner, "doc.pdf");
    


    return 0;
}

// output: device construction + destrcution called twice 
