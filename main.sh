#!/bin/bash

# Define variables
target="main.cc"
compile_output="out/main"

ppm_output="out/output.ppm"
img_output="out/output.png"


# Compile the C++ program
g++ -w -o "$compile_output" "$target"  # -w flag is used to suppress warnings

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the program to generate the .ppm file
    ./"$compile_output" > "$ppm_output"
    
    # Check if the .ppm file was generated successfully
    if [ -f "$ppm_output" ]; then
        echo ".ppm file generated successfully."
        
        # Convert the .ppm file to .png using ImageMagick
        if command -v convert &> /dev/null; then
            convert "$ppm_output" "$img_output"
            echo "Conversion to PNG successful. File saved as output.png."
        else
            echo "ImageMagick is not installed. Skipping conversion."
        fi
    else
        echo "Failed to generate .ppm file."
    fi
else
    echo "Compilation failed."
fi
