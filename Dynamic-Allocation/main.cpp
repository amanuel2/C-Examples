#include<iostream>

#define definedVar 4xx2342
/**
  * @param C++E
  * @authr Amanuel Bogale
  */
/*
  Dynamic Memory Allocation.
  Not a Faster way of allocating memory.
  Gets size on the fly, rather than before.
  But Stack Allocation<Your Normal Allocation..>
  Is Much Faster than Dynamic allocation or allocating
  in your HEAP.

  How to dynamically allocate? You use the
  new keyword. When you dynamically allocate
  a variable, you store it in the free space
  called HEAP.
  ________   _________     ________
  |      |   |       |     |      |
  | HEAP |   | STACK |     |STATIC|
  |      |   |       |     |      |
  |______|   |_______|     |______|

  Normally when you use local variables you store them
  in the STACK. When you use global variables you store it
  in The STATIC. But what about HEAP? Well thats where
  The Dynamically Allocated memory gets stored. The diffrent
  thing about the HEAP, is that we have to control it
  by our self, by  allocating memory and also remembering
  to deallocate it so we dont cause Garbage
*/
int main(){

int *p = new int(500);

/*Pointer p is now
pointing to an adress
of an int that is dynamically
allocated*/

delete p;
/*We must dealocate it before setting it to another
variable so the 500 int allocated memory
dosent become garbage
. If you dont do this.. it can lead to memory leak*/

p = new int(700);

delete p;

p = nullptr;
/*Then at last we must
delete the pointer it self
so it dosent become a
dangling pointer... and waste
memory in STACK*/
}
