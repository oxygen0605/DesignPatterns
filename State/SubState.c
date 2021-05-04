#include <stdio.h>
#include "State.h"

static int SubStateCooling_switch(FSM *fsm);
static int SubStateWarming_switch(FSM *fsm);
static int SubStateDehumidifying_switch(FSM *fsm);

static const State substate_Cooling = {0,0,0,0,SubStateCooling_switch};
static const State substate_Warming = {0,0,0,0,SubStateWarming_switch};
static const State substate_Dehumidifying = {0,0,0,0,SubStateDehumidifying_switch};

void init_last_substate(FSM *fsm){
    fsm->last_substate = &substate_Cooling;
}

static int SubStateCooling_switch(FSM *fsm){
    printf("SubState: Cooling -> Warming\n");
    FSM_change_substate(fsm, &substate_Warming);
}

static int SubStateWarming_switch(FSM *fsm){
    printf("SubState: Warming -> Dehumidifying\n");
    FSM_change_substate(fsm, &substate_Dehumidifying);
}

static int SubStateDehumidifying_switch(FSM *fsm){
    printf("SubState: Dehumidifying -> Clooling\n");
    FSM_change_substate(fsm, &substate_Cooling);
}
