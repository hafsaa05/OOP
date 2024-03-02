/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
using namespace std;

class GraphicsRenderer {
public:
    void renderGraphics() {
        cout << "Rendering the graphics." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Handling the input." << endl;
    }
};

class PhysicsSimulator {
public:
    void simulatePhysics() {
        cout << "Simulating the physics." << endl;
    }
};
class GameEngine {
private:
    GraphicsRenderer graphicsRenderer;
    InputHandler inputHandler;
    PhysicsSimulator physicsSimulator;

public:
    GameEngine() {
        cout << "GAME ENGINE:"<<endl;
    }

    void startEngine() {
        graphicsRenderer.renderGraphics();
        inputHandler.handleInput();
        physicsSimulator.simulatePhysics();
    }
};

int main() {
    GameEngine game1;
    game1.startEngine();

    return 0;
}
