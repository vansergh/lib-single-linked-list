```
==203248== Memcheck, a memory error detector
==203248== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==203248== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==203248== Command: ./single-linked-list
==203248==
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
==203248==
==203248== HEAP SUMMARY:
==203248==     in use at exit: 0 bytes in 0 blocks
==203248==   total heap usage: 6 allocs, 6 frees, 73,792 bytes allocated
==203248==
==203248== All heap blocks were freed -- no leaks are possible
==203248==
==203248== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```