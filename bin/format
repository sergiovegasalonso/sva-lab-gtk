#!/bin/bash
set -eo pipefail

echo "⚠ Formatting code..."
find src/ test/ -name "*.c" -o -name "*.h" | xargs clang-format -i
echo "✓ Format process"
