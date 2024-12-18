# Super-market-billing
Supermarket Billing System
Description
This is a simple supermarket billing system implemented in C++. The program allows users to:

-Add items to the inventory.
-Print a bill based on items purchased.
-Maintain and update the inventory in a text file (bill.txt).
Features
-Add Item: Add an item to the inventory with its name, rate, and quantity.
-Print Bill: Generate a bill by selecting items and quantities from the inventory.
-File Handling: Inventory data is saved and updated in a file (bill.txt) to ensure data persistence.
-Session Management: The system ensures that inventory changes are reflected in real-time using temporary files.
Prerequisites
A C++ compiler (e.g., GCC, MinGW, or Visual Studio).
Windows operating system (due to the use of windows.h for Sleep() and system("cls")).
Administrator privileges if the file path D:\\bill.txt is restricted.
