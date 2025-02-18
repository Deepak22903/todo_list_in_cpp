#include "header.h"
#include <string>
int sr;

json in_from_json() {
  ifstream inputFile("tasks.json");
  if (!inputFile.is_open()) {
    std::cout << "Error opening the tasks.json file" << "\n";
    return 1;
  }

  json j;
  inputFile >> j;
  inputFile.close();
  return j;
}
void out_to_json(json j) {
  ofstream outputFile("tasks.json");
  if (!outputFile.is_open()) {
    cout << "Error opening the tasks.json file" << "\n";
    return;
  }
  j.dump(4);
  outputFile << j;
  outputFile.close();
  return;
}

string arg_to_string(int argc, char **argv) {
  string res;
  for (int i = 2; i < argc; i++) {
    if (i == 2) {
      res = res + string(argv[i]);
    } else {
      res = res + " " + string(argv[i]);
    }
  }
  return res;
}
void add_task(int argc, char **argv) {
  string task = arg_to_string(argc, argv);
  json j = in_from_json();

  json newTask = {{"status", " "}, {"desc", task}};

  j["tasks"].push_back(newTask);
  out_to_json(j);
  cout << "added\n";
}

void display_tasks() {
  json j = in_from_json();
  sr = 1;
  for (auto &task : j["tasks"]) {
    cout << sr << ". [" << task.at("status").get<string>() << "] "
         << task.at("desc").get<string>() << "\n";
    sr++;
  }
}

void remove_task() {
  json j = in_from_json();
  int choice;
  cout << "Select a Task\n";
  display_tasks();
  cout << ">> ";
  cin >> choice;
  if (choice < 0 || choice > sr - 1) {
    cout << "Invalid task\n";
  } else {
    choice--;
    j["tasks"].erase(j["tasks"].begin() + choice);
    out_to_json(j);
    cout << "removed\n";
  }
}

void mark_done() {
  json j = in_from_json();
  int choice;
  cout << "Select a Task\n";
  display_tasks();
  cout << ">> ";
  cin >> choice;
  if (choice < 0 || choice > sr - 1) {
    cout << "Invalid task\n";
  } else {
    choice--;
    j["tasks"][choice].at("status") = "*";
    out_to_json(j);
    cout << "done\n";
  }
}

void remove_all() {
  json j = in_from_json();
  j["tasks"].clear();
  out_to_json(j);
  cout << "done\n";
}
