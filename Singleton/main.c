#include"stdio.h"
#include"singleton.h"

int main(){
    Singleton* singleton = getSingletonInstance();
    
    printf("%c\n", singleton->michael);

    return 0;
}