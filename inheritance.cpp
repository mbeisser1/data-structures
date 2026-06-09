#include <iostream>

class Base {
public:
    int pub = 10;
protected:
    int prot = 20;
private:
    int priv = 30;

public:
    Base() {
        std::cout << "Base constructor:\n";
        std::cout << "  pub=" << pub << "\n";
        std::cout << "  prot=" << prot << "\n";
        std::cout << "  priv=" << priv << "\n";
    }
};

// Protected inheritance
class Derived1 : protected Base {
    // now protected:
    // int pub;
    // int prot;
    
    // now inaccessible:
    // int priv;

public:
    Derived1() : Base() {
        std::cout << "Derived1 (protected inheritance):\n";
        std::cout << "  pub=" << pub << "\n";           // OK — pub became protected
        std::cout << "  prot=" << prot << "\n";         // OK — prot stayed protected
        // std::cout << "  priv=" << priv << "\n";      // ERROR — priv is inaccessible
    }
};

// Private inheritance
class Derived2 : private Base {
    // now private:
    // int pub;
    // int prot;
    
    // now inaccessible:
    // int priv;

public:
    Derived2() : Base() {
        std::cout << "Derived2 (private inheritance):\n";
        std::cout << "  pub=" << pub << "\n";           // OK — pub became private
        std::cout << "  prot=" << prot << "\n";         // OK — prot became private
        // std::cout << "  priv=" << priv << "\n";      // ERROR — priv is inaccessible
    }
};

// Further derived from Derived1 (protected inheritance)
class Further1 : public Derived1 {
    // inherited from Derived1 — still protected:
    // int pub;
    // int prot;
    
    // still inaccessible:
    // int priv;

public:
    Further1() : Derived1() {
        std::cout << "Further1 (from Derived1):\n";
        std::cout << "  pub=" << pub << "\n";           // OK — pub is protected in Derived1
        std::cout << "  prot=" << prot << "\n";         // OK — prot is protected in Derived1
        // std::cout << "  priv=" << priv << "\n";      // ERROR — priv is inaccessible
    }
};

// Further derived from Derived2 (private inheritance)
class Further2 : public Derived2 {
    // inherited from Derived2 — now inaccessible:
    // int pub;
    // int prot;
    
    // still inaccessible:
    // int priv;

public:
    Further2() : Derived2() {
        std::cout << "Further2 (from Derived2):\n";
        // std::cout << "  pub=" << pub << "\n";        // ERROR — pub is private in Derived2
        // std::cout << "  prot=" << prot << "\n";      // ERROR — prot is private in Derived2
        // std::cout << "  priv=" << priv << "\n";      // ERROR — priv is inaccessible
    }
};

int main() {
    std::cout << "=== Creating Derived1 ===\n";
    Derived1 d1;
    // d1.pub;   // ERROR — pub is protected in Derived1
    // d1.prot;  // ERROR — prot is protected in Derived1

    std::cout << "\n=== Creating Derived2 ===\n";
    Derived2 d2;
    // d2.pub;   // ERROR — pub is private in Derived2
    // d2.prot;  // ERROR — prot is private in Derived2

    std::cout << "\n=== Creating Further1 ===\n";
    Further1 f1;

    std::cout << "\n=== Creating Further2 ===\n";
    Further2 f2;

    return 0;
}
