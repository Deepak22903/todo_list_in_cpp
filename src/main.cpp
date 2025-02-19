#include "../include/header.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Usage : todo <option> <input>" << "\n";
    cout << "Use todo -h for help" << "\n";
    return 1;
  } else if (string(argv[1]) == "-h") {
    cout << "Usage : todo option <input>\n"
            "Your personal todo list uitility\n"
            "OPTIONS : \n"
            "   -h        : for help\n"
            "   add <task>: to add a new task\n"
            "   mark      : mark the task as done\n"
            "   show      : list all the tasks\n"
            "   rm        : remove a task\n"
            "   rm -r     : remove all tasks\n";
    return 0;
  } else if (string(argv[1]) == "add") {
    add_task(argc, argv);
    return 0;
  } else if (string(argv[1]) == "show") {
    display_tasks();
    return 0;
  } else if (string(argv[1]) == "rm" && string(argv[2]) == "-r") {
    remove_all();
    return 0;
  } else if (string(argv[1]) == "rm") {
    remove_task();
    return 0;
  } else if (string(argv[1]) == "mark") {
    mark_done();
    return 0;
  }
}
