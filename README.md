**Note that this branch may not contain all the features of the master branch. Use the master branch as the project template and adjust accordingly to VSCode with the differences specified below.**

## VSCode-specific differences

I haven't found a clean way to get VSCode to recognize gtest (GoogleTest) headers. There is the option of installing the package via *vcpkg*, which, at a cursory glance, introduces unknowns and unnecessary overhead into my local system (I want to keep my system as clean as possible and not add anything that I can't fully understand). 

Anyways, the header detection problem is expected to recur with any library my CMake config pulls directly from git during the build process. My hack workaround right now is to maintain a folder within the project directory named ***thirdparty/hidden*** with a copy of gtest's (release) source code. That folder is included in the gitignore to not pollute the repository (*note that the entire project build completely ignores it anyways*). I then manually add that folder to VSCode's include path for autocomplete support.

The downside to this approach is for large-scale projects with many dependencies, it might be hard to keep track of / remember to sync different library versions. Continuous integration might help with making sure nothing breaks, but it's best to still keep the number of dependencies low. In addition, it is crucial to **only store copies of libraries in *thirdparty/hidden* AFTER you ensure it builds on CMake alone!**

This branch also exposes the .vscode folder. Of particular interest is the [c_cpp_properties.json](https://code.visualstudio.com/docs/cpp/c-cpp-properties-schema-reference) file, which enables modifications like changing VSCode's include search path mentioned above. Note that my config file is specific to my current machine running Ubuntu 18.04 with all relevant libraries installed (refer to personal config for backlog).
