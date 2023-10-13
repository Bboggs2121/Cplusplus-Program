# Cplusplus-Program
The program created in C++ included in this repository was made to read an input file that contains one string on each line, and return a count for the product entered in those lines. I utilized a map to add the items into to keep each pair with its product name, and an integer (count). Once the product key is called, the count is returned. The menu choices provide options for the user to perform a specific task based on the integer they input into the program. For option 1, a product is searched for that is provided by the user in a prompt. After the user inputs a valid item in the list, the count is returned for the occurence of that item based on the input.txt file that was read. Option 2 provides a full list of all the items and their counts for the user to view. Option 3 provides a full list of all of the products and the count is printed with asterisks versus a number to display a histrogram type format. Option 4 allows the user to exit the program. 

# What did you do particularly well?
I feel that I provided the program with good code to protect the program from invalid inputs that may be entered by the user with the use of try and catch statements.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could have removed the redundant code in the main function for "string product" as it was not used in the loop. I probably could have better utilized std::map for searching to improve the time complexity overall, but I was not very familiar with maps at the time of writing. 

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I struggled with fully understanding the map container as well as implementations of the map. I had to lookup various youtube videos and read the cpluscplus page regarding what maps can do to gain a better understanding of how to properly use them. 

# What skills from this project will be particularly transferable to other project or course work?
I was able to narrow down my search for information regarding maps because of my understanding of what I needed the code to do because of the past activities we had learned from regarding vectors and linked lists. I think being able to read an input file stream and produce an output file stream will be important skills moving forward.

# How did you make this program maintainable, readable, and adaptable?
I was able to logically group functionality into separate functions, which makes the code maintainable and easier to understand. My naming conventions for the functions are descriptive of what is being performed by the function, which aids readability. The code I produced has consistent indentation and spacing, that way the structure is easier to understand. Error handling was implemented by anticipating possible invalid responses and handling them within the program. The overall separation of the program's functions allow for them to be easier in extending or modifying them for future use without affecting the others. 
