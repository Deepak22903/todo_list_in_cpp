#ifndef MAIN
#define MAIN

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>
#include <string>

using json = nlohmann::json;
using namespace std;

json in_from_json();
void out_to_json(json j);
string arg_to_string(int argc, char *argv[]);
void add_task(int argc, char *argv[]);
void display_tasks();
void mark_done();
void remove_task();
void remove_all();

#endif // MAIN
