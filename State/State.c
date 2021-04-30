#include <stdio.h>
#include "State.h"

static void s_Stopped_run(FSM *fsm);

static void s_Running_entry(FSM *fsm);
static void s_Running_exit(FSM *fsm);
static void s_Running_stop(FSM *fsm);

static const State s_Stopped = {0, 0, s_Stopped_run, 0, 0};
static const State s_Running = {s_Running_entry, s_Running_exit, 0, s_Running_stop, 0};

void State_init(FSM *fsm){
    void init_last_substate(FSM *fsm);
    fsm->current_state = &s_Stopped;
    fsm->current_substate = 0;
    init_last_substate(fsm);
}

/** Events **/
/* Stopped */
static void s_Stopped_run(FSM *fsm){
    printf("State: Stopped -> Runnning\n");
    FSM_change_state(fsm, &s_Running);
}

/** Running **/
/* 入状イベント */
static void s_Running_entry(FSM *fsm){
    FSM_change_substate(fsm, fsm->last_substate);
}

/* 出状イベント */
static void s_Running_exit(FSM *fsm){
    fsm->last_substate = fsm->current_substate;
    FSM_change_substate(fsm, 0);
}

/* 運転停止イベント */
static void s_Running_stop(FSM *fsm){
    printf("State: Running -> Stopped");
    FSM_change_state(fsm, &s_Stopped);
}