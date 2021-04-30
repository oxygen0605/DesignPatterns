#include <stdio.h>
#include "State.h"

static void StateStopped_entry(FSM *fsm);
static void StateStopped_run(FSM *fsm);

static void StateRunning_entry(FSM *fsm);
static void StateRunning_exit(FSM *fsm);
static void StateRunning_stop(FSM *fsm);

static const State state_Stopped = {StateStopped_entry, 0, StateStopped_run, 0, 0};
static const State state_Running = {StateRunning_entry, StateRunning_exit, 0, StateRunning_stop, 0};

void State_init(FSM *fsm){
    void init_last_substate(FSM *fsm);
    fsm->current_state = &state_Stopped;
    fsm->current_substate = 0;
    init_last_substate(fsm);
}

/** Events **/
/* Stopped */
static void StateStopped_entry(FSM *fsm){
    FSM_change_substate(fsm, 0);
}
static void StateStopped_run(FSM *fsm){
    printf("State: Stopped -> Runnning\n");
    FSM_change_state(fsm, &state_Running);
}

/** Running **/
/* 入状イベント */
static void StateRunning_entry(FSM *fsm){
    FSM_change_substate(fsm, fsm->last_substate);
}

/* 出状イベント */
static void StateRunning_exit(FSM *fsm){
    fsm->last_substate = fsm->current_substate;
    FSM_change_substate(fsm, 0);
}

/* 運転停止イベント */
static void StateRunning_stop(FSM *fsm){
    printf("State: Running -> Stopped");
    FSM_change_state(fsm, &state_Stopped);
}