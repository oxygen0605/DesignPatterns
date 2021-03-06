#include <stdio.h>
#include "FiniteStateMachine.h"


int main(void){

    int c;
    FSM fsm;
    FSM_init(&fsm);

    while ((c = getchar()) != EOF) {
        switch (c) {
        case 'x':
            FSM_run(&fsm);
            break;
        case 'y':
            FSM_stop(&fsm);
            break;
        case 'z':
            FSM_switch(&fsm);
            break;
        default:
            break;
        }
    }
    return 0;
}