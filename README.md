#### A simple todo list :smile:

### Create a tasks.json with the following contents

```json
{
  "tasks": []
}
```

### Compile with

```bash
g++ main.cpp functions.cpp -o todo
```

### Usage

```bash
./todo -h
```

### Options

```code
   -h        : for help
   add <task>: to add a new task
   mark      : mark the task as done
   show      : list all the tasks
   rm        : remove a task
   rm -r     : remove all tasks
```
