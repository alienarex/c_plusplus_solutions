# Resources
This folder should be used for general resources, such as files needed for input and those generated as output. Everything
in this folder, except for this **README** and images used for exercise descriptions, will be ignored as stated in **``.gitignore``**:

````
_Resources/*
!_Resources/README.md
!_Resources/img/
````

The reason we use a specified folder for resources is because of how _**working directories**_ are handled by different
environments. In order to avoid the hassle of finding the _**working directory**_ used by a certain IDE (for I/O files), 
we simply state that this folder should be used. For instance, we can do this in code as can be seen in some of the examples:

````
string fileName = "../../../_Resources/names.biy";
fstream outFile(fileName, ios::out|ios::binary);
...
````  

... which will open a stream to the file **``names.biy``** under **``/_Resources/``**. The dot-syntax **``../../../``** simply states that 
we need to traverse the folder structure backwards until we find the needed directory, which's placed directly under the 
project root.