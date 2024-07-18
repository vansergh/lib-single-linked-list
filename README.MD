```
==124755== Memcheck, a memory error detector
==124755== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==124755== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==124755== Command: ./single-linked-list
==124755==
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
==124755==
==124755== HEAP SUMMARY:
==124755==     in use at exit: 0 bytes in 0 blocks
==124755==   total heap usage: 21 allocs, 21 frees, 74,320 bytes allocated
==124755==
==124755== All heap blocks were freed -- no leaks are possible
==124755==
==124755== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```