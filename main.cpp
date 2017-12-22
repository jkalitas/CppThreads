/**
 * Examples from https://www.tutorialcup.com/cplusplus/multithreading.htm
 */

#include <iostream>
#include <thread>
#include "FooClass.h"
#include "FooClass1.h"

using namespace std;

void threadSendMessage(){

    cout << "ThreadID: " << this_thread::get_id() << endl;
    cout << "Hello World on Thread" << endl;

}

/**
 * Simple Thread.
 */
void thread1(){
    cout << "####   Thread 1   ####" << endl;
    //Creating thread
    thread thread(threadSendMessage);
    //Wainting for the thread to finish
    thread.join();
    cout << endl;

}

/**
 * Example but testing if it's joinable.
 */
void thread2(){
    cout << "####   Thread 2   ####" << endl;

    thread thread1(threadSendMessage);
    //Once this is detached we wont see the message output
    thread1.detach();

    if(thread1.joinable()){
        thread1.join();
    }else{
        cout << "Thread1 is detached" << endl;
    }

    cout << endl;

}

int main() {

    thread1();
    thread2();

    /**
     * Initialize thread with a function from class.
     */
    FooClass fooClass;
    thread fooFunctor(fooClass);
    if(fooFunctor.joinable()){
        fooFunctor.join();
    }

    thread fooFunction(&FooClass::fooMethod,fooClass);
    if (fooFunction.joinable()){
        fooFunction.join();
    }


    thread fooFunctionWithParams(&FooClass::fooMethodWithParameters,fooClass,"Test message",6,7.543);
    if(fooFunctionWithParams.joinable()){
        fooFunctionWithParams.join();
    }

    FooClass1 fooClass1;
    int size = 6;
    thread functorWithParams(&FooClass1::operator(),fooClass1,size);
    if(functorWithParams.joinable()){
        functorWithParams.join();
    }

    return 0;
}