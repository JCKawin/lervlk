#!/usr/bin/env bash

# Exit immediately if a command fails
set -e

SRC_DIR="shaders"
DST_DIR="compiled_shaders"

# Create output directory if it doesn't exist
mkdir -p "$DST_DIR"

# Check if glslc is installed
if ! command -v glslc &> /dev/null; then
    echo "Error: 'glslc' is not installed or not in PATH. Please install the Vulkan SDK."
    exit 1
fi

echo "Compiling shaders from '$SRC_DIR' into '$DST_DIR'..."

# Enable nullglob so empty folder doesn't break the loop
shopt -s nullglob
shader_files=("$SRC_DIR"/*)

if [ ${#shader_files[@]} -eq 0 ]; then
    echo "No files found in '$SRC_DIR/'."
    exit 0
fi

# Loop through and compile each file
for file in "${shader_files[@]}"; do
    if [ -f "$file" ]; then
        filename=$(basename "$file")
        output="$DST_DIR/${filename}.spv"
        
        echo "Compiling: $file -> $output"
        glslc "$file" -o "$output"
    fi
done

echo "Done! All shaders compiled successfully."