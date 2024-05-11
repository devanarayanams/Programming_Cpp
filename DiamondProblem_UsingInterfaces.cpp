#include <iostream>
#include <string>
using namespace std;

// Interface for printing functionality
class IPrinter {
public:
    virtual void print(string content) = 0;
    virtual ~IPrinter() {}
};

// Interface for scanning functionality
class IScanner {
public:
    virtual void scan(string content) = 0;
    virtual ~IScanner() {}
};

// Device class with name, model, and version info
class Device {
protected:
    string name;
    string model;
    string version;
public:
    Device(string nameArg, string modelArg, string versionArg) : name(nameArg), model(modelArg), version(versionArg) {
        cout << "Device Instantiated" << endl;
    }

    ~Device() {
        cout << "Device Destructed" << endl;
    }
};

// Printer class implementing IPrinter interface
class Printer : public IPrinter, public Device {
public:
    Printer(string name, string model, string version) : Device(name, model, version) {
        cout << "Printer Instantiated" << endl;
    }

    ~Printer() {
        cout << "Printer Destructed" << endl;
    }

    void print(string content) {
        cout << "Print" << content << endl;
    }
};

// Scanner class implementing IScanner interface
class Scanner : public IScanner, public Device {
public:
    Scanner(string name, string model, string version) : Device(name, model, version) {
        cout << "Scanner Instantiated" << endl;
    }

    ~Scanner() {
        cout << "Scanner Destructed" << endl;
    }

    void scan(string content) {
        cout << "Scan" << content << endl;
    }
};

// PrintScanner class implementing both IPrinter and IScanner interfaces
class PrintScanner : public IPrinter, public IScanner, public Device {
public:
    PrintScanner(string name, string model, string version) : Device(name, model, version) {
        cout << "PrintScanner Instantiated" << endl;
    }

    ~PrintScanner() {
        cout << "PrintScanner Destructed" << endl;
    }

    void print(string content) {
        cout << "Print" << content << endl;
    }

    void scan(string content) {
        cout << "Scan" << content << endl;
    }
};

// TaskManager 
class TaskManager {
public:
    void invokePrintTask(IPrinter* printerPtr, string content) {
        printerPtr->print(content);
    }

    void invokeScanTask(IScanner* scannerPtr, string content) {
        scannerPtr->scan(content);
    }
};

int main()
{
    Printer hpPrinter("HP Printer", "1234", "v1.0");
    Scanner hpScanner("HP Scanner", "5678", "v2.0");
    PrintScanner hpPrintScanner("HP PrintScanner", "9012", "v3.0");

    TaskManager taskmgr;


    taskmgr.invokePrintTask(&hpPrintScanner, "doc.pdf");
    taskmgr.invokePrintTask(&hpPrinter, "doc.pdf");
    taskmgr.invokeScanTask(&hpPrintScanner, "doc.pdf");
    taskmgr.invokeScanTask(&hpScanner, "doc.pdf");

    return 0;
}
