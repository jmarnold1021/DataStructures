# Data Structures From a Languages Perspective

## General Conventions
 - Using VS Code IDE Currently cause I am helping a Friend.
 - Download and Install [VS Code](https://code.visualstudio.com/)
 - Working in MacOS(BSD) Environment
 - **If My code is used for cheating in School I am not Responsible!!!**
 - [VSCode User and Workspace Settings overview](https://code.visualstudio.com/docs/getstarted/settings)
 - Usually would not commit the env/ide configs but since they are in there own top level folder
   the code can just be pulled out of each repective language folder and reconfigured for different
   environments. I don't want to have to re-remember all this vs code stuff.
 - [Git Commit message conventions](https://eslint.org/docs/developer-guide/contributing/pull-requests#step-2-make-your-changes) I usually use these to
   maintain good habits but usually ignored unless adopted by many...


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
 - Build with Shift+CMD+B while DataStructuresTestRunner.cpp is selected,
   and run the executable created in C++/bin using the VSCode Terminal


## Python
 - In VS Code install "Python Extension Pack" Extension
 - Working with it is pretty much explained in the Extension details.
 - Note the .env file config necessary for properly importing custom modules
 - Note the "python.envFile" value in settings.json


## Node.js
 - TODO
