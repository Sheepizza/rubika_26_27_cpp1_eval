# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

There is the preprocessor (execute the macro, set the const...) then by script it will create a long .i file wich contains all the
include in the same file then it will merge all the .i files in .obj files.

2. What is the difference between a declaration and a definition?

In a declaration we say that a method exist ; it's in the .h file. A definition is what the method 
will do, we give a body to the declaration in the .cpp file.
 
3. What is the difference between passing a parameter by value, by reference, and by pointer?

When we pass a parameter by value we're actually making a copy of the value, a reference will pass 
the same object so if we modify the reference inside a method, it will modify it outside too, by 
pointer is actually a copy too but we will be able to modify the base object because we know his 
position in the memory.

4. What is the difference between the stack and the heap?

The stack is limited but quick, the heap is massive (it's the RAM) but slow. To put someting in the heap we use "new"
and we can access with a pointer, we also need to use "delete" to release the memory.

5. What is the difference between struct and class in C++?

A class will set his functions and variables in private by default, meanwhile the struct set in public by default.

6. What is the difference between the public, protected, and private access specifiers?

Public means everybody can access, protected just the object itself et his childrens can access 
and private is just the object itself.

7. What is a pure virtual function? What effect does it have on a class?

It's a function that doesnt have any definition and will need to have a definition in their childs, it's write 'virtual f() = 0'.

8. Briefly explain the diamond problem in multiple inheritance.

It's when we have a class inherit by two (at least) classes that inherite by the same parent class. In that case the derivate
class possess multiple definition for the same function / variable and we can't know wich one to use.

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

- The array : it's a fix sized container, it's good but it's not dynamic.
- The list : it's dynamic but it's slow to search and travel beacause it's fragmented inside the memory.
- The vector : it's a dynamic array so the elements are adjacent in the memory inside the memory, the problem 
is that when the vector reach the end of his allocated memory, it need to copy himself elsewhere.
- The map : it contains a pair of key/value and don't work with index, it's good for research but bad to travel
- The set : it's hashed so it can't contains the same element twice, it's good for research but bad to travel
- The queue : it's a vector but it follows the rule FIFO (First In First Out), so we can only get the first element
- The stack : the same that the queue but it follows LIFO (Last In First Out) so it returns the last element

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change.

An array

- You need to manage a queue of tasks that must be executed in the order they arrive.

A queue

- You frequently need to insert and remove elements in the middle of a sequence.

A vector

- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter.

A set

- You need to keep track of actions so that the most recent action can be undone before earlier actions.

A stack

- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations.

A set

- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID.

A map