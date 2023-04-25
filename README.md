<!DOCTYPE HTML>
<html>
 <h1> CSC212 DSA Project by Jacob Hyun, Ivan Abreu, Sean Reth, Tanya Li </h1>
<body>
  <h2>B-Tree
  </h2>

<p>
  This project is a simple implementation of a B-Tree data structure in C++. The B-Tree is used to store and search student data, which is read from a csv file. The implementation allows users to perform searches for specific student data using the B-Tree's binary search algorithm.
  </p>
  
<h2>B-Tree Implementation
  </h2>

<p>
  A B-Tree is a self-balancing search tree that can be used to store and retrieve large amounts of data. In this project, we have implemented a B-Tree that stores student records, which consist of a student's ID, name, classes, emails. 
  </p>

<p>
  The B-Tree implementation in this project supports the following operations:<br>
* Insertion of new student records.<br>
* Deletion of existing student records.<br>
* Insertion or deletion of existing student classes.<br>
* Searching for student records by student ID.<br>
* Searching for the amount of student in a course.<br>
* Searching for the email of a student.<br>
* All students data could be printing out.<br>
  </P>

<h2>
  Planning
  </h2>

<p>
  Before implementing B-Tree, we discussed the basic requirements of the project. We decided to use a B-Tree data structure to store and search student records because it is an efficient way to perform binary searches on large numbers of records.
  </p>

<p>
  We also discuss how B-trees work in this project, including the specific requirements for the student records that will be stored. We decided to include Student ID, Last Name, First Name, Class 1, 2, 3, 4, 5, 6, and email in the record because these are common attributes used to identify and differentiate students.
  </p>

<p>
  Additionally, we determined the format and content of the CSV data file used to populate the B-tree with student records.
  </p>
  <h2>Indepth Look at the Program</h2>
  <h3> Files </h3>
  <p> The project consists of the following files: </p>
  <p><li>main.cpp - The main program file that contains the user interface for interacting with the Student Information System.</li>
     <li>student.h - Header file containing the declaration of the Student class.</li>
     <li>student.cpp - Source file containing the implementation of the Student class.</li>
     <li>bst.h - Header file containing the declaration of the BSTNode and BST classes.</li>
     <li>bst.cpp - Source file containing the implementation of the BSTNode and BST classes. </li></p>
 <h3> Compiling  Instructions</h3>
 <li>Compile the project files (main.cpp, student.cpp, and bst.cpp) using a C++ compiler (e.g., g++  main.cpp student.cpp bst.cpp -o main). </li>
 <li>You can then either continue through the terminal in CLION or open the executable created by the compiler in your directory </li>
 <li>Run the compiled program (e.g., ./main) if using terminal in CLION.</li>
 <li>Follow the prompts to interact with the Student Information System.</li>
 
 <h3> Runtime Instruction </h3>
 <p>After you have compiled and executed the program, you will be guided through a series of prompts to interact with the program. Here's a step-by- step guide on how to use the program: </p>
 <li>First, you will be prompted to enter the input file name containing the initial list of students and their information. Enter the file name and press Enter. </li>
 <li>Next, you will be prompted to enter the output file name where the program will store the results of your actions (e.g., printing all students' schedules). </li>
 <li>You will then see a list of available commands. Enter the command of your choice and press Enter.</li>
 <li>Based on your selected command, you may need to provide additional information, such as student ID, course name, or student details. </li>
 <li>After completing an action, you will be returned to the list of available commands. Continue to enter commands as needed.</li>
 <li>When you are done using the program, enter the 'QUIT' command to exit the program. </li>
 <li>Upon exiting the program, you can open the output file specified earlier to view the results of your actions. </li>

 <h2> Binary Tree Visualizer</h2>
 <p> It is recommended to click on this link https://github.com/Jacooob3/CSC212DSAProject/raw/main/graphviz.svg for the full visuals as it is a very wide image
     and could not fit on this page</p>
    
<h2> 
  In Conclusion
  </h2>
  
<p>
  Overall, this project provides a simple implementation of a B-Tree data structure written in C++ that can be used to store and search student records. B-Tree implementations are based on well-known algorithms and techniques designed to handle large datasets efficiently and scalable.
  </p>
  </body>
  </html>
