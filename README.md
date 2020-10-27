# Order-Of-Execution

Given homework was to determine the execution order of the lines in a given arbitarary programming language. This programming language was given in codes.txt file.

1 BEGIN Fun1
2 EXECUTE Fun1
3 END
4 BEGIN Main
5 CALL Fun1
6 END

An example code can be seen above. The execution order of the code will be 4,5,1,2,3,6 because of the rules of programming language.

The rules are: 

Every program will start from Main
CALL refers to function call and after the call program will continue from called function.
END refers to function end and after that the function will terminate.
After Main funtion ends the program will terminate and print the execution order with the Stack information.

A more complex example can be seen from codes.txt file.
