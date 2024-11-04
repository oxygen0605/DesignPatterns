#ifndef FSM_H
#define FSM_H

struct State;

typedef struct FiniteStateMachine {
    const struct State *current_state;
    const struct State *current_substate;
    const struct State *last_substate;
} FSM;
void FSM_init(FSM *self);

void FSM_run(FSM *self);
void FSM_stop(FSM *self);
void FSM_switch(FSM *self);

void FSM_change_state(FSM *self, const struct State *new_state);
void FSM_change_substate(FSM *self, const struct State *new_state);

#endif /* FSM_H */