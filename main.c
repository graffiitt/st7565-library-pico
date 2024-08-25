
#include "st7567.h"

int main()
{
    stdio_init_all();

    st7567_Init();

    while (1)
    {
        sleep_ms(50);
        st7567_Test();
    }
}