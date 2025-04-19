#include <iostream>
#include <string>
#include <memory>
#include <gtest/gtest.h>

//abstarct interfaces
class Window {
public:
    virtual std::string render() const = 0;
    virtual ~Window() {}
};

class ScrollBar {
public:
    virtual std::string render() const = 0;
    virtual ~ScrollBar() {}
};

//Concrete Products - Windows 
class WindowsWindow : public Window {
public:
    std::string render() const override {
        return "Rendering Windows Window";
    }
};

class WindowsScrollBar : public ScrollBar {
public:
    std::string render() const override {
        return "Rendering Windows ScrollBar";
    }
};

