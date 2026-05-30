Explain the concept of friend functions and classes. #q28 #friend #oop-concepts

---
**Friend functions** and **friend classes** are special constructs that allow **controlled access** to a class’s **`private`** and **`protected`** members. Use them sparingly — overuse can break encapsulation.

%%%MOCHI_CARD%%%
What is a friend function? #q28 #friend #oop-concepts

---

- Declared inside a class with **`friend`**, but **defined outside** the class
- **Not a member function**, yet has direct access to **`private`** and **`protected`** members
- Typically used when a function needs internal access to one or more classes

%%%MOCHI_CARD%%%
Show a friend function example. How can a non-member `calculateArea` read private `Rectangle` dimensions? #q28 #friend #oop-concepts

---
```cpp
#include <iostream>

class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    friend int calculateArea(const Rectangle& rect);
};

int calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

int main() {
    Rectangle rect(5, 3);
    std::cout << "Area: " << calculateArea(rect) << std::endl;
    return 0;
}
```

%%%MOCHI_CARD%%%
What is a friend class? #q28 #friend #oop-concepts

---

- Declared with **`friend class Other;`** inside the class
- **All members** of the friend class can access **`private`** and **`protected`** members
- Useful when two classes must work closely together and share internal data
- Friendship is **not mutual** and **not inherited**

%%%MOCHI_CARD%%%
Show a friend class example. How can `BankManager` read private `BankAccount` fields? #q28 #friend #oop-concepts

---
```cpp
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNum, double bal)
        : accountNumber(accNum), balance(bal) {}

    friend class BankManager;
};

class BankManager {
public:
    void displayAccountDetails(const BankAccount& account) {
        std::cout << "Account: " << account.accountNumber
                  << ", Balance: $" << account.balance << std::endl;
    }
};
```

%%%MOCHI_CARD%%%
What are key considerations for `friend` in C++? #q28 #friend #oop-concepts

---

- **Encapsulation** — overuse breaks abstraction; prefer public interfaces when possible
- Friendship is **not mutual** — A friend of B ≠ B friend of A
- Friendship is **not inherited** by derived classes
- C++20: **templated friend functions** inside class templates

%%%MOCHI_CARD%%%
In about 60 seconds, explain friend functions and classes. #q28 #friend #oop-concepts

---

- **`friend`** grants access to **`private`/`protected`** members
- **Friend function** — non-member with insider access
- **Friend class** — another class with full insider access
- Use **sparingly**; friendship is **one-way** and **not inherited**
