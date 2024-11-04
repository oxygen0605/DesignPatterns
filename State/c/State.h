#ifndef STATE_H
#define STATE_H

#include "FiniteStateMachine.h"

typedef struct State  {
    int (*entry)(FSM *fsm);        //入状イベント
    int (*exit)(FSM *fsm);         //出状イベント
    int (*event_run)(FSM *fsm);    //運転開始イベント
    int (*event_stop)(FSM *fsm);   //運転停止イベント
    int (*event_switch)(FSM *fsm); //運転切り替えイベント
} State;
void State_init(FSM *fsm);

#endif /* STATE_H */