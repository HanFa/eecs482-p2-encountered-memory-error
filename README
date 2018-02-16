This is an example of a memory read error, which results in the undeterministic bugs in eecs482 project2.

Here is the setup: 

We have a class call `thread`, which has a member of `impl_ptr` that points to an allocated block of memory of the subclass `thread::impl`.

And the member function `echoValue` yells out the value inside the `impl_ptr`.

The main function echos this value twice before and after the deletion of the memory pointed by `impl_ptr`:

``` c++
thread t1;
t1.echoValue();

// if impl is deleted
delete t1.impl_ptr;
t1.echoValue();
```

The output will be (surprisingly without segfault):

```
the val in impl is 100
the val in impl is 100
```

Detect this kind of error using `valgrind ./exe.out`:

```
==2897== Memcheck, a memory error detector
==2897== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==2897== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==2897== Command: ./exe.out
==2897== 
the val in impl is 100
==2897== Invalid read of size 4
==2897==    at 0x400ADC: thread::echoValue() (thread.cc:10)
==2897==    by 0x400BBC: main (main.cc:14)
==2897==  Address 0x5ab6c80 is 0 bytes inside a block of size 4 free'd
==2897==    at 0x4C2F24B: operator delete(void*) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2897==    by 0x400BB0: main (main.cc:13)
==2897==  Block was alloc'd at
==2897==    at 0x4C2E0EF: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==2897==    by 0x400AAC: thread::thread() (thread.cc:5)
==2897==    by 0x400B98: main (main.cc:9)
==2897== 
the val in impl is 100
==2897== 
==2897== HEAP SUMMARY:
==2897==     in use at exit: 72,704 bytes in 1 blocks
==2897==   total heap usage: 3 allocs, 2 frees, 73,732 bytes allocated
==2897== 
==2897== LEAK SUMMARY:
==2897==    definitely lost: 0 bytes in 0 blocks
==2897==    indirectly lost: 0 bytes in 0 blocks
==2897==      possibly lost: 0 bytes in 0 blocks
==2897==    still reachable: 72,704 bytes in 1 blocks
==2897==         suppressed: 0 bytes in 0 blocks
==2897== Rerun with --leak-check=full to see details of leaked memory
==2897== 
==2897== For counts of detected and suppressed errors, rerun with: -v
==2897== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


```