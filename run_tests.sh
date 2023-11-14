#!/bin/bash
for file in bytecodes/*.m; do
    echo "Running $file..."
    ./monty "$file"
done
