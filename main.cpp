#include "header.h"
#include <string>

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
  } else if (string(argv[1]) == "add") {
    add_task(argc, argv);
  } else if (string(argv[1]) == "show") {
    display_tasks();
  } else if (string(argv[1]) == "rm") {
    if (string(argv[2]) == "-r") {
      remove_all();
    } else {
      remove_task();
    }
  } else if (string(argv[1]) == "mark") {
    mark_done();
  }
}
