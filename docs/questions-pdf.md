## C++ Basics and Language Features

### 1. What are the main *features* of *C++*?

**C++** is renowned for its diverse set of features, many of which it inherited from **C** but also enhanced and expanded upon. These features enable a wide range of programming paradigms, from procedural to object-oriented and generic programming.

#### Key Features

##### Efficiency

- **Low-Level Access**: Pointers, direct memory manipulation.
- **Resource Management**: Smart pointers, deterministic destructors with RAII.
- **Inline Functions**: Eliminates function call overhead.
- **Move Semantics**: Transfers resources rather than copying.

##### Flexibility in Types

- **Strongly-Typed**: Encourages type safety.
- **Type Inference**: `auto` keyword deduces types.
- **Concepts** (C++20): Constraints and requirements for templates.

##### Multiple Paradigms

- **Procedural**: Functions and control structures.
- **OOP Support**: Classes, objects, inheritance, polymorphism.
- **Functional Features**: Lambdas, `constexpr`, immutability.
- **Generic Programming**: Templates and concepts.

##### Standard Library

- **Rich in Utilities**: Data structures, algorithms, I/O facilities.
- **Modularity**: Components like `<algorithm>` encourage algorithmic abstraction.
- **Ranges** (C++20): Composable algorithm sequences.

##### Code Reusability

- **Inheritance**: Base classes and derived classes.
- **Composition**: Building classes from other objects.
- **Association**: Member objects and relationships.

##### Polymorphism

- **Compile-Time**: Templates and concepts.
- **Run-Time**: Virtual functions, dynamic_cast.

##### Memory Management

- **Stack vs. Heap**: Automatic storage (`stack`), dynamic memory via pointers.
- **Smart Pointers**: Ownership-aware pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`).
- **RAII**: Resource Acquisition Is Initialization.

##### Modern Features

- **Coroutines** (C++20): Simplified asynchronous programming.
- **Modules** (C++20): Improved code organization and compilation.
- **Constexpr**: Compile-time computation.

#### Code Example: Features in Action

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <concepts>

template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
T addOne(const T& val) {
    return val + 1;
}

struct Animal {
    virtual void speak() const = 0;
    virtual ~Animal() = default;
};

struct Dog : public Animal {
    void speak() const override { std::cout << "Woof!" << std::endl; }
};

int main() {
    std::vector<int> vec { 1, 2, 3 };
    for (const auto& num : vec) {
        std::cout << addOne(num) << std::endl;
    }

    auto dog = std::make_unique<Dog>();
    dog->speak();

    // C++20 feature: constexpr vector
    constexpr std::vector<int> constexpr_vec{1, 2, 3, 4, 5};
    static_assert(constexpr_vec.size() == 5);

    return 0;
}
```


<div class="page"/>

### 2. Explain the *difference* between *C* and *C++*.

- **C**: Developed primarily for system programming at Bell Labs in the 1970s. It laid the foundation for many operating systems and is still widely used.
- **C++**: Emerged in the early 1980s as an extension of C, introducing object-oriented programming (OOP) paradigms. It has since evolved to incorporate features from multiple programming paradigms.

#### Key Distinctions

##### Paradigms

- **C**: Primarily *procedural*.
- **C++**: *Multi-paradigm*; supports procedural, OOP, generic, and functional programming.

##### Function Overloading

- **C**: Doesn’t support overloading.
- **C++**: Allows *function overloading*, enabling multiple functions with the same name but different parameters.

```cpp
// C++ function overloading example
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
```

##### Memory Management

- **C**: Manual memory management using functions like `malloc()` and `free()`.
- **C++**: Offers both manual management and automated options via *RAII* (Resource Acquisition Is Initialization), *smart pointers*, and the `new` and `delete` operators.

```cpp
// C++ smart pointer example
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(42);
```

##### Code Organization

- **C**: Organizes code into functions and modules.
- **C++**: Extends this with *classes*, *objects*, *inheritance*, and other OOP features.

##### Standard Libraries

- **C**: Uses the C Standard Library.
- **C++**: Incorporates the C++ Standard Library, which includes the C Standard Library and adds features like *containers*, *algorithms*, and *streams*.

##### Header Files

- **C**: Typically uses `.h` extension for header files.
- **C++**: Uses headers without the `.h` extension (e.g., `<iostream>`), though it can still use C-style headers.

##### Type Safety

- **C**: Provides basic type checking.
- **C++**: Offers stronger type checking and features like *templates* for improved type safety.

```cpp
// C++ template example
template <typename T>
T max(T a, T b) { return (a > b) ? a : b; }
```

##### Object-Oriented Features

- **C**: Does not support OOP concepts natively.
- **C++**: Fully supports OOP with *classes*, *inheritance*, *polymorphism*, and *encapsulation*.

##### Exception Handling

- **C**: Doesn’t support exceptions natively.
- **C++**: Provides built-in *exception handling* mechanisms.

```cpp
// C++ exception handling example
try {
    // code that might throw an exception
} catch (const std::exception& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
```

##### Boolean Type

- **C**: Traditionally uses integers for boolean values (0 for false, non-zero for true).
- **C++**: Introduces a built-in `bool` type with `true` and `false` keywords.

##### Standardization

- **C**: Latest standard is C17 (ISO/IEC 9899:2018), with C23 in development.
- **C++**: Latest standard is C++20, with C++23 nearing completion.


<div class="page"/>

### 3. What is *object-oriented programming* in *C++*?

**Object-Oriented Programming** (OOP) is a programming paradigm that organizes code into reusable and self-contained units called **objects**. Each object groups **data attributes** (characteristics) and **methods** (behaviors) that operate on the data.

#### The Four Pillars of OOP

1. **Encapsulation**: Objects hide their internal state and behavior, exposing a controlled public interface.
2. **Inheritance**: Defines an “is-a” relationship, allowing objects of a derived class to access attributes and behaviors of a base class.
3. **Polymorphism**: Enables objects to be treated as instances of their parent class while exhibiting their own behaviors.
4. **Abstraction**: Simplifies complex systems by focusing on high-level actions while hiding implementation details.

#### Key OOP Concepts in C++

##### Classes and Objects

A `class` is a blueprint for creating objects:

```cpp
class Car {
private:
    std::string model;
    int year;

public:
    Car(std::string m, int y) : model(m), year(y) {}
    void display() {
        std::cout << year << " " << model << std::endl;
    }
};

int main() {
    Car myCar("Tesla", 2023);
    myCar.display();
    return 0;
}
```

##### Inheritance

C++ supports single and multiple inheritance:

```cpp
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(std::string m, int y, int bc) : Car(m, y), batteryCapacity(bc) {}
};
```

##### Polymorphism

C++ supports both compile-time (function overloading, templates) and runtime polymorphism (virtual functions):

```cpp
class Vehicle {
public:
    virtual void start() = 0;  // Pure virtual function
};

class Car : public Vehicle {
public:
    void start() override {
        std::cout << "Car started" << std::endl;
    }
};
```

##### Encapsulation

C++ uses access specifiers (`public`, `private`, `protected`) to control member visibility:

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};
```

##### Abstraction

Abstract classes and interfaces in C++ are created using pure virtual functions:

```cpp
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() override {
        return M_PI * radius * radius;
    }
};
```

#### Modern C++ OOP Features

- **Smart Pointers**: `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr` for better resource management.
- **Move Semantics**: Efficient transfer of resources between objects.
- **Lambda Expressions**: Inline function objects for more flexible OOP designs.
- **Concepts** (C++20): Constraints on template parameters for improved type checking and error messages.


<div class="page"/>

### 4. What are the *access specifiers* in *C++* and what do they do?

Access specifiers are keywords in C++ that control the visibility and accessibility of class members. They enable the **principle of data encapsulation**, ensuring data integrity and promoting a clear separation between a class’s interface and its implementation.

#### Types of Access Specifiers

C++ provides three main access specifiers:

1. **`public`**: Members are accessible from any part of the program. This category typically includes the class’s interface—its public methods and data.

2. **`protected`**: Access is limited to the containing class, its derived classes, and friends. This specifier is useful in inheritance scenarios.

3. **`private`**: Members are accessible only from within the containing class and its friends. This is the default access level for class members and ensures that the class’s internal implementation details are hidden from external users.

#### Code Example

Here’s a comprehensive example demonstrating the use of access specifiers in C++:

```cpp
#include <iostream>

class MyClass {
public:
    void publicMethod() {
        std::cout << "Public method, accessing private data: " << privateData << std::endl;
    }

    struct PublicStruct {
        int data;
    };

    enum class Visibility { Hidden, Visible };

    Visibility toggleVisibility() {
        visibility = (visibility == Visibility::Visible) ? Visibility::Hidden : Visibility::Visible;
        return visibility;
    }

protected:
    int protectedData = 20;

private:
    int privateData = 10;
    Visibility visibility = Visibility::Visible;
};

class DerivedClass : public MyClass {
public:
    void accessProtectedData() {
        std::cout << "Accessing protected data: " << protectedData << std::endl;
        // Cannot access privateData here
    }
};

int main() {
    MyClass obj;
    obj.publicMethod(); // OK
    // obj.privateData; // Error: privateData is not accessible
    // obj.protectedData; // Error: protectedData is not accessible

    DerivedClass derived;
    derived.publicMethod(); // OK
    derived.accessProtectedData(); // OK
    // derived.privateData; // Error: privateData is not accessible

    return 0;
}
```

#### Key Points

- **`public`** members can be accessed from anywhere in the program.
- **`protected`** members are accessible within the class, its derived classes, and friends.
- **`private`** members are only accessible within the class and its friends.
- The default access specifier for class members is **`private`**.
- Structs and unions default to **`public`** access, unlike classes.
- Access specifiers can be used multiple times within a class definition to change the access level of subsequent members.

#### Modern C++ Considerations

In modern C++ (C++11 and later):

- Use of the `class` keyword for inheritance implies **`private`** inheritance by default.
- Use of the `struct` keyword for inheritance implies **`public`** inheritance by default.
- The `friend` keyword allows a function or another class to access private and protected members of a class.
- C++11 introduced strongly typed enums (`enum class`), which have the same access control as regular classes.


<div class="page"/>

### 5. Explain the concept of *namespaces* in *C++*.

**Namespaces** in C++ are a fundamental feature used to organize code into logical groups and prevent naming conflicts. They provide a way to encapsulate related functionality and avoid naming collisions in large projects.

#### Key Concepts

##### Namespace Declaration and Usage

Namespaces are declared using the `namespace` keyword:

```cpp
namespace MyNamespace {
    // Declarations and definitions
}
```

To use elements from a namespace, you can either:

1. Use the scope resolution operator `::`:

```cpp
MyNamespace::function();
```

2. Use the `using` directive:

```cpp
using namespace MyNamespace;
function(); // Now directly accessible
```

##### Nested Namespaces

Namespaces can be nested within other namespaces:

```cpp
namespace Outer {
    namespace Inner {
        // Declarations and definitions
    }
}
```

In C++17 and later, you can use nested namespace definitions:

```cpp
namespace Outer::Inner {
    // Declarations and definitions
}
```

##### Unnamed Namespaces

Unnamed (or anonymous) namespaces limit the visibility of their contents to the current translation unit:

```cpp
namespace {
    int hidden_variable = 42;
}
```

##### Namespace Aliases

You can create aliases for long namespace names:

```cpp
namespace very_long_namespace_name {
    void function();
}

namespace vln = very_long_namespace_name;
vln::function(); // Equivalent to very_long_namespace_name::function();
```

#### Code Example

Here’s a comprehensive example demonstrating various namespace concepts:

```cpp
#include <iostream>

// Standard namespace
namespace std_example {
    void print(const char* message) {
        std::cout << "Standard: " << message << std::endl;
    }
}

// Nested namespace
namespace outer {
    namespace inner {
        void print(const char* message) {
            std::cout << "Nested: " << message << std::endl;
        }
    }
}

// Unnamed namespace
namespace {
    void print(const char* message) {
        std::cout << "Unnamed: " << message << std::endl;
    }
}

int main() {
    std_example::print("Hello from std_example");
    outer::inner::print("Hello from outer::inner");
    print("Hello from unnamed namespace");

    // Using directive
    using namespace std_example;
    print("Using std_example namespace");

    return 0;
}
```


<div class="page"/>

### 6. What is the *difference* between ‘*struct*’ and ‘*class*’ in *C++*?

In C++, both `struct` and `class` are used to create **user-defined data types**, but they have key differences in their default member access levels, default inheritance access levels, and intended use-cases.

#### Key Distinctions

1. **Member Access Levels**:

    - `struct`: Members are **public** by default.
    - `class`: Members are **private** by default.
2. **Inheritance Access Levels**:

    - `struct`: **Public** inheritance is the default.
    - `class`: **Private** inheritance is the default.
3. **Usage-Centric Distinctions**:

    - `struct`: Suited for small, simple objects with data that is mostly public.
    - `class`: Intended for larger, more complex objects that use encapsulation, data hiding, and have specific member functions.

#### Code Example: struct vs. class

```cpp
#include <iostream>
#include <string>

struct PersonStruct {
    std::string name;
    int age;
};

class PersonClass {
private:
    std::string name;
    int age;

public:
    void setName(const std::string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        if (newAge > 0)
            age = newAge;
    }

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

int main() {
    // struct members are public by default
    PersonStruct myStructPerson { "John", 30 };
    std::cout << "Name: " << myStructPerson.name << ", Age: " << myStructPerson.age << std::endl;

    // class members are private by default
    PersonClass myClassPerson;
    myClassPerson.setName("Jane");
    myClassPerson.setAge(25);
    std::cout << "Name: " << myClassPerson.getName() << ", Age: " << myClassPerson.getAge() << std::endl;

    return 0;
}
```

#### Additional Considerations

- In modern C++, the distinction between `struct` and `class` is mainly a matter of default access specifiers.
- The choice between `struct` and `class` often depends on the design intent and coding style guidelines of a project.
- Some developers use `struct` for **Plain Old Data** (POD) types and `class` for more complex objects with behaviors.
- Both `struct` and `class` can have member functions, constructors, and destructors.
- The `struct` keyword is retained in C++ for backward compatibility with C and to provide a quick way to create simple data structures.


<div class="page"/>

### 7. What is a *constructor* and what are its *types* in *C++*?

A **constructor** in C++ is a special member function responsible for initializing instances of a class. Constructors are called automatically when an object is created.

#### Types of Constructors

##### 1\. Default Constructor

If a class doesn’t have any constructors specified, the compiler automatically generates a default constructor. Its role is to initialize the object to a default state.

```cpp
class MyClass {
public:
    MyClass() = default;  // Explicitly defaulted constructor
};
```

##### 2\. Parameterized Constructor

Designed to accept arguments for custom object initialization.

```cpp
class Person {
public:
    Person(const std::string& name, int age) : name_(name), age_(age) {}
private:
    std::string name_;
    int age_;
};
```

##### 3\. Copy Constructor

Used for creating an object as a copy of an existing object. The parameter is typically a `const` reference to the same class.

```cpp
class MyClass {
public:
    MyClass(const MyClass& other) : data_(other.data_) {}
private:
    int data_;
};
```

##### 4\. Move Constructor

Optimized for moving data from temporary objects or rvalue references. Introduced in C++11.

```cpp
class MyClass {
public:
    MyClass(MyClass&& other) noexcept : data_(std::move(other.data_)) {}
private:
    std::vector<int> data_;
};
```

##### 5\. Delegating Constructor (C++11)

Allows a constructor to call another constructor of the same class.

```cpp
class Rectangle {
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    Rectangle() : Rectangle(0, 0) {}  // Delegating constructor
private:
    int length, width;
};
```

##### 6\. Inherited Constructor (C++11)

Allows a derived class to inherit constructors from its base class.

```cpp
class Base {
public:
    Base(int x) : x_(x) {}
private:
    int x_;
};

class Derived : public Base {
public:
    using Base::Base;  // Inherit constructors from Base
};
```

#### Key Points

- Constructors are declared in the **`public`** section of the class.
- Multiple constructors can coexist in a class (**constructor overloading**).
- Use **member initializer lists** for efficient initialization, especially for `const` members and base classes.
- Consider using `= default` for explicitly defaulted constructors and `= delete` for deleted constructors (C++11).
- Implement the **Rule of Five** (or Rule of Zero) for classes managing resources: define or delete copy constructor, move constructor, copy assignment, move assignment, and destructor.
- Use **`std::move`** in move constructors to transfer ownership of resources efficiently.


<div class="page"/>

### 8. Explain the concept of *destructors* in *C++*.

In C++, a **destructor** is a special member function that is automatically called when an object goes out of scope or is explicitly deleted using the `delete` keyword. Its primary purpose is to ensure **proper cleanup** of the object’s allocated resources.

#### Key Features

- **Automatic Invocation**: Destructors are called implicitly when an object leaves its scope or is explicitly deleted.

- **Syntax**: Destructors are identified by the `~` symbol followed by the class name (e.g., `~MyClass()`).

- **No Return Type or Arguments**: Destructors don’t return a value and typically don’t take any arguments.

- **Order of Destruction**: Objects are destroyed in the reverse order of their creation.

- **Virtual Destructors**: Essential for polymorphic behavior in inheritance hierarchies.

#### Code Example

```cpp
class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
};

class MyClass {
private:
    Resource* resource;
public:
    MyClass() : resource(new Resource()) {}
    ~MyClass() { delete resource; }
};
```

#### Use Cases

1. **Memory Management**: Releasing dynamically allocated memory.

    ```cpp
    class DynamicArray {
    private:
        int* arr;
        size_t size;
    public:
        DynamicArray(size_t s) : size(s), arr(new int[s]) {}
        ~DynamicArray() { delete[] arr; }
    };
    ```

2. **File Handling**: Closing open files.

    ```cpp
    class FileHandler {
    private:
        std::ofstream file;
    public:
        FileHandler(const std::string& filename) : file(filename) {}
        ~FileHandler() { if (file.is_open()) file.close(); }
    };
    ```

3. **Resource Management**: Closing database connections, network sockets, etc.

#### Best Practices

- **RAII (Resource Acquisition Is Initialization)**: Use destructors to implement RAII, ensuring resources are properly managed.

- **Virtual Destructors**: Always declare destructors as `virtual` in base classes intended for inheritance.

    ```cpp
    class Base {
    public:
        virtual ~Base() = default;
    };
    ```

- **Noexcept Specifier**: Modern C++ recommends marking destructors as `noexcept`.

    ```cpp
    class Modern {
    public:
        ~Modern() noexcept {
            // Cleanup code
        }
    };
    ```

#### C++11 and Beyond

- **\= default**: You can explicitly request a default destructor.

    ```cpp
    class DefaultDtor {
    public:
        ~DefaultDtor() = default;
    };
    ```

- **Smart Pointers**: Modern C++ encourages using smart pointers (`std::unique_ptr`, `std::shared_ptr`) which manage their own destruction, reducing the need for explicit destructors in many cases.


<div class="page"/>

### 9. What is *function overloading* in *C++*?

**Function overloading** in C++ is a feature that allows multiple functions to have the same name but different parameter lists. The compiler distinguishes between these functions based on the **number**, **types**, and **order** of parameters.

#### Key Concepts

##### Parameter Lists

- Functions are differentiated based on:

  - Types of parameters
  - Order of parameters
  - Total number of parameters
- An empty parameter list is valid (nullary function)

##### Restrictions

- Return type alone is not sufficient to differentiate functions
- Overloading works for both global and member functions

#### Code Example

Here’s a C++ code snippet demonstrating function overloading:

```cpp
#include <iostream>
#include <string>

void print(int num) {
    std::cout << "Integer: " << num << std::endl;
}

void print(double num) {
    std::cout << "Double: " << num << std::endl;
}

void print(const std::string& str) {
    std::cout << "String: " << str << std::endl;
}

int main() {
    print(5);
    print(3.14);
    print(std::string("Overloading"));
    return 0;
}
```

#### Best Practices

- **Consistent Naming**: Use function names that reflect their purpose
- **Clarity Over Complexity**: Use overloading judiciously to maintain readability
- **Combine with Default Arguments**: Consider using default arguments to reduce the number of overloaded functions

##### Modern C++ Considerations

- With C++11 and later, consider using **variadic templates** for more flexible function overloading
- Use `std::string` instead of `const char*` for string parameters in modern C++ code
- Utilize `constexpr` for compile-time evaluations when applicable


<div class="page"/>

### 10. What is *operator overloading* in *C++*?

**Operator overloading** in C++ allows developers to define custom behaviors for operators when used with user-defined types such as classes and structures. This feature enables the creation of more intuitive and expressive code by extending the functionality of standard operators to work with custom types.

#### Key Concepts

- **Custom Behavior**: Operators can be redefined to perform specific actions for user-defined types.
- **Syntax Enhancement**: Allows for more natural and readable code when working with custom types.
- **Type-Specific Operations**: Enables the implementation of operations that are meaningful for particular classes or structures.

#### Syntax for Operator Overloading

Operators can be overloaded using either member functions or non-member functions (often declared as `friend` functions).

##### Member Function Syntax

```cpp
class MyClass {
public:
    MyClass operator+(const MyClass& other) const {
        // Implementation
    }
};
```

##### Non-member Function Syntax

```cpp
class MyClass {
    // Class definition
};

MyClass operator+(const MyClass& lhs, const MyClass& rhs) {
    // Implementation
}
```

#### Commonly Overloaded Operators

- Arithmetic operators (`+`, `-`, `*`, `/`, etc.)
- Comparison operators (`==`, `!=`, `<`, `>`, etc.)
- Assignment operator (`=`)
- Stream insertion and extraction operators (`<<`, `>>`)
- Increment and decrement operators (`++`, `--`)
- Subscript operator (`[]`)

#### Best Practices

1. **Maintain Intuitive Behavior**: Overloaded operators should behave consistently with their built-in counterparts.
2. **Preserve Semantics**: The meaning of the operator should remain clear and logical.
3. **Consider Efficiency**: Implement overloaded operators efficiently, especially for frequently used operations.
4. **Use Sparingly**: Overload operators only when it significantly improves code readability and maintainability.
5. **Document Thoroughly**: Clearly document the behavior of overloaded operators, especially if it deviates from standard expectations.

#### Code Example: Overloading the Addition Operator

```cpp
class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex a(1, 2), b(3, 4);
    Complex c = a + b;  // Uses overloaded operator+
    return 0;
}
```

#### Limitations and Considerations

- **Cannot Create New Operators**: Only existing operators can be overloaded.
- **Precedence and Arity**: The precedence and number of operands of an operator cannot be changed.
- **Cannot Overload for Built-in Types**: Operators for fundamental types (like `int`, `float`) cannot be overloaded.
- **Some Operators Cannot Be Overloaded**: Operators like `.`, `::`, `?:`, and `sizeof` cannot be overloaded.

* * *

## Memory Management and Pointers

* * *


<div class="page"/>

### 11. What is *dynamic memory allocation* in *C++*?

**Dynamic memory allocation** in C++ allows for memory management during program execution. Unlike automatic and static storage durations, dynamic allocation lets you explicitly control an object’s lifetime, size, and location in the program’s memory.

#### Key Concepts

##### Heap

Dynamic memory is allocated from the **heap**, a large pool of memory that exists throughout the program’s runtime. Unlike the stack, which has a fixed and more limited size, the heap can grow and shrink as needed.

##### `new` and `delete` Operators

The operators `new` and `delete` are used for dynamic memory management:

- `new` allocates memory for a single object or an array of objects
- `delete` releases this memory when it’s no longer needed, ensuring that the object’s destructor is called

##### Smart Pointers

Introduced in C++11, smart pointers provide a safer and more convenient way to manage dynamic memory:

- `std::unique_ptr`: Ensures a single owner for the allocated object
- `std::shared_ptr`: Allows for multiple owners, using a control block to track the object’s lifetime
- `std::weak_ptr`: Non-owning “weak” reference to an object managed by `std::shared_ptr`

#### Code Example: Using `new` and `delete`

```cpp
#include <iostream>

class DynamicMemoryExample {
public:
    DynamicMemoryExample() { std::cout << "Constructor called!" << std::endl; }
    ~DynamicMemoryExample() { std::cout << "Destructor called!" << std::endl; }
};

int main() {
    int* intPtr = new int(42);  // Allocate memory for an integer on the heap
    std::cout << *intPtr << std::endl;
    delete intPtr;  // Release the memory

    DynamicMemoryExample* array = new DynamicMemoryExample[3];  // Allocate an array of objects
    delete[] array;  // Release the array

    return 0;
}
```

#### Code Example: Using Smart Pointers

```cpp
#include <iostream>
#include <memory>

class DynamicMemoryExample {
public:
    DynamicMemoryExample() { std::cout << "Constructor called!" << std::endl; }
    ~DynamicMemoryExample() { std::cout << "Destructor called!" << std::endl; }
};

int main() {
    auto uptr = std::make_unique<int>(42);  // Create a unique pointer to an integer
    std::cout << *uptr << std::endl;

    auto sptr = std::make_shared<DynamicMemoryExample>();  // Create a shared pointer to an object

    auto array = std::make_unique<DynamicMemoryExample[]>(3);  // Create a unique pointer to an array

    return 0;  // Smart pointers automatically release memory when they go out of scope
}
```

#### Memory Leaks and Best Practices

- Always pair `new` with `delete` and `new[]` with `delete[]`
- Prefer smart pointers over raw pointers to prevent memory leaks
- Use `std::make_unique` and `std::make_shared` for exception safety and efficiency
- Consider using container classes (e.g., `std::vector`) for dynamic arrays instead of manual allocation


<div class="page"/>

### 12. Explain the *difference* between ‘*new*’ and ‘*malloc()*’.

In C++, both `new` and `malloc()` are used for **dynamic memory allocation**, but they have different origins and characteristics.

#### Key Distinctions

1. **Origin**:

    - `new` is part of the C++ language.
    - `malloc()` stems from C.

    For modern C++ code, it’s generally preferred to use `new`, `new[]` for arrays, and smart pointers like `std::unique_ptr` or `std::shared_ptr` to manage dynamic memory.

2. **Return Type**:

    - `new` returns a pointer of the requested type. If memory allocation fails, it throws a `std::bad_alloc` exception (unless a custom handler is set).
    - `malloc()` returns a `void*` pointer. If allocation fails, it returns `nullptr`.
3. **Object Construction and Destruction**:

    - `new` allocates memory and calls the object’s constructor.
    - `malloc()` only allocates raw memory; it doesn’t invoke constructors.
    - `delete` calls the object’s destructor and then deallocates the memory.
    - `free()` only deallocates the memory without calling any destructors.
4. **Size Specification**:

    - `new` automatically deduces the size based on the type.
    - `malloc()` requires explicit size specification in bytes.
5. **Type Safety**:

    - `new` is type-safe and returns a pointer of the correct type.
    - `malloc()` returns a `void*` that needs to be explicitly cast to the desired type.

#### Code Example

```cpp
#include <iostream>
#include <cstdlib>
#include <new>

class Widget {
public:
    Widget(int val) : value(val) { std::cout << "Widget constructed\n"; }
    ~Widget() { std::cout << "Widget destructed\n"; }
private:
    int value;
};

int main() {
    // Using new
    Widget* w1 = new Widget(5);
    int* arr = new int[10];

    // Using malloc
    Widget* w2 = static_cast<Widget*>(std::malloc(sizeof(Widget)));

    // Proper construction with placement new
    if (w2) {
        new (w2) Widget(10);
    }

    // Cleanup
    delete w1;  // Calls destructor and deallocates
    delete[] arr;

    if (w2) {
        w2->~Widget();  // Manually call destructor
        std::free(w2);  // Deallocate memory
    }

    return 0;
}
```

#### Modern C++ Considerations

In modern C++, it’s recommended to use smart pointers and container classes instead of raw pointers and manual memory management:

```cpp
#include <memory>
#include <vector>

std::unique_ptr<Widget> w = std::make_unique<Widget>(5);
std::vector<int> vec(10);  // Dynamic array managed by vector
```


<div class="page"/>

### 13. What is a *memory leak* and how can it be prevented?

A **memory leak** occurs when a program allocates memory but fails to release it when it’s no longer needed. This leads to a gradual reduction in available memory, potentially causing performance issues or program crashes.

#### Common Causes of Memory Leaks

- **Missing Deallocation**: Failing to `delete` for every `new` or `free` for every `malloc`.
- **Complex Data Structures**: Forgetting to deallocate memory in structures like linked lists or trees.
- **Circular References**: In garbage-collected languages, circular references between objects can prevent memory reclamation.

#### Techniques to Prevent Memory Leaks

##### Manual Memory Management

- **RAII (Resource Acquisition Is Initialization)**: Allocate resources in the constructor and release them in the destructor.
- **Smart Pointers**: Use `std::unique_ptr`, `std::shared_ptr`, or `std::weak_ptr` from the `<memory>` header in C++.

##### Automatic Memory Management

- **Garbage Collection**: Languages with automatic garbage collection reduce the need for manual memory management.

#### Best Practices

- **Use Stack Allocation**: Prefer stack-allocated objects when their lifetime aligns with the scope.
- **Prefer Smart Pointers**: Automate memory management to reduce leak likelihood.
- **Clear Ownership**: Establish which part of the code is responsible for deallocation.

#### Code Example: Memory Management Techniques

```cpp
#include <iostream>
#include <memory>

class MyResource {
public:
    MyResource() { std::cout << "Resource acquired!\n"; }
    ~MyResource() { std::cout << "Resource released!\n"; }
};

void manualManagement() {
    MyResource* resource = new MyResource();
    // Uncommenting the next line would ensure manual resource release
    // delete resource;
}

void raii() {
    MyResource resource;  // Automatically released when out of scope
}

void smartPointers() {
    auto resource = std::make_unique<MyResource>();
    // Automatically released when unique_ptr goes out of scope
}

int main() {
    std::cout << "RAII:\n";
    raii();

    std::cout << "\nUnique Pointers:\n";
    smartPointers();

    std::cout << "\nManual Memory Management:\n";
    manualManagement();

    return 0;
}
```


<div class="page"/>

### 14. What is a *dangling pointer*?

A **dangling pointer** is a pointer that references a memory location that has been **deallocated** or is no longer valid. This situation typically occurs when the memory to which the pointer was pointing has been `free`d or `delete`d, or when the object it was referencing has gone out of scope.

#### Causes of Dangling Pointers

1. **Premature Deallocation**: Memory is freed or deleted while pointers to it still exist.
2. **Returning Local References**: Returning a reference or pointer to a local variable that goes out of scope.
3. **Use-After-Free**: Accessing memory through a pointer after it has been deallocated.

#### Avoiding Dangling Pointers

1. **Smart Pointers**: Utilize `std::unique_ptr`, `std::shared_ptr`, or `std::weak_ptr` from the C++11 standard library to manage memory automatically.
2. **Nullify After Deallocation**: Set pointers to `nullptr` after using `delete`.
3. **RAII (Resource Acquisition Is Initialization)**: Use objects with well-defined lifetimes to manage resources.
4. **Careful Scope Management**: Be mindful of object lifetimes, especially when using raw pointers.

#### Code Example: Dangling Pointers

```cpp
#include <iostream>
#include <memory>

void danglingPointerExample() {
    int* rawPtr = new int(5);
    delete rawPtr;
    // rawPtr is now dangling
    // *rawPtr; // Undefined behavior

    // Better approach using smart pointers
    std::unique_ptr<int> smartPtr = std::make_unique<int>(5);
    // No need to manually delete, memory is automatically managed
}

int* returnDanglingPointer() {
    int localVar = 10;
    return &localVar; // Dangling pointer: localVar goes out of scope
}

int main() {
    danglingPointerExample();

    int* danglingPtr = returnDanglingPointer();
    // *danglingPtr; // Undefined behavior

    return 0;
}
```

#### Modern C++ Best Practices

1. **Use Smart Pointers**: Prefer `std::unique_ptr` for exclusive ownership and `std::shared_ptr` for shared ownership.
2. **Avoid Raw Pointers**: When possible, use references or smart pointers instead of raw pointers.
3. **Consider `std::optional`**: For functions that might not return a value, use `std::optional` (C++17) instead of nullable pointers.
4. **Use Static Analysis Tools**: Employ tools like Clang Static Analyzer or Cppcheck to detect potential dangling pointer issues.


<div class="page"/>

### 15. Explain the concept of *smart pointers* in *C++*.

**Smart pointers** in C++ are objects designed for managing **dynamic memory** in a more automated and safe way than traditional raw pointers.

They offer several advantages:

- **Automated Memory Management**: Simplify memory cleanup using well-defined strategies like reference counting or ownership.
- **Improved Safety**: Minimize risks of memory leaks, dangling pointers, and double deletions.
- **Scoped Ownership**: Establish a clear ownership hierarchy, making it easier to determine which part of the code is responsible for managing the memory.

#### Types of Smart Pointers

C++ provides three primary types of smart pointers, all of which are defined in the `<memory>` header:

1. **`std::unique_ptr`**
2. **`std::shared_ptr`**
3. **`std::weak_ptr`**

##### Unique Pointers (`std::unique_ptr`)

- Used for **exclusive ownership** of a dynamically allocated object.
- The object is automatically destroyed when the unique pointer goes out of scope.
- Efficient and lightweight.
- Not copyable, but can be moved.

```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> uptr = std::make_unique<int>(5);
    // std::unique_ptr<int> uptr2 = uptr; // Error: unique_ptr is not copyable
    std::cout << *uptr << std::endl;
    // Memory is automatically released when uptr goes out of scope
    return 0;
}
```

##### Shared Pointers (`std::shared_ptr`)

- Enable **multiple pointers** to own the same object.
- The object is destroyed when the last shared pointer owning it is destroyed.
- Thread-safe reference counting, but this adds some overhead.
- Can lead to **circular references** if not used carefully.

```cpp
#include <memory>
#include <iostream>

struct Node {
    std::shared_ptr<Node> next;
};

int main() {
    std::shared_ptr<int> sptr = std::make_shared<int>(10);
    {
        std::shared_ptr<int> anotherSptr = sptr;
        std::cout << *anotherSptr << std::endl;
    }
    // The referenced int is still alive

    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();
    node1->next = node2;
    node2->next = node1;  // Creates a circular reference

    // Node objects are still in memory due to the circular reference
    return 0;
}
```

##### Weak Pointers (`std::weak_ptr`)

- Designed to **observe** an object owned by a shared pointer without extending its lifetime.
- Resolves to a shared pointer or an expired state, allowing you to check if the object still exists.
- Helps break circular references in `std::shared_ptr`.

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sPtr = std::make_shared<int>(42);
    std::weak_ptr<int> wPtr = sPtr;

    if (auto locked = wPtr.lock()) {
        std::cout << "Value: " << *locked << std::endl;
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    sPtr.reset();  // Release the resource

    if (auto locked = wPtr.lock()) {
        std::cout << "Value: " << *locked << std::endl;
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    return 0;
}
```

#### Best Practices

- Use `std::make_unique` and `std::make_shared` for creating smart pointers (since C++14).
- Prefer `std::unique_ptr` when single ownership is sufficient.
- Use `std::shared_ptr` when multiple ownership is required.
- Employ `std::weak_ptr` to break circular references and for temporary observation of shared objects.
- Avoid mixing raw pointers and smart pointers for the same resource.


<div class="page"/>

### 16. What is the *difference* between *unique_ptr*, *shared_ptr*, and *weak_ptr*?

Smart pointers in C++ are crucial for **memory management** and preventing issues like **dangling pointers** and **memory leaks**. The three main types of smart pointers are `unique_ptr`, `shared_ptr`, and `weak_ptr`, each serving different purposes.

#### unique_ptr

- Implements **exclusive ownership** semantics. Only one `unique_ptr` can own a resource at a time.
- Supports **move semantics** for transferring ownership.
- Automatically deletes the managed object when the `unique_ptr` goes out of scope.
- Ideal for scenarios where sharing is not needed and performance is critical.

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(42);
// ptr is the sole owner of the int
```

#### shared_ptr

- Implements **shared ownership** semantics. Multiple `shared_ptr`s can own the same resource.
- Uses **reference counting** to track the number of owners.
- Automatically deletes the managed object when the last `shared_ptr` owning it is destroyed.
- Provides **thread-safe** reference counting, but at a performance cost.

```cpp
std::shared_ptr<int> ptr1 = std::make_shared<int>(42);
std::shared_ptr<int> ptr2 = ptr1; // Both ptr1 and ptr2 share ownership
```

#### weak_ptr

- Holds a **non-owning** (“weak”) reference to an object managed by `shared_ptr`.
- Used to **break circular references** that can occur with `shared_ptr`.
- Does not affect the reference count of the `shared_ptr`.
- Can be converted to a `shared_ptr` to regain temporary ownership.

```cpp
std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;

if (auto locked = weak.lock()) {
    // Use the locked shared_ptr
} else {
    // Object has been deleted
}
```

#### Code Example: Breaking Circular References

Here’s an example demonstrating how `weak_ptr` can break circular references:

```cpp
#include <memory>
#include <iostream>

class B;

class A {
public:
    std::shared_ptr<B> b_ptr;
    A() { std::cout << "A constructed\n"; }
    ~A() { std::cout << "A destructed\n"; }
};

class B {
public:
    std::weak_ptr<A> a_ptr;  // Using weak_ptr to break the cycle
    B() { std::cout << "B constructed\n"; }
    ~B() { std::cout << "B destructed\n"; }
};

int main() {
    {
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->b_ptr = b;
        b->a_ptr = a;
    }  // Both a and b are properly destructed here
    std::cout << "End of scope\n";
    return 0;
}
```


<div class="page"/>

### 17. How does *reference counting* work in *shared_ptr*?

**Reference counting** in `std::shared_ptr` is a mechanism that tracks the number of smart pointers referencing a particular object. When this count reaches zero, the object is automatically deallocated.

#### Key Mechanisms

##### Shared Ownership

`std::shared_ptr` allows multiple pointers to share ownership of the same object. This is achieved through a dedicated control block, often referred to as the “shared count”.

##### Atomic Operations

To ensure thread safety, `shared_ptr` operations involving the reference count are atomic. This means they are either completed entirely or not started at all, using CPU-specific instructions to guarantee atomicity.

##### Separate Control Block

The shared count is maintained separately from individual `shared_ptr` instances. This separation allows for efficient management of the reference count, ensuring that operations with different `shared_ptr` objects remain synchronized.

##### Efficient Bookkeeping

The control block is a lightweight structure containing:

- The reference count
- A pointer to the managed object
- A pointer to the deleter (if custom)
- A weak count (for `std::weak_ptr` support)

#### Code Example

```cpp
#include <memory>
#include <iostream>

int main() {
    auto sp1 = std::make_shared<int>(42);
    std::cout << "Reference count: " << sp1.use_count() << std::endl; // Output: 1

    {
        auto sp2 = sp1;
        std::cout << "Reference count: " << sp1.use_count() << std::endl; // Output: 2
    } // sp2 goes out of scope, count decrements

    std::cout << "Reference count: " << sp1.use_count() << std::endl; // Output: 1

    sp1.reset(); // Resets sp1, count becomes 0, object is deallocated

    return 0;
}
```

#### Performance Considerations

- **Creation**: Using `std::make_shared` is generally more efficient than creating a `shared_ptr` with `new`, as it allocates the object and control block in a single operation.
- **Copy/Move**: Copying a `shared_ptr` is relatively cheap, involving only incrementing the reference count. Moving a `shared_ptr` is even cheaper, as it doesn’t affect the count.
- **Destruction**: When the last `shared_ptr` is destroyed, it deallocates both the object and the control block.

#### Thread Safety

While the reference counting operations are thread-safe, the object pointed to by `shared_ptr` is not automatically protected from race conditions. Proper synchronization mechanisms should be used when accessing the shared object from multiple threads.


<div class="page"/>

### 18. What is the *rule of three* in *C++*?

The **Rule of Three** in C++ is a guideline for managing **dynamic resources** in classes that have user-defined special member functions. It states that if a class defines any of the following three special member functions, it should probably explicitly define all three:

1. **Destructor**
2. **Copy constructor**
3. **Copy assignment operator**

#### Core Concepts

- **Resource Management**: Ensures proper handling of dynamically allocated resources.
- **Consistency**: Provides a coherent approach to object lifecycle management.
- **Exception Safety**: Helps prevent resource leaks in case of exceptions.

#### Modern Update: Rule of Five

With C++11 and beyond, the guideline has evolved into the **Rule of Five**, which includes two additional special member functions:

4. **Move constructor**
5. **Move assignment operator**

These additions leverage **move semantics** to optimize resource transfer and improve performance.

#### Benefits of Using Smart Pointers

- **Automatic Resource Management**: Smart pointers like `std::unique_ptr` and `std::shared_ptr` handle resource cleanup automatically.
- **RAII Compliance**: Aligns with the Resource Acquisition Is Initialization principle.
- **Exception Safety**: Provides strong exception guarantees for resource management.

#### Code Example: Rule of Three Implementation

```cpp
class Resource {
private:
    int* data;

public:
    // Constructor
    Resource(int value) : data(new int(value)) {}

    // Destructor
    ~Resource() { delete data; }

    // Copy constructor
    Resource(const Resource& other) : data(new int(*other.data)) {}

    // Copy assignment operator
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }
};
```

#### Code Example: Rule of Five Implementation

```cpp
class ModernResource {
private:
    int* data;

public:
    // Constructor
    ModernResource(int value) : data(new int(value)) {}

    // Destructor
    ~ModernResource() { delete data; }

    // Copy constructor
    ModernResource(const ModernResource& other) : data(new int(*other.data)) {}

    // Copy assignment operator
    ModernResource& operator=(const ModernResource& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move constructor
    ModernResource(ModernResource&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    ModernResource& operator=(ModernResource&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }
};
```

#### Using Smart Pointers

Modern C++ encourages the use of smart pointers to simplify resource management:

```cpp
#include <memory>

class SmartResource {
private:
    std::unique_ptr<int> data;

public:
    SmartResource(int value) : data(std::make_unique<int>(value)) {}

    // Copy operations
    SmartResource(const SmartResource& other) : data(std::make_unique<int>(*other.data)) {}
    SmartResource& operator=(const SmartResource& other) {
        if (this != &other) {
            data = std::make_unique<int>(*other.data);
        }
        return *this;
    }

    // Move operations are automatically generated and work correctly
};
```

By using `std::unique_ptr`, we adhere to the Rule of Five without explicitly defining all five special member functions. The move operations are automatically generated and work correctly, while the copy operations are explicitly defined to perform deep copies.


<div class="page"/>

### 19. What is the *rule of five* in *C++*?

The **Rule of Five** in C++ is a set of guidelines for proper resource management, particularly when dealing with dynamic memory. It establishes the relationship between five special member functions of a class:

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

Adhering to the Rule of Five ensures that when a class directly manages a resource (like dynamic memory), instances of the class properly handle the resource’s ownership, avoiding issues like memory leaks or double deletions.

#### The Rule of Five: Implementation and Example

Let’s implement a simple class following the Rule of Five:

```cpp
class MyClass {
private:
    int* data;
    size_t size;

public:
    // Constructor
    MyClass(size_t s) : data(new int[s]), size(s) {}

    // Destructor
    ~MyClass() {
        delete[] data;
    }

    // Copy Constructor
    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + size, data);
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            MyClass temp(other);
            std::swap(data, temp.data);
            std::swap(size, temp.size);
        }
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};
```

#### Key Points

1. **Destructor**: Frees the dynamically allocated memory.
2. **Copy Constructor**: Creates a deep copy of the object.
3. **Copy Assignment Operator**: Performs a deep copy, using the copy-and-swap idiom for exception safety.
4. **Move Constructor**: Transfers ownership of resources from the source object.
5. **Move Assignment Operator**: Transfers ownership, ensuring proper cleanup of existing resources.

#### Modern C++ Considerations

- In C++11 and later, you can use `= default` to explicitly request compiler-generated versions of these special functions if the default behavior is sufficient.
- Use `= delete` to explicitly forbid the compiler from generating these functions.
- Consider using smart pointers (like `std::unique_ptr` or `std::shared_ptr`) to manage dynamic memory, which can simplify resource management and potentially reduce the need for explicit implementation of the Rule of Five.
- The Rule of Zero: If you can avoid defining any of these special member functions, you should do so. This often leads to more maintainable and less error-prone code.

#### Example with Smart Pointers

```cpp
#include <memory>
#include <vector>

class ModernClass {
private:
    std::unique_ptr<int[]> data;
    size_t size;

public:
    ModernClass(size_t s) : data(std::make_unique<int[]>(s)), size(s) {}

    // Rule of Zero: No need to explicitly declare special member functions
};
```

In this modern approach, the `std::unique_ptr` handles the memory management, allowing us to follow the Rule of Zero and avoid explicitly implementing the Rule of Five.


<div class="page"/>

### 20. Explain *move semantics* in *C++*.

**Move semantics** in C++ enables more efficient handling of data by allowing the transfer of **rvalue** resources like temporary objects, literals, or explicitly moved objects. This feature, introduced in C++11, significantly improves performance by reducing unnecessary copying of objects.

#### Rvalues and Lvalues

In C++, an **lvalue** represents an object with an **identity** and **persisting state**, like a named variable. An **rvalue** is a temporary entity without a named identity, often a temporary or literal value.

#### The Problem

Consider a function like `std::vector<int> createIntVector();` that returns a `std::vector<int>`. Without move semantics, assigning this to another `std::vector<int>`, e.g., `auto vec = createIntVector();`, would result in a deep copy of the entire vector, leading to unnecessary overhead.

#### The Solution

Move semantics addresses this issue through:

##### Move Constructor

A special constructor that transforms an rvalue into an lvalue, making its content accessible without copying. It’s declared as:

```cpp
ClassName(ClassName&& other) noexcept;
```

##### Move Assignment Operator

Similar to the move constructor, it allows objects to **take ownership** of another rvalue’s resources. It’s declared as:

```cpp
ClassName& operator=(ClassName&& other) noexcept;
```

##### Utility Functions

The `<utility>` header provides functions like `std::move` to convert lvalues into rvalues, facilitating resource transfer.

#### Code Example: Move Constructor

```cpp
#include <iostream>
#include <utility>

class MyVector {
private:
    int* data;
    size_t size;

public:
    // Normal Constructor
    MyVector(size_t s) : size(s), data(new int[s]) {
        std::cout << "Normal Constructor\n";
    }

    // Move Constructor
    MyVector(MyVector&& other) noexcept
        : data(std::exchange(other.data, nullptr))
        , size(std::exchange(other.size, 0))
    {
        std::cout << "Move Constructor\n";
    }

    // Destructor
    ~MyVector() {
        delete[] data;
        std::cout << "Destructor\n";
    }
};

int main() {
    MyVector v1(5);  // Normal Constructor
    MyVector v2 = std::move(v1);  // Move Constructor

    return 0;
}
```

In this example, `MyVector` implements a move constructor to demonstrate the transfer of its dynamically-allocated array. Note the use of `std::exchange`, which assigns a new value to a variable and returns its old value.

#### Code Example: Move Assignment Operator

```cpp
#include <iostream>
#include <utility>

class MyVector {
private:
    int* data;
    size_t size;

public:
    // Normal Constructor
    MyVector(size_t s) : size(s), data(new int[s]) {
        std::cout << "Normal Constructor\n";
    }

    // Move Constructor
    MyVector(MyVector&& other) noexcept
        : data(std::exchange(other.data, nullptr))
        , size(std::exchange(other.size, 0))
    {
        std::cout << "Move Constructor\n";
    }

    // Move Assignment Operator
    MyVector& operator=(MyVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = std::exchange(other.data, nullptr);
            size = std::exchange(other.size, 0);
        }
        std::cout << "Move Assignment Operator\n";
        return *this;
    }

    // Destructor
    ~MyVector() {
        delete[] data;
        std::cout << "Destructor\n";
    }
};

int main() {
    MyVector v1(3);  // Normal Constructor
    MyVector v2(2);  // Normal Constructor

    v2 = std::move(v1);  // Move Assignment

    return 0;
}
```

Here, `MyVector` overloads the move assignment operator to showcase efficient transfer of its dynamically-allocated data. The use of `std::exchange` ensures exception safety and clear ownership transfer.

* * *

## Object-Oriented Programming Concepts

* * *


<div class="page"/>

### 21. What is *inheritance* in *C++*? Explain its *types*.

**Inheritance** in C++ is a fundamental object-oriented programming concept that allows a new class (derived class) to be created based on an existing class (base class). This mechanism facilitates code reusability and establishes an “is-a” relationship between classes.

#### Types of Inheritance

C++ supports several types of inheritance:

##### 1\. Single Inheritance

A derived class inherits from a single base class.

```cpp
class Base {
    // Base class members
};

class Derived : public Base {
    // Derived class members
};
```

##### 2\. Multiple Inheritance

A derived class inherits from two or more base classes.

```cpp
class Base1 {
    // Base1 class members
};

class Base2 {
    // Base2 class members
};

class Derived : public Base1, public Base2 {
    // Derived class members
};
```

##### 3\. Multilevel Inheritance

A derived class becomes a base class for another derived class.

```cpp
class Grandparent {
    // Grandparent class members
};

class Parent : public Grandparent {
    // Parent class members
};

class Child : public Parent {
    // Child class members
};
```

##### 4\. Hierarchical Inheritance

Multiple derived classes inherit from a single base class.

```cpp
class Base {
    // Base class members
};

class Derived1 : public Base {
    // Derived1 class members
};

class Derived2 : public Base {
    // Derived2 class members
};
```

##### 5\. Virtual Inheritance

Used to prevent multiple instances of a base class in diamond inheritance scenarios.

```cpp
class Base {
    // Base class members
};

class Derived1 : virtual public Base {
    // Derived1 class members
};

class Derived2 : virtual public Base {
    // Derived2 class members
};

class FinalDerived : public Derived1, public Derived2 {
    // FinalDerived class members
};
```

#### Inheritance Access Specifiers

C++ provides three inheritance access specifiers:

1. **`public`**: Public and protected members of the base class become public and protected members of the derived class, respectively.

2. **`protected`**: Public and protected members of the base class become protected members of the derived class.

3. **`private`**: Public and protected members of the base class become private members of the derived class.

```cpp
class Base {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class PublicDerived : public Base {
    // x is public, y is protected, z is not accessible
};

class ProtectedDerived : protected Base {
    // x and y are protected, z is not accessible
};

class PrivateDerived : private Base {
    // x and y are private, z is not accessible
};
```

The choice of inheritance type and access specifier depends on the desired level of encapsulation and the relationship between the base and derived classes.


<div class="page"/>

### 22. What is *polymorphism* and how is it implemented in *C++*?

**Polymorphism** in C++ allows objects of different data types to be treated as if they are of the same data type, facilitating **code reusability** and **separation of concerns**.

#### Types of Polymorphism in C++

C++ supports two main types of polymorphism:

1. **Compile-time Polymorphism**: Achieved through function overloading and operator overloading.
2. **Run-time Polymorphism**: Achieved using virtual functions and inheritance.

#### Key Mechanism for Run-Time Polymorphism: Virtual Functions

- C++ implements run-time polymorphism mainly through the use of **virtual functions**.
- These functions are declared in a base class and can be overridden in derived classes.
- The function call is resolved at run time, based on the type of object being referred to.

##### Code Example: Virtual Functions

```cpp
#include <iostream>
#include <memory>

class Animal {
public:
    virtual void speak() const {
        std::cout << "The animal speaks!\n";
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "The dog barks!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "The cat meows!\n";
    }
};

int main() {
    std::unique_ptr<Animal> myDog = std::make_unique<Dog>();
    std::unique_ptr<Animal> myCat = std::make_unique<Cat>();

    myDog->speak();  // Output: The dog barks!
    myCat->speak();  // Output: The cat meows!

    return 0;
}
```

#### Mechanism Behind Virtual Functions: vTable and vPtr

- C++ uses a **virtual table (vtable)** for every class that has at least one virtual function.
- This table is an array of function pointers. Each class with virtual functions has its own vtable.
- The **vptr** (virtual pointer) is a hidden member of objects with virtual functions. It points to the vtable of the corresponding class.
- When a virtual function is called, the function pointer from the vtable of the object’s actual class is dereferenced and executed.

#### Performance Considerations

- Virtual function calls have a small overhead due to the vtable lookup.
- However, modern compilers and hardware architectures are optimized for virtual function performance, and any differences in speed are generally negligible for most applications.

#### Recommendations for Virtual Functions

- Use virtual functions when designing a **base class** that defines an interface to be implemented by derived classes.
- They are crucial for implementing **polymorphic behavior** and **abstract base classes**.

#### Modern C++ Alternatives and Enhancements

- **std::variant** and **std::visit** (C++17) provide compile-time polymorphism for heterogeneous types.
- **Concepts** (C++20) allow for compile-time polymorphism with improved type checking.
- **Coroutines** (C++20) offer a new way to write asynchronous and generator-like code, which can be seen as a form of control flow polymorphism.

#### Best Practices

- Always declare destructors of base classes as `virtual` to ensure proper cleanup of derived objects.
- Use `override` keyword (C++11 onwards) when overriding virtual functions to catch errors at compile-time.
- Consider using `final` specifier for classes or virtual functions that should not be inherited or overridden further.


<div class="page"/>

### 23. Explain the concept of *virtual functions* in *C++*.

**Virtual functions** are a fundamental concept in C++ that enable **polymorphic behavior** through a mechanism known as **dynamic dispatch**. They allow the correct function to be called based on the actual object type rather than the type of the pointer or reference used to access it.

#### How Virtual Functions Work

##### Virtual Table (vtable)

- Each class with one or more virtual functions contains a hidden pointer called the **vpointer**.
- The vpointer points to a **virtual table** (vtable), which is a table of function pointers.
- The vtable contains addresses of the virtual functions for that class.

##### Dynamic Dispatch

- When a virtual function is called, the program uses the vtable to determine which function to execute at runtime.
- This process is known as **late binding** or **dynamic binding**.

#### Key Benefits

1. **Polymorphism**: Enables objects of derived classes to be treated as objects of the base class.
2. **Abstraction**: Facilitates the creation of abstract base classes, defining interfaces without implementation.
3. **Flexibility**: Allows for easy extension of existing code without modifying the base class.

#### Code Example

```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "The animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "The dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "The cat meows" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // Output: The dog barks
    animal2->makeSound();  // Output: The cat meows

    delete animal1;
    delete animal2;
    return 0;
}
```

#### Performance Considerations

- **Slight Overhead**: Virtual function calls involve an extra level of indirection, which can introduce a minor performance cost.
- **Memory Usage**: Classes with virtual functions have an additional pointer (vpointer), increasing their size.
- **Optimization**: Modern compilers often optimize virtual function calls, minimizing performance impact in many scenarios.

#### Modern C++ Features

- **`override` Specifier**: Introduced in C++11, it explicitly indicates that a function is meant to override a virtual function from a base class.
- **`final` Specifier**: Also from C++11, it prevents further derivation of a class or overriding of a virtual function.

#### Best Practices

1. Use `virtual` for base class destructors when inheritance is involved.
2. Employ the `override` keyword for derived class functions to catch errors and improve readability.
3. Consider the performance implications in performance-critical code sections.


<div class="page"/>

### 24. What is a *pure virtual function*?

A **pure virtual function** in C++ is a virtual member function of a base class that has no implementation and is meant to be overridden by derived classes. It’s a key feature for implementing abstract classes and interfaces in C++.

#### Syntax

To declare a pure virtual function, use the `virtual` keyword and assign it to 0:

```cpp
class Base {
public:
    virtual void pureVirtualFunction() = 0;
};
```

#### Key Characteristics

1. **No Implementation**: Pure virtual functions have no implementation in the base class.
2. **Abstract Class**: A class with at least one pure virtual function becomes an abstract class.
3. **Mandatory Override**: Derived classes must override all pure virtual functions to be instantiable.

#### Use Cases

1. **Defining Interfaces**: Create abstract base classes that define a contract for derived classes.
2. **Polymorphism**: Enable runtime polymorphism through abstract base class pointers.
3. **Template Method Pattern**: Define a skeleton of an algorithm in the base class, leaving specific steps to be implemented by subclasses.

#### Code Example

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        std::cout << "Drawing a circle\n";
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void draw() const override {
        std::cout << "Drawing a rectangle\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5));
    shapes.push_back(std::make_unique<Rectangle>(4, 6));

    for (const auto& shape : shapes) {
        shape->draw();
        std::cout << "Area: " << shape->area() << std::endl;
    }

    return 0;
}
```

#### Important Notes

- Abstract classes (with pure virtual functions) cannot be instantiated directly.
- If a derived class doesn’t override all pure virtual functions, it remains abstract.
- Pure virtual functions can have a default implementation, but the `= 0` is still required to make it pure virtual.
- Virtual destructors are crucial in base classes to ensure proper cleanup of derived objects.


<div class="page"/>

### 25. What is an *abstract class* in *C++*?

In **C++**, an **abstract class** is a class designed primarily to serve as a **base class**. It supports **inheritance** and **polymorphism** through **virtual functions** but cannot be instantiated on its own. Abstract classes are useful for defining a general interface for derived classes without providing specific implementations for all methods.

#### Key Features

1. **Virtual Functions**: Abstract classes declare one or more virtual functions, which act as placeholders defining an interface without concrete implementation.

2. **Pure Virtual Functions**: These are virtual functions with no implementation in the base class, declared using the “pure specifier” `= 0`. Classes with pure virtual functions cannot be instantiated unless all such functions are overridden in derived classes.

3. **Constructor and Destructor**: Abstract classes can have constructors and destructors, typically used for internal setup and cleanup.

#### Code Example: Abstract Class

```cpp
#include <iostream>

class Shape {
public:
    virtual ~Shape() = default; // Virtual destructor

    virtual double area() const = 0; // Pure virtual function
    virtual double perimeter() const = 0;

    virtual void printType() const {
        std::cout << "This is a Shape" << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double area() const override {
        return std::numbers::pi * radius * radius;
    }

    double perimeter() const override {
        return 2 * std::numbers::pi * radius;
    }

    void printType() const override {
        std::cout << "This is a Circle" << std::endl;
    }
};

int main() {
    // Shape myShape; // Error: Cannot instantiate abstract class

    Circle c(5);
    std::cout << "Area: " << c.area() << std::endl;
    std::cout << "Perimeter: " << c.perimeter() << std::endl;
    c.printType();

    Shape* shape_ptr = &c; // Pointer to base class
    shape_ptr->printType(); // Calls Circle's printType()

    return 0;
}
```

#### Additional Notes

- Abstract classes can have **non-pure virtual functions** with default implementations.
- The size of an abstract class is not zero, but it’s implementation-defined.
- Using `final` keyword prevents further inheritance: `class DerivedClass final : public BaseClass {...};`
- Since C++11, use `override` keyword to explicitly mark overridden virtual functions.
- Modern C++ (C++11 and later) prefers `= default` for destructors instead of empty implementations.
- Use `std::numbers::pi` (C++20) for a more precise pi value, or `M_PI` from `<cmath>` in earlier versions.


<div class="page"/>

### 26. Explain the *diamond problem* in *multiple inheritance* and how to solve it.

The **diamond problem** is a classic issue in C++ that arises from **multiple inheritance** when a derived class inherits from two base classes that share a common ancestor. This situation creates ambiguity and potential data duplication.

#### Visual Representation

![Diamond Problem](data:image/jpeg;base64,/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAsHCAoIBwsKCQoMDAsNEBsSEA8PECEYGRQbJyMpKScjJiUsMT81LC47LyUmNko3O0FDRkdGKjRNUkxEUj9FRkP/2wBDAQwMDBAOECASEiBDLSYtQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0NDQ0P/wgARCAWYCcoDAREAAhEBAxEB/8QAHAABAAMBAQEBAQAAAAAAAAAAAAEGBwUEAgMI/8QAGAEBAQEBAQAAAAAAAAAAAAAAAAEDAgT/2gAMAwEAAhADEAAAANcAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB5bypAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAC2I9Mv2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA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AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAzT1YXfPr1SgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACHGa686r5fSAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBn/ox4u2f2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEg6WWmj+bcAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAD//xAA9EAAABQMDAQUHBAIBAwMFAAAAAQMEBQIG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)

#### Key Issues

1. **Ambiguity**: Uncertainty about which version of a member (method or attribute) should be used in the derived class.
2. **Data Duplication**: Multiple copies of the common ancestor’s attributes in the derived class.

#### Code Example: Diamond Problem

```cpp
#include <iostream>

class Base {
public:
    void display() { std::cout << "Display from Base" << std::endl; }
};

class BaseA : public Base {};
class BaseB : public Base {};

class Derived : public BaseA, public BaseB {};

int main() {
    Derived d;
    // d.display();  // Compilation error: ambiguous call
    return 0;
}
```

#### Solutions to the Diamond Problem

##### 1\. Virtual Inheritance

Use the `virtual` keyword when deriving from the common base class:

```cpp
class BaseA : virtual public Base {};
class BaseB : virtual public Base {};

class Derived : public BaseA, public BaseB {};
```

This ensures only one instance of the base class exists in the derived class.

##### 2\. Explicit Qualification

Specify which base class’s member to use:

```cpp
d.BaseA::display();  // Calls display() from BaseA
```

##### 3\. Virtual Functions

Use virtual functions in the base class for proper runtime polymorphism:

```cpp
class Base {
public:
    virtual void display() { std::cout << "Display from Base" << std::endl; }
};
```

##### 4\. Override in Derived Class

Provide a new implementation in the derived class:

```cpp
class Derived : public BaseA, public BaseB {
public:
    void display() override { std::cout << "Display from Derived" << std::endl; }
};
```

#### Constructor Considerations with Virtual Inheritance

When using virtual inheritance, ensure proper construction of the virtual base:

```cpp
class Derived : public BaseA, public BaseB {
public:
    Derived() : Base(), BaseA(), BaseB() {}
};
```

#### Modern C++ Considerations

- C++11 and later versions provide the `override` keyword to explicitly mark overriding functions.
- Use `= default` for default constructors and destructors when possible.
- Consider alternatives to multiple inheritance, such as composition or interfaces (pure abstract classes), when appropriate.


<div class="page"/>

### 27. What is *function hiding* in *C++*?

**Function hiding** in C++ occurs when a derived class declares a function with the same name as a function in the base class, but with a different signature. This leads to the base class function being hidden in the derived class, rather than being overloaded or overridden.

##### Key Points:

- Function hiding can cause unexpected behavior and is often considered error-prone.
- It differs from function overriding, which requires the same name and signature.
- Hidden functions are not accessible directly through the derived class object.

#### Example of Function Hiding

```cpp
class Base {
public:
    void display() {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display(std::string message) {
        std::cout << "Derived display: " << message << std::endl;
    }
};

int main() {
    Derived d;
    d.display("Hello");  // Works fine
    // d.display();  // Error: Base::display() is hidden
}
```

#### Preventing Function Hiding

##### 1\. Using the `override` Keyword

The `override` specifier ensures that a function in the derived class is intended to override a virtual function from the base class:

```cpp
class Base {
public:
    virtual void display() const {
        std::cout << "Base display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "Derived display" << std::endl;
    }
};
```

##### 2\. Using the `using` Declaration

The `using` declaration brings the base class function into the derived class’s scope:

```cpp
class Base {
public:
    void print(int x) {
        std::cout << "Printing int: " << x << std::endl;
    }
};

class Derived : public Base {
public:
    using Base::print;  // Brings Base::print into Derived's scope
    void print(double x) {
        std::cout << "Printing double: " << x << std::endl;
    }
};

int main() {
    Derived d;
    d.print(5);     // Calls Base::print(int)
    d.print(3.14);  // Calls Derived::print(double)
}
```

#### Best Practices

1. Use `virtual` for base class functions intended to be overridden.
2. Always use the `override` specifier in derived classes when overriding.
3. If you want to add overloads in a derived class, use the `using` declaration to bring base class functions into scope.
4. Be explicit about your intentions to avoid unintended function hiding.


<div class="page"/>

### 28. Explain the concept of *friend functions* and *classes*.

In C++, **friend functions** and **friend classes** are special constructs that allow controlled access to the `private` and `protected` members of a class.

#### Friend Functions

- **Definition**: Functions declared within a class using the `friend` keyword but defined outside the class scope.
- **Accessibility**: Have direct access to the class’s `private` and `protected` members.
- **Usage**: Typically used when a function needs access to internal data of multiple classes.

#### Friend Classes

- **Definition**: A class declared as a friend within another class using the `friend` keyword.
- **Accessibility**: Grants full access to the `private` and `protected` members of the declaring class.
- **Usage**: Useful when two classes need to work closely together and share internal data.

#### Code Example: Friend Function

```cpp
#include <iostream>

class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    // Declare the friend function
    friend int calculateArea(const Rectangle& rect);
};

// Define the friend function
int calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;  // Direct access to private members
}

int main() {
    Rectangle rect(5, 3);
    std::cout << "Area: " << calculateArea(rect) << std::endl;
    return 0;
}
```

#### Code Example: Friend Class

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

    // Declare the friend class
    friend class BankManager;
};

class BankManager {
public:
    void displayAccountDetails(const BankAccount& account) {
        // Access private members of BankAccount
        std::cout << "Account: " << account.accountNumber 
                  << ", Balance: $" << account.balance << std::endl;
    }
};

int main() {
    BankAccount account("1234567890", 1000.0);
    BankManager manager;
    manager.displayAccountDetails(account);
    return 0;
}
```

#### Key Considerations

1. **Encapsulation**: While friends provide flexibility, overuse can break encapsulation. Use sparingly.
2. **Non-member functions**: Friend functions are not member functions of the class.
3. **Friendship is not mutual**: If class A is a friend of class B, B doesn’t automatically become a friend of A.
4. **Friendship is not inherited**: Derived classes don’t inherit friendship.
5. **C++20 update**: Introduced the ability to declare templated friend functions inside class templates.


<div class="page"/>

### 29. What is the *difference* between *composition* and *inheritance*?

Both **inheritance** and **composition** are fundamental concepts in Object-Oriented Programming (OOP) for establishing relationships between classes.

#### Inheritance

Inheritance establishes an **“is-a”** relationship, where a derived class (subclass) **is a kind of** the base class.

For example, a `Square` can be seen as a specialized form of a `Rectangle`. Since all squares are rectangles, this is an “is-a” relationship.

##### Code Example: Inheritance

```cpp
// Base class
class Animal {
public:
    virtual void eat() { std::cout << "Nom nom nom\n"; }
};

// Derived class
class Lion : public Animal {
public:
    void roam() { std::cout << "Roaming the savannah\n"; }
    void eat() override { std::cout << "Lion eating meat\n"; }
};
```

Here, `Lion` inherits from `Animal` and can override the `eat()` function.

#### Composition

Composition establishes a **“has-a”** relationship, where one class contains another as a member.

For instance, a `Car` has an **engine**. The existence of the engine is tied to the car; if the car is destroyed, the engine also ceases to exist.

##### Code Example: Composition

```cpp
#include <memory>

class Engine {
public:
    void start() { std::cout << "Engine started\n"; }
};

// Car class using composition
class Car {
    std::unique_ptr<Engine> engine;
public:
    Car() : engine(std::make_unique<Engine>()) {}
    void start() { engine->start(); }
};
```

Here, `Car` contains an `Engine` as a member using a smart pointer. This is a composition relationship.

#### Key Differences

1. **Relationship**: Inheritance represents “is-a”, while composition represents “has-a”.
2. **Coupling**: Inheritance creates tighter coupling between classes compared to composition.
3. **Flexibility**: Composition offers more flexibility as it’s easier to change the composed object at runtime.
4. **Code Reuse**: Inheritance promotes code reuse through base class implementation, while composition achieves it through object composition.
5. **Design Principle**: “Favor composition over inheritance” is a common design principle, as it often leads to more flexible and maintainable code.


<div class="page"/>

### 30. What is *RAII* (Resource Acquisition Is Initialization) in *C++*?

**RAII** (Resource Acquisition Is Initialization) is a fundamental design pattern in C++ for efficient and deterministic **resource management**. It’s used to handle resources such as memory, file handles, network connections, and locks.

The core principle of RAII is to tie the lifecycle of a resource to the lifetime of an object. This approach offers several benefits:

1. **Automatic resource management**: Resources are automatically released when the object goes out of scope.
2. **Exception safety**: Resources are properly cleaned up even if an exception is thrown.
3. **Simplification of code**: Reduces the need for explicit resource management.

#### Key Concepts

##### Resource Acquisition

In RAII, resources are typically acquired in the constructor of an object. This ensures that the resource is available as soon as the object is created.

```cpp
class FileHandler {
    std::ifstream file;
public:
    FileHandler(const std::string& filename) : file(filename) {
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file");
        }
    }
    // ... other methods ...
};
```

##### Resource Release

Resources are released in the destructor of the object. This guarantees that the resource is freed when the object is destroyed, regardless of how it goes out of scope.

```cpp
class FileHandler {
    std::ifstream file;
public:
    // ... constructor ...
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
        }
    }
};
```

##### Scope-Based Management

RAII leverages C++'s deterministic destruction to manage resources. When an object goes out of scope, its destructor is automatically called, ensuring resource release.

#### Modern C++ RAII Implementations

C++11 and later versions provide several standard library classes that implement RAII:

1. **`std::unique_ptr`**: For exclusive ownership of dynamically allocated objects.
2. **`std::shared_ptr`**: For shared ownership of dynamically allocated objects.
3. **`std::lock_guard`** and **`std::unique_lock`**: For automatic management of mutexes.
4. **`std::fstream`** and its derivatives: For file I/O with automatic file closing.

#### Example: RAII with `std::unique_ptr`

```cpp
#include <memory>
#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
    void use() { std::cout << "Resource used\n"; }
};

void raiiDemo() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->use();
    // No need for explicit delete
}

int main() {
    raiiDemo();
    // Resource is automatically released when res goes out of scope
    return 0;
}
```

* * *

## Templates and Generic Programming

* * *


<div class="page"/>

### 31. What are *templates* in *C++*?

**Templates** in C++ are a powerful feature that enables **generic programming**, allowing you to write code that works with multiple data types without sacrificing type safety. They are extensively used in the **Standard Template Library (STL)** for implementing containers and algorithms.

#### Basic Template Syntax

Here’s a simple example of a function template:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

This `add` function can work with any type `T` that supports the `+` operator.

#### Template Instantiation

When you use a template, the compiler generates a specific version for the given types:

```cpp
int result1 = add(5, 3);        // Instantiates add<int>
double result2 = add(3.14, 2.5); // Instantiates add<double>
```

#### Type Deduction and Implicit Conversions

C++ can deduce types and perform implicit conversions:

```cpp
auto result = add(5, 3.2);  // Deduces double, promotes 5 to 5.0
```

#### Multiple Template Parameters

Templates can have multiple type parameters:

```cpp
template <typename T, typename U>
auto multiply(T a, U b) -> decltype(a * b) {
    return a * b;
}
```

#### Class Templates

Templates are not limited to functions; you can create class templates as well:

```cpp
template <typename T>
class Vector {
private:
    T* elements;
    size_t size;
public:
    // ... methods ...
};

Vector<int> intVector;
Vector<std::string> stringVector;
```

#### Specialization

You can provide specialized implementations for specific types:

```cpp
template <>
class Vector<bool> {
    // Specialized implementation for bool
};
```

#### Concepts (C++20)

C++20 introduced *concepts*, which allow you to specify constraints on template parameters:

```cpp
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
};

template <Addable T>
T add(T a, T b) {
    return a + b;
}
```

This ensures that `add` only works with types that support addition.

#### Variadic Templates

C++11 introduced variadic templates, allowing a variable number of template parameters:

```cpp
template<typename... Args>
void printAll(Args... args) {
    (std::cout << ... << args) << '\n';
}

printAll(1, 2.0, "three");
```


<div class="page"/>

### 32. Explain the *difference* between *function templates* and *class templates*.

Both **function templates** and **class templates** are powerful features in C++ that enable generic programming, allowing code to work with different data types. However, they have distinct characteristics and use cases.

#### Function Templates

Function templates allow you to write a single function that can operate on different data types. They are defined using the `template` keyword followed by type parameter(s) enclosed in angle brackets `<>`.

##### Key Features:

- Type is inferred from the function’s arguments
- Instantiated when called with specific types
- Useful for operations that need to be performed on multiple data types

##### Code Example:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Usage
int maxInt = max(5, 10);        // T is deduced as int
double maxDouble = max(3.14, 2.71);  // T is deduced as double
```

#### Class Templates

Class templates enable the creation of generic classes that can work with different data types. They are defined using `template <typename T>` before the class declaration.

##### Key Features:

- Create generic data structures or types
- Type must be specified when instantiating the class
- Useful for containers, mathematical structures, or any class that needs to work with multiple types

##### Code Example:

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(T const& elem) { elements.push_back(elem); }
    void pop() { elements.pop_back(); }
    T top() const { return elements.back(); }
    bool empty() const { return elements.empty(); }
};

// Usage
Stack<int> intStack;
Stack<std::string> stringStack;
```

#### When to Use Each

- Use **function templates** for generic algorithms or operations that need to work with multiple types, like sorting or finding elements.

- Use **class templates** for generic data structures or when you need to create a type that can work with different data types, such as containers (e.g., vectors, lists) or custom data structures.

#### Modern C++ Considerations

In modern C++ (C++11 and later), concepts like `auto` type deduction and variadic templates have further enhanced the power and flexibility of both function and class templates, making generic programming even more accessible and powerful.


<div class="page"/>

### 33. What is *template specialization*?

**Template specialization** in C++ allows you to provide custom implementations for specific data types within a template class or function. This feature is particularly useful for:

1. **Performance optimization**
2. **Handling non-standard types**
3. **Implementing type-specific behavior**

#### Types of Template Specialization

##### 1\. Primary Template

The primary template serves as the default implementation for most data types:

```cpp
template <typename T>
class MyClass {
    // General implementation
};
```

##### 2\. Explicit (Full) Specialization

Provides a completely different implementation for a specific type:

```cpp
template <>
class MyClass<int> {
    // Specialized implementation for int
};
```

##### 3\. Partial Specialization

Allows specialization based on partial information about the template parameters (only for class templates):

```cpp
template <typename T>
class MyClass<T*> {
    // Specialized implementation for pointer types
};
```

#### Code Example

Here’s a comprehensive example demonstrating template specialization:

```cpp
#include <iostream>
#include <type_traits>

// Primary template
template <typename T>
struct Calculator {
    static T add(T a, T b) {
        std::cout << "General addition" << std::endl;
        return a + b;
    }
};

// Explicit specialization for int
template <>
struct Calculator<int> {
    static int add(int a, int b) {
        std::cout << "Optimized integer addition" << std::endl;
        return a + b;
    }
};

// Partial specialization for pointer types
template <typename T>
struct Calculator<T*> {
    static T* add(T* a, std::ptrdiff_t b) {
        std::cout << "Pointer arithmetic" << std::endl;
        return a + b;
    }
};

int main() {
    std::cout << Calculator<double>::add(3.14, 2.86) << std::endl;
    std::cout << Calculator<int>::add(5, 7) << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    int* result = Calculator<int*>::add(arr, 2);
    std::cout << *result << std::endl;

    return 0;
}
```


<div class="page"/>

### 34. How does *template metaprogramming* work in *C++*?

**Template metaprogramming** in C++ is a powerful technique that utilizes templates to perform computations and generate code at compile-time. It enables the creation of flexible, efficient, and type-safe code. Here are the key aspects:

##### Template Specialization

Template specialization allows you to define custom implementations for specific types or values:

```cpp
template <typename T>
struct is_void {
    static constexpr bool value = false;
};

template <>
struct is_void<void> {
    static constexpr bool value = true;
};
```

##### Type Traits

Type traits provide compile-time information about types:

```cpp
#include <type_traits>

template <typename T>
void process(T value) {
    if constexpr (std::is_integral_v<T>) {
        // Integer-specific processing
    } else {
        // General processing
    }
}
```

##### SFINAE (Substitution Failure Is Not An Error)

SFINAE allows for compile-time selection of function overloads:

```cpp
template <typename T>
typename std::enable_if<std::is_integral_v<T>, bool>::type
is_even(T value) {
    return value % 2 == 0;
}
```

##### Constexpr

`constexpr` enables compile-time evaluation of functions and variables:

```cpp
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

constexpr int result = factorial(5);  // Computed at compile-time
```

##### Variadic Templates

Variadic templates allow for a variable number of template parameters:

```cpp
template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;
}
```

#### Advanced Example: Compile-Time Fibonacci

Here’s an example of computing Fibonacci numbers at compile-time:

```cpp
template<unsigned N>
struct Fibonacci {
    static constexpr unsigned value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0> {
    static constexpr unsigned value = 0;
};

template<>
struct Fibonacci<1> {
    static constexpr unsigned value = 1;
};

static_assert(Fibonacci<10>::value == 55, "Fibonacci<10> should be 55");
```


<div class="page"/>

### 35. What are *variadic templates*?

**Variadic templates** are a powerful C++ feature introduced in C++11 that allow templates to accept an arbitrary number of arguments. They can handle different types (type-variadic) and values (value-variadic).

The term “variadic” comes from “variety,” indicating the templates’ ability to work with a variable number of arguments.

#### Syntax

In C++11 and later, a variadic template is defined by specifying at least one type or value parameter followed by an ellipsis (`...`):

```cpp
template <typename... Ts>
void myFunction(Ts... args);
```

Here, `Ts` is a **parameter pack**, representing zero or more types. The ellipsis indicates that `Ts` is a pack.

##### Non-Type Parameter Packs

Since C++17, **non-type parameter packs** are also supported, allowing packs of values, references, or non-type template arguments:

```cpp
template <auto... Values>
struct NonTypePackExample {};
```

#### Use Cases

Variadic templates are crucial for creating flexible **utility functions** and components:

- `std::make_unique` and `std::make_shared`
- `std::tuple`: A heterogeneous collection
- `std::async`: For asynchronous function invocation
- `std::visit`: Used with `std::variant` for value inspection

#### Common Implementations

##### Parameter Pack Expansion

Expand a parameter pack using the `...` syntax:

```cpp
template <typename... Ts>
void printAll(Ts... args) {
    (std::cout << ... << args) << '\n';  // C++17 fold expression
}
```

##### Fold Expressions (C++17)

**Fold expressions** simplify operations on all pack elements:

```cpp
template <typename... Ts>
auto sum(Ts... args) {
    return (... + args);  // Left fold
}
```

##### Recursion and Pack Unpacking

For more complex operations or mixing pack and non-pack arguments:

```cpp
template <typename T>
void print(T arg) {
    std::cout << arg << '\n';
}

template <typename T, typename... Ts>
void print(T first, Ts... rest) {
    std::cout << first << ' ';
    print(rest...);
}
```

##### Perfect Forwarding

Use `std::forward` to preserve value category:

```cpp
template <typename... Args>
void wrapper(Args&&... args) {
    someFunction(std::forward<Args>(args)...);
}
```

#### C++20 Enhancements

C++20 introduced additional features for variadic templates:

- **Template parameter lists** for lambdas
- **Constraints** and **concepts** for more precise template specialization

```cpp
auto lambda = []<typename... Ts>(Ts... args) requires (sizeof...(Ts) > 0) {
    // Lambda body
};
```


<div class="page"/>

### 36. Explain the concept of *type traits* in *C++*.

**Type traits** are a powerful feature in C++ that allow developers to query and manipulate type properties at compile-time. They are particularly useful in template metaprogramming and generic programming scenarios.

##### Core Concepts

Type traits are typically implemented as template structs in the `<type_traits>` header. They provide a uniform interface to access type information, often through a static constant `value` or a type alias `type`.

##### Commonly Used Type Traits

1. **Type Categories**

    - `std::is_integral<T>`: Checks if `T` is an integral type
    - `std::is_floating_point<T>`: Identifies floating-point types
    - `std::is_arithmetic<T>`: Combines integral and floating-point types
    - `std::is_void<T>`: Indicates void types
2. **Type Properties**

    - `std::is_const<T>`: Checks if `T` is const-qualified
    - `std::is_volatile<T>`: Tests for volatile qualification
    - `std::is_trivially_copyable<T>`: Verifies if `T` is trivially copyable
3. **Type Relationships**

    - `std::is_same<T, U>`: Checks if `T` and `U` are the same type
    - `std::is_base_of<Base, Derived>`: Checks if `Base` is a base class of `Derived`
4. **Type Transformations**

    - `std::remove_const<T>`: Removes const qualification
    - `std::add_pointer<T>`: Adds a pointer to the type

##### Code Example:

```cpp
#include <type_traits>
#include <iostream>

template<typename T>
void print_type_info() {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "T is an integral type\n";
    } else if constexpr (std::is_floating_point<T>::value) {
        std::cout << "T is a floating-point type\n";
    } else {
        std::cout << "T is neither integral nor floating-point\n";
    }
}

int main() {
    print_type_info<int>();    // Output: T is an integral type
    print_type_info<double>(); // Output: T is a floating-point type
    print_type_info<char*>();  // Output: T is neither integral nor floating-point
}
```

##### Code Example: C++17 and Beyond

C++17 introduced variable templates for type traits, allowing for more concise syntax:

```cpp
template<class T>
inline constexpr bool is_integral_v = std::is_integral<T>::value;
```

This allows us to write `std::is_integral_v<T>` instead of `std::is_integral<T>::value`.

##### Code Example: Custom Type Traits

```cpp
template<typename T>
struct is_container {
    static constexpr bool value = false;
};

template<typename T>
struct is_container<std::vector<T>> {
    static constexpr bool value = true;
};

// Usage
static_assert(is_container<std::vector<int>>::value, "std::vector is a container");
static_assert(!is_container<int>::value, "int is not a container");
```


<div class="page"/>

### 37. What is *SFINAE* (Substitution Failure Is Not An Error)?

**SFINAE** is a powerful mechanism in C++ that allows templates to **gracefully handle errors** during template argument deduction without causing compilation failures. It’s a fundamental concept in template metaprogramming and enables more flexible and expressive template designs.

#### Core Concept

The essence of SFINAE is that when substituting template arguments fails, the compiler doesn’t immediately report an error. Instead, it removes that particular function template specialization from the overload set. This behavior allows for more sophisticated template designs and function overloading based on type traits.

#### Code Example: SFINAE in Action

```cpp
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void print_number(T value) {
    std::cout << "Integral: " << value << std::endl;
}

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
void print_number(T value) {
    std::cout << "Floating-point: " << value << std::endl;
}

int main() {
    print_number(42);    // Calls the integral version
    print_number(3.14);  // Calls the floating-point version
    // print_number("hello");  // Compilation error: no matching function
}
```

In this example, SFINAE allows the compiler to select the appropriate function based on the type of the argument, without generating errors for the non-matching overloads.

#### SFINAE vs. Concepts

While SFINAE remains a crucial technique, C++20 introduced **concepts**, which provide a more readable and maintainable way to achieve similar results:

```cpp
#include <concepts>

template <std::integral T>
void print_number(T value) {
    std::cout << "Integral: " << value << std::endl;
}

template <std::floating_point T>
void print_number(T value) {
    std::cout << "Floating-point: " << value << std::endl;
}
```

Concepts offer a cleaner syntax and improved error messages compared to traditional SFINAE techniques.

#### Advanced SFINAE Techniques

##### Code Example: Tag Dispatching

Tag dispatching is a technique often used in conjunction with SFINAE:

```cpp
template <typename T>
void process_impl(T value, std::true_type) {
    std::cout << "Processing integral type" << std::endl;
}

template <typename T>
void process_impl(T value, std::false_type) {
    std::cout << "Processing non-integral type" << std::endl;
}

template <typename T>
void process(T value) {
    process_impl(value, std::is_integral<T>{});
}
```

##### Code Example: Expression SFINAE

Expression SFINAE allows for more complex condition checking:

```cpp
template <typename T>
auto has_toString(T t) -> decltype(t.toString(), std::true_type{});

std::false_type has_toString(...);

template <typename T>
void callToString(T t) {
    if constexpr (decltype(has_toString(t))::value) {
        std::cout << t.toString() << std::endl;
    } else {
        std::cout << "No toString method" << std::endl;
    }
}
```

#### SFINAE in Modern C++

While concepts provide a more elegant solution for many use cases, SFINAE remains relevant in C++20 and beyond, especially for more complex metaprogramming tasks. Understanding both SFINAE and concepts allows developers to choose the most appropriate tool for each specific scenario.


<div class="page"/>

### 38. How do you implement a *type-safe container* using *templates*?

A **type-safe container** ensures that only objects of a specific type can be stored and retrieved. You can implement this using **templates** in C++.

#### Code Example

Here’s an example of how to create a type-safe container using templates:

```cpp
#include <iostream>
#include <stdexcept>
#include <optional>

template <typename T>
class TypeSafeContainer {
private:
    std::optional<T> value;

public:
    void setValue(const T& newValue) {
        value = newValue;
    }

    T getValue() const {
        if (!value.has_value()) {
            throw std::logic_error("No value set");
        }
        return value.value();
    }

    bool hasData() const {
        return value.has_value();
    }

    void reset() {
        value.reset();
    }
};
```

#### Key Features

1. **Template Usage**: The `TypeSafeContainer` is defined as a `template <typename T>`, allowing it to work with any data type.

2. **Type Safety**: The container only accepts and returns values of type `T`, ensuring type safety at compile-time.

3. **std::optional**: We use `std::optional<T>` to manage the stored value, which provides a more idiomatic way to handle the presence or absence of a value.

4. **Error Handling**: The `getValue()` method throws an exception if no value is set, preventing undefined behavior.

#### Code Example

Here’s how you can use the `TypeSafeContainer`:

```cpp
int main() {
    // Integer container
    TypeSafeContainer<int> intContainer;
    intContainer.setValue(42);
    std::cout << "Integer value: " << intContainer.getValue() << std::endl;

    // String container
    TypeSafeContainer<std::string> stringContainer;
    stringContainer.setValue("Hello, World!");
    std::cout << "String value: " << stringContainer.getValue() << std::endl;

    // Attempting to set a different type will result in a compile-time error
    // intContainer.setValue("Not an integer"); // This line would not compile

    // Checking for data
    std::cout << "Has data? " << (intContainer.hasData() ? "Yes" : "No") << std::endl;

    // Resetting the container
    intContainer.reset();
    std::cout << "After reset, has data? " << (intContainer.hasData() ? "Yes" : "No") << std::endl;

    return 0;
}
```


<div class="page"/>

### 39. What are the *advantages* and *disadvantages* of using *templates*?

Using templates in C++ offers both advantages and disadvantages. Let’s explore them in detail:

#### Advantages of Using Templates

1. **Code Reusability** Templates enable generic programming, allowing functions and classes to operate on any data type. This significantly enhances code reusability.

    ```cpp
    template <typename T>
    T max(T a, T b) {
        return (a > b) ? a : b;
    }
    ```

2. **Type Safety** Templates provide strong type-checking without sacrificing flexibility. This helps catch type-related errors at compile time, improving overall code quality.

3. **Performance** Template-based code can achieve better performance by enabling compiler optimizations. The compiler can generate specialized code for each instantiation, potentially leading to more efficient execution.

4. **Flexibility** Templates offer a high degree of flexibility, allowing for custom memory management and data processing strategies tailored to specific types.

5. **Compile-Time Polymorphism** Templates facilitate compile-time polymorphism, which can lead to more efficient code compared to runtime polymorphism through virtual functions.

#### Disadvantages of Using Templates

1. **Code Bloat** Instantiating templates for multiple types can lead to code bloat, increasing executable sizes. This may impact memory consumption and cache efficiency.

2. **Compilation Time** Templates are typically instantiated during compilation. Using complex or heavily templated libraries can significantly increase compilation times.

    ```cpp
    template <typename T, size_t N>
    class Array {
        T data[N];
        // ... implementation
    };

    // Multiple instantiations can increase compilation time
    Array<int, 10> arr1;
    Array<double, 20> arr2;
    Array<std::string, 30> arr3;
    ```

3. **Error Messages** Template-related error messages can be notoriously long and difficult to interpret, especially with complex template metaprogramming.

4. **Debuggability** Template-based code can be more challenging to debug, as some template-related issues might only surface during the instantiation of specific types.

5. **Learning Curve** Templates, especially advanced features like template metaprogramming, can have a steep learning curve and require a strong understanding of the underlying mechanisms.

6. **Header-Only Libraries** Template implementations typically need to be in header files, which can lead to longer compilation times and potential issues with separate compilation models.


<div class="page"/>

### 40. Explain the concept of *template argument deduction*.

**Template argument deduction** is a powerful feature in C++ that allows the compiler to **automatically infer template arguments** from function call parameters. This mechanism simplifies code by reducing the need for explicit type specifications.

##### How TAD Works

When you define a function template like `template <typename T> void myFunc(T arg)`, the compiler uses TAD to determine the concrete type for `T` based on the argument provided during the function call.

TAD primarily uses two sources of information:

1. **Explicitly Specified Arguments**: These take precedence when provided within angle brackets.

    ```cpp
    std::vector<int> v;  // 'int' is explicitly specified
    ```

2. **Function Parameters**: The compiler deduces types by matching function parameters with template parameters.

    ```cpp
    myFunc(5);  // 'T' is deduced as 'int'
    ```

##### Deduction Rules

- **Non-Deduced Contexts**: Some scenarios prevent deduction, such as when a template parameter appears only in non-deduced contexts.

- **Qualifiers**: `const` and `volatile` qualifiers are typically preserved during deduction but can be adjusted in certain cases.

- **Reference Collapsing**: TAD handles references consistently, following reference collapsing rules.

##### C++17 and Beyond

C++17 introduced **class template argument deduction (CTAD)**, extending TAD to class templates:

```cpp
std::pair p(1, 2.5);  // deduced as std::pair<int, double>
```

C++20 further enhanced TAD with **concepts** and **constraints**, allowing more precise control over deduction:

```cpp
template <std::integral T>
void integerFunc(T value) { /* ... */ }

integerFunc(42);    // OK, deduced as int
integerFunc(3.14);  // Error, doesn't satisfy std::integral
```

##### Benefits and Considerations

- TAD enhances code readability by reducing explicit type declarations.
- It can lead to more generic and reusable code.
- In complex scenarios, explicit type specification (using `auto` or `decltype`) might still be necessary.

##### Code Example: Array Size Deduction

```cpp
template <typename T, std::size_t N>
void processArray(T (&arr)[N]) {
    std::cout << "Array of size " << N << std::endl;
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    processArray(arr);  // Deduces T as int and N as 5
    return 0;
}
```

* * *

## Exception Handling

* * *


<div class="page"/>

### 41. What is *exception handling* in *C++*?

**Exception handling** in C++ is a mechanism to manage and respond to unexpected events during program execution, such as errors and abnormal conditions.

#### Key Components

- **`try` block**: Identifies a segment of code where exceptions might occur.
- **`throw` statement**: Explicitly signals that an exception has occurred.
- **`catch` block**: Handles exceptions of a specific type.
- **Exception classes**: Predefined in the C++ standard library, defined in the `<exception>` header.

#### Basic Syntax

```cpp
try {
    // Code that might throw an exception
    if (someErrorCondition) {
        throw std::runtime_error("An error occurred");
    }
} catch (const std::exception& e) {
    // Handle the exception
    std::cerr << "Caught exception: " << e.what() << std::endl;
}
```

#### Common Use Cases

1. **Error Reporting and Handling**: For file I/O problems, network issues, etc.
2. **Resource Management**: Ensure proper cleanup of resources even in error situations.
3. **Handling Abnormal Situations**: Address unexpected program behavior like division by zero.

#### Best Practices

- Use exceptions for exceptional situations, not for regular control flow.
- Avoid throwing exceptions in destructors.
- Document functions that may throw exceptions.
- Provide strong exception guarantees where possible.
- Use `noexcept` specifier for functions that don’t throw exceptions.

#### Standard Exception Hierarchy

C++ provides a hierarchy of standard exception classes:

```
std::exception
├── std::logic_error
│   ├── std::invalid_argument
│   ├── std::domain_error
│   ├── std::length_error
│   ├── std::out_of_range
│   └── std::future_error
└── std::runtime_error
    ├── std::range_error
    ├── std::overflow_error
    ├── std::underflow_error
    └── std::system_error
```

#### Modern C++ Features (C++11 and later)

- **`noexcept` specifier**: Indicates that a function doesn’t throw exceptions.
- **`std::exception_ptr`**: Allows storing and rethrowing exceptions across thread boundaries.
- **Nested exceptions**: Enables wrapping one exception inside another.

#### Example: Custom Exception Class

```cpp
class CustomException : public std::exception {
public:
    CustomException(const char* message) : msg_(message) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

// Usage
try {
    throw CustomException("Custom error occurred");
} catch (const CustomException& e) {
    std::cout << "Caught custom exception: " << e.what() << std::endl;
}
```

#### Performance Considerations

- Exception handling has a performance cost, mainly when an exception is thrown.
- The cost of setting up `try-catch` blocks is minimal if no exception is thrown.
- In performance-critical code, consider alternatives like error codes for expected error conditions.


<div class="page"/>

### 42. Explain the *try*, *catch*, and *throw* keywords.

In C++, the keywords **try**, **catch**, and **throw** are used for **exception handling**, providing a structured way to deal with errors and unexpected behavior.

#### try

The `try` block is used to enclose code that might throw an exception. It allows you to define a scope in which exceptions are caught.

```cpp
try {
    // Code that might throw an exception
}
```

#### catch

The `catch` block is used to handle exceptions. It follows a `try` block and specifies the type of exception it can handle.

```cpp
catch (ExceptionType& e) {
    // Code to handle the exception
}
```

#### throw

The `throw` keyword is used to generate (or “throw”) an exception. It can be used with an argument that specifies the exception object to be thrown.

```cpp
throw ExceptionObject();
```

#### Basic Mechanism

1. Code inside a `try` block is executed.
2. If an exception is thrown, the program looks for a matching `catch` block.
3. If a matching `catch` is found, it handles the exception.
4. If no matching `catch` is found, the program terminates (unless there’s a global exception handler).

#### Code Example

Here’s a comprehensive example demonstrating the use of `try`, `catch`, and `throw`:

```cpp
#include <iostream>
#include <stdexcept>

void validateAge(int age) {
    if (age < 0) {
        throw std::invalid_argument("Age cannot be negative");
    }
    if (age > 150) {
        throw std::out_of_range("Age is unrealistically high");
    }
}

int main() {
    try {
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;

        validateAge(age);

        std::cout << "Your age is: " << age << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
```

This example demonstrates:

- Using `throw` to generate exceptions in `validateAge()`.
- Using `try` to enclose code that might throw exceptions.
- Using multiple `catch` blocks to handle different types of exceptions.
- Using standard exception classes (`std::invalid_argument`, `std::out_of_range`).
- Using a catch-all block for `std::exception` to handle any unexpected exceptions.

#### Best Practices

1. Use standard exception classes when possible.
2. Catch exceptions by const reference to avoid slicing.
3. Order `catch` blocks from most specific to most general.
4. Use `noexcept` for functions that don’t throw exceptions.
5. Consider using `std::optional` or `std::expected` (C++23) for error handling in performance-critical code.


<div class="page"/>

### 43. What is the purpose of the ‘*noexcept*’ specifier?

The `noexcept` specifier in C++ is used to indicate whether a function can throw exceptions. It serves two main purposes:

1. **Optimization**: Allows the compiler to perform certain optimizations.
2. **Documentation**: Clearly communicates the exception-throwing behavior of a function.

#### Key Points

- Introduced in **C++11**
- Initially informative (C++11, C++14)
- Became contractual from **C++17** onwards (violating `noexcept` leads to `std::terminate`)

#### Usage

The `noexcept` specifier can be used in two forms:

1. **Simple form**: `noexcept`
2. **Conditional form**: `noexcept(expression)`

##### Example:

```cpp
void func1() noexcept;  // Simple form
void func2() noexcept(sizeof(int) == 4);  // Conditional form
```

#### Benefits

- **Performance**: Enables compiler optimizations
- **Error Handling**: Guarantees no exceptions, allowing for robust error-handling strategies
- **Resource Management**: Helps in proper resource management during exceptions

#### Code Example

```cpp
#include <iostream>

// This function is marked noexcept as integer multiplication won't throw
int square(int num) noexcept {
    return num * num;
}

// This function might throw, so it's not marked noexcept
int divide(int a, int b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}

int main() {
    std::cout << "Square of 5: " << square(5) << std::endl;

    try {
        std::cout << "10 / 2 = " << divide(10, 2) << std::endl;
        std::cout << "10 / 0 = " << divide(10, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```

#### Best Practices

1. **Be Accurate**: Use `noexcept` only for functions that truly won’t throw exceptions
2. **Use `noexcept` Operators**: Provide clear syntax for documenting exception guarantees
3. **Consider Implications**: Functions called by a `noexcept` function should also be `noexcept`
4. **Move Operations**: Use `noexcept` for move constructors and move assignment operators when possible
5. **Avoid Redundancy**: Prefer `noexcept` over older exception specifications like `throw()`

#### Note on C++20

In C++20, the `noexcept` specifier is part of the function type, allowing for more precise function overloading and template specialization based on exception specifications.


<div class="page"/>

### 44. How do you create *custom exception classes*?

In C++, you can create **custom exception classes** by inheriting from the standard `std::exception` class or its derived classes. This allows you to define specific exceptions tailored to your application’s needs.

#### Code Example

Here’s an example of how to create a custom exception class:

```cpp
#include <exception>
#include <string>

class FileException : public std::exception {
private:
    std::string m_message;
    std::string m_fileName;
    int m_errorCode;

public:
    FileException(const std::string& message, const std::string& fileName, int errorCode)
        : m_message(message), m_fileName(fileName), m_errorCode(errorCode) {}

    const char* what() const noexcept override {
        return m_message.c_str();
    }

    const std::string& fileName() const {
        return m_fileName;
    }

    int errorCode() const {
        return m_errorCode;
    }
};
```

#### Key Points

1. **Inheritance**: Inherit from `std::exception` or one of its derived classes.
2. **Override `what()`**: Implement the `what()` method to provide a description of the exception.
3. **Additional Information**: Add custom members and methods to provide more context about the exception.
4. **`noexcept` Specifier**: Use `noexcept` for the `what()` method to indicate it doesn’t throw exceptions.

#### Code Example

Here’s how you can use the custom exception:

```cpp
#include <iostream>

int main() {
    try {
        throw FileException("File not found", "example.txt", 404);
    }
    catch (const FileException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        std::cout << "File: " << e.fileName() << std::endl;
        std::cout << "Error code: " << e.errorCode() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }

    return 0;
}
```

#### Best Practices

1. **Specific Exceptions**: Create specific exception classes for different types of errors.
2. **Meaningful Names**: Use descriptive names for your exception classes.
3. **Inheritance Hierarchy**: Consider creating a hierarchy of custom exceptions if needed.
4. **Exception Safety**: Ensure that your custom exceptions are exception-safe and don’t leak resources.


<div class="page"/>

### 45. What happens if an *exception* is not caught?

In C++, when an **exception** isn’t caught, it triggers a series of predefined actions known as the “exception handling mechanism”. This typically involves the exception being propagated up through the call stack until it either gets handled or results in program termination.

#### Mechanism of Uncaught Exceptions

##### Stack Unwinding

When an exception isn’t managed locally, the C++ runtime initiates a process called **stack unwinding**. This involves:

1. Searching for a suitable `catch` block up the call stack.
2. Destroying local objects in reverse order of their creation (calling their destructors).
3. Popping function calls off the stack.

##### Propagation

If no matching `catch` block is found within the current function:

- Control is transferred to the calling function.
- The process repeats until a matching `catch` block is found or the main function is reached.

##### Termination

If the exception reaches the top of the call stack without being caught:

- The `std::terminate()` function is called.
- By default, this calls `std::abort()`, which abnormally terminates the program.

#### Customizing Termination Behavior

You can customize the termination behavior using `std::set_terminate()`:

```cpp
#include <exception>
#include <iostream>

void custom_terminate() {
    std::cout << "Uncaught exception: terminating program\n";
    std::abort();
}

int main() {
    std::set_terminate(custom_terminate);
    throw 20;  // Uncaught exception
}
```

#### Noexcept Specifier

Functions marked with `noexcept` have special behavior:

- If an exception escapes a `noexcept` function, `std::terminate()` is called immediately.
- This bypasses normal stack unwinding.

```cpp
void func() noexcept {
    throw std::runtime_error("Error");  // Immediate termination
}
```

#### Best Practices

1. **Catch exceptions at appropriate levels**: Don’t catch exceptions you can’t handle meaningfully.
2. **Use exception specifications judiciously**: `noexcept` can optimize code but limits exception handling flexibility.
3. **Ensure resource cleanup**: Use RAII (Resource Acquisition Is Initialization) to manage resources, ensuring proper cleanup even during stack unwinding.

#### Code Example: Exception Propagation

```cpp
#include <iostream>
#include <stdexcept>

void inner_function() {
    throw std::runtime_error("Error in inner_function");
}

void middle_function() {
    inner_function();  // Exception propagates
}

int main() {
    try {
        middle_function();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```


<div class="page"/>

### 46. Explain the concept of *exception safety*.

**Exception safety** in C++ refers to writing code that maintains consistency and prevents resource leaks, even when exceptions occur. It’s a crucial concept for developing robust and reliable software.

##### Key Principles:

1. **Resource Acquisition Is Initialization (RAII)**:

    - Use objects to manage resources, ensuring proper release even when exceptions occur.
    - Example: `std::unique_ptr` for dynamic memory management.
2. **Exception-Safe Operations**:

    - Perform potentially-throwing operations before modifying object state.
    - If an exception occurs, the object remains in its original state.
3. **Exception Safety Guarantees**:

    - **Strong Guarantee**: If an exception is thrown, the function has no effect (state remains unchanged).
    - **Basic Guarantee**: If an exception is thrown, no resources are leaked, but the state may change.
    - **No-throw Guarantee**: The function never throws exceptions (marked with `noexcept`).

##### Code Example: Demonstrating Exception Safety Levels

```cpp
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>

// Strong Guarantee
void strongGuarantee(std::vector<int>& vec, int value) {
    auto tempVec = vec;  // Create a temporary copy
    tempVec.push_back(value);
    vec = std::move(tempVec);  // Only modify if all operations succeed
}

// Basic Guarantee
void basicGuarantee(std::vector<int>& vec, int count) {
    for (int i = 0; i < count; ++i) {
        try {
            vec.push_back(i);
            if (i == 3) throw std::runtime_error("Simulated error");
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            // Partial rollback: remove added elements
            vec.resize(vec.size() - i - 1);
            throw;  // Re-throw for caller to handle
        }
    }
}

// No-throw Guarantee
void noThrowGuarantee(std::vector<int>& vec, int value) noexcept {
    try {
        vec.push_back(value);
    } catch (...) {
        // Catch all exceptions and handle internally
    }
}

int main() {
    std::vector<int> v;

    try {
        strongGuarantee(v, 1);  // Strong guarantee
        basicGuarantee(v, 5);   // Basic guarantee
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    noThrowGuarantee(v, 10);  // No-throw guarantee

    std::cout << "Final vector size: " << v.size() << std::endl;

    return 0;
}
```


<div class="page"/>

### 47. What is the *difference* between *synchronous* and *asynchronous exceptions*?

In C++, exceptions can be classified as either **synchronous** or **asynchronous**. These two types of exceptions differ in their behavior and typical use cases.

#### Synchronous Exceptions

- **Triggering**: Result from *explicit code statements* or *operations*
- **Timing**: Thrown *immediately* at the point of the issue
- **Flow**: Disrupt the normal program flow
- **Handling**: Can be caught and handled using `try-catch` blocks

#### Asynchronous Exceptions

- **Triggering**: Typically caused by *external events* or *system-level issues*
- **Timing**: May occur at *any time* during program execution
- **Flow**: Do not immediately disrupt program flow
- **Handling**: Often difficult to catch and handle reliably

#### Code Example

```cpp
#include <iostream>
#include <stdexcept>
#include <thread>
#include <future>

void synchronousException() {
    throw std::runtime_error("This is a synchronous exception.");
}

void asynchronousException(std::promise<void> p) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_exception(std::make_exception_ptr(std::runtime_error("This is an asynchronous exception.")));
}

int main() {
    // Synchronous exception
    try {
        synchronousException();
    } catch (const std::exception& e) {
        std::cout << "Caught synchronous exception: " << e.what() << std::endl;
    }

    // Asynchronous exception
    std::promise<void> p;
    std::future<void> f = p.get_future();
    std::thread t(asynchronousException, std::move(p));

    try {
        f.get(); // Wait for the asynchronous operation and retrieve the result
    } catch (const std::exception& e) {
        std::cout << "Caught asynchronous exception: " << e.what() << std::endl;
    }

    t.join();

    return 0;
}
```

In this example:

- The `synchronousException()` function demonstrates a *synchronous exception* that is thrown and caught immediately.
- The `asynchronousException()` function simulates an *asynchronous exception* using `std::promise` and `std::future`. The exception is set in a separate thread and later retrieved in the main thread.


<div class="page"/>

### 48. How do you handle *constructor failures* using *exceptions*?

In C++, **constructor failures** can occur due to various reasons such as input validation errors, resource allocation failures, or exceptions thrown during object initialization. Properly handling these failures is crucial for maintaining program integrity and preventing resource leaks.

The recommended approach for handling constructor failures in C++ is to **throw an exception**. This ensures that:

1. The object is not left in an invalid or partially constructed state.
2. Resources are properly cleaned up.
3. The caller is notified of the failure and can handle it appropriately.

##### Code Example

Here’s a C++ example demonstrating how to handle constructor failures:

```cpp
#include <iostream>
#include <stdexcept>
#include <memory>

class Resource {
public:
    Resource() {
        // Simulate resource allocation
        if (/* allocation fails */) {
            throw std::runtime_error("Resource allocation failed");
        }
    }

    void initialize() {
        // Simulate initialization that might fail
        if (/* initialization fails */) {
            throw std::runtime_error("Resource initialization failed");
        }
    }

    ~Resource() {
        std::cout << "Resource cleaned up" << std::endl;
    }
};

class MyClass {
private:
    std::unique_ptr<Resource> resource;

public:
    MyClass() {
        resource = std::make_unique<Resource>();
        try {
            resource->initialize();
        } catch (...) {
            // Resource initialization failed, unique_ptr will handle cleanup
            throw; // Re-throw the caught exception
        }
    }
};

int main() {
    try {
        MyClass obj;
    } catch (const std::exception& e) {
        std::cerr << "Constructor failed: " << e.what() << std::endl;
    }
    return 0;
}
```

##### Key Points

1. Use **RAII** (Resource Acquisition Is Initialization) principles. In the example, `std::unique_ptr` ensures automatic cleanup if an exception is thrown.

2. **Throw exceptions** for any failures during construction. This prevents the object from being used in an invalid state.

3. If the constructor performs actions that might throw after acquiring resources, wrap those actions in a `try-catch` block and re-throw the exception after any necessary cleanup.

4. Use **smart pointers** like `std::unique_ptr` or `std::shared_ptr` for managing dynamically allocated resources. They provide automatic cleanup in case of exceptions.

5. Keep constructors **exception-neutral** by allowing exceptions to propagate. This gives the caller the opportunity to handle the failure.


<div class="page"/>

### 49. What is the purpose of *std::exception* and its *derived classes*?

`std::exception` serves as the **base class** for all standard C++ exceptions, providing a foundational structure for **exception handling**. Its derived classes offer specific exception types tailored to different error scenarios.

#### Key Benefits

- **Polymorphic Flexibility**: Inherited exceptions can be handled through the base class pointer, allowing for polymorphic behavior.
- **Type Identification**: Using `dynamic_cast`, you can determine the specific derived exception type, enabling tailored error management.

#### Common Derived Classes and Their Functions

| Exception Type | Description | Member Function | Purpose |
| --- | --- | --- | --- |
| `std::bad_alloc` | Thrown for dynamic memory allocation failures, like `new`. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::bad_cast` | Thrown when a `dynamic_cast` to a reference type fails. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::bad_function_call` | Thrown when an `std::function` object is called without a valid target. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::bad_typeid` | Thrown when `typeid` is used on a null pointer to a polymorphic type. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::bad_weak_ptr` | Thrown when creating a `std::shared_ptr` from an expired `std::weak_ptr`. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::logic_error` | Base class for exceptions indicating errors in program logic. | \-  | \-  |
| `std::invalid_argument` | Indicates a function was called with an invalid argument. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::length_error` | Thrown when an operation would exceed the maximum allowed size. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::out_of_range` | Thrown when accessing elements outside a valid range. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::runtime_error` | Base class for exceptions indicating runtime errors. | \-  | \-  |
| `std::overflow_error` | Thrown to indicate arithmetic overflow. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::underflow_error` | Thrown to indicate arithmetic underflow. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::system_error` | Represents errors from the operating system. | `code()` | Get the associated error code. |
| `std::ios_base::failure` | Thrown on I/O stream failures. | `what() const noexcept` | Retrieve an explanatory string. |
| `std::regex_error` | Represents errors in regular expression processing. | `code()` | Get the specific regex error code. |
| `std::future_error` | Represents errors in asynchronous operations. | `code()` | Get the associated error code. |
| `std::filesystem::filesystem_error` | Represents errors in filesystem operations. | `path1()`, `path2()` | Get the involved path(s). |

#### Code Example: Catching Multiple Derived Exceptions

```cpp
#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>

void handleException(const std::exception& ex) {
    std::cout << "Exception: " << ex.what() << std::endl;
}

void simulateExceptions(int exType) {
    switch (exType) {
        case 1: throw std::invalid_argument("Invalid argument!");
        case 2: throw std::bad_alloc();
        case 3: throw std::out_of_range("Out of range!");
        default: throw std::runtime_error("Generic runtime error");
    }
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        try {
            simulateExceptions(i);
        } catch (const std::exception& ex) {
            handleException(ex);
        }
    }

    return 0;
}
```


<div class="page"/>

### 50. How do you implement a *stack unwinding mechanism*?

**Stack unwinding** is a crucial process in C++ exception handling that ensures proper cleanup of resources when an exception is thrown. It involves the systematic destruction of objects as the program’s execution unwinds through the call stack.

#### Key Components

1. **Exception Throwing**: When an exceptional condition occurs, an exception object is created and thrown.

2. **Stack Traversal**: The runtime system searches for a suitable `catch` block by unwinding the stack frame by frame.

3. **Object Destruction**: During unwinding, local objects in each stack frame are destroyed in reverse order of their construction.

4. **Resource Management**: This mechanism is vital for proper resource management, especially when using RAII (Resource Acquisition Is Initialization) idiom.

#### Implementation Details

1. **Compiler Support**: Modern C++ compilers automatically generate the necessary code for stack unwinding.

2. **Exception Tables**: Compilers create exception tables that map program counter values to the corresponding cleanup code.

3. **Unwinding Library**: The C++ runtime typically includes an unwinding library (e.g., `libunwind`) that handles the mechanics of stack traversal.

#### Code Example

```cpp
#include <iostream>
#include <stdexcept>

class Resource {
public:
    Resource(int id) : m_id(id) { 
        std::cout << "Resource " << m_id << " acquired\n"; 
    }
    ~Resource() { 
        std::cout << "Resource " << m_id << " released\n"; 
    }
private:
    int m_id;
};

void innerFunction() {
    Resource r1(1);
    Resource r2(2);
    throw std::runtime_error("Error in innerFunction");
}

void outerFunction() {
    Resource r3(3);
    try {
        innerFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught in outerFunction: " << e.what() << '\n';
        throw; // Re-throw
    }
}

int main() {
    try {
        outerFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught in main: " << e.what() << '\n';
    }
}
```

##### Output

```
Resource 3 acquired
Resource 1 acquired
Resource 2 acquired
Resource 2 released
Resource 1 released
Caught in outerFunction: Error in innerFunction
Resource 3 released
Caught in main: Error in innerFunction
```

* * *

## Standard Template Library (STL)

* * *


<div class="page"/>

### 51. What is the *Standard Template Library* (STL)?

The **Standard Template Library** (STL) in C++ is a powerful collection of reusable components that provides generic algorithms and data structures. It’s a standardized part of the C++ Standard Library and is essential for efficient and rapid software development.

#### Components of STL

The STL is comprised of three primary components:

1. **Containers**: These are class templates that store and manage collections of objects. Examples include `vector`, `list`, and `map`.

2. **Algorithms**: These are function templates that operate on data, typically provided in the form of iterators. Algorithms perform various operations such as sorting, searching, and modifying ranges of elements.

3. **Iterators**: These are objects that allow traversing through the elements of a container, abstracting away the underlying data structure.

#### Advantages of Using STL

- **Performance**: STL algorithms are often highly optimized, leading to efficient execution.
- **Reusability**: STL components can be used with various data types, promoting code reuse.
- **Reduced Coding Burden**: STL abstracts away low-level details, allowing developers to focus on higher-level tasks.
- **Standardization**: As part of the C++ Standard Library, STL functionality is consistent across compliant compilers.
- **Type Safety**: STL provides mechanisms that help prevent type-related errors at compile-time.

#### Common STL Components

##### Sequence Containers

- **`vector`**: Dynamic array with fast random access.
- **`list`**: Doubly-linked list for efficient insertion and deletion.
- **`deque`**: Double-ended queue with fast insertion at both ends.

##### Associative Containers

- **`set`**: Ordered collection of unique keys.
- **`multiset`**: Ordered collection allowing duplicate keys.
- **`map`**: Ordered key-value pairs with unique keys.
- **`multimap`**: Ordered key-value pairs allowing duplicate keys.

##### Unordered Associative Containers (C++11 and later)

- **`unordered_set`**: Hash table of unique keys.
- **`unordered_multiset`**: Hash table allowing duplicate keys.
- **`unordered_map`**: Hash table of key-value pairs with unique keys.
- **`unordered_multimap`**: Hash table of key-value pairs allowing duplicate keys.

##### Iterators

- **Input Iterators**: Read-only, single-pass traversal.
- **Output Iterators**: Write-only, single-pass traversal.
- **Forward Iterators**: Multi-pass read-write traversal in one direction.
- **Bidirectional Iterators**: Multi-pass read-write traversal in both directions.
- **Random Access Iterators**: Direct element access and arbitrary step traversal.

##### Algorithms

STL provides a wide range of algorithms. Here are a few examples:

```cpp
#include <algorithm>
#include <vector>

std::vector<int> v = {3, 1, 4, 1, 5, 9};

// Sorting
std::sort(v.begin(), v.end());

// Finding an element
auto it = std::find(v.begin(), v.end(), 4);

// Counting elements that satisfy a condition
int count = std::count_if(v.begin(), v.end(), [](int n) { return n % 2 == 0; });
```

##### Adaptors

STL also provides container adaptors that modify the behavior of underlying containers:

- **`stack`**: LIFO data structure.
- **`queue`**: FIFO data structure.
- **`priority_queue`**: Highest priority element always at the top.


<div class="page"/>

### 52. Explain the *difference* between *vector* and *list* in *STL*.

Key Differences Between `vector` and `list` in STL

##### Memory Layout and Management

- **`vector`**: Uses a *contiguous memory* block, dynamically resizing when needed. This can lead to *iterator invalidation* during reallocation.
- **`list`**: Implements a *doubly linked list*, allocating memory for each node separately. *Iterators remain valid* even after insertions or deletions.

##### Performance Characteristics

###### Access

- **`vector`**: Offers *constant-time random access* (`O(1)`) via index.
- **`list`**: Provides only *linear-time access* (`O(n)`), requiring traversal from the beginning or end.

###### Insertion and Deletion

- **`vector`**:
    - *Constant time* (`O(1)`) at the end (amortized).
    - *Linear time* (`O(n)`) elsewhere due to element shifting.
- **`list`**:
    - *Constant time* (`O(1)`) anywhere, given an iterator to the position.

###### Memory Efficiency

- **`vector`**: More *memory-efficient* for small objects due to contiguous storage.
- **`list`**: Has *overhead* for node pointers, less cache-friendly.

##### Use Cases

- **`vector`**: Ideal for:
    - Frequent random access
    - Mostly back-end insertions/deletions
    - When size is known or rarely changes
- **`list`**: Preferred for:
    - Frequent insertions/deletions throughout the container
    - When element order must be preserved during erasures

#### Code Example

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <chrono>

template<typename T>
void measureInsertionTime(T& container) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; ++i) {
        container.insert(container.begin(), i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Time taken: " << diff.count() << " seconds\n";
}

int main() {
    std::vector<int> vec;
    std::list<int> lst;

    std::cout << "Vector insertion time:\n";
    measureInsertionTime(vec);

    std::cout << "List insertion time:\n";
    measureInsertionTime(lst);

    return 0;
}
```

This example demonstrates the performance difference between `vector` and `list` for frequent insertions at the beginning, highlighting `list`’s advantage in this scenario.


<div class="page"/>

### 53. What are the *associative containers* in *STL*?

**Associative containers** in the **C++ Standard Template Library (STL)** are data structures optimized for quick retrieval and storage of key-value pairs or unique elements. They use different types of **trees** or **hash tables** internally for efficient operations.

#### Types of Associative Containers

##### Ordered Associative Containers

1. **`std::map`**: Stores unique key-value pairs, sorted by keys.
2. **`std::set`**: Stores unique elements, sorted.
3. **`std::multimap`**: Allows duplicate keys, sorted by keys.
4. **`std::multiset`**: Allows duplicate elements, sorted.

These containers use a balanced binary search tree (typically Red-Black Tree) internally, providing logarithmic time complexity for most operations.

##### Unordered Associative Containers

1. **`std::unordered_map`**: Stores unique key-value pairs, unsorted.
2. **`std::unordered_set`**: Stores unique elements, unsorted.
3. **`std::unordered_multimap`**: Allows duplicate keys, unsorted.
4. **`std::unordered_multiset`**: Allows duplicate elements, unsorted.

These containers use hash tables internally, offering constant-time average complexity for most operations.

#### Code Example: Using std::map

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m{{1, "One"}, {2, "Two"}, {3, "Three"}};

    // Access and print the third element
    std::cout << "Third: " << m[3] << std::endl;

    // Iterate over the map
    for (const auto& [key, value] : m) {
        std::cout << key << ": " << value << std::endl;
    }

    return 0;
}
```

#### Code Example: Using std::unordered_set

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet = {1, 2, 3, 4, 5};

    // Insert a few more numbers
    mySet.insert(6);
    mySet.insert(7);

    // Check if 3 is in the set and output the result
    if (mySet.contains(3)) {
        std::cout << "3 is in the set." << std::endl;
    }

    return 0;
}
```

#### Key Characteristics

- **Ordered containers**: Maintain elements in a sorted order, useful for range queries.
- **Unordered containers**: Provide faster access and insertion times on average.
- **Unique key containers** (`map`, `set`): Ensure each key appears only once.
- **Multi-key containers** (`multimap`, `multiset`): Allow multiple elements with the same key.


<div class="page"/>

### 54. How does an *unordered_map* work internally?

An `std::unordered_map` in C++ is a **hash table-based** associative container, optimized for fast average-case lookup, insertion, and deletion operations. Here’s how it works internally:

##### Hash Function

- Uses a **hash function** to map keys to fixed-size values (hash codes).
- These hash codes determine the storage location or “bucket” for each key-value pair.

##### Collision Handling

When two different keys produce the same hash code (a collision), `unordered_map` employs collision resolution techniques:

- **Separate Chaining**: The most common method, where each bucket contains a linked list of elements.
- **Open Addressing**: Less common in C++ implementations, involves finding the next available slot in the array.

##### Internal Structure

```
[Bucket 0] -> (Key1, Value1) -> (Key2, Value2)
[Bucket 1] -> (Key3, Value3)
[Bucket 2] -> (Key4, Value4) -> (Key5, Value5)
...
```

##### Load Factor and Rehashing

- **Load Factor**: The ratio of the number of elements to the number of buckets.
- When the load factor exceeds a threshold (typically 1.0), the container performs **rehashing**:
    1. Increases the number of buckets.
    2. Recomputes hash codes for all elements.
    3. Redistributes elements into new buckets.

##### Time Complexity

- Average case: O(1) for insert, delete, and search operations.
- Worst case: O(n) when all elements hash to the same bucket.

##### Code Example: Basic Operations

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;

    // Insertion
    umap["apple"] = 5;
    umap.insert({"banana", 3});
    umap.emplace("cherry", 7);

    // Access and modification
    umap["apple"] = 6;

    // Search
    if (umap.find("banana") != umap.end()) {
        std::cout << "Found banana: " << umap["banana"] << std::endl;
    }

    // Iteration
    for (const auto& [key, value] : umap) {
        std::cout << key << ": " << value << std::endl;
    }

    // Deletion
    umap.erase("cherry");

    // Size and bucket information
    std::cout << "Size: " << umap.size() << std::endl;
    std::cout << "Bucket count: " << umap.bucket_count() << std::endl;
    std::cout << "Load factor: " << umap.load_factor() << std::endl;

    return 0;
}
```


<div class="page"/>

### 55. What is the *difference* between *set* and *multiset*?

`std::set` and `std::multiset` are both associative containers in C++ that store sorted keys. The primary distinction between them lies in how they handle duplicate elements.

#### Key Differences

##### Uniqueness

- `std::set`: Ensures each key is **unique**. Attempting to insert a duplicate key has no effect.
- `std::multiset`: Allows **duplicate** keys. Each insertion adds the key, regardless of whether it already exists.

##### Insertion Behavior

- `std::set`: Inserts keys while maintaining the set’s sorting order. If a duplicate is attempted, the insertion fails.
- `std::multiset`: Inserts keys while preserving the existing order, including duplicates.

##### Usage Scenarios

- `std::set`: Ideal for maintaining a collection of unique elements in sorted order.
- `std::multiset`: Useful when you need to keep track of element frequencies or allow duplicates in a sorted collection.

#### Code Example

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3};
    std::multiset<int> ms = {1, 2, 3};

    s.insert(2);  // No effect, 2 already exists
    ms.insert(2); // Adds another 2

    std::cout << "set size: " << s.size() << std::endl;        // Output: 3
    std::cout << "multiset size: " << ms.size() << std::endl;  // Output: 4

    return 0;
}
```

#### Performance

Both `std::set` and `std::multiset` typically use **red-black trees** as their underlying data structure, providing logarithmic time complexity (O(log n)) for insertion, deletion, and search operations.

#### C++20 Update

With C++20, both containers support heterogeneous lookup, allowing searches with types different from the container’s key type, as long as they’re comparable.


<div class="page"/>

### 56. Explain the concept of *iterators* in *STL*.

**Iterators** in the **Standard Template Library** (STL) are objects that provide a way to access and traverse elements in containers, abstracting the underlying data structure.

#### Key Advantages of Iterators

- Enable generic algorithms that work across different container types
- Support range-based `for` loops (C++11 and later)
- Provide a consistent interface for container traversal
- Often more efficient than direct index-based access

#### Iterator Categories

STL defines several iterator categories, each with specific capabilities:

1. **Input**: Read-only, single-pass
2. **Output**: Write-only, single-pass
3. **Forward**: Single-direction traversal, multi-pass
4. **Bidirectional**: Bi-directional movement
5. **Random Access**: Full traversal capabilities, including arithmetic operations
6. **Contiguous**: Guarantees contiguous memory layout (C++17)

#### Code Example: Iterator Category

```cpp
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    auto it = vec.begin();

    if constexpr(std::is_same_v<std::random_access_iterator_tag, 
                 typename std::iterator_traits<decltype(it)>::iterator_category>) {
        std::cout << "Vector iterator is Random Access\n";
    }
}
```

#### Common Iterator Types

1. **Regular Iterators**: Point to elements in a container
2. **Const Iterators**: Provide read-only access to container elements
3. **Reverse Iterators**: Traverse containers in reverse order
4. **Move Iterators**: Transfer ownership of pointed elements (C++11)

#### Code Example: Using Different Iterator Types

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};

    // Regular iterator
    auto it = vec.begin();
    std::cout << "First element: " << *it << '\n';

    // Const iterator
    auto cit = vec.cbegin();
    // *cit = 10; // Error: read-only access

    // Reverse iterator
    auto rit = vec.rbegin();
    std::cout << "Last element: " << *rit << '\n';

    // Using algorithms with iterators
    std::for_each(vec.begin(), vec.end(), [](int& n) { n *= 2; });
}
```

#### Modern C++ Iterator Concepts

C++20 introduced iterator concepts, providing more precise requirements for iterators:

- `std::input_iterator`
- `std::output_iterator`
- `std::forward_iterator`
- `std::bidirectional_iterator`
- `std::random_access_iterator`
- `std::contiguous_iterator`


<div class="page"/>

### 57. What are *function objects* (functors) in *STL*?

**Function objects**, commonly known as **functors**, are a powerful feature in C++ that allow function calls to be treated as first-class objects. They are particularly useful when working with **STL algorithms**.

#### Key Characteristics of STL Algorithms

- **Generic Design**: STL algorithms are designed to work with iterators, making them adaptable to various scenarios.
- **Flexible Callable Objects**: These algorithms can be used with:
    - Function pointers
    - `std::function` objects
    - Functors

This flexibility enables functors to introduce complex strategies into algorithms.

#### Anatomy of Functors

Functors are **user-defined types** that emulate **function-callable objects** by overloading the `operator()`. This unique feature allows them to:

- Act like functions
- Maintain **state**
- Be **task-specific**

#### Advantages of Functors over Function Pointers

1. **Statefulness**: Functors can carry and modify internal state across invocations.
2. **Performance**: Modern compilers can often optimize inlined functor calls better than function pointers.

#### Types of Functors

1. **Traditional Class Functors**: Classes that define `operator()`. They can have member variables for maintaining state.

2. **Lambda Expressions**: Introduced in C++11, lambdas can be viewed as **anonymous functors**, ideal for short-lived or one-time functor needs.

#### Code Example: Unary Predicate Functor

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven {
    bool operator()(int num) const {
        return num % 2 == 0;
    }
};

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Using IsEven functor with std::remove_if
    auto newEnd = std::remove_if(nums.begin(), nums.end(), IsEven{});
    nums.erase(newEnd, nums.end());

    for (int num : nums) {
        std::cout << num << " ";
    }
    // Output: 1 3 5 7 9 
    return 0;
}
```

#### Code Example: Stateful Binary Operation Functor

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

struct SumWithAccumulator {
    int total = 0;

    int operator()(int num) {
        return total += num;
    }
};

int main() {
    std::vector<int> nums {1, 2, 3, 4, 5};

    // Using SumWithAccumulator functor with std::transform
    std::transform(nums.begin(), nums.end(), nums.begin(), SumWithAccumulator{});

    for (int num : nums) {
        std::cout << num << " ";
    }
    // Output: 1 3 6 10 15 
    return 0;
}
```

#### Modern C++ Enhancements

- Since C++11, **lambda expressions** provide a concise way to create inline functors:

```cpp
auto isEven = [](int num) { return num % 2 == 0; };
auto newEnd = std::remove_if(nums.begin(), nums.end(), isEven);
```

- C++14 introduced **generic lambdas**, allowing for more flexible functor-like objects:

```cpp
auto genericPredicate = [](auto const& item) { return item > 0; };
```

- C++17 added **class template argument deduction**, simplifying functor creation:

```cpp
std::greater greater; // Instead of std::greater<int> greater;
```


<div class="page"/>

### 58. How do you use *algorithms* like *sort*, *find*, and *binary_search* in *STL*?

The C++ Standard Template Library (**STL**) provides a rich set of algorithms through the `<algorithm>` header. These algorithms can operate on various **STL** containers such as vectors, lists, sets, and maps.

#### Basic Algorithm Structure

- **Function Syntax**: Algorithms usually take two iterators that define a range and sometimes a predicate or comparator.
- **Return Value**: Most algorithms return an iterator pointing to the first element after the operation.

#### Commonly Used Algorithms

##### Sorting Algorithms

- **`std::sort`**: Reorders elements in a range.
- **`std::stable_sort`**: Sorts elements while preserving the relative order of equal elements.
- **`std::partial_sort`**: Sorts some elements in a range.
- **`std::is_sorted`**: Checks if a range is sorted.

##### Searching Algorithms

- **`std::find`**: Finds a value in a range.
- **`std::find_if`**: Finds an element satisfying a predicate.
- **`std::binary_search`**: Checks if a value exists in a sorted range.
- **`std::lower_bound`** and **`std::upper_bound`**: Find boundaries for a value in a sorted range.

#### Code Example

Using `std::sort`, `std::find`, and `std::binary_search`:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 8, 10, 1, 3, 6};

    // Sort the vector in ascending order
    std::sort(numbers.begin(), numbers.end());

    // Use std::find to locate a value
    int numToFind = 6;
    auto it = std::find(numbers.begin(), numbers.end(), numToFind);

    if (it != numbers.end()) {
        std::cout << numToFind << " found at index: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << numToFind << " not found in the vector" << std::endl;
    }

    // Use std::binary_search on the sorted vector
    int numToSearch = 7;
    bool found = std::binary_search(numbers.begin(), numbers.end(), numToSearch);

    std::cout << numToSearch << (found ? " exists" : " does not exist") << " in the sorted vector" << std::endl;

    return 0;
}
```

##### Output

```
6 found at index: 4
7 does not exist in the sorted vector
```

#### Performance Considerations

- **`std::sort`**: $O(n \log n)$ complexity on average.
- **`std::find`**: $O(n)$ complexity for unsorted ranges.
- **`std::binary_search`**: $O(\log n)$ complexity for sorted ranges.

#### Custom Comparators

Many STL algorithms allow custom comparators for more flexible sorting and searching:

```cpp
std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return std::abs(a) < std::abs(b);  // Sort by absolute value
});
```


<div class="page"/>

### 59. What is the purpose of *std::pair* and *std::tuple*?

In C++, **std::pair** and **std::tuple** are template classes that allow for the storage and handling of fixed collections of heterogeneous data. While both serve this common purpose, each has unique attributes and ideal use-cases.

#### std::pair

**std::pair** is designed for scenarios where exactly two elements need to be bundled together. It’s part of the `<utility>` header.

##### Key features:

- Stores **two** elements of potentially different types
- Elements are accessed using `.first` and `.second` member variables
- Provides comparison operators based on lexicographical order

##### Common use-cases:

- **Key-value pairs**: Particularly useful in associative containers like `std::map`
- **Function returns**: When a function needs to return two values

#### std::tuple

**std::tuple** is more flexible and can accommodate a variable number of elements. It’s defined in the `<tuple>` header.

##### Key features:

- Can store **any number** of elements of potentially different types
- Elements are accessed using `std::get<N>()` where N is the index
- Provides comparison operators based on lexicographical order
- Since C++14, `std::tuple` can have any number of elements (previously limited to an implementation-defined maximum)

##### Common use-cases:

- **Multiple return values**: When a function needs to return more than two values
- **Heterogeneous collections**: Storing a known but variable (at compile-time) number of elements of different types

#### Code Example

Here’s a C++ code example demonstrating the use of both `std::pair` and `std::tuple`:

```cpp
#include <iostream>
#include <utility>
#include <tuple>
#include <string>

// Function using std::pair
std::pair<bool, int> divide(int a, int b) {
    if (b == 0) return {false, 0};
    return {true, a / b};
}

// Function using std::tuple
std::tuple<bool, double, std::string> process_data(double value) {
    if (value < 0) return {false, 0.0, "Error: Negative input"};
    double result = value * 2;
    return {true, result, "Success"};
}

int main() {
    // Using std::pair
    auto div_result = divide(10, 2);
    if (div_result.first) {
        std::cout << "Division result: " << div_result.second << std::endl;
    }

    // Using std::tuple
    auto [success, result, message] = process_data(5.0);
    if (success) {
        std::cout << "Processed result: " << result << ", Message: " << message << std::endl;
    }

    return 0;
}
```

In this example, `std::pair` is used to return a boolean status and an integer result from the `divide` function. `std::tuple` is used to return a boolean status, a double result, and a string message from the `process_data` function.

Note the use of **structured binding** (C++17 feature) to unpack the tuple in the `main` function, which provides a convenient way to access tuple elements.


<div class="page"/>

### 60. Explain the concept of *allocators* in *STL*.

**Allocators** in the C++ Standard Template Library (STL) are objects that handle memory allocation and deallocation for containers. They provide an abstraction layer between containers and memory management, allowing for customized memory handling strategies.

#### Key Concepts

- **Separation of Concerns**: Allocators separate memory management from object construction and destruction.
- **Customization**: Containers can use custom allocators, enabling specialized memory management strategies.
- **Default Allocator**: `std::allocator` is the default allocator used by STL containers.

#### Allocator Requirements

Allocators must fulfill certain requirements to be used with STL containers:

##### Memory Management

- `allocate(size_t n)`: Allocates uninitialized storage for `n` objects.
- `deallocate(T* p, size_t n)`: Deallocates storage pointed to by `p`.

##### Object Lifetime Management

- `construct(T* p, Args&&... args)`: Constructs an object at `p` using the provided arguments.
- `destroy(T* p)`: Destroys the object pointed to by `p`.

##### Other Requirements

- `max_size()`: Returns the largest supported allocation size.
- `select_on_container_copy_construction()`: Creates a new allocator instance for container copy construction.

#### Standard Allocator Types

1. **`std::allocator<T>`**

    - Default allocator used by STL containers.
    - Uses `operator new` and `operator delete` for memory management.
2. **`std::pmr::polymorphic_allocator<T>`** (C++17)

    - Allows runtime polymorphic memory allocation.
    - Works with memory resources to enable custom allocation strategies.

#### Custom Allocator Example

Here’s an example of a simple custom allocator:

```cpp
#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class SimpleAllocator {
public:
    using value_type = T;

    SimpleAllocator() noexcept {}
    template <class U> SimpleAllocator(const SimpleAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        ::operator delete(p);
    }
};

int main() {
    std::vector<int, SimpleAllocator<int>> vec;
    vec.push_back(42);
    std::cout << "Vector size: " << vec.size() << std::endl;
    return 0;
}
```

#### Benefits of Using Custom Allocators

1. **Performance Optimization**: Tailored memory management for specific use cases.
2. **Memory Tracking**: Implement custom allocators for debugging or profiling memory usage.
3. **Memory Pooling**: Efficient allocation for frequently created/destroyed objects.
4. **Specialized Hardware**: Optimize for specific memory architectures or devices.

#### C++17 and Beyond

- **Polymorphic Allocators**: C++17 introduced `std::pmr::polymorphic_allocator` for more flexible memory management.
- **Allocator Traits**: Use `std::allocator_traits` to work with allocators, providing default implementations for some allocator functions.

* * *

## Concurrency and Multithreading

* * *


<div class="page"/>

### 61. What is *multithreading* in *C++*?

**Multithreading** in C++ involves using multiple **threads** to execute code concurrently. This technique is valuable for improving program performance and responsiveness, especially in CPU-bound and I/O-bound tasks.

#### Key Multithreading Concepts

- **Thread**: The basic unit of CPU utilization. Threads within a process share the same memory space.
- **Concurrency**: The property that enables multiple tasks to make progress over time.
- **Parallelism**: Occurs when multiple tasks literally execute simultaneously on different CPU cores.

#### Thread Support in C++

C++11 and later versions provide built-in support for multithreading:

- `std::thread`: From the `<thread>` header. Provides a high-level interface for managing threads.
- `std::async`: Offers high-level abstractions for tasks that may run asynchronously.
- **Thread-safe components**: Various standard library components are designed to be thread-safe.

#### Thread Safety

Ensuring **thread safety** is critical for avoiding issues like data races and deadlocks.

- **Thread-Safe**: Objects or functions that can be safely used or called from multiple threads simultaneously.
- **Not Thread-Safe**: Objects or functions that are not equipped to handle concurrent access and can lead to issues when used by multiple threads at once.

#### Thread Safety Mechanisms

- **Mutexes**: Synchronization primitives that ensure only one thread at a time can execute a critical section of code.
- **Atomic Operations**: Provide a way to ensure data integrity without explicit locking.
- **Lock-free Programming**: Techniques to design algorithms that don’t require explicit locks.

#### Code Example: Simple Counter with Thread Safety

Here’s a C++ example demonstrating a thread-safe counter using `std::atomic`:

```cpp
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 100000; ++i) {
        counter++;  // Thread-safe increment
    }
}

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementCounter);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Counter: " << counter << std::endl;
    return 0;
}
```

#### Modern C++ Threading Features

- **std::jthread** (C++20): Automatically joins on destruction, simplifying thread management.
- **Parallel Algorithms** (C++17): Standard algorithms with parallel execution policies.
- **std::latch** and **std::barrier** (C++20): Synchronization primitives for managing groups of threads.


<div class="page"/>

### 62. How do you create and manage *threads* using *std::thread*?

`std::thread` provides a powerful way to work with threads in C++. Here’s how to create and manage threads effectively:

#### Thread Creation

You can create a thread by instantiating a `std::thread` object and associating it with a callable entity:

```cpp
#include <iostream>
#include <thread>

void threadFunction() {
    std::cout << "Hello from a thread!\n";
}

int main() {
    // Create thread with a function
    std::thread t1(threadFunction);

    // Create thread with a lambda
    std::thread t2([]() { 
        std::cout << "Hello from a lambda thread!\n"; 
    });

    // Join both threads
    t1.join();
    t2.join();

    return 0;
}
```

#### Thread Management

##### Joining Threads

Use `join()` to wait for a thread to complete:

```cpp
std::thread t(threadFunction);
t.join(); // Wait for t to finish
```

##### Detaching Threads

Use `detach()` to allow a thread to run independently:

```cpp
std::thread t(threadFunction);
t.detach(); // t runs independently
```

##### Checking Joinability

Before joining or detaching, check if a thread is joinable:

```cpp
if (t.joinable()) {
    t.join(); // or t.detach();
}
```

#### Thread Ownership and Moving

Threads are move-only objects. You can transfer ownership using `std::move`:

```cpp
std::thread t1(threadFunction);
std::thread t2 = std::move(t1); // t2 now owns the thread
```

#### Passing Arguments to Threads

Pass arguments to thread functions by providing them after the function name:

```cpp
void threadFunction(int x, std::string str) {
    std::cout << "Received: " << x << ", " << str << std::endl;
}

int main() {
    std::thread t(threadFunction, 42, "Hello");
    t.join();
    return 0;
}
```

#### Thread Safety and Synchronization

When working with shared resources, use synchronization primitives:

##### Mutexes

```cpp
#include <mutex>

std::mutex mtx;
int sharedResource = 0;

void threadFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    sharedResource++; // Safe access
}
```

##### Condition Variables

```cpp
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
bool ready = false;

void waitForSignal() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });
    // Do work after receiving signal
}

void sendSignal() {
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
}
```

#### Best Practices

1. **Prefer `std::jthread` (C++20)**: It automatically joins on destruction, simplifying resource management.

2. **Use `std::async` for tasks with return values**: It’s more convenient for managing futures.

3. **Avoid detached threads**: They can lead to resource leaks and hard-to-debug issues.

4. **Handle exceptions**: Use `try-catch` in thread functions to prevent unhandled exceptions from terminating the program.

5. **Be cautious with shared resources**: Always use proper synchronization mechanisms when accessing shared data.


<div class="page"/>

### 63. Explain the concept of *mutex* and its *types* in *C++*.

A **mutex** (short for “mutual exclusion”) in C++ is a synchronization primitive used to protect shared resources in multi-threaded environments. It ensures that **only one thread** can access a shared resource at a time, preventing data races and maintaining thread safety.

#### Types of Mutex in C++

C++ provides several types of mutexes, each with specific characteristics:

1. **`std::mutex`**: Basic mutex for exclusive ownership
2. **`std::recursive_mutex`**: Allows the same thread to lock multiple times
3. **`std::timed_mutex`**: Supports timed lock attempts
4. **`std::recursive_timed_mutex`**: Combines features of recursive and timed mutexes
5. **`std::shared_mutex`** (C++17): Supports multiple readers or a single writer

#### Basic Usage of std::mutex

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

void sharedResourceAccess(int threadId) {
    std::lock_guard<std::mutex> lock(m);  // RAII-style locking
    std::cout << "Thread " << threadId << " is accessing the shared resource.\n";
}

int main() {
    std::thread t1(sharedResourceAccess, 1);
    std::thread t2(sharedResourceAccess, 2);

    t1.join();
    t2.join();

    return 0;
}
```

In this example, `std::lock_guard` provides exception-safe locking, automatically releasing the mutex when the guard goes out of scope.

#### std::recursive_mutex for Nested Locking

```cpp
#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rm;

void processSubTask(int taskId) {
    std::lock_guard<std::recursive_mutex> lock(rm);
    std::cout << "Processing sub-task " << taskId << "\n";

    if (taskId == 2) {
        std::lock_guard<std::recursive_mutex> nestedLock(rm);
        std::cout << "Nested lock in sub-task 2\n";
    }
}

void sharedResourceAccess(int threadId) {
    std::lock_guard<std::recursive_mutex> lock(rm);
    std::cout << "Thread " << threadId << " is accessing the shared resource.\n";
    processSubTask(threadId);
}
```

`std::recursive_mutex` allows the same thread to acquire the lock multiple times, which is useful for recursive algorithms or nested function calls.

#### std::timed_mutex for Time-Bound Locking

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tm;

void sharedResourceAccess(int threadId) {
    if (tm.try_lock_for(std::chrono::seconds(1))) {
        std::cout << "Thread " << threadId << " acquired the timed_mutex.\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        tm.unlock();
    } else {
        std::cout << "Thread " << threadId << " failed to acquire the timed_mutex.\n";
    }
}
```

`std::timed_mutex` allows attempts to acquire the lock with a timeout, useful for avoiding deadlocks or implementing more complex synchronization patterns.

#### std::shared_mutex for Reader-Writer Locks (C++17)

```cpp
#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>

std::shared_mutex sharedMutex;
int sharedData = 0;

void reader(int id) {
    std::shared_lock<std::shared_mutex> lock(sharedMutex);
    std::cout << "Reader " << id << " reads: " << sharedData << "\n";
}

void writer(int id) {
    std::unique_lock<std::shared_mutex> lock(sharedMutex);
    sharedData++;
    std::cout << "Writer " << id << " writes: " << sharedData << "\n";
}
```

`std::shared_mutex` allows multiple threads to read simultaneously while ensuring exclusive access for writers, optimizing scenarios with frequent reads and occasional writes.


<div class="page"/>

### 64. What is a *deadlock* and how can it be prevented?

A **deadlock** is a situation in a concurrent system where two or more processes are unable to proceed because each is waiting for the other to release resources. In a deadlock, **resources are tied up** and the system may halt, leading to reduced efficiency and potential data loss.

#### Core Components of Deadlock

Four conditions, known as the **Coffman conditions**, must be present simultaneously for a deadlock to occur:

1. **Mutual Exclusion**: At least one resource must be held in a non-sharable mode.
2. **Hold and Wait**: Processes must be holding at least one resource while waiting to acquire additional resources held by other processes.
3. **No Preemption**: Resources cannot be forcibly taken away from a process; they must be released voluntarily.
4. **Circular Wait**: A circular chain of two or more processes exists, each waiting for a resource held by the next process in the chain.

#### Deadlock Prevention Strategies

To prevent deadlocks, at least one of the Coffman conditions must be eliminated:

1. **Eliminate Mutual Exclusion**:

    - Not always possible as some resources, like printers, are inherently non-sharable.
2. **Eliminate Hold and Wait**:

    - Require processes to request all needed resources at once before starting.
    - Force processes to release all held resources before requesting new ones.
3. **Allow Preemption**:

    - Implement a system where resources can be forcibly taken from processes.
4. **Prevent Circular Wait**:

    - Impose a total ordering of resource types and require processes to request resources in that order.

#### Code Example: Resource Ordering

Here’s a C++ example demonstrating resource ordering to prevent deadlock:

```cpp
#include <mutex>
#include <thread>

class Resource {
public:
    Resource(int id) : id_(id) {}
    void lock() { mutex_.lock(); }
    void unlock() { mutex_.unlock(); }
    int getId() const { return id_; }

private:
    std::mutex mutex_;
    int id_;
};

void useResources(Resource& r1, Resource& r2) {
    Resource& first = (r1.getId() < r2.getId()) ? r1 : r2;
    Resource& second = (r1.getId() < r2.getId()) ? r2 : r1;

    std::lock_guard<Resource> lock1(first);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<Resource> lock2(second);

    // Use resources...
}

int main() {
    Resource r1(1), r2(2);

    std::thread t1([&]() { useResources(r1, r2); });
    std::thread t2([&]() { useResources(r2, r1); });

    t1.join();
    t2.join();

    return 0;
}
```

In this example, resources are always locked in order of their IDs, preventing circular wait and thus avoiding deadlock.

#### Modern Approaches

1. **Lock-Free and Wait-Free Algorithms**: These algorithms avoid using locks altogether, eliminating the possibility of deadlocks.

2. **Transactional Memory**: This approach allows for atomic execution of a group of load and store instructions, simplifying concurrent programming and reducing deadlock risks.

3. **Deadlock Detection and Recovery**: In some systems, it’s more efficient to allow deadlocks to occur and then detect and recover from them, rather than trying to prevent them entirely.


<div class="page"/>

### 65. How do you use *condition variables* for *thread synchronization*?

**Condition variables** are synchronization primitives in C++ used for thread coordination. They allow threads to wait for a specific condition to become true before proceeding. The `std::condition_variable` class, available in the `<condition_variable>` header, is the primary tool for implementing this mechanism.

#### Basic Usage of Condition Variables

A condition variable is typically used in conjunction with a `std::mutex` and a `std::unique_lock`. Here’s a general pattern:

```cpp
std::mutex mtx;
std::condition_variable cv;
bool condition = false;

// Waiting thread
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return condition; });
    // Process the condition
}

// Notifying thread
{
    std::lock_guard<std::mutex> lock(mtx);
    condition = true;
    cv.notify_one(); // or cv.notify_all()
}
```

#### Key Functions

1. `wait(lock)`: Blocks the thread until notified.
2. `wait(lock, predicate)`: Blocks the thread until notified and the predicate returns true.
3. `notify_one()`: Wakes up one waiting thread.
4. `notify_all()`: Wakes up all waiting threads.

#### Practical Example: Producer-Consumer Pattern

Here’s a more comprehensive example demonstrating a producer-consumer scenario:

```cpp
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const int max_buffer_size = 10;
std::mutex mtx;
std::condition_variable buffer_not_full;
std::condition_variable buffer_not_empty;

void producer(int id) {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        buffer_not_full.wait(lock, []{ return buffer.size() < max_buffer_size; });

        buffer.push(i);
        std::cout << "Producer " << id << " produced: " << i << std::endl;

        lock.unlock();
        buffer_not_empty.notify_one();
    }
}

void consumer(int id) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        buffer_not_empty.wait(lock, []{ return !buffer.empty(); });

        int value = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed: " << value << std::endl;

        lock.unlock();
        buffer_not_full.notify_one();
    }
}

int main() {
    std::thread p1(producer, 1);
    std::thread p2(producer, 2);
    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);

    p1.join(); p2.join(); c1.join(); c2.join();
    return 0;
}
```

#### Waiting with a Timeout

C++11 introduced `wait_for` and `wait_until` to allow waiting with a timeout:

```cpp
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::unique_lock<std::mutex> lock(mtx);
    if (cv.wait_for(lock, std::chrono::seconds(1), []{ return ready; })) {
        // Condition became true within the timeout
    } else {
        // Timeout occurred
    }
}
```

#### Best Practices

1. Always use condition variables with a mutex to protect shared data.
2. Use the predicate version of `wait` to guard against spurious wakeups.
3. Prefer `notify_one()` when only one thread needs to be woken up.
4. Use `notify_all()` when multiple threads might be waiting and all need to check the condition.


<div class="page"/>

### 66. What is the purpose of *std::atomic*?

`std::atomic` is a powerful tool in C++ for handling concurrent data access and ensuring memory visibility in multithreaded programs. It achieves **synchronization** through hardware and memory model support, making operations more efficient than traditional locks.

#### Key Features

- **Thread Safety**: Operations on `std::atomic` types are inherently atomic, guaranteeing no data races.
- **Memory Visibility**: Changes made to an atomic variable are immediately visible to other threads.
- **Efficiency**: The use of `std::memory_order` specifications allows for tailored synchronization without incurring unnecessary overhead.

#### Mechanism Behind `std::atomic`

Under the hood, `std::atomic` leverages hardware support, such as **Compare-And-Swap (CAS)** instructions on architectures like x86, to ensure variables are modified atomically.

While the exact implementation details can vary across different hardware and compilers, the consistent behavior is that operations on `std::atomic` types are either fully completed or not visible to other threads at all. This “all or nothing” guarantee supports data integrity in concurrent environments.

#### Code Example: Using std::atomic

Here’s a C++ code example demonstrating the correct usage of `std::atomic<int>`:

```cpp
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> sharedValue(0);

void incrementSharedValue() {
    for (int i = 0; i < 1000000; ++i) {
        sharedValue.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(incrementSharedValue);
    std::thread t2(incrementSharedValue);

    t1.join();
    t2.join();

    std::cout << "Final shared value: " << sharedValue.load() << std::endl;

    return 0;
}
```

In this example, we use `std::atomic<int>` instead of `std::atomic_int` (which is a typedef) for clarity. The `fetch_add` function is used to perform an atomic increment operation, ensuring thread safety. The `std::memory_order_relaxed` argument specifies that no synchronization is needed beyond the atomicity of this single operation.

#### Important Considerations

1. **Atomic Operations**: Use atomic operations like `fetch_add`, `compare_exchange_weak`, etc., to ensure thread-safe modifications.
2. **Memory Ordering**: Understand and use appropriate memory ordering constraints (`std::memory_order`) to balance performance and synchronization needs.
3. **Atomic Types**: `std::atomic` can be used with various types, including user-defined types that satisfy certain criteria.
4. **Performance**: While more efficient than locks for simple operations, complex atomic operations can still have performance implications.


<div class="page"/>

### 67. Explain the *difference* between *std::async* and *std::thread*.

Both `std::thread` and `std::async` are mechanisms for **concurrent execution** in C++11 and later standards, but they have distinct features and use-cases.

#### Core Distinctions

- `std::thread` is a **low-level threading tool** directly linked to a hardware thread (on most systems). `std::async` is a **higher-level construct** that enables task-based parallelism, often utilizing a thread from a **thread pool**.

- With `std::thread`, you have **direct control** over when the thread starts via its constructor. `std::async` offers different **launch policies** for managing the initiation of the asynchronous operation.

- Threads created with `std::thread` are **eagerly evaluated**; they start running immediately upon construction. `std::async` with the default policy (`std::launch::async | std::launch::deferred`) can start the task either immediately or defer its execution.

#### Ownership and Execution

- `std::thread` requires explicit passing of the function or function object to be executed.

- `std::async` allows providing a function or function object directly, or creating a task from a function and its arguments.

#### Return Values

- Both support **return values** from the executed function.

- For `std::thread`, retrieving the return value requires joining the thread or using inter-thread communication (e.g., `std::promise` and `std::future`).

- `std::async` conveniently returns a `std::future` for accessing the result.

#### Error Handling

- Unhandled exceptions in `std::thread` terminate the entire application unless caught within the thread function.

- `std::async` propagates exceptions to the `std::future` object, allowing them to be caught when retrieving the result.

#### Use Cases

- Use `std::thread` for fine-grained control over thread execution or when using platform-specific thread features.

- Prefer `std::async` for task-focused parallelism and when you want to abstract away thread management details.

#### Code Example: std::thread

```cpp
#include <iostream>
#include <thread>

void backgroundTask() {
    std::cout << "Running on a background thread\n";
}

int main() {
    std::thread t(backgroundTask);
    t.join();  // Wait for the thread to finish
    return 0;
}
```

#### Code Example: std::async

```cpp
#include <iostream>
#include <future>

int computeResult() {
    return 42;
}

int main() {
    std::future<int> result = std::async(std::launch::async, computeResult);
    std::cout << "Result from async task: " << result.get() << "\n";
    return 0;
}
```

#### Performance Considerations

- `std::thread` may have lower overhead for long-running tasks or when fine-grained control is needed.

- `std::async` can be more efficient for short-lived tasks due to potential thread pooling, especially in scenarios with many small tasks.

#### C++20 Updates

- C++20 introduces `std::jthread`, which automatically joins on destruction, simplifying thread management.

- `std::async` remains largely unchanged in C++20, but benefits from general improvements to the standard library’s concurrency support.


<div class="page"/>

### 68. What is a *thread pool* and how would you implement one?

A **thread pool** is a managed group of threads designed to efficiently process tasks in a multi-threaded environment. It offers performance benefits by reusing threads instead of creating and destroying them for individual tasks.

#### Core Components

1. **Task**: A unit of work that is submitted to the thread pool for execution.
2. **Work Queue**: A queue or other data structure that holds tasks until a thread is available to execute them.
3. **Threads**: The workers that execute tasks. They continuously monitor the work queue and pick up tasks as they become available.
4. **Lifecycle Methods**: Functions to start, stop, and manage the state of the thread pool.

#### Code Example: Basic Thread Pool

Here’s a modern C++17 implementation of a basic thread pool:

```cpp
#include <iostream>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <future>

class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) -> std::future<typename std::invoke_result<F, Args...>::type> {
        using return_type = typename std::invoke_result<F, Args...>::type;
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            if (stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");
            tasks.emplace([task]() { (*task)(); });
        }
        condition.notify_one();
        return res;
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker : workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
};

int main() {
    ThreadPool pool(4);

    std::vector<std::future<int>> results;

    for (int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "Task " << i << " executed by thread: " << std::this_thread::get_id() << std::endl;
                return i * i;
            })
        );
    }

    for (auto &result : results)
        std::cout << "Result: " << result.get() << std::endl;

    return 0;
}
```

This implementation uses:

- `std::vector<std::thread>` as the **thread container**
- `std::queue<std::function<void()>>` as the **work queue**
- `std::mutex`, `std::condition_variable`, and `std::unique_lock` for **thread synchronization**
- `std::atomic<bool>` for the **stop flag**, ensuring thread-safe access
- `std::future` to allow tasks to return values asynchronously

The `enqueue` function is now a template that can accept any callable object and its arguments. It returns a `std::future` object, allowing the caller to retrieve the result of the task execution.


<div class="page"/>

### 69. How do you handle *race conditions* in *C++*?

**Race conditions** occur when multiple threads access shared data concurrently, and at least one thread modifies the data. This can lead to unpredictable behavior and hard-to-reproduce bugs. Here are several ways to handle race conditions in C++:

#### Synchronization Primitives

##### Mutexes

C++ provides various mutex types in the `<mutex>` header:

- **`std::mutex`**: Basic mutex for exclusive access
- **`std::recursive_mutex`**: Allows the same thread to lock multiple times
- **`std::timed_mutex`**: Supports timed lock attempts
- **`std::shared_mutex`** (C++17): Allows multiple readers or one writer

Use these with RAII wrappers like `std::lock_guard`, `std::unique_lock`, or `std::scoped_lock` (C++17) for automatic locking and unlocking.

```cpp
#include <mutex>
#include <thread>

std::mutex m;
int shared_data = 0;

void increment() {
    std::lock_guard<std::mutex> lock(m);
    shared_data++;
}
```

##### Atomic Operations

Use `std::atomic` types from the `<atomic>` header for lock-free operations:

```cpp
#include <atomic>
#include <thread>

std::atomic<int> counter(0);

void increment() {
    counter++;  // Atomic operation
}
```

#### Advanced Techniques

##### Memory Ordering

C++20 introduced **memory_order** constants to fine-tune atomic operations:

```cpp
std::atomic<int> flag(0);
flag.store(1, std::memory_order_release);
int value = flag.load(std::memory_order_acquire);
```

##### Lock-Free Data Structures

Implement lock-free algorithms using atomic operations and careful design:

```cpp
template<typename T>
class LockFreeStack {
    struct Node {
        T data;
        std::atomic<Node*> next;
    };
    std::atomic<Node*> head;

public:
    void push(T value) {
        Node* new_node = new Node{value};
        do {
            new_node->next = head.load(std::memory_order_relaxed);
        } while (!head.compare_exchange_weak(new_node->next, new_node,
                                             std::memory_order_release,
                                             std::memory_order_relaxed));
    }
    // ... pop and other methods
};
```

##### Thread-Local Storage

Use `thread_local` for data that should be unique to each thread:

```cpp
thread_local int per_thread_counter = 0;

void increment_local() {
    per_thread_counter++;  // No race condition
}
```

#### Best Practices

1. **Minimize Shared Data**: Design your program to reduce the need for shared mutable state.
2. **Use High-Level Abstractions**: Prefer `std::async`, `std::future`, and `std::promise` over raw threads when possible.
3. **Consider Lock-Free Algorithms**: For performance-critical sections, lock-free algorithms can provide better scalability.
4. **Use Static Analysis Tools**: Employ tools like Clang’s Thread Safety Analysis to detect potential race conditions at compile-time.

#### Example: Combining Techniques

Here’s an example that combines atomic operations and mutexes:

```cpp
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>

class ThreadSafeCounter {
    std::atomic<int> fast_counter{0};
    mutable std::mutex m;
    int precise_counter{0};

public:
    void increment() {
        fast_counter++;
        std::lock_guard<std::mutex> lock(m);
        precise_counter++;
    }

    int get_fast_count() const {
        return fast_counter.load(std::memory_order_relaxed);
    }

    int get_precise_count() const {
        std::lock_guard<std::mutex> lock(m);
        return precise_counter;
    }
};
```


<div class="page"/>

### 70. Explain the concept of *memory ordering* in *C++ concurrency*.

**Memory ordering** in C++ concurrency refers to the rules governing how memory operations (reads and writes) are observed and synchronized across multiple threads. It’s a crucial concept for ensuring correct behavior in multi-threaded programs.

#### The Need for Memory Ordering

In modern computer architectures, each CPU core often has its own **cache**. Without proper synchronization, these caches can become inconsistent with main memory, leading to **data races** and other concurrency issues.

#### `std::atomic` and Memory Ordering

C++ provides the `std::atomic` template class to ensure **atomic operations**. When using `std::atomic`, you can specify the desired memory ordering for each operation.

#### Types of Memory Ordering

C++ defines six memory ordering options:

1. `std::memory_order_relaxed`: No synchronization or ordering constraints.
2. `std::memory_order_consume`: Ensures ordering of dependent operations (deprecated in C++17).
3. `std::memory_order_acquire`: Synchronizes with a release operation.
4. `std::memory_order_release`: Synchronizes with an acquire operation.
5. `std::memory_order_acq_rel`: Combines acquire and release semantics.
6. `std::memory_order_seq_cst`: Provides sequential consistency (default).

##### Code Example: Relaxed Ordering

```cpp
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter.load(std::memory_order_relaxed) << std::endl;
    return 0;
}
```

This example uses `std::memory_order_relaxed`, which provides no synchronization guarantees but is fast for operations like simple counters.

##### Code Example: Acquire-Release Ordering

```cpp
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<bool> ready(false);
int data = 0;

void producer() {
    data = 42;  // Prepare data
    ready.store(true, std::memory_order_release);
}

void consumer() {
    while (!ready.load(std::memory_order_acquire)) {
        // Wait
    }
    std::cout << "Data: " << data << std::endl;
}

int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
```

This example demonstrates `std::memory_order_release` and `std::memory_order_acquire` to ensure that the `data` write in the producer is visible to the consumer.

##### Code Example: Sequential Consistency

```cpp
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> x(0), y(0);

void thread1() {
    x.store(1, std::memory_order_seq_cst);
    int r1 = y.load(std::memory_order_seq_cst);
    std::cout << "Thread 1: r1 = " << r1 << std::endl;
}

void thread2() {
    y.store(1, std::memory_order_seq_cst);
    int r2 = x.load(std::memory_order_seq_cst);
    std::cout << "Thread 2: r2 = " << r2 << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}
```

This example uses `std::memory_order_seq_cst`, which provides the strongest guarantees but may have performance implications on some architectures.

* * *

## C++11 and Beyond Features

* * *


<div class="page"/>

### 71. What are *lambda expressions* in *C++*?

A **lambda expression** in C++ is a concise way to define an **unnamed function object**. It’s particularly useful for creating simple functions on-the-fly, often used in scenarios like sorting, filtering, or mapping.

#### Syntax

The general form of a lambda expression is:

```cpp
[capture-list] (parameters) specifiers -> return-type {
    // function body
}
```

Where:

- `capture-list`: Specifies which variables from the enclosing scope are accessible.
- `parameters`: The function parameters (can be omitted if empty).
- `specifiers`: Optional modifiers like `mutable`, `constexpr`, or `consteval`.
- `return-type`: The function’s return type (can be omitted for automatic deduction).

#### Capture Modes

Lambdas can capture variables from their enclosing scope using various modes:

- **By Value**: `[=]` or `[var1, var2]`
- **By Reference**: `[&]` or `[&var1, &var2]`
- **Mixed**: `[=, &var1]` or `[&, var2]`
- **This**: `[this]` or `[*this]` (C++17)

#### Code Example: Basic Lambda

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {4, 1, 3, 5, 2};

    // Lambda to print a number
    auto print = [](int n) { std::cout << n << ' '; };

    // Using lambda with std::for_each
    std::for_each(numbers.begin(), numbers.end(), print);

    return 0;
}
```

#### Advanced Features (C++14 and beyond)

1. **Generic Lambdas** (C++14):

    ```cpp
    auto generic = [](auto x, auto y) { return x + y; };
    ```

2. **Capture with Initialization** (C++14):

    ```cpp
    int x = 5;
    auto lambda = [y = x + 1]() { return y; };
    ```

3. **Constexpr Lambdas** (C++17):

    ```cpp
    constexpr auto square = [](int n) { return n * n; };
    ```

4. **Lambda Capture of `*this`** (C++17):

    ```cpp
    struct S {
        int data = 0;
        auto f() {
            return [*this]() { return data; };
        }
    };
    ```

5. **Template Lambdas** (C++20):

    ```cpp
    auto lambda = []<typename T>(T x, T y) { return x + y; };
    ```

Lambdas in C++ are essentially **closures**, capturing and preserving the state of variables from their enclosing scope, even after that scope has exited. This makes them powerful for creating context-dependent functions inline.


<div class="page"/>

### 72. Explain the ‘*auto*’ keyword and *type inference*.

The `auto` keyword in C++ is closely associated with **type inference**, a feature introduced in C++11 that allows the compiler to automatically deduce a variable’s type based on its initializer. This capability enhances code readability and reduces the need for explicit type declarations.

#### Key Uses of `auto`

##### Complex Type Declarations

`auto` simplifies declarations involving complex or templated types:

```cpp
std::map<std::string, std::vector<int>>::iterator it = myMap.begin();
// Can be simplified to:
auto it = myMap.begin();
```

##### Improving Readability

It can make code more concise and easier to understand:

```cpp
for (const auto& element : container) {
    // Use element
}
```

##### Facilitating Refactoring

`auto` helps maintain type consistency during code refactoring:

```cpp
auto result = complexFunction();
// The type of 'result' automatically adapts if complexFunction's return type changes
```

#### Limitations and Considerations

- The initializer must provide unambiguous type information for `auto` to work correctly.
- `auto` is resolved at compile-time, not suitable for runtime type changes.
- Overuse can potentially obscure code intent in some cases.

#### Modern C++ Enhancements

Since C++14, `auto` can be used in function return types for improved type deduction:

```cpp
auto calculateValue(int x, int y) {
    return x * y;  // Return type is deduced as int
}
```

C++17 introduced `auto` for non-type template parameters:

```cpp
template<auto N>
class FixedArray {
    std::array<int, N> data;
};

FixedArray<5> arr;  // N is deduced as 5
```

#### Code Example: Practical Use of `auto`

```cpp
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

    // Using auto for iterator
    for (auto it = names.begin(); it != names.end(); ++it) {
        auto& name = *it;  // Reference to avoid copying
        // Process name
    }

    // Range-based for loop with auto
    for (const auto& name : names) {
        // Process name
    }

    return 0;
}
```


<div class="page"/>

### 73. What is *uniform initialization* in *C++11*?

**Uniform initialization** in C++11 introduces a consistent syntax for initializing variables, objects, and containers using curly braces `{}`. This feature enhances code readability and type safety across different initialization scenarios.

#### Key Features

1. **Consistency**: Uses `{}` for initializing all types, from primitives to complex objects.
2. **Type Safety**: Prevents narrowing conversions, enhancing type safety.
3. **Versatility**: Works with various types including user-defined classes and STL containers.
4. **List Initialization**: Prioritizes constructors that accept `std::initializer_list` when available.

#### Benefits

- **Resolves Most Vexing Parse**: Eliminates ambiguity between function declarations and object definitions.
- **Prevents Implicit Conversions**: Ensures exact initialization, reducing unexpected behavior.
- **Uniform Syntax**: Simplifies learning and using C++ by providing a consistent initialization method.

#### Code Examples

##### Basic Types and Objects

```cpp
#include <iostream>
#include <vector>
#include <map>

class Point {
public:
    int x, y;
    Point(int x, int y) : x{x}, y{y} {}
};

int main() {
    // Primitive types
    int a{5};
    double b{3.14};
    bool flag{true};

    // User-defined type
    Point p{10, 20};

    // Arrays
    int arr[]{1, 2, 3, 4, 5};

    // STL containers
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::map<int, std::string> map{{1, "one"}, {2, "two"}};

    // Output
    std::cout << "a: " << a << ", b: " << b << ", flag: " << std::boolalpha << flag << '\n';
    std::cout << "Point: (" << p.x << ", " << p.y << ")\n";

    return 0;
}
```

##### Preventing Narrowing Conversions

```cpp
int x{3.14};  // Error: narrowing conversion
int y(3.14);  // Warning: possible loss of data
```

##### List Initialization Priority

```cpp
#include <initializer_list>

class Widget {
public:
    Widget(int i, bool b) { std::cout << "Regular constructor\n"; }
    Widget(std::initializer_list<long double> il) { std::cout << "initializer_list constructor\n"; }
};

int main() {
    Widget w1(10, true);    // Calls regular constructor
    Widget w2{10, true};    // Calls initializer_list constructor
    Widget w3{10, true, 5}; // Calls initializer_list constructor

    return 0;
}
```

#### Modern C++ Updates

In C++17 and later, uniform initialization has been further refined:

- **Mandatory Copy Elision**: Guarantees that certain temporary objects are not copied, improving performance.
- **Structured Bindings**: Allows unpacking of struct-like objects into individual variables.

```cpp
#include <tuple>

std::tuple<int, double, char> foo() { return {1, 3.14, 'a'}; }

int main() {
    auto [x, y, z] = foo();  // Structured binding declaration
    return 0;
}
```


<div class="page"/>

### 74. How does *range-based for loop* work?

The **range-based for loop** in C++ simplifies iteration through sequences, arrays, and other data structures. It’s especially useful for containers like `std::vector`, C-style arrays, and even user-defined types that support iteration.

#### Syntax

```cpp
for (declaration : expression)
    statement
```

Where:

- **declaration**: Specifies the type and name of the iteration variable. The type can be explicitly provided or deduced using `auto`.
- **expression**: The range over which to iterate.
- **statement**: The code to execute for each iteration.

#### How It Works

1. The compiler translates the range-based for loop into a traditional for loop using iterators.
2. It calls `begin()` and `end()` (or `std::begin()` and `std::end()` for C-style arrays) on the expression.
3. It iterates through the range, assigning each element to the declared variable.

#### Code Examples

##### Iterating over a Vector

```cpp
std::vector<int> vec = {1, 2, 3};

for (int num : vec) {
    std::cout << num << " ";
}
// Output: 1 2 3
```

##### Using auto for Type Deduction

```cpp
std::vector<std::string> words = {"Hello", "World"};

for (const auto& word : words) {
    std::cout << word << " ";
}
// Output: Hello World
```

##### Iterating over a C-style Array

```cpp
int arr[] = {4, 5, 6};

for (int num : arr) {
    std::cout << num << " ";
}
// Output: 4 5 6
```

#### Key Considerations

1. **Performance**: Range-based for loops are generally as efficient as traditional for loops with iterators.

2. **Mutability**:

    - To modify elements, use a reference:

        ```cpp
        for (auto& elem : container) {
            elem *= 2;  // Modifies the actual elements
        }
        ```

    - For read-only access, use a const reference:

        ```cpp
        for (const auto& elem : container) {
            // Read-only access
        }
        ```

3. **Compatibility**: Works with any type that provides `begin()` and `end()` functions or can be used with `std::begin()` and `std::end()`.

4. **C++20 Enhancements**: With C++20, you can use init-statements in range-based for loops:

    ```cpp
    for (std::vector<int> vec = {1, 2, 3}; const auto& elem : vec) {
        std::cout << elem << " ";
    }
    ```

5. **Structured Bindings**: C++17 introduced structured bindings, which can be used with range-based for loops:

    ```cpp
    std::map<std::string, int> myMap = {{"a", 1}, {"b", 2}};
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << "\n";
    }
    ```


<div class="page"/>

### 75. What are *delegating constructors*?

**Delegating constructors** in C++ are a feature introduced in C++11 that allow one constructor to call another constructor of the same class. This feature helps reduce code duplication and ensures consistent initialization logic across multiple constructors.

#### Syntax and Usage

The syntax for delegating constructors is as follows:

```cpp
ClassName(parameters) : ClassName(delegated_parameters) { /* constructor body */ }
```

Key points to remember:

- The delegating call must be the only member in the initializer list.
- The delegating constructor cannot have its own member initializer list.
- Delegation must not form a cycle (i.e., constructors cannot delegate to each other in a loop).

#### Benefits

1. **Code Reuse**: Reduces duplication by centralizing common initialization logic.
2. **Consistency**: Ensures that objects are initialized consistently across different constructors.
3. **Maintainability**: Makes it easier to update initialization logic in one place.

#### Code Example: Use of Delegating Constructors

```cpp
#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Base constructor
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Base constructor called\n";
    }

    // Delegating constructor
    Person() : Person("John Doe", 30) {
        std::cout << "Delegating constructor called\n";
    }

    // Another delegating constructor
    Person(const std::string& n) : Person(n, 25) {
        std::cout << "Name-only constructor called\n";
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

int main() {
    Person p1;
    Person p2("Alice");
    Person p3("Bob", 40);

    p1.display();
    p2.display();
    p3.display();

    return 0;
}
```

#### Limitations

1. **Single Delegation**: A constructor can delegate to only one other constructor.
2. **No Additional Initialization**: The delegating constructor cannot perform any member initialization before calling the target constructor.
3. **Potential for Confusion**: Overuse of delegation can make the code flow harder to follow.

#### Best Practices

- Use delegating constructors to centralize common initialization logic.
- Avoid creating long chains of delegating constructors.
- Consider using default arguments as an alternative when appropriate.


<div class="page"/>

### 76. Explain the concept of *rvalue references*.

**Rvalue references** were introduced in C++11 to efficiently handle temporaries (rvalues). They enable features like **move semantics** and **perfect forwarding**.

#### Basic Concept

An **rvalue reference** is declared using double ampersands (`&&`) and binds to temporaries, which can be modified or have their resources “stolen”. It’s distinct from an **lvalue reference** (`&`), which binds to non-temporary objects.

This differentiation allows the compiler to identify **rvalues** and **lvalues**, optimizing operations accordingly.

#### Key Use Cases

##### Move Semantics

Enables the efficient transfer of resources (like dynamic memory or ownership) between objects, typically improving performance.

```cpp
std::vector<int> createVector() {
    return std::vector<int>{1, 2, 3, 4, 5};
}

std::vector<int> vec = createVector(); // Move constructor is called
```

##### Perfect Forwarding

Allows preserving the value category (lvalue vs. rvalue) and efficiently passing arguments, commonly seen in templated functions.

```cpp
template<typename T>
void wrapper(T&& arg) {
    foo(std::forward<T>(arg)); // Perfectly forwards 'arg' to 'foo'
}
```

#### Code Example: Rvalue Reference

```cpp
#include <iostream>
#include <utility>

void modifyRValue(int&& rvalue) {
    rvalue += 10;
    std::cout << "Inside modifyRValue: " << rvalue << '\n';
}

int main() {
    int&& rvref = 5;  // Bind to the temporary integer 5
    std::cout << "Initial value: " << rvref << '\n';

    modifyRValue(std::move(rvref));  // Invoke with the rvalue reference
    std::cout << "After move: " << rvref << '\n';

    // Error: Cannot bind rvalue reference to lvalue
    // modifyRValue(rvref);  

    return 0;
}
```

#### Modern Utilities

- **`std::move`**: Converts lvalues into rvalues, indicating resources can be moved.
- **`std::forward`**: Preserves the value category of arguments, facilitating perfect forwarding.

#### C++17 and Beyond

- **Guaranteed copy elision**: Eliminates the need for move constructors in certain scenarios, further optimizing performance.
- **Fold expressions**: Simplifies variadic template code, often used with perfect forwarding.


<div class="page"/>

### 77. What is *perfect forwarding* in *C++*?

**Perfect forwarding** in C++ is a technique that allows functions to pass their arguments to other functions while preserving the value category (lvalue or rvalue) and cv-qualification of the original arguments. This feature is particularly useful for implementing generic wrapper functions and constructors.

#### Key Concepts

##### Value Categories

In C++, expressions are categorized as:

- **lvalue**: Has an identity and can be addressed
- **rvalue**: Temporary object or value that can be moved from

##### Universal References

Also known as forwarding references, they are declared using `T&&` in a template context:

```cpp
template<typename T>
void func(T&& arg);
```

These can bind to both lvalues and rvalues, unlike regular rvalue references.

##### std::forward

The `std::forward` function is crucial for perfect forwarding:

```cpp
template<typename T>
void wrapper(T&& arg) {
    some_function(std::forward<T>(arg));
}
```

It preserves the value category of the argument when passing it to another function.

#### Benefits of Perfect Forwarding

1. **Avoids Redundant Copies**: Efficiently handles both lvalues and rvalues without unnecessary copying.
2. **Preserves Const-ness**: Maintains const qualification of forwarded arguments.
3. **Enables Generic Code**: Allows writing flexible wrapper functions that can work with various argument types.

#### Code Example: Perfect Forwarding

```cpp
#include <iostream>
#include <utility>

void process(int& x) {
    std::cout << "lvalue reference: " << x << std::endl;
}

void process(int&& x) {
    std::cout << "rvalue reference: " << x << std::endl;
}

template<typename T>
void perfect_forward(T&& x) {
    process(std::forward<T>(x));
}

int main() {
    int a = 5;
    perfect_forward(a);        // Calls process(int&)
    perfect_forward(10);       // Calls process(int&&)
    perfect_forward(std::move(a)); // Calls process(int&&)
    return 0;
}
```

#### Potential Pitfalls

1. **Forwarding References vs. Rvalue References**: Be cautious not to confuse `T&&` in a template context (forwarding reference) with a regular rvalue reference.
2. **Multiple Parameters**: When forwarding multiple parameters, each must be wrapped in `std::forward`.
3. **Type Deduction**: Perfect forwarding relies on template type deduction, which can sometimes lead to unexpected behavior with certain types (e.g., initializer lists).


<div class="page"/>

### 78. How do you use *std::chrono* for time-related operations?

`std::chrono` is C++'s standard library for time-related operations, providing a robust, type-safe, and hardware-independent way to work with time.

#### Types of Clocks

`std::chrono` defines three primary types of clocks:

1. **`system_clock`**: Represents the system’s real time. It’s not guaranteed to be monotonic.
2. **`steady_clock`**: A monotonic clock that’s not affected by changes in the system’s time.
3. **`high_resolution_clock`**: Usually an alias for either `steady_clock` or `system_clock`, depending on the implementation.

#### Key Components

##### Durations

Time intervals are represented as `std::chrono::duration`. Durations can be specified in various units:

```cpp
std::chrono::hours h(1);
std::chrono::minutes m(30);
std::chrono::seconds s(45);
std::chrono::milliseconds ms(500);
```

##### Time Points

A specific point in time is represented as `std::chrono::time_point`. It’s associated with a clock:

```cpp
auto now = std::chrono::system_clock::now();
```

#### Common Operations

##### Measuring Elapsed Time

```cpp
auto start = std::chrono::steady_clock::now();
// ... some operation ...
auto end = std::chrono::steady_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
```

##### Converting Between Time Units

```cpp
auto seconds = std::chrono::duration_cast<std::chrono::seconds>(minutes);
```

##### Sleeping for a Duration

```cpp
std::this_thread::sleep_for(std::chrono::milliseconds(100));
```

#### Example: Printing Current Time and Measuring Elapsed Time

```cpp
#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    std::cout << "Current time: " << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S") << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    auto later = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = later - now;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s" << std::endl;

    return 0;
}
```


<div class="page"/>

### 79. What are the *improvements* in *smart pointers* introduced in *C++11*?

C++11 introduced significant improvements in **smart pointers**, enhancing memory management safety and offering new features. Here are the key improvements:

#### Improvements in Smart Pointers in C++11

##### `std::shared_ptr`

- Implements **shared ownership** semantics
- Uses a control block with **reference counting**
- Automatically deallocates the managed object when the last `shared_ptr` is destroyed

##### `std::unique_ptr`

- Replaces the deprecated `std::auto_ptr`
- Ensures **exclusive ownership** of the managed object
- Automatically releases the resource when going out of scope
- More efficient than `shared_ptr` due to lack of reference counting overhead

##### `std::weak_ptr`

- Provides a non-owning “weak” reference to an object managed by `std::shared_ptr`
- Helps break cyclic dependencies that can occur with `shared_ptr`

##### Creation Functions

- `std::make_shared` and `std::make_unique` (C++14)
- Offer exception safety and optimization benefits
- Reduce the number of memory allocations

#### Code Example: Using Smart Pointers

```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource released\n"; }
    void use() { std::cout << "Resource used\n"; }
};

int main() {
    // Using unique_ptr
    {
        auto uniqueResource = std::make_unique<Resource>();
        uniqueResource->use();
    } // Resource automatically released here

    // Using shared_ptr
    {
        auto sharedResource1 = std::make_shared<Resource>();
        {
            auto sharedResource2 = sharedResource1; // Shared ownership
            sharedResource2->use();
        } // sharedResource2 goes out of scope, but Resource is not released yet
    } // Resource released when last shared_ptr is destroyed

    // Using weak_ptr
    auto sharedResource = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakResource = sharedResource;

    if (auto temp = weakResource.lock()) {
        temp->use();
    } else {
        std::cout << "Resource no longer available\n";
    }

    return 0;
}
```


<div class="page"/>

### 80. Explain the concept of *constexpr*.

The `constexpr` keyword in C++ is used to declare that it’s possible to evaluate the value of a function or variable at **compile time**. Introduced in **C++11** and significantly enhanced in subsequent standards, `constexpr` enables developers to move computations from run-time to compile-time, potentially improving performance and allowing for more extensive compile-time checks.

#### Key Features

1. **Compile-Time Evaluation**: `constexpr` entities can be computed during compilation, if their inputs are known at that time.

2. **Dual Nature**: `constexpr` functions and variables can be used in both compile-time and run-time contexts.

3. **Type Requirements**: `constexpr` variables must have literal types, which includes scalar types, references, and certain user-defined types with `constexpr` constructors.

4. **Function Constraints**: `constexpr` functions must consist of a single `return` statement in C++11, but this restriction was relaxed in C++14 and later versions.

#### Evolution of `constexpr`

- **C++11**: Initial introduction, with significant limitations.
- **C++14**: Relaxed restrictions, allowing more complex `constexpr` functions.
- **C++17**: Further enhancements, including `if constexpr` for compile-time conditional statements.
- **C++20**: Introduced `consteval` for functions that must produce a compile-time constant, and `constinit` for variables with static storage duration.

#### Code Example

```cpp
#include <iostream>
#include <array>

// constexpr function
constexpr int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    // Compile-time computation
    constexpr int fact5 = factorial(5);

    // Run-time computation (still possible)
    int n = 6;
    int fact6 = factorial(n);

    // Compile-time initialized array
    constexpr std::array<int, factorial(4)> arr = {1, 2, 3, 4, 5, 6};

    std::cout << "5! = " << fact5 << std::endl;
    std::cout << "6! = " << fact6 << std::endl;
    std::cout << "Size of arr: " << arr.size() << std::endl;

    return 0;
}
```

#### Benefits of `constexpr`

1. **Performance**: Moves computations to compile-time, potentially speeding up run-time execution.
2. **Optimization**: Enables compiler optimizations based on known constant values.
3. **Safety**: Allows for more compile-time error checking.
4. **Expressiveness**: Enables writing of more generic and flexible code, especially in template metaprogramming.

#### Limitations

- Not all operations are allowed in `constexpr` contexts, especially in earlier C++ standards.
- Complexity of `constexpr` functions can impact compile times.
- Debug information for `constexpr` computations may be limited.

* * *

## Advanced C++ Concepts

* * *


<div class="page"/>

### 81. What is *CRTP* (Curiously Recurring Template Pattern)?

The **Curiously Recurring Template Pattern (CRTP)** is an advanced **C++** design pattern that leverages **static polymorphism**. It enables a base class to access the complete set of derived class methods and properties, creating a form of **compile-time** polymorphism.

#### How CRTP Works

At the core of CRTP is the use of **templates** for establishing the inheritance relationship. The base class is a template that takes the derived class as a template parameter.

```cpp
template <typename Derived>
class Base {
    // ...
};

class Derived : public Base<Derived> {
    // ...
};
```

This allows the base class to refer to itself using the derived class type, achieving a kind of **compile-time reflection**. When a class derives from the base using the specific derived type as the template argument, the base class gains direct access to the derived class’s members and methods.

#### Benefits

1. **Efficiency**: CRTP avoids the overhead of virtual function dispatch, leading to more performant code.
2. **Compile-Time Safety**: Since CRTP achieves polymorphism through type information during compilation, it can help flag certain kinds of errors earlier in the development process.
3. **Static Polymorphism**: Enables polymorphic behavior without the need for virtual functions.
4. **No Runtime Overhead**: Unlike dynamic polymorphism, CRTP doesn’t require vtable lookups.

#### Code Example: CRTP in Action

```cpp
#include <iostream>

// Define the base class using the CRTP
template <typename Derived>
class Base {
public:
    void interface() {
        // Access a method specific to the derived class
        static_cast<Derived*>(this)->implementation();
    }

    static void static_interface() {
        // Access a static method of the derived class
        Derived::static_implementation();
    }

protected:
    // Prevent direct instantiation of Base
    Base() = default;
};

// Derive a class using the CRTP
class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Derived::implementation\n";
    }

    static void static_implementation() {
        std::cout << "Derived::static_implementation\n";
    }
};

int main() {
    Derived d;
    d.interface();          // Output: Derived::implementation
    Derived::static_interface();  // Output: Derived::static_implementation

    // Attempting to instantiate Base directly would result in a compile-time error
    // Base<Derived> b;  // Compile-time error
    return 0;
}
```

#### Modern C++ Considerations

In C++20 and later, the `static_cast<Derived*>(this)` can be replaced with more type-safe alternatives:

```cpp
template <typename Derived>
class Base {
public:
    void interface() {
        // C++20: Use static_cast to derived
        static_cast<Derived&>(*this).implementation();

        // C++23: Use explicit object parameter (if supported)
        // this->implementation();
    }
    // ...
};
```


<div class="page"/>

### 82. Explain the concept of *type erasure* in *C++*.

**Type erasure** in C++ is a powerful design pattern that allows storing objects of different types within a single container while exposing a consistent interface. This technique is fundamental in implementing **polymorphism** and generic programming paradigms, such as `std::function` and `std::any` in the C++ Standard Template Library (STL).

#### How Type Erasure Works

Type erasure leverages several C++ features to unify the interface of disparate types:

1. **Common Interface**: Types to be stored or operated upon implement a shared interface.
2. **Virtual Functions**: The shared interface uses virtual functions, allowing runtime polymorphism.
3. **Internal Abstraction**: The type’s internal representation is “erased”, presenting a consistent interface.

#### Code Example

Here is a simple example of different dog breeds:

```cpp
#include <iostream>
#include <memory>

// Common interface using virtual functions
class Dog {
public:
    virtual ~Dog() = default;
    virtual void bark() const = 0;
    virtual std::unique_ptr<Dog> clone() const = 0;
};

// Concrete implementation for a specific breed
class GoldenRetriever : public Dog {
public:
    void bark() const override {
        std::cout << "Woof! I'm a friendly Golden Retriever!" << std::endl;
    }

    std::unique_ptr<Dog> clone() const override {
        return std::make_unique<GoldenRetriever>(*this);
    }
};

// Type-erased wrapper
class AnyDog {
private:
    std::unique_ptr<Dog> pDog;

public:
    template<typename T>
    AnyDog(T dog) : pDog(std::make_unique<T>(std::move(dog))) {}

    AnyDog(const AnyDog& other) : pDog(other.pDog->clone()) {}

    void bark() const { pDog->bark(); }
};

int main() {
    AnyDog dog1(GoldenRetriever{});
    dog1.bark();  // Output: Woof! I'm a friendly Golden Retriever!

    AnyDog dog2 = dog1;  // Copy constructor uses clone()
    dog2.bark();  // Same output

    return 0;
}
```

#### Key Benefits

1. **Flexibility**: Allows working with objects of different types through a unified interface.
2. **Encapsulation**: Hides implementation details of specific types.
3. **Runtime Polymorphism**: Enables dynamic dispatch without exposing inheritance hierarchy.

#### Modern C++ Enhancements

C++17 introduced `std::any`, which provides built-in type erasure for arbitrary types:

```cpp
#include <any>
#include <iostream>

int main() {
    std::any a = 1;
    std::cout << std::any_cast<int>(a) << std::endl;  // Output: 1

    a = 3.14;
    std::cout << std::any_cast<double>(a) << std::endl;  // Output: 3.14

    a = std::string("Hello, type erasure!");
    std::cout << std::any_cast<std::string>(a) << std::endl;  // Output: Hello, type erasure!

    return 0;
}
```


<div class="page"/>

### 83. What are *fold expressions* in *C++17*?

**Fold expressions**, introduced in C++17, provide a concise way to **reduce or combine** multiple values in a parameter pack using a single binary operation. They simplify tasks like summing elements in a variadic template or combining them with logical operations.

#### Syntax

There are four types of fold expressions:

1. **Unary right fold**: `(pack op ...)`
2. **Unary left fold**: `(... op pack)`
3. **Binary right fold**: `(pack op ... op init)`
4. **Binary left fold**: `(init op ... op pack)`

Where `op` is a binary operator, `pack` is an unexpanded parameter pack, and `init` is an initial value.

#### Code Examples

##### Sum of Variadic Arguments

```cpp
#include <iostream>

template <typename... Args>
auto sum(Args... args) {
    return (... + args);  // Unary left fold
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5);  // Output: 15
    return 0;
}
```

##### Logical AND

```cpp
#include <iostream>

template <typename... Args>
bool are_all_true(Args... args) {
    return (... && args);  // Unary left fold
}

int main() {
    std::cout << std::boolalpha;
    std::cout << are_all_true(true, true, true) << '\n';  // Output: true
    std::cout << are_all_true(true, false, true) << '\n'; // Output: false
    return 0;
}
```

##### Function Argument Display

```cpp
#include <iostream>

template <typename... Args>
void display_args(Args... args) {
    ((std::cout << args << ' '), ...);  // Unary right fold
    std::cout << '\n';
}

int main() {
    display_args(1, 2, "three", 4.4, '5');  // Output: 1 2 three 4.4 5
    return 0;
}
```

#### Associativity and Order of Evaluation

- For **associative operators**, the associativity follows the fold direction.
- For **non-associative operators**, C++17 guarantees left-to-right evaluation order of the operands.

#### Empty Parameter Packs

Fold expressions handle empty parameter packs as follows:

- `&&` folds on empty packs yield `true`
- `||` folds on empty packs yield `false`
- `,` folds on empty packs yield `void()`
- All other folds on empty packs are ill-formed

#### Binary Folds

Binary folds allow specifying an initial value:

```cpp
template<typename... Args>
auto sum_with_initial(int initial, Args... args) {
    return (initial + ... + args);  // Binary right fold
}

int main() {
    std::cout << sum_with_initial(10, 1, 2, 3);  // Output: 16
    return 0;
}
```


<div class="page"/>

### 84. How do you implement a *singleton pattern* in *C++*?

The **singleton pattern** in C++ ensures a class has only one instance and provides a global point of access to it. Here’s a modern implementation using C++11 and beyond:

```cpp
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
};
```

#### Key Features:

1. **Static Member Function**: `getInstance()` provides global access to the single instance.
2. **Static Local Variable**: `static Singleton instance` ensures thread-safe lazy initialization.
3. **Deleted Copy Constructor and Assignment Operator**: Prevents creation of additional instances.
4. **Private Constructor**: Disallows direct instantiation.

#### Thread Safety

This implementation is **thread-safe** in C++11 and later due to the guaranteed thread-safe initialization of static local variables.

#### Code Example

```cpp
int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    assert(&s1 == &s2); // Both references point to the same instance

    // Singleton s3; // Compile error: constructor is private
    // Singleton s4 = s1; // Compile error: copy constructor is deleted

    return 0;
}
```

#### Alternative Implementations

##### Meyer’s Singleton (Recommended)

The implementation shown above is known as **Meyer’s Singleton**. It’s considered the most elegant and efficient way to implement the singleton pattern in modern C++.

##### Pointer-based Singleton

For older C++ versions or specific requirements:

```cpp
class Singleton {
public:
    static Singleton* getInstance() {
        static std::unique_ptr<Singleton> instance(new Singleton());
        return instance.get();
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton() = default;
};
```

This version uses a `std::unique_ptr` to manage the singleton instance, providing automatic memory management.


<div class="page"/>

### 85. What is the purpose of *std::optional*?

`std::optional` is a template class introduced in C++17 that serves as a container for values that may or may not be present. It provides a more expressive and safer alternative to using raw pointers or sentinel values to represent optional data.

#### Key Features

- **Nullable Type**: `std::optional` can hold a value of a specified type or be empty, effectively representing a nullable type.
- **Type Safety**: It provides type-safe access to the contained value, reducing the risk of null pointer dereferences.
- **Explicit Semantics**: The use of `std::optional` in function signatures clearly communicates that a value might be absent.
- **Value Semantics**: Unlike pointers, `std::optional` follows value semantics, making it easier to reason about ownership and lifetime.

#### Common Use Cases

##### Return Values for Fallible Operations

`std::optional` is ideal for functions that may fail to produce a valid result:

```cpp
std::optional<int> parse_integer(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::exception&) {
        return std::nullopt;
    }
}
```

##### Optional Function Parameters

It can be used to represent optional function parameters with default behavior:

```cpp
void process_data(int required, std::optional<int> optional = std::nullopt) {
    if (optional) {
        // Use optional value
    } else {
        // Use default behavior
    }
}
```

#### Code Example

Use of `std::optional`

```cpp
#include <iostream>
#include <optional>
#include <string>

std::optional<std::string> get_middle_name(const std::string& full_name) {
    size_t first_space = full_name.find(' ');
    if (first_space == std::string::npos) return std::nullopt;

    size_t last_space = full_name.rfind(' ');
    if (first_space == last_space) return std::nullopt;

    return full_name.substr(first_space + 1, last_space - first_space - 1);
}

int main() {
    std::string name1 = "John Doe";
    std::string name2 = "Alice Middle Smith";

    auto middle1 = get_middle_name(name1);
    auto middle2 = get_middle_name(name2);

    if (middle1) {
        std::cout << "Middle name: " << *middle1 << std::endl;
    } else {
        std::cout << "No middle name found" << std::endl;
    }

    if (middle2) {
        std::cout << "Middle name: " << middle2.value() << std::endl;
    } else {
        std::cout << "No middle name found" << std::endl;
    }

    return 0;
}
```


<div class="page"/>

### 86. Explain the concept of *concepts* in *C++20*.

**Concepts** are a powerful feature introduced in C++20 that provide a **mechanism for constraining templates**, making them more expressive and easier to work with. They allow developers to specify requirements on template arguments in a concise and readable way.

#### Key Aspects of Concepts

- **Type Constraints**: Enforce rules about what types or values are valid for a template.
- **Compile-Time Checking**: The compiler verifies concept adherence, flagging violations as errors.
- **Improved Readability**: Clearly communicate template requirements.
- **Better Error Messages**: Provide more meaningful diagnostics at compile time.

#### Defining a Concept

A concept is declared using the `concept` keyword, followed by a name and a set of constraints:

```cpp
template <typename T>
concept MyConcept = /* Constraint expression */;
```

#### Types of Concepts

##### 1\. Simple Concepts

These are based on type traits or other simple conditions:

```cpp
template <typename T>
concept Integral = std::is_integral_v<T>;
```

##### 2\. Compound Concepts

Combine multiple concepts using logical operators:

```cpp
template <typename T>
concept Arithmetic = Integral<T> || std::floating_point<T>;
```

##### 3\. Requires Clauses

More complex concepts can use `requires` clauses to specify detailed requirements:

```cpp
template <typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
    std::swap(a, b);
};
```

#### Using Concepts

Concepts can be used in various ways:

##### 1\. Function Templates

```cpp
template <std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

##### 2\. Class Templates

```cpp
template <std::ranges::range R>
class RangeWrapper {
    R range;
public:
    // ...
};
```

##### 3\. Auto Parameters

```cpp
void print_number(std::integral auto x) {
    std::cout << x << std::endl;
}
```

#### Benefits of Concepts

1. **Improved Code Clarity**: Concepts make template requirements explicit.
2. **Better Error Messages**: Compiler errors become more meaningful and easier to understand.
3. **Overload Resolution**: Concepts can be used to disambiguate function overloads.
4. **Code Reusability**: Concepts promote the creation of more generic and reusable code.

#### Code Example: Using Concepts with Ranges

```cpp
#include <concepts>
#include <ranges>
#include <vector>
#include <iostream>

template <std::ranges::input_range R>
    requires std::integral<std::ranges::range_value_t<R>>
void print_sum(const R& range) {
    auto sum = std::ranges::fold_left(range, 0, std::plus{});
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    print_sum(vec);  // Valid: vector<int> is an input_range of integral values

    // print_sum("Hello");  // Would not compile: string is not a range of integral values
}
```


<div class="page"/>

### 87. What are *coroutines* in *C++20*?

**Coroutines** in C++20 are functions that can be **suspended** and **resumed**. They offer a structured approach to asynchronous programming, making tasks like event handling and I/O more manageable.

#### Key Components of Coroutines

- **Promise**: Acts as a bridge between the coroutine and the outside world. It handles the passing of values in and out of the coroutine.

- **Coroutine Handle**: Represents the lifecycle of the coroutine. It can be used to track, resume, and destroy the coroutine.

- **Generator**: A special kind of coroutine that produces a sequence of values. It’s commonly implemented using a coroutine.

#### Basic Coroutine Operations

1. **`co_await`**: Suspends the coroutine until a particular condition is met. Typically used with awaitable types, like promises or futures.

```cpp
auto result = co_await someTask(); // Suspend until task is complete.
```

2. **`co_yield`**: Synchronously yields a value from the coroutine, especially useful in generators.

```cpp
std::generator<int> generateNumbers() {
    co_yield 1;
    co_yield 2;
    co_yield 3;
}
```

3. **`co_return`**: Indicates the end of the coroutine, optionally returning a value.

#### Code Example: Simple Coroutine to Generate Fibonacci Sequence

```cpp
#include <coroutine>
#include <iostream>
#include <vector>

class FibonacciGenerator {
public:
    struct promise_type {
        int current_value = 0;
        int next_value = 1;

        FibonacciGenerator get_return_object() {
            return FibonacciGenerator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() { std::terminate(); }
        std::suspend_always yield_value(int value) {
            current_value = value;
            return {};
        }
    };

    FibonacciGenerator(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~FibonacciGenerator() { if (handle) handle.destroy(); }

    int next() {
        handle.resume();
        return handle.promise().current_value;
    }

private:
    std::coroutine_handle<promise_type> handle;
};

FibonacciGenerator fibonacci_sequence() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        int temp = a;
        a = b;
        b = temp + b;
    }
}

int main() {
    auto fib = fibonacci_sequence();
    for (int i = 0; i < 10; ++i) {
        std::cout << fib.next() << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

#### Benefits of Coroutines

1. **Simplified Asynchronous Code**: Coroutines make asynchronous code look more like synchronous code, improving readability.

2. **Efficient Resource Usage**: They allow for cooperative multitasking without the overhead of threads.

3. **Lazy Evaluation**: Coroutines can generate values on-demand, useful for working with infinite sequences.

4. **Improved Performance**: They can reduce the need for callbacks and complex state machines in asynchronous code.


<div class="page"/>

### 88. How do you use *std::variant* and *std::visit*?

`std::variant` and `std::visit` are powerful C++17 features for handling **sum types** or **discriminated unions**.

#### `std::variant`

`std::variant` is a **type-safe union** that can hold a value of any of its specified alternative types.

##### Basic Usage

```cpp
#include <variant>
#include <string>

std::variant<int, float, std::string> var;
var = 3.14f;  // Assign a float
var = "Hello";  // Now it contains a string
```

##### Checking and Accessing Values

To safely access the value:

```cpp
if (std::holds_alternative<std::string>(var)) {
    std::cout << std::get<std::string>(var);
}

// Or using std::get_if for pointer-like access
if (auto str = std::get_if<std::string>(&var)) {
    std::cout << *str;
}
```

#### `std::visit`

`std::visit` allows you to perform **type-based dispatch** on a `std::variant`.

##### Basic Usage

```cpp
std::visit([](const auto& val) {
    std::cout << val;
}, var);
```

##### Multiple Variants

`std::visit` can handle multiple variants simultaneously:

```cpp
std::variant<int, float> v1{10};
std::variant<char, std::string> v2{'a'};

std::visit([](auto&& arg1, auto&& arg2) {
    std::cout << arg1 << ", " << arg2;
}, v1, v2);
```

##### Custom Visitor

You can define a custom visitor class for more complex operations:

```cpp
struct Visitor {
    void operator()(int i) { std::cout << "Int: " << i; }
    void operator()(float f) { std::cout << "Float: " << f; }
    void operator()(const std::string& s) { std::cout << "String: " << s; }
};

std::visit(Visitor{}, var);
```

#### Performance Considerations

- `std::variant` typically has the same size as its largest alternative plus a small overhead for type information.
- `std::visit` usually compiles to efficient switch statements, offering performance comparable to hand-written type-based dispatch code.


<div class="page"/>

### 89. What is the purpose of *std::any*?

`std::any` is a versatile and type-safe storage solution introduced in **C++17**. It allows you to store **values of any type** within a single variable, providing a reliable and adaptable alternative to `void*` and `union`.

#### Purpose and Benefits

- **Type-safe storage**: `std::any` can hold a value of any type while maintaining type safety.
- **Flexibility**: It’s especially useful when the specific type is not known in advance or may change at runtime.
- **Improved alternative**: Offers a more secure and convenient solution compared to `void*` and unions.

#### Key Features and Operations

##### Type Checks and Information

- `.has_value()`: Determines if the `std::any` instance is currently holding a value.
- `.type()`: Retrieves type information, returning a `std::type_info` reference.

##### Value Management

- `.reset()`: Clears the stored value.
- `.emplace<T>(args...)`: Replaces the existing value with a new one of type `T`, constructing it with the provided arguments.

##### Value Retrieval

- `std::any_cast<T>()`: Extracts a value of type `T`. Throws `std::bad_any_cast` if the stored type doesn’t match.

#### Code Example

Usage of `std::any`:

```cpp
#include <iostream>
#include <string>
#include <any>

int main() {
    std::any data;

    // Check if empty
    if (!data.has_value()) {
        std::cout << "No value stored in 'data'." << std::endl;
    }

    // Store and retrieve an int
    data = 42;
    std::cout << "Stored int: " << std::any_cast<int>(data) << std::endl;

    // Store and retrieve a string
    data = std::string("Hello, std::any!");
    std::cout << "Stored string: " << std::any_cast<std::string>(data) << std::endl;

    // Use emplace to construct a complex object in-place
    struct Point { int x, y; };
    data.emplace<Point>(10, 20);
    const auto& point = std::any_cast<const Point&>(data);
    std::cout << "Stored Point: (" << point.x << ", " << point.y << ")" << std::endl;

    // Type information
    std::cout << "Current type: " << data.type().name() << std::endl;

    // Reset and check
    data.reset();
    if (!data.has_value()) {
        std::cout << "'data' has been reset and is empty." << std::endl;
    }

    // Demonstrating exception handling
    try {
        std::any_cast<float>(data); // This will throw
    } catch (const std::bad_any_cast& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```


<div class="page"/>

### 90. Explain the concept of *modules* in *C++20*.

C++20 introduces **modules** as a more efficient and modern alternative to header files and the traditional `#include` mechanism.

#### Benefits of Modules Over Headers

- **Performance**: Modules can significantly speed up build times by eliminating redundant parsing and inclusion of headers.
- **Encapsulation**: They offer better support for information hiding and only export what’s specified, reducing the risk of accidental access to private module components.
- **Solving ODR Issues**: Modules help address One Definition Rule (ODR) violations by ensuring that definitions are only included once, reducing linking errors.
- **Improved Compilation Model**: Modules provide a clearer dependency structure and can be precompiled, further improving build times.

#### Key Concepts

##### Module Units

A **module** consists of one or more module units. There are three types of module units:

1. **Primary Module Interface Unit**: Defines the main interface of the module.
2. **Module Implementation Unit**: Contains implementation details.
3. **Module Partition Unit**: Allows splitting the module interface into multiple files.

##### Export Declaration

The `export` keyword marks specific declarations for external visibility. Only exported items can be accessed from outside the module.

#### Syntax Examples

##### Module Interface

```cpp
// mymodule.cpp
export module mymodule;

export int globalVar;
export void someFunction();

export class MyClass {
public:
    void method();
};
```

##### Module Implementation

```cpp
module mymodule;

#include <vector>

int globalVar = 42;

void someFunction() {
    // Implementation details
}

void MyClass::method() {
    // Method implementation
}
```

##### Module Usage

```cpp
import mymodule;

int main() {
    someFunction();
    MyClass obj;
    obj.method();
    return 0;
}
```

#### Module Partitions

Modules can be split into partitions for better organization:

```cpp
// mymodule-part.cpp
export module mymodule:part;

export void partFunction();
```

```cpp
// mymodule.cpp
export module mymodule;

export import :part;

// Additional exports...
```

#### Global Module Fragment

For legacy code compatibility, modules can include traditional headers in a global module fragment:

```cpp
module;

#include <legacy_header.h>

export module mymodule;

// Module content...
```

#### Module Compatibility

C++20 allows modules and traditional includes to coexist, ensuring a smooth transition for existing codebases. However, not all compilers fully support modules as of 2023, so check your compiler’s documentation for the latest implementation status.

* * *

## Performance and Optimization

* * *


<div class="page"/>

### 91. What is *cache coherence* and how does it affect *C++ program performance*?

**Cache coherence** is a crucial concept in multi-core systems that ensures shared data remains consistent across different CPU caches. It’s essential for maintaining correct program behavior in parallel computing environments.

#### Mechanisms for Ensuring Cache Coherence

1. **Snooping Protocol**

    - Each cache monitors or “snoops” the memory bus for changes
    - Effective for small-scale systems but can cause bus congestion in larger setups
2. **Directory-Based Protocol**

    - A centralized directory tracks the state of cache lines
    - More scalable for large systems but introduces some latency
3. **MESI Protocol**

    - Common cache coherence protocol
    - Tags cache lines as `Modified`, `Exclusive`, `Shared`, or `Invalid`
    - Efficiently manages data states across multiple caches

#### Impact on C++ Program Performance

1. **Memory Model Considerations**

    - C++11 introduced a standardized memory model
    - Programmers must understand memory ordering to prevent data races and ensure correct behavior
2. **False Sharing**

    - Occurs when different cores modify variables in the same cache line
    - Can lead to unnecessary cache invalidations and performance degradation
3. **Data Locality**

    - Proper data layout can improve cache utilization
    - Techniques like padding can help avoid false sharing
4. **Synchronization Overhead**

    - Maintaining coherence often requires synchronization primitives
    - These can introduce performance overhead, especially in highly contended scenarios

#### Code Example: Demonstrating Cache Coherence Issues

```cpp
#include <atomic>
#include <thread>
#include <vector>
#include <iostream>

struct alignas(64) PaddedInt {
    std::atomic<int> value;
    char padding[60]; // Ensure each PaddedInt is on its own cache line
};

void increment(PaddedInt& data, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        data.value.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    const int num_threads = 4;
    const int iterations = 10000000;

    std::vector<PaddedInt> data(num_threads);
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(increment, std::ref(data[i]), iterations);
    }

    for (auto& t : threads) {
        t.join();
    }

    for (int i = 0; i < num_threads; ++i) {
        std::cout << "Thread " << i << " count: " << data[i].value << std::endl;
    }

    return 0;
}
```

This example demonstrates how to mitigate false sharing by using padded data structures. Each `PaddedInt` is aligned to a cache line boundary, preventing different threads from modifying the same cache line. The use of `std::atomic` ensures thread-safe operations without explicit locking, while `std::memory_order_relaxed` allows for maximum performance in this scenario where strict ordering is not required.


<div class="page"/>

### 92. How do you *optimize memory usage* in *C++ programs*?

Optimizing memory usage in C++ programs is crucial for creating efficient, fast, and stable code. Here are several strategies to achieve this:

#### Storage Classes

- **Automatic**: Variables declared within a function scope. They are automatically created and destroyed. Use them when the variable’s lifespan matches its containing scope.

- **Static**: `static` variables persist throughout the program. They are created when first encountered and destroyed at program termination. Use when a variable needs to retain its value across function calls.

- **Thread Local**: Introduced in C++11 with the `thread_local` keyword. These variables have unique instances for each thread.

- **Global**: Declared outside any function, available throughout the program. Created before `main()` starts and destroyed after it exits.

#### Smart Pointers

Smart pointers automatically manage dynamic memory, providing safer alternatives to raw pointers:

- **`std::unique_ptr`**: For single-owner scenarios. Automatically releases memory when the owning object is destroyed.

```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(42);
```

- **`std::shared_ptr`**: For multiple-owner scenarios. Uses reference counting to release memory when the last owner goes out of scope.

```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(42);
```

#### Memory Pools

Memory pools efficiently manage memory by reusing allocated chunks:

- **Object Pools**: Useful for frequently created and destroyed objects. Example using `boost::object_pool`:

```cpp
#include <boost/pool/object_pool.hpp>

struct MyClass { /* ... */ };
boost::object_pool<MyClass> pool;

MyClass* obj = pool.construct();
pool.destroy(obj);
```

- **Stack-based Allocation**: Utilizes stack memory for faster allocation/deallocation. C++17 introduced `std::pmr::monotonic_buffer_resource` for this purpose:

```cpp
#include <memory_resource>

std::array<std::byte, 1024> buffer;
std::pmr::monotonic_buffer_resource mbr{buffer.data(), buffer.size()};
std::pmr::vector<int> vec{&mbr};
```

#### Efficient Data Structures and Algorithms

Choose appropriate data structures and algorithms based on the specific use case:

- **Hash Tables**: Fast lookups but higher memory usage. Use `std::unordered_map` or `std::unordered_set`.
- **Binary Search Trees**: Balanced memory usage and performance. Use `std::map` or `std::set`.
- **Custom Data Structures**: Design specialized structures for specific needs to minimize memory overhead.

#### Additional Techniques

- **Move Semantics**: Utilize move operations to avoid unnecessary copying of large objects.
- **Small String Optimization (SSO)**: Many C++ standard library implementations use SSO to store small strings without heap allocation.
- **Memory-mapped Files**: For large datasets, use memory-mapped files to access data without loading it entirely into RAM.

```cpp
#include <boost/iostreams/device/mapped_file.hpp>

boost::iostreams::mapped_file_source file("large_data.bin");
// Access file data directly through file.data()
```

#### Profiling and Analysis

Use memory profiling tools like Valgrind or Visual Studio’s memory profiler to identify memory bottlenecks and optimize accordingly.


<div class="page"/>

### 93. Explain the concept of *branch prediction* and its impact on *performance*.

**Branch prediction** is a hardware optimization technique used in modern CPUs to enhance performance by anticipating the outcome of conditional statements (branches) in code.

When the CPU encounters a branch instruction, such as an `if-else` statement, it attempts to predict which path the program will take. It then **speculatively executes** instructions along the predicted path while waiting for the actual condition to be evaluated. This strategy aims to keep the CPU’s instruction pipeline full, minimizing idle time and improving overall performance.

#### How Branch Prediction Works

Modern CPUs use sophisticated algorithms for branch prediction, including:

1. **Static Prediction**: Based on compile-time heuristics.
2. **Dynamic Prediction**: Uses runtime behavior to make predictions.
    - **Two-Level Adaptive Predictor**: Considers both global and local branch history.
    - **Neural Branch Predictor**: Employs machine learning techniques for more accurate predictions.

#### Impact on Performance

Effective branch prediction can significantly impact performance:

- **Reduced Pipeline Stalls**: Correct predictions keep the instruction pipeline flowing smoothly.
- **Improved Instruction Throughput**: By minimizing wasted cycles on mispredicted branches.
- **Enhanced Parallelism**: Allows for more efficient out-of-order execution.

However, mispredictions can lead to performance penalties as the CPU must flush the pipeline and start over with the correct branch.

#### Code Example

Demonstrating a scenario where branch prediction can be beneficial:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int sum_positive(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num > 0) {  // Branch predictor can learn this pattern
            sum += num;
        }
    }
    return sum;
}

int main() {
    std::vector<int> data(1000000);
    std::generate(data.begin(), data.end(), []() { return rand() % 100 - 25; });

    int result = sum_positive(data);
    std::cout << "Sum of positive numbers: " << result << std::endl;

    return 0;
}
```

##### Optimizing for Branch Prediction

Developers can help branch predictors by:

- **Sorting data**: Predictable patterns are easier to predict.
- **Using `likely`/`unlikely` hints**: Some compilers support these to guide the predictor.
- **Avoiding unpredictable branches**: Especially in performance-critical loops.


<div class="page"/>

### 94. What is *loop unrolling* and when is it beneficial?

**Loop unrolling** is an optimization technique that aims to enhance the execution efficiency of loops. When a compiler unrolls a loop, it effectively reduces or eliminates the overhead associated with loop control, such as maintaining loop counters and performing branch operations.

This optimization can lead to **faster execution** due to improved utilization of the CPU’s instruction pipeline, which processes multiple instructions in parallel.

#### How Loop Unrolling Works

In a typical scenario, a CPU processes instructions sequentially. This means that in a loop, the CPU might need to wait for one iteration to complete before starting the next. By unrolling the loop, instructions from multiple iterations can overlap, potentially reducing CPU downtime.

Consider this simple loop:

```cpp
for (int i = 0; i < 4; ++i) {
    // Do something
}
```

If the compiler unrolls this loop, the result might look like this:

```cpp
for (int i = 0; i < 4; i += 2) {
    // Do something (iteration 1)
    // Do something (iteration 2)
}
```

In this unrolled version, the loop counter is incremented by 2 in each iteration, and the loop body is executed twice. This reduces the overhead related to loop control.

#### Benefits of Loop Unrolling

- **Improved Performance**: Unrolling can lead to better CPU pipeline usage and potentially reduce branching.

- **Enhanced Vectorization**: Modern CPUs often process multiple data elements in a single instruction (vectorization). Unrolling can improve utilization of this capability.

- **Reduced Overhead**: With fewer checks on loop conditions and counter increments, more loop iterations can be performed with fewer instructions.

#### Trade-Offs and Limitations

- **Code Bloat**: Unrolling can increase executable code size, potentially affecting cache performance.

- **Reduced Readability**: Unrolled loops can be more complex, making the code harder to understand and maintain.

- **Compile-Time Decision**: The number of iterations to unroll is typically fixed at compile time, reducing flexibility.

#### Best Practices

- **Moderate Unrolling**: Avoid excessive unrolling; a factor of 2 or 4 is often beneficial.

- **Compiler Optimization**: Utilize compiler optimization flags to control loop unrolling judiciously.

- **Profile-Guided Optimization (PGO)**: Use PGO to let the compiler make data-driven decisions about loop unrolling.

#### Code Example: Unrolling a Sum Calculation

```cpp
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int SIZE = 100000000;
    std::vector<int> data(SIZE, 1);  // Initialize with 1's for simplicity
    long long sum = 0;

    // Original loop
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; ++i) {
        sum += data[i];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Original sum: " << sum << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

    // Unrolled loop with a factor of 4
    sum = 0;  // Reset sum
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i += 4) {
        sum += data[i] + data[i + 1] + data[i + 2] + data[i + 3];
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Unrolled sum: " << sum << std::endl;
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;

    return 0;
}
```


<div class="page"/>

### 95. How do you *profile C++ code* for *performance optimization*?

Profiling is a crucial technique for **detailed performance analysis** of C++ code, helping identify bottlenecks and areas for optimization. Here’s a step-by-step approach to profile C++ code:

#### Compile with Debug Symbols

When using compilers like `g++` or `clang++`, include the `-g` flag to embed debugging information in the executable:

```bash
g++ -g -O2 your_code.cpp -o your_executable
```

This enables meaningful output from profilers while maintaining optimizations.

#### Choose a Profiling Tool

Select a profiling tool that best suits your needs:

- **gprof**: A simple, built-in profiler for GNU Compiler Collection (GCC).
- **Valgrind**: Offers tools like Callgrind for in-depth analysis.
- **perf**: A lightweight profiling tool for Linux systems.
- **Intel VTune Profiler**: Provides advanced profiling capabilities, especially for Intel architectures.
- **Google Performance Tools (gperftools)**: A suite of tools for memory and CPU profiling.

#### Use the Profiling Tool

##### gprof

1. Compile with `-pg` flag:

    ```bash
    g++ -pg -g -O2 your_code.cpp -o your_executable
    ```

2. Run your executable to generate `gmon.out`.

3. Analyze with:

    ```bash
    gprof your_executable gmon.out > analysis.txt
    ```

##### Valgrind/Callgrind

1. Run:

    ```bash
    valgrind --tool=callgrind ./your_executable
    ```

2. Visualize the generated `callgrind.out.<pid>` file using KCacheGrind or QCacheGrind.

##### perf

1. Record data:

    ```bash
    perf record ./your_executable
    ```

2. View results:

    ```bash
    perf report
    ```

##### Intel VTune Profiler

1. Launch VTune and create a new project.
2. Select the analysis type (e.g., Hotspots, Microarchitecture Exploration).
3. Run the analysis on your executable.
4. Examine the results in the VTune GUI.

##### gperftools

1. Link your program with `-lprofiler`:

    ```bash
    g++ your_code.cpp -lprofiler -o your_executable
    ```

2. Run your program to generate a profile file.

3. Analyze with `pprof`:

    ```bash
    pprof --text ./your_executable profile.log
    ```

#### Interpret the Results

Analyze the profiler output to identify:

- Functions consuming the most CPU time
- Frequently called functions
- Cache misses and branch mispredictions
- Memory allocation patterns

Focus on optimizing the most time-consuming parts of your code, considering algorithmic improvements, data structure changes, or low-level optimizations like loop unrolling or vectorization.

#### Continuous Profiling

Integrate profiling into your development workflow:

- Use automated profiling in CI/CD pipelines
- Regularly profile after significant code changes
- Set performance budgets and monitor trends over time


<div class="page"/>

### 96. What is the *difference* between *constexpr* and *inline functions* in terms of *performance*?

##### `constexpr` Functions

- **Compile-time Evaluation**: `constexpr` functions are designed for **compile-time computation**. When used in a constant expression context, they are evaluated during compilation, potentially improving run-time performance.

```cpp
constexpr int square(int x) {
    return x * x;
}

constexpr int result = square(5); // Computed at compile-time
```

- **Run-time Behavior**: `constexpr` functions can also be used at run-time. In such cases, they behave like regular functions with no special performance benefits.

- **Optimization Opportunities**: Compilers can leverage `constexpr` to perform more aggressive optimizations, potentially leading to more efficient code.

##### `inline` Functions

- **Function Call Overhead**: The primary purpose of `inline` is to suggest that the compiler replace function calls with the function’s body, potentially reducing function call overhead.

```cpp
inline int add(int a, int b) {
    return a + b;
}

int result = add(3, 4); // Compiler may replace this with: int result = 3 + 4;
```

- **Code Size**: Excessive use of `inline` can lead to **code bloat**, as the function’s body is duplicated at each call site.

#### Key Differences in Performance

1. **Compile-time vs. Run-time**: `constexpr` focuses on compile-time computation, while `inline` aims to optimize run-time performance.

2. **Optimization Scope**: `constexpr` allows for broader compile-time optimizations, whereas `inline` primarily targets function call overhead.

3. **Code Generation**: `constexpr` can lead to more efficient code generation due to compile-time evaluation, while `inline` may increase code size but reduce function call overhead.

4. **Flexibility**: `constexpr` functions must adhere to strict rules to be eligible for compile-time evaluation, whereas `inline` functions have no such restrictions.

#### Modern C++ Considerations

- In modern C++, the `inline` keyword is often unnecessary, as compilers are adept at deciding when to inline functions.
- `constexpr` has gained more importance in recent C++ standards, offering increased compile-time computation capabilities.

```cpp
// C++17 and later
constexpr int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

constexpr int result = factorial(5); // Computed at compile-time
```


<div class="page"/>

### 97. Explain the concept of *false sharing* and how to avoid it.

**False sharing** is a performance issue that occurs in multi-threaded programs when multiple threads, each with its **own cache**, access data that resides in the **same cache line**. This results in excessive cache invalidations and can lead to significant performance degradation.

#### How It Occurs

False sharing happens when:

1. Multiple threads work on **independent data**
2. The data is **close enough in memory** to share a cache line
3. At least one thread is **writing** to its data

Even though the threads are not sharing data logically, they are forced to synchronize due to the hardware’s cache coherence protocols.

#### Code Example

Consider an array where adjacent elements are modified by different threads:

```cpp
#include <iostream>
#include <thread>
#include <vector>

constexpr int arraySize = 10000;
std::vector<int> data(arraySize);

void modifyElements(int start, int end) {
    for (int i = start; i < end; ++i) {
        data[i] = i;  // Modifies elements in the assigned range
    }
}

int main() {
    std::thread t1(modifyElements, 0, arraySize / 2);
    std::thread t2(modifyElements, arraySize / 2, arraySize);
    t1.join();
    t2.join();
    return 0;
}
```

In this example, `t1` and `t2` work on different halves of the array. However, if elements from both halves share a cache line, false sharing will occur.

#### Avoiding False Sharing

1. **Padding**: Add unused bytes between data elements to ensure they occupy distinct cache lines.

    ```cpp
    struct PaddedInt {
        int value;
        char padding[60];  // Assumes 64-byte cache line
    };
    ```

2. **Alignment**: Use `alignas` or `std::hardware_destructive_interference_size` to align data structures with cache boundaries.

    ```cpp
    alignas(std::hardware_destructive_interference_size) int data1;
    alignas(std::hardware_destructive_interference_size) int data2;
    ```

3. **Thread-Local Storage**: Use thread-local variables when possible to ensure each thread has its own copy of the data.

    ```cpp
    thread_local int localCounter = 0;
    ```

4. **Data Structure Redesign**: Organize data to promote cache-friendly access patterns.

#### Hardware Considerations

- Cache lines are typically **64 bytes** on modern x86 architectures.
- **Multi-core systems** often have independent caches for each core.
- Some modern CPUs (e.g., AMD Zen 3) have larger cache lines (128 bytes), so always check your target architecture.


<div class="page"/>

### 98. How do you *optimize code* for modern *CPU architectures* (e.g., *SIMD instructions*)?

To optimize code for modern CPU architectures like SIMD, you can employ techniques such as **data vectorization**, **loop unrolling**, and **cache optimization**. Let’s explore each of these in detail.

#### Data Vectorization

**Data vectorization** processes multiple data elements in a single processor instruction. Modern CPUs support SIMD (Single Instruction, Multiple Data) instructions through extensions like SSE, AVX, and AVX-512, which can handle 128, 256, and 512 bits simultaneously, respectively.

Here’s a C++ example using AVX2 intrinsic functions:

```cpp
#include <immintrin.h>

void AddArrays(float* result, const float* arr1, const float* arr2, int size) {
    for (int i = 0; i < size; i += 8) {
        __m256 a = _mm256_loadu_ps(&arr1[i]);
        __m256 b = _mm256_loadu_ps(&arr2[i]);
        __m256 r = _mm256_add_ps(a, b);
        _mm256_storeu_ps(&result[i], r);
    }
}
```

This example adds 8 floating-point numbers at a time using AVX2 instructions.

#### Loop Unrolling

**Loop unrolling** reduces loop overhead by handling multiple iterations in a single CPU cycle, allowing for better instruction-level parallelism and CPU pipelining.

Modern compilers often perform loop unrolling automatically, but you can guide them using pragmas:

```cpp
#pragma unroll(4)
for (int i = 0; i < size; i++) {
    result[i] = arr1[i] + arr2[i];
}
```

#### Cache Optimization

**Cache optimization** ensures data resides in the CPU cache for faster access. This involves techniques like data alignment, prefetching, and structuring data for spatial locality.

Here’s an example demonstrating cache-friendly data access:

```cpp
#include <vector>
#include <algorithm>

float CalculateSum(const std::vector<float>& data) {
    const size_t size = data.size();
    const size_t cacheLineSize = 64;  // Typical L1 cache line size in bytes
    const size_t step = cacheLineSize / sizeof(float);

    float sum = 0.0f;
    for (size_t i = 0; i < size; i += step) {
        sum += data[i];
    }

    return sum;
}
```

This example accesses data at intervals matching the cache line size, improving cache utilization.

#### Compiler Optimizations

Modern compilers like GCC, Clang, and MSVC offer auto-vectorization and other optimizations. Enable them with flags like `-O3`, `-march=native`, or `/O2` for MSVC.

#### Profiling and Measurement

Always profile your code to identify bottlenecks and measure the impact of optimizations. Tools like Intel VTune, AMD μProf, or platform-specific profilers can provide valuable insights.

#### Portable SIMD with Libraries

For portable SIMD code, consider using libraries like:

- **Eigen**: For linear algebra operations
- **xsimd**: A header-only C++ library for SIMD intrinsics
- **Highway**: Google’s performance-portable SIMD library


<div class="page"/>

### 99. What are some techniques for *reducing compile times* in large *C++ projects*?

Long compile times can be a significant bottleneck in larger C++ projects. Here are some effective techniques to reduce them:

#### Techniques for Reducing Compile Times

##### 1\. Use Forward Declarations

Prefer **forward declarations** in headers instead of full `#include` statements, especially for classes and functions where a pointer or reference is sufficient.

```cpp
// Forward declare instead of including the entire header
class SomeClass;

// Use a pointer or reference to the forward-declared class
SomeClass* ptr;
```

##### 2\. Minimize Header Inclusions

In `.h` files, only include the headers that are essential for the file’s declarations. Move unnecessary ones to the corresponding `.cpp` files.

##### 3\. Use Header Guards or `#pragma once`

Protect against multiple inclusions using **header guards** or `#pragma once`:

```cpp
#pragma once

// Or traditional header guards
#ifndef SOME_HEADER_H
#define SOME_HEADER_H
// ... header content ...
#endif
```

##### 4\. Prefer `inline` Functions in Headers

For small functions in header files, use the `inline` keyword to avoid multiple definitions:

```cpp
inline int square(int x) { return x * x; }
```

##### 5\. Use Angle Brackets for Standard Headers

For C++ standard headers, use angle brackets and the versions without the “c” prefix:

```cpp
#include <cmath>  // Instead of <math.h>
#include <vector>
```

##### 6\. Minimize Template Instantiations in Headers

Put explicit template **instantiations in source files** instead of headers to avoid code bloat.

##### 7\. Use Pimpl Idiom and Facades

The **Pointer to Implementation** (`Pimpl`) and **facade** design techniques hide class details, reducing ripple effects of changes.

##### 8\. Employ `const`, `constexpr`, and `enum class`

Use these tools to define compile-time constants:

```cpp
constexpr int MAX_SIZE = 100;
enum class Color { Red, Green, Blue };
```

##### 9\. Apply the One Definition Rule (ODR)

Ensure there is only one definition for non-inline objects or functions across translation units.

##### 10\. Keep Code Modular and Loosely Coupled

**Modular code** minimizes dependencies and allows for incremental changes.

##### 11\. Leverage Precompiled Headers

Use **precompiled headers** (PCH) to reduce repeated processing of standard or frequently used headers.

##### 12\. Consider Unity Builds

A **unity build** involves combining multiple source files into a single translation unit, potentially reducing build times.

##### 13\. Limit the Use of `auto` in Headers

Using `auto` may lead to implicit type inclusions, potentially affecting compile times in header files.

##### 14\. Use Modern C++ Features Judiciously

Features like concepts, coroutines, and modules can impact compile times. While they bring expressive power, be mindful of their associated costs.

##### 15\. Utilize Modules (C++20)

C++20 introduces **modules**, which can significantly improve compile times by reducing header parsing and providing better encapsulation:

```cpp
import <vector>;
import mymodule;
```

##### 16\. Employ Parallel Compilation

Utilize multi-core processors by enabling **parallel compilation** in your build system or compiler flags.

##### 17\. Use Extern Templates

For heavily templated code, use `extern template` to reduce instantiations:

```cpp
// In header
extern template class std::vector<MyClass>;

// In one cpp file
template class std::vector<MyClass>;
```

##### 18\. Optimize Include Hierarchies

Analyze and optimize your include hierarchies to minimize cascading includes and circular dependencies.


<div class="page"/>

### 100. How do you implement and use *lock-free data structures* for better *concurrency performance*?

Lock-free data structures are designed to improve **concurrency performance** in multi-threaded applications, particularly on modern CPU architectures. They offer several advantages over traditional lock-based synchronization mechanisms.

#### Key Benefits

- **Reduced Contention**: Minimizes threads waiting for locks
- **Deadlock Prevention**: Eliminates certain lock-induced application halts
- **Enhanced Scalability**: Maintains efficient thread utilization, especially on multi-core systems

#### Core Mechanisms

##### Atomic Operations

Atomic operations are fundamental to lock-free programming:

- **Guarantee**: Hardware ensures operation completion without interruption
- **Usage**: Crucial for maintaining data consistency in concurrent scenarios

```cpp
#include <atomic>

std::atomic<int> counter(0);
counter.fetch_add(1, std::memory_order_relaxed);
```

##### Compare-And-Swap (CAS)

CAS is a cornerstone of lock-free algorithms:

- **Purpose**: Ensures a value hasn’t changed since last read before modification
- **Application**: Enables optimistic concurrency control

```cpp
#include <atomic>

std::atomic<int> value(0);

bool cas_update(int expected, int new_value) {
    return value.compare_exchange_strong(expected, new_value);
}
```

##### Memory Ordering

Specifies how memory accesses are ordered:

- **Options**: `std::memory_order_seq_cst` (default), `std::memory_order_acquire`, `std::memory_order_release`, `std::memory_order_relaxed`
- **Usage**: Choose appropriate ordering to ensure necessary data dependencies and cache coherence

```cpp
#include <atomic>

std::atomic<int> data(0);
std::atomic<bool> flag(false);

// Producer
data.store(42, std::memory_order_relaxed);
flag.store(true, std::memory_order_release);

// Consumer
while (!flag.load(std::memory_order_acquire)) {}
int result = data.load(std::memory_order_relaxed);
```

#### Implementing Lock-Free Data Structures

##### Lock-Free Stack

A basic implementation of a lock-free stack:

```cpp
template<typename T>
class LockFreeStack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };
    std::atomic<Node*> head;

public:
    void push(const T& data) {
        Node* new_node = new Node(data);
        do {
            new_node->next = head.load(std::memory_order_relaxed);
        } while (!head.compare_exchange_weak(new_node->next, new_node,
                                             std::memory_order_release,
                                             std::memory_order_relaxed));
    }

    bool pop(T& result) {
        Node* old_head = head.load(std::memory_order_relaxed);
        do {
            if (old_head == nullptr) return false;
        } while (!head.compare_exchange_weak(old_head, old_head->next,
                                             std::memory_order_acquire,
                                             std::memory_order_relaxed));
        result = old_head->data;
        delete old_head;
        return true;
    }
};
```

#### Best Practices

1. **Use Standard Library**: Leverage `std::atomic` for atomic operations
2. **Avoid Blocking**: Design algorithms to progress without blocking threads
3. **Handle ABA Problem**: Be aware of and mitigate the ABA problem in CAS operations
4. **Memory Management**: Implement safe memory reclamation techniques (e.g., hazard pointers, epoch-based reclamation)
5. **Thorough Testing**: Extensively test lock-free structures under high concurrency
