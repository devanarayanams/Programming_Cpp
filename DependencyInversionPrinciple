#include <iostream>
using namespace std;

// Abstraction: Engine interface
class IKEngine {
public:
    // Pure virtual methods to start and stop the engine
    virtual void start() = 0;
    virtual void stop() = 0;
};

// Low-level Module: MPFIEngine implements the Engine interface
class MPFIEngine : public IKEngine {
public:
    // Implementation of starting the engine
    void start() override {
        // Implementation details for starting MPFIEngine
        cout << "MPFI Engine started." << endl;
    }

    // Implementation of stopping the engine
    void stop() override {
        // Implementation details for stopping MPFIEngine
        cout << "MPFI Engine stopped." << endl;
    }
};

// High-level Module: XUV3XO
class XUV3XO {
private:
    IKEngine* engine; // Dependency on the Engine interface

public:
    // Constructor with dependency injection
    XUV3XO(IKEngine* engineArg) : engine(engineArg) {}

    // Method to drive the car
    void drive() {
        engine->start(); // Start the engine
        cout << "Car is being driven." << endl;
    }

    // Method to halt the car
    void halt() {
        engine->stop(); // Stop the engine
        cout << "Car has halted." << endl;
    }

    // Destructor
    ~XUV3XO() {
        delete engine; // Release memory for the engine
    }
};

// Low-level Module: GDIEngine implements the Engine interface
class GDIEngine : public IKEngine {
public:
    // Implementation of starting the engine
    void start() override {
        // Implementation details for starting GDIEngine
        cout << "GDI Engine started." << endl;
    }

    // Implementation of stopping the engine
    void stop() override {
        // Implementation details for stopping GDIEngine
        cout << "GDI Engine stopped." << endl;
    }
};

int main() {
    // Create instances of low-level engine modules
    MPFIEngine napEngine;
    GDIEngine turboEngine;

    // Create high-level module instances with different engine dependencies
    XUV3XO car1(&napEngine); // XUV3XO with MPFIEngine
    XUV3XO car2(&turboEngine); // XUV3XO with GDIEngine

    // Drive car2
    car2.drive();

    return 0;
}
