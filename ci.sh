#!/bin/bash

# Simple CI script for sva-gtk library tests
# This script builds the project and runs all tests

set -e  # Exit on any error

echo "=== SVA-GTK Library CI Test Runner ==="
echo

# Check for required dependencies
echo "Checking dependencies..."
if ! pkg-config --exists gtk4; then
    echo "ERROR: GTK4 development libraries not found!"
    echo "Please install gtk4-devel or libgtk-4-dev package"
    exit 1
fi

if ! command -v gcc &> /dev/null; then
    echo "ERROR: GCC compiler not found!"
    exit 1
fi

echo "✓ Dependencies found"
echo

# Build the main project
echo "Building main project..."
make clean
make build
echo "✓ Main project built successfully"
echo

# Build and run tests
echo "Building and running tests..."
make build-test
make test
echo "✓ All tests passed!"
echo

echo "=== CI COMPLETED SUCCESSFULLY ==="
