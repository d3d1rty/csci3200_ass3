#Assignment 3 - CSCI 3200 (APSU)
##About
This project is an assignment for CSCI 3200 (XML Processing) course at APSU. Being this is an educational project for a grade, collaboration isn't exactly the goal here. But if you feel that you can benefit from perusing my code, go for it! 

For reference, I have included the original assignment instructions. 

##Academic Honesty
Please, just keep in mind that academic dishonesty is probably (definitely) not tolerated by your educational institution, so come up with your own solutions. Besides, I sincerely doubt that your assignment has the same requirements as mine, so you will probably look like an idiot if you try to turn this in.

##Questions/Comments/Concerns
If you have any questions regarding this project, send me a message and I'd be more than happy to explain my code.

##Credits
In this particular project, I've used the Xerces library provided by Apache. Refer to that project website for license information. All non-Xerces code is mine.

##Compiling
To compile the project, use the following command:

g++ -O2 -I ./xerces/include/ main.cpp ./xerces/lib/libxerces-c.a -lpthread -lcurl -licuuc

##Dependencies

ICU- https://icu-project.org/

Libcurl- https://libcurl.org/

Xerces- https://xerces.apache.org/