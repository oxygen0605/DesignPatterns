#ifndef STATE_H
#define STATE_H

#include "FiniteStateMachine.h"

typedef struct State  {
    void (*entry)(FSM *fsm);        //入状イベント
    void (*exit)(FSM *fsm);         //出状イベント
    void (*event_run)(FSM *fsm);    //運転開始イベント
    void (*event_stop)(FSM *fsm);   //運転停止イベント
    void (*event_switch)(FSM *fsm); //運転切り替えイベント
} State;
void State_init(FSM *fsm);

#endif /* STATE_H */