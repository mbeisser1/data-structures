How do you create custom exception classes? #q44 #custom-exceptions #exceptions

---
Create **custom exception classes** by **inheriting from `std::exception`** (or its derived classes) — define exceptions tailored to your application’s needs. **Override `what()`** and add members for extra context.

%%%MOCHI_CARD%%%
Show a custom `FileException` class. How do you extend `std::exception` with a message, file name, and error code? #q44 #custom-exceptions #exceptions

---
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

    const std::string& fileName() const { return m_fileName; }
    int errorCode() const { return m_errorCode; }
};
```

%%%MOCHI_CARD%%%
Show catching and using a custom exception. How do you throw `FileException` and read `what()`, file name, and error code in a handler? #q44 #custom-exceptions #exceptions

---
```cpp
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
```

%%%MOCHI_CARD%%%
What are best practices for custom exceptions? #q44 #custom-exceptions #exceptions

---

- **Specific types** for distinct failure modes
- **Descriptive names** (`FileException`, not `MyError`)
- **`what() const noexcept override`**
- Optional **hierarchy** of related exceptions
- Keep exceptions **exception-safe** (no leaks in ctor/`what()`)

%%%MOCHI_CARD%%%
In about 60 seconds, explain custom exception classes. #q44 #custom-exceptions #exceptions

---

- Inherit **`std::exception`**
- Override **`what()`**; mark it **`noexcept`**
- Add accessors for extra data (file name, error code, etc.)
- Catch **specific** type first, then **`std::exception`**
