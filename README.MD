```
==7071== Memcheck, a memory error detector
==7071== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==7071== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==7071== Command: ./single-linked-list
==7071==
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
> FromBack:
> Back: 0
> Size: 0
> Empty: Yes
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
> FromBack: lion, elephant, cow, shark, dolphin
> Back: lion
> Size: 5
> Empty: No
==============================
> Clear
> Print: List is empty
> Back:
> Size: 0
> Empty: Yes
==============================
==7071==
==7071== HEAP SUMMARY:
==7071==     in use at exit: 0 bytes in 0 blocks
==7071==   total heap usage: 15 allocs, 15 frees, 74,152 bytes allocated
==7071==
==7071== All heap blocks were freed -- no leaks are possible
==7071==
==7071== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```