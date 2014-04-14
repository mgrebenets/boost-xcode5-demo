Boost Xcode 5 Demo
===

# Purpose
This is a demo project on using the boost framework built using [this script](https://github.com/mgrebenets/boost-ios-xcode5)

# Setting up the Project
Before you can build the demo project, you need to get boost framework for iOS and OSX.
Build those using the script mentioned above.
Then put iOS boost.framework into `vendor/ios` and OSX boost.framework to `vendor/osx`.
When building, include the following libraries into `BOOST_LIBS`:
* system
* thread
* serialization

``` bash
# boost.sh
: ${BOOST_LIBS:="serialization thread system"}
```

If you don't feel like building anything, just pick the tarball from [Releases section](https://github.com/mgrebenets/boost-xcode5-demo/releases) of this repo. Download it, unpack and replace contents of empty `vendor` folder.

# Build and Test
The project has some c++ code mainly demonstrating the use of `serialization` library, and a bit demo for `thread` library.
Sample code is provided as unit tests.
Build and run Unit Tests targets for iOS and OSX to see how it works.
