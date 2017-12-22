//
// Created by jsilva on 22-12-2017.
//

#ifndef CPPTHREADS_FOOCLASS1_H

#include <iostream>
#include <thread>

using namespace std;

#define CPPTHREADS_FOOCLASS1_H

class FooClass1{

public:
    /**
     * To run it with parameters.
     */
    void operator()(int size){
        cout << "####   Thread in a Class   ####" << endl;


        cout << "ThreadID: " << this_thread::get_id() << endl;
        cout << "SIZE = " << size << endl;
        cout << endl;

    }
};
#endif //CPPTHREADS_FOOCLASS1_H
