Boost Xcode 5 Demo
===

# Purpose
This is a demo project on using the boost framework built using [this script](https://github.com/mgrebenets/boost-ios-xcode5)

# Setting up the Project
Before you can build the demo project, you need to get boost framework for iOS and OSX.
Build those using the script mentioned above.
Then put iOS boost.framework into `vendor/ios` and OSX boost.framework to `vendor/osx`.

# Build and Test
The project has some c++ code mainly demonstrating the use of `serialization` library.
Sample code is provided as unit tests.
Build and run Unit Tests targets for iOS and OSX to see how it works.
