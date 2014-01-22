//
//  BDAppDelegate.m
//  boost-xcode5-osx-demo
//
//  Created by Grebenets, Maksym on 11/22/13.
//  Copyright (c) 2013 i4nApps. All rights reserved.
//

#import "BDAppDelegate.h"
#import "ThreadDemo.h"

@implementation BDAppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application

    ThreadDemo demo;
    demo.Demo();
}

@end
