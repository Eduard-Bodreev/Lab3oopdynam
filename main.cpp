#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Lab3.h"

int main(int argc, char* argv[]) {
    const char* MSGS[] = { "0 - Quit",
                        "1 - Print",
                        "2 - Union",
                        "3 - Add",
                        "4 - Intersection",
                        "5 - Exception",
                        "6 - IsExists" };

    const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
    int choice = 0;

    Set set = Program::CreateSet();

    do {
        choice = Input::dialog(MSGS, MSGS_SIZE);

        switch (choice) {
        case 1:
            Program::PrintSet(set);
            break;
        case 2:
            Program::Union(set);
            break;
        case 3:
            Program::Add(set);
            break;
        case 4:
            Program::Intersection(set);
            break;
        case 5:
            Program::Exception(set);
            break;
        case 6:
            Program::IsExist(set);
            break;
        default:
            break;
        }
        printf("--------\n");

    } while (choice >= 1 && choice <= 6);
    //char* trash = new char[100];
    _CrtDumpMemoryLeaks();
    return 0;
}