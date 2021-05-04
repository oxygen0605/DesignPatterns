#include <stdio.h>
#include "State.h"

static enum StateID {
    INIT_STATE,
    MIDDLE_STATE,
    FINAL_STATE 
} e_st;

static enum EventID {
    FIRST_EVE,
    SECOND_EVE
} e_ev;

static int s_Closed_run(FSM *fsm);
static int s_Opened_entry(FSM *fsm);
static int s_Opened_exit(FSM *fsm);
static int s_Opened_stop(FSM *fsm);

static const State s_Closed = {0, 0, s_Closed_run, 0, 0};
static const State s_Opened = {s_Opened_entry, s_Opened_exit, 0, s_Opened_stop, 0};

void State_init(FSM *fsm){
    printf("%d\n", INIT_STATE);
    void init_last_substate(FSM *fsm);
    fsm->current_state = &s_Closed;
    fsm->current_substate = 0;
    init_last_substate(fsm);
}

/** Events **/
/* Closed */
static int s_Closed_run(FSM *fsm){
    printf("State: Closed -> Runnning\n");
    FSM_change_state(fsm, &s_Opened);
}

/** Opened **/
/* 入状イベント */
static int s_Opened_entry(FSM *fsm){
    FSM_change_substate(fsm, fsm->last_substate);
}

/* 出状イベント */
static int s_Opened_exit(FSM *fsm){
    fsm->last_substate = fsm->current_substate;
    FSM_change_substate(fsm, 0);
}

/* 運転停止イベント */
static int s_Opened_stop(FSM *fsm){
    printf("State: Opened -> Closed\n");
    FSM_change_state(fsm, &s_Closed);
}