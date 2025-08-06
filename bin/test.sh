#!/bin/bash
set -eo pipefail

echo "⚠ Running tests..."
make clean-test
make test
echo "✓ Tests execution"
