#include "Context.hpp"
#include "State.hpp"

Context::Context(StateID initialStateID): sharedData(0) {
    // 状態オブジェクトの初期化
    stateMap[StateID::StateA] = std::make_shared<ConcreteStateA>();
    stateMap[StateID::StateB] = std::make_shared<ConcreteStateB>();
    
    // 状態遷移のルール（状態遷移表）を設定
    stateTransitionTable[std::make_pair(StateID::StateA, Event::Event1)] = StateID::StateB;
    stateTransitionTable[std::make_pair(StateID::StateA, Event::Event2)] = StateID::StateA;
    stateTransitionTable[std::make_pair(StateID::StateB, Event::Event1)] = StateID::StateA;
    stateTransitionTable[std::make_pair(StateID::StateB, Event::Event2)] = StateID::StateB;

    // 初期状態の設定
    currentState = stateMap[initialStateID];
    currentState->entry(*this, Event::Unknown);
}

void Context::start() {
    int i = 0;
    while(i < 5) {
    //while(true) {
        Event ev = currentState->run(*this, Event::Unknown);
        changeState(ev);
        i++;
    }
}

void Context::changeState(Event event) {
    StateID currentStateID = currentState->getStateID();
    auto key = std::make_pair(currentStateID, event);
    auto it = stateTransitionTable.find(key);

    if (it != stateTransitionTable.end()) {
        currentState->exit(*this, event);
        
        StateID nextStateID = it->second;
        currentState = stateMap[nextStateID];
        currentState->entry(*this, event);
    } else {
        std::cout << "Context::hundleEvent: Unknown transition" << std::endl;
    }
}

void Context::setSharedData(int data) {
    sharedData = data;
}

int Context::getSharedData() const {
    return sharedData;
}