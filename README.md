# Project: Seneca Library Application

The library application is written in `C++` following the `Object-Oriented` programming principles.

When Books and other publications arrive in the Seneca library, they should be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them. 
This application receives the publications and stores them into the system with the information needed for their retrieval. 
Later, each publication can be lent out to members of the library with a due date for return.

# Sample Output:

#### Adding a new publication to the library:
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 1
Adding new publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Shelf No: S001
Title: Seneca Student Handbook
Date: 2022/1/5
Add this publication to the library?
 1- Yes
 0- Exit
> 1
Publication added
```

#### removing a publication from the library 
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 2
Removing publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/11 |
   2- | P008 | MoneySense Magazine........... | 72614 | 2021/11/16 |
   3- | P008 | MoneySense Magazine........... | 48096 | 2021/11/17 |
   4- | P008 | MoneySense Magazine........... | 89325 | 2021/11/17 |
   5- | P008 | MoneySense Magazine........... | 33074 | 2021/11/17 |
   6- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/18 |
   7- | P008 | MoneySense Magazine........... | 70451 | 2021/11/24 |
   8- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 8
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Remove this publication from the library?
 1- Yes
 0- Exit
> 1
Publication removed
```

#### Checking out a publication
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/11 |
   2- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/18 |
   3- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 3
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Check out publication?
 1- Yes
 0- Exit
> 1
Enter Membership number: 12345
Publication checked out
```

#### Returning publication to library
```Text
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 4
Return publication to the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 1
Publication Title: Harry
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | T343 | Harry Potter.................. | 65205 | 2021/11/19 | J. K. Rowling   |
   2- | C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
   3- | C332 | Harry Potter and the Half/Bloo | 85952 | 2021/11/22 | J. K. Rowling   |
   4- | D208 | Harry Potter and the Philosoph | 72685 | 2021/11/19 | J. K. Rowling   |
> X (to Exit)
> Row Number(select publication)
> 2
| C872 | Harry Potter and the Deathly H | 64984 | 2021/11/17 | J. K. Rowling   |
Return Publication?
 1- Yes
 0- Exit
> 1
Please pay $4.00 penalty for being 8 days late!
Publication returned
```

> Made as a final project for the Object-Oriented Programming Principles course at Seneca College (Summer 2023)
