#pragma once

#include <iostream>
#include "Context.hpp"

// イベントの定義
enum class Event {
    None = -1,
    Event1,
    Event2,
    Unknown
};

enum class StateID {
    None = -1,
    Event1,
    StateA,
    StateB,
    Unknown
};

class State {
public:
    virtual ~State() {};
    virtual Event run(Context& context, Event event) = 0;
    virtual Event entry(Context& context, Event event) = 0;
    virtual Event exit(Context& context, Event event) = 0;
    virtual StateID getStateID() const = 0;  
};

class ConcreteStateA : public State {
public:
    Event run(Context& context, Event event) override {
        std::cout << "ConcreteStateA::run" << std::endl;

        //共有データを操作
        int data = context.getSharedData();
        data += 10;
        context.setSharedData(data);
        std::cout << "ConcreteStateA::run: sharedData = " << data << std::endl;
        return Event::Event1;
    }

    Event entry(Context& context, Event event) override {
        std::cout << "ConcreteStateA::entry" << std::endl;
        return Event::None;
    }

    Event exit(Context& context, Event event) override {
        std::cout << "ConcreteStateA::exit" << std::endl;
        return Event::None;
    }

    StateID getStateID() const override {
        return StateID::StateA;
    }
};

class ConcreteStateB : public State {
public:
    Event run(Context& context, Event event) override {
        std::cout << "ConcreteStateB::run" << std::endl;

        //共有データを操作
        int data = context.getSharedData();
        data /= 2;
        context.setSharedData(data);
        std::cout << "ConcreteStateB::run: sharedData = " << data << std::endl;

        return Event::Event1;
    }

    Event entry(Context& context, Event event) override {
        std::cout << "ConcreteStateB::entry" << std::endl;
        return Event::None;
    }

    Event exit(Context& context, Event event) override {
        std::cout << "ConcreteStateB::exit" << std::endl;
        return Event::None;
    }

    StateID getStateID() const override {
        return StateID::StateB;
    }
};