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

To install ```clang-format```, run the folling commands:

```bash
sudo apt install clang-format
```

After installation, you should be able to build the project using the provided Makefile.

## Build Targets

### Using the run script

You can use the `./run` script to execute common tasks:

- **`./run setup`** - Setup the development environment
- **`./run start`** - Build and run the application
- **`./run test`** - Build and run tests
- **`./run format`** - Format the source code using clang-format

### Using Make directly

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
# Using the run script

./run build     # Just build the app
./run run       # Build and run the app
./run test      # Build and run tests
./run format    # Format source code

# Using make directly

make build      # Just build the app without running it
make build-test # Just build tests without running them
make run        # Build and run the app
make test       # Build and run tests
```

## Pending Tasks

0. refactorizar todo
* crear todos los tests
1. cuando esté estable después de refactorizar todo, meter un cli para crear componentes, pages and utils
3. clear comments
4. create style guideline
* meter css formatter
* integrar con apt
* mirar cómo meter variables de CSS
* meter tema claro y tema oscuro aunque sea cargando distintos ficheros main en cada caso
* cuando esté todo el proceso inicial listo replicar el proceso para ver si es fácil instalarlo en otro entorno y perfeccionar el proceso (ya que aquí no tenemos gestor de paquetes)