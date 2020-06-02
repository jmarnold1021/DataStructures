# Data Structures From a Languages Perspective

## General Conventions
 - Using VS Code IDE Currently cause I am helping a Friend.
 - Download and Install [VS Code](https://code.visualstudio.com/)
 - Working in MacOS(BSD) Environment
 - **If My code is used for cheating in School I am not Responsible!!!**

## Java
 - In VS Code install "Java Extension Pack" Extension
 - Fork this repo in Github and clone to your dev machine...where vs code is installed.
 - In VS Code open open the cloned DataStructures Folder.
 - Third Party Junit libs are added through VS Code's Referenced Libraries in the project navs side bar.
 - Running the Top Level test in DataStructuresTestRunner should Fail a single test on a Builtin Java collection.
 - Start Implementing The empty methods in Java files and write corresponding tests in DataStructuresTestRunner.java.

**If still receiving errors may need to manually install JDK first I did this first and everything else worked.**
 - Download and install [Java JDK14 from Oracle](https://www.oracle.com/java/technologies/javase-jdk14-downloads.html) which is the newset.

## C++
 - In VS Code install [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) Extension
   there are a couple different ones but this should help find a good one, the one I am using.
 -  Follow [VS Code Clang Tutorial](https://code.visualstudio.com/docs/cpp/config-clang-mac)
    Except for the prjects and hellow world creation since that is the C++ dir.

 - tasks.json example
```javascript
# tasks.json example...
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  // for the documentation about the tasks.json format
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "clang++ build active file",
      "command": "/usr/bin/clang++",
      "args": [
        "-std=c++17",
        "-stdlib=libc++",
        "-g",
        "${workspaceFolder}/C++/*.cpp",
        "-o",
        "${workspaceFolder}/C++/bin/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceFolder}/C++"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```

- Build with Shift+CMD+B and run the executable created in C++/bin using the VSCode Terminal


## Python
 - In VS Code install "Python Extension Pack" Extension
 - Working with it is pretty much explained in the Extension details.


## Node.js
 - TODO
