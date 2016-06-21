#!/bin/sh

# scripts to run before build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..

# build and run tests (ie make & make test)
cmake --build .
ctest --verbose --output-on-failure

# generate (but don't publish) GCov coveralls results
coveralls --dryrun --root .. --verbose --exclude-pattern ".*feature_tests.*" --exclude-pattern ".*CompilerId.*"

