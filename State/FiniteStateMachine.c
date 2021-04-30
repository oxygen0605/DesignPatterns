#include <stdio.h>
#include "FiniteStateMachine.h"
#include "State.h"

void FSM_init(FSM *self){
    State_init(self);
}

void FSM_run(FSM *self){
    if (self->current_state && self->current_state->event_run){
        printf("Event: Run\n");
        self->current_state->event_run(self);
    }
}

void FSM_stop(FSM *self){
    if (self->current_state && self->current_state->event_stop) {
        printf("Event: Stop\n");
        self->current_state->event_stop(self);
    }
}

void FSM_switch(FSM *self){
    if (self->current_substate && self-> current_substate->event_switch) {
        printf("Event: Switch\n");
        self->current_substate->event_switch(self);
    }
}

static void change_state_common(FSM *self, const State **current, const State *new_state){
    if (*current && (*current)->exit) {
        printf("Do exit func\n");
        (*current)->exit(self);
    }
    
    *current = new_state;
    if (new_state && new_state->entry) {
        new_state->entry(self);
    }
}

void FSM_change_state(FSM *self, const State *new_state) {
    change_state_common(self, &self->current_state, new_state);
}

void FSM_change_substate(FSM *self, const State *new_state) {
    change_state_common(self, &self->current_substate, new_state);
}