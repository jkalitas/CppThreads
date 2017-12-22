//
// Created by jsilva on 22-12-2017.
//

#ifndef CPPTHREADS_FOOCLASS_H

#include <thread>
#include <iostream>
using namespace std;

#define CPPTHREADS_FOOCLASS_H

class FooClass{


public:

    /**
     * To run it as thread we must implement the void operator()() function.
     */
    void operator()(){
        cout << "####   Thread in a Class   ####" << endl;
        cout << "ThreadID: " << this_thread::get_id() << endl;
        cout << "Foo Class function" << endl;
        cout << endl;

    }

    void fooMethod(){

        cout << "####   Foo Method   ####" << endl;
        cout << "ThreadID: " << this_thread::get_id() << endl;
        cout << "Public function from class" << endl;
        cout << endl;
    }

    void fooMethodWithParameters(string message, int anyValue, float floatValue){

        cout << "####   Foo Method w/ Parameters   ####" << endl;
        cout << "ThreadID: " << this_thread::get_id() << endl;
        cout << message << endl;
        cout << anyValue << endl;
        cout << floatValue << endl;
        cout << endl;

    }
};
#endif //CPPTHREADS_FOOCLASS_H
