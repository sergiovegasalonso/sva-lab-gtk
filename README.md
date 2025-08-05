# sva-lab-gtk

A simple GTK4-based desktop application for personal experiments.

## Project Structure

sva-lab-gtk/
├── src/                        # Source code
│   ├── main.c                  # Main application entry point
│   ├── pages/                  # Page components
│   │   ├── home/
│   │   │   ├── home_page.c
│   │   │   └── home_page.h
│   │   ├── about/
│   │   │   ├── about_page.c
│   │   │   └── about_page.h
│   │   └── contact/
│   │       ├── contact_page.c
│   │       └── contact_page.h
│   └── utils/                  # Utility functions
│       ├── utils.c
│       └── utils.h
├── test/                       # Test suite
│   ├── README.md
│   ├── utils/
│   │   └── utils.c
│   └── pages/
│       ├── home/
│       ├── about/
│       └── contact/
├── Makefile                    # Build configuration
├── ci.sh                       # CI/CD script
└── README.md                   # Project documentation

## Build Targets

### Application

- **`make build`** - Build the application executable
- **`make run`** - Build and run the application
- **`make clean`** - Clean application build artifacts
- **`make rebuild`** - Clean and rebuild the application
- **`make all`** - Build application executable (same as `build`)

### Test

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

## Continuous Integration

Run the complete CI pipeline:

```bash
./ci.sh
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

