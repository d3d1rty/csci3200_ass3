#Assignment 3 - CSCI 3200 (APSU)
##About
This project is an assignment for CSCI 3200 (XML Processing) course at APSU. Being this is an educational project for a grade, collaboration isn't exactly the goal here. But if you feel that you can benefit from perusing my code, go for it! 

For reference, I have included the original assignment instructions. 

##What it Does
The purpose of the project is to extract specialized information from a well-formed XML document into separate comma-separated values (CSV) files. This is accomplished by using the Xerces SAX parser to parse through the XML document and creating specialized event handlers to perform the required actions. Refer to the comments in the code for more detailed information.

##Compiling
This project was compiled with the g++ compiler on an Arch linux machine. It *should* work with other Linux environments after you have satisfied the dependencies. Windows developers should be aware some changes to the program as well as system configuration may be necessary for it to function correctly on your system. 

To compile the project, use the following command:

`g++ -O2 -I ./xerces/include/ main.cpp ./xerces/lib/libxerces-c.a -lpthread -lcurl -licuuc`

Make sure that you include the `-lcurl -licuuc` flags or it will not compile.

##Dependencies

ICU- https://icu-project.org/

Libcurl- https://libcurl.org/

Xerces- https://xerces.apache.org/

##Instructions for Xerces
Download the tarball from http://xerces.apache.org/xerces-c/download.cgi

Extract the contents to the project directory. Important: if the xerces library is not located inside the project directory, you will need to adjust the `#include` statements in the program.

Go into the newly created directory and run the following commands:
```./configure --prefix=`pwd`/../xerces
make
make install```

##Academic Honesty
Please, just keep in mind that academic dishonesty is probably (definitely) not tolerated by your educational institution, so come up with your own solutions. Besides, I sincerely doubt that your assignment has the same requirements as mine, so you will probably look like an idiot if you try to turn this in.

##Credits
In this particular project, I've used the Xerces library provided by Apache. Refer to that project website for license information.

Big thanks to Dr. Nicholson for all guidance and assistance provided throughout the project. In addition to the personal assistance he provided in getting my environment set up correctly, his instructional videos for building a SAX parser were immensely helpful.

##Questions/Comments/Concerns
If you have any questions regarding this project, send me a message and I'd be more than happy to explain my code.

