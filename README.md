# sva-lab-gtk

A simple GTK4-based desktop application for personal experiments.

## Installation GTK on Ubuntu

To install GTK4 development dependencies on Ubuntu, run the following commands:

```bash
# Update package list
sudo apt update

# Install GTK4 development libraries and tools
sudo apt install libgtk-4-dev

# Install additional development tools
sudo apt install build-essential pkg-config

# Verify installation
pkg-config --modversion gtk4
```

After installation, you should be able to build the project using the provided Makefile.

## Project Structure

```bash
sva-lab-gtk/
├── .github/
│   ├── workflows/
│       └── ci.yml              # Continous integration steps
├── .vscode/
│   ├── c_cpp_properties.json   # C and C++ configuration for Visual Studio Code
│   └── settings.json           # C and C++ configuration for Visual Studio Code
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
├── .gitignore                  # Files to be ignored by git
├── Makefile                    # Build configuration
└── README.md                   # Project documentation
```

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

0. refactorizar todo
2. extract navbar component from main
3. clear comments
4. create style guideline
5. add prettier
6. add husky
1. create basic tests
