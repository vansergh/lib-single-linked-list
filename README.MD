```
==104852== Memcheck, a memory error detector
==104852== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==104852== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==104852== Command: ./single-linked-list
==104852==
//////////////////////////////
// Scalar test              //
//////////////////////////////

==============================
> Back: 0
> Size: 0
> Empty: Yes
==============================
> PushBack: 7, 9, 12
> Print: [12]<-[9]<-[7]
> Back: 12
> Size: 3
> Empty: No
==============================
> PopBack
> Print: [9]<-[7]
> Back: 9
> Size: 2
> Empty: No
==============================
> PopBack
> Print: [7]
> Back: 7
> Size: 1
> Empty: No
==============================
> PopBack
> Print: List is empty
> Back: 0
> Size: 0
> Empty: Yes
==============================
> PopBack (list is empty)
> Print: List is empty
> Back: 0
> Size: 0
> Empty: Yes
==============================
> PushBack: 7, 9, 12
> Print: [12]<-[9]<-[7]
> Back: 12
> Size: 3
> Empty: No
==============================
> FromBack: 12, 9, 7
> Back: 12
> Size: 3
> Empty: No
==============================
> Clear
> Print: List is empty
> Back: 0
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
> PushBack: cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]
> Back: lion
> Size: 3
> Empty: No
==============================
> PopBack
> Print: [elephant]<-[cow]
> Back: elephant
> Size: 2
> Empty: No
==============================
> PopBack
> Print: [cow]
> Back: cow
> Size: 1
> Empty: No
==============================
> PopBack
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> PopBack (list is empty)
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
> PushBack: dolphin, shark, cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]<-[shark]<-[dolphin]
> Back: lion
> Size: 5
> Empty: No
==============================
> PushBack: cow, elephant, lion
> Print: [lion]<-[elephant]<-[cow]<-[lion]<-[elephant]<-[cow]<-[shark]<-[dolphin]
> Back: lion
> Size: 8
> Empty: No
==============================
> FromBack: lion, elephant, cow, lion, elephant, cow, shark, dolphin
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
> list4.PushBack("one");
> list4.PushBack("two");
> list4.PushBack("five");
==============================
> Print list1: [world]<-[hello]
> Print list2: [red]<-[blue]
> Print list3: [dog]<-[cat]
> Print list4: [five]<-[two]<-[one]
==============================
> Copy
==============================
> Print list1: [world]<-[hello]
> {
>       SLList<std::string> list_r1 = list1;
>       Print list_r1: [world]<-[hello]
>       Print list1: [world]<-[hello]
> }
> Print list1: [world]<-[hello]
> list_r1 deleted
==============================
> Print list2: [red]<-[blue]
> SLList<std::string> list_r2(list2);
> Print list_r2: [red]<-[blue]
> Print list2: [red]<-[blue]
> list_r2.Clear();
> Print list_r2: List is empty
> Print list2: [red]<-[blue]
==============================
> Move
==============================
> Print list3: [dog]<-[cat]
> SLList<std::string> list_r3;
> list_r3 = std::move(list3);
> Print list3: List is empty
> Print list_r3: [dog]<-[cat]
==============================
> Print list4: [five]<-[two]<-[one]
> SLList<std::string> list_r4(std::move(list4));
> Print list4: List is empty
> Print list_r4: [five]<-[two]<-[one]
==============================
==104852==
==104852== HEAP SUMMARY:
==104852==     in use at exit: 0 bytes in 0 blocks
==104852==   total heap usage: 32 allocs, 32 frees, 74,784 bytes allocated
==104852==
==104852== All heap blocks were freed -- no leaks are possible
==104852==
==104852== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```