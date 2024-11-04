#pragma once

#include <memory>
#include <map>

enum class StateID;
enum class Event;
class State;

class Context {
public:
    Context(StateID initialStateID);
    void start();
    void setSharedData(int data);
    int getSharedData() const;
private:
    void changeState(Event event);
    std::shared_ptr<State> currentState;
    // 状態遷移表: (現在の状態ID, イベント) -> 次の状態ID
    std::map<std::pair<StateID, Event>, StateID> stateTransitionTable;
    // 状態IDと状態オブジェクトのマッピング
    std::map<StateID, std::shared_ptr<State>> stateMap;
    // 共有データ 
    int sharedData;
};