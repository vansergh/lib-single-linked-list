```
==204778== Memcheck, a memory error detector
==204778== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==204778== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==204778== Command: ./single-linked-list
==204778==
//////////////////////////////
// Scalar test              //
//////////////////////////////

==============================
> Back:
> Size: 0
> Empty: Yes
==============================
> push_back: 7, 9, 12
> Print: [12]<-[9]<-[7]
> Back: 12
> Size: 3
> Empty: No
==============================
> pop_back
> Print: [9]<-[7]
> Back: 9
> Size: 2
> Empty: No
==============================
> pop_back
> Print: [7]
> Back: 7
> Size: 1
> Empty: No
==============================
> pop_back
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> pop_back (list is empty)
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> push_back: 7, 9, 12
> Print: [12]<-[9]<-[7]
> Back: 12
> Size: 3
> Empty: No
==============================
> Clear
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================

//////////////////////////////
// Class (std::string) test //
//////////////////////////////

==============================
> Back:
> Size: 0
> Empty: Yes
==============================
> push_back: cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]
> Back: lion
> Size: 3
> Empty: No
==============================
> pop_back
> Print: [elephant]<-[cow]
> Back: elephant
> Size: 2
> Empty: No
==============================
> pop_back
> Print: [cow]
> Back: cow
> Size: 1
> Empty: No
==============================
> pop_back
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> pop_back (list is empty)
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> push_back: dolphin, shark, cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]<-[shark]<-[dolphin]
> Back: lion
> Size: 5
> Empty: No
==============================
> push_back: cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]<-[lion]<-[elephant]<-[cow]<-[shark]<-[dolphin]
> Back: lion
> Size: 8
> Empty: No
==============================
> Clear
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================

//////////////////////////////
// Copy & Move test         //
//////////////////////////////

==============================
> Initialization
==============================
> SLList<std::string> list1 = SLList<std::string>({ "hello"s,"world"s }); // std::initializer_list&& <- move
> SLList<std::string> list2 = {"blue"s,"red"s}; // std::initializer_list&& <- move
> SLList<std::string> list3({ "cat", "dog" }); // std::initializer_list&& <- move
> SLList<std::string> list4; // <- default empty constructor
> list4.push_back("one");
> list4.push_back("two");
> list4.push_back("five");
==============================
> Print list1: [hello]<-[world]
> Print list2: [blue]<-[red]
> Print list3: [cat]<-[dog]
> Print list4: [five]<-[two]<-[one]
==============================
> Copy
==============================
> Print list1: [hello]<-[world]
> {
>       SLList<std::string> list_r1 = list1;
>       Print list_r1: [hello]<-[world]
>       Print list1: [hello]<-[world]
> }
> Print list1: [hello]<-[world]
> list_r1 deleted
==============================
> Print list2: [blue]<-[red]
> SLList<std::string> list_r2(list2);
> Print list_r2: [blue]<-[red]
> Print list2: [blue]<-[red]
> list_r2.clear();
> Print list_r2: List is empty
> Print list2: [blue]<-[red]
==============================
> Move
==============================
> Print list3: [cat]<-[dog]
> SLList<std::string> list_r3;
> list_r3 = std::move(list3);
> Print list3: List is empty
> Print list_r3: [cat]<-[dog]
==============================
> Print list4: [five]<-[two]<-[one]
> SLList<std::string> list_r4(std::move(list4));
> Print list4: List is empty
> Print list_r4: [five]<-[two]<-[one]
==============================
==204778==
==204778== HEAP SUMMARY:
==204778==     in use at exit: 0 bytes in 0 blocks
==204778==   total heap usage: 32 allocs, 32 frees, 74,784 bytes allocated
==204778==
==204778== All heap blocks were freed -- no leaks are possible
==204778==
==204778== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```