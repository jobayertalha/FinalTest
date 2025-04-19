#include <iostream>
#include <string>
#include <memory>
#include <gtest/gtest.h>
#include "pch.h"


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

// G-Test 
TEST(WindowsFactoryTest, CreateComponents) {
    WindowsFactory factory;
    auto window = factory.createWindow();
    auto scrollbar = factory.createScrollBar();
    EXPECT_EQ(window->render(), "Rendering Windows Window");
    EXPECT_EQ(scrollbar->render(), "Rendering Windows ScrollBar");
}

TEST(LinuxFactoryTest, CreateComponents) {
    LinuxFactory factory;
    auto window = factory.createWindow();
    auto scrollbar = factory.createScrollBar();
    EXPECT_EQ(window->render(), "Rendering Linux Window");
    EXPECT_EQ(scrollbar->render(), "Rendering Linux ScrollBar");
}

//  Demo 
void Demo(const GUIFactory& factory, const std::string& platformName) {
    std::cout << "Demo for " << platformName << ":\n";
    auto window = factory.createWindow();
    auto scrollbar = factory.createScrollBar();
    std::cout << window->render() << std::endl;
    std::cout << scrollbar->render() << std::endl;
    std::cout << "-----------------------------\n";
}

//  Main 
int main(int argc, char** argv) {
    // Run demo
    WindowsFactory windowsFactory;
    LinuxFactory linuxFactory;

    Demo(windowsFactory, "Windows");
    Demo(linuxFactory, "Linux");

   
}

