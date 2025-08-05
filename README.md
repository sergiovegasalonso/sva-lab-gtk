# SVA-GTK Library

A simple GTK4-based desktop application with multiple pages and navigation.

## Build

```bash
make clean
make
make run
```

## Testing

Run the test suite to verify functionality:

```bash
# Run tests
make test

# Run tests with verbose output
make test-verbose

# Clean test artifacts
make test-clean
```

For more detailed testing information, see the [tests README](tests/README.md).

## CI/CD

Run the complete CI pipeline:

```bash
./ci.sh
```

## Project Structure

```
sva-gtk/
├── main.c              # Main application entry point
├── Makefile            # Build configuration
├── ci.sh               # CI/CD script
├── pages/              # Page components
│   ├── home/
│   ├── about/
│   └── contact/
├── utils/              # Utility functions
│   ├── utils.c
│   └── utils.h
└── tests/              # Test suite
    ├── test_utils.c
    ├── Makefile
    └── README.md
```

## Build Targets

### Application Build and Execution

- **`make build`** - Build the main application executable
- **`make run`** - Build and run the application
- **`make clean`** - Clean application build artifacts
- **`make rebuild`** - Clean and rebuild the application
- **`make all`** - Default target (same as `build`)

### Test Build and Execution

- **`make build-test`** - Build the test executable
- **`make test`** - Build and run tests
- **`make test-verbose`** - Build and run tests with verbose output
- **`make clean-test`** - Clean test build artifacts
- **`make rebuild-test`** - Clean and rebuild tests
- **`make all-test`** - Build test executable (alias for `build-test`)

This separation allows you to build and execute the application and tests independently:

```bash
# Just build the app without running it
make build

# Just build tests without running them
make build-test

# Build and run the app
make run

# Build and run tests
make test
```

## Pending Tasks

0. refactorizar todo, incluso este readme
2. extract navbar component from main
3. clear comments
4. create style guideline
5. add prettier
6. add husky
7. add github action
1. create basic tests

