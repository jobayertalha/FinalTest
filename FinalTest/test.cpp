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

//  Concrete Products - Linux
class LinuxWindow : public Window {
public:
    std::string render() const override {
        return "Rendering Linux Window";
    }
};

class LinuxScrollBar : public ScrollBar {
public:
    std::string render() const override {
        return "Rendering Linux ScrollBar";
    }
};

//  Abstract Factory 
class GUIFactory {
public:
    virtual std::unique_ptr<Window> createWindow() const = 0;
    virtual std::unique_ptr<ScrollBar> createScrollBar() const = 0;
    virtual ~GUIFactory() {}
};

// Concrete Factories
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Window> createWindow() const override {
        return std::make_unique<WindowsWindow>();
    }

    std::unique_ptr<ScrollBar> createScrollBar() const override {
        return std::make_unique<WindowsScrollBar>();
    }
};

class LinuxFactory : public GUIFactory {
public:
    std::unique_ptr<Window> createWindow() const override {
        return std::make_unique<LinuxWindow>();
    }

    std::unique_ptr<ScrollBar> createScrollBar() const override {
        return std::make_unique<LinuxScrollBar>();
    }
};


