# Factory-System-DS
Using different data structures (Tree, Double linked list, stack, queue) to implement a factory system that manage Suppliers and Spare parts data and the link between both of them.

# idea
Two classes one for suppliers and one for spare parts and the different data structures are functioning on these clases data.
The relation between the supplier class and the spare part class is represented in a double linked list.

# Generating Unique ID
generating IDs for every supplier and for every spare part.

the limits of the factory doesn't exceed 1000 so, we generate IDs from 1 to 1000 and mark them in a frequency array to true in order not repeat the same ID for two differnt things.
and then if any supplier or spare part is deleted mark it's ID in the frequency array to false to be able to generate this ID for something else. This will help us track the data and make links between them easily.

![Screenshot 2024-01-13 185445](https://github.com/Zay-nabb/Factory-System-DS/assets/156392721/c677fc54-e828-49aa-92c7-87fef13be08a)

# Template
using template in the tree and DLL, why?
For instance, to pass the class and multiple data of one supplier into one node.

# Stack
acts as the history of the program saves every single operation you have done.

# Options 
1. Add Supplier
2. Add Spare Part
3. Display Certain Supplier Details
4. Display Certain Spare Part's Details
5. Modify Certain Supplier Details
6. Modify Certain Spare Part's Details
7. Display Suppliers Tree
8. Display Parts Tree
9. Display Suppliers Linked list
10. Display Parts Linked list
11. Link Part to Supplier
12. Display Linked Parts and Suppliers
13. Remove Link Between Part and Supplier
14. Remove Supplier and Associated Links
15. Remove Spare Part and Associated Links
16. Display History Stack
17. Delete History Stack

