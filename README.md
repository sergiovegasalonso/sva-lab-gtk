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

* dale caña a bin.sh y documentar el README con los comandos
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