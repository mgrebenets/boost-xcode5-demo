//
//  ThreadDemo.cpp
//  boost-xcode5-demo
//
//  Created by Grebenets, Maksym on 1/22/14.
//  Copyright (c) 2014 i4nApps. All rights reserved.
//

#include "ThreadDemo.h"

#include <iostream>
#include <boost/thread.hpp>

using namespace std;

ThreadDemo::ThreadDemo() {

}

void ThreadFunction(void)
{
    int counter = 0;

    for(;;)
    {
        cout << "thread iteration " << ++counter << " Press Enter to stop" << endl;

        try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            boost::this_thread::sleep(boost::posix_time::milliseconds(500));
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread is stopped" << endl;
            return;
        }
    }
}

void ThreadDemo::Demo(void) {
    boost::thread t(&ThreadFunction);

    sleep(5);

    t.interrupt();
    t.join();

    cout << "Done with the thread";
}

