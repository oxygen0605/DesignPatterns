#include "Context.hpp"
#include "State.hpp"


int main() {
    Context context(StateID::StateA); //StateAのrunは実行されない
    context.start();
    return 0;
}