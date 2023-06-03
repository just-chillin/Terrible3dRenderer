// Terrible3dRenderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

#include <SDL.h>

#include "RenderNode.h"
#include "RenderObject.h"

bool isObjectDefinition(std::string& line) {
    if (line.length() < 0) {
        return false;
    }

    return line[0] == 'o';
}

std::vector<std::unique_ptr<RenderObject>> getRenderObjects(std::ifstream& buf) {
    std::vector<std::unique_ptr<RenderObject>> objects;

    while (!buf.eof()) {
        std::string current_line;
        std::getline(buf, current_line);

        if (isObjectDefinition(current_line)) {
            objects.push_back(std::make_unique<RenderObject>(RenderObject()));
            continue;
        }
        
        if (objects.empty()) {
            // TODO: process global render directives
            continue;
        }

        // Temporary pointer to current_object
        auto& current_object = objects.back();

        try {
            std::stringstream l;
            l << current_line;
            current_object->consume(l);
        }
        catch (...) {
            std::cerr << "invalid line: " << current_line << std::endl;
            continue;
        }
    }

    return objects;
}

void usage() {
    std::cout << "usage: render.exe file" << std::endl;
}

int wmain(int argc, wchar_t** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    if (argc < 1) {
        usage();
        return 1;
    }

    std::ifstream input_file;
    input_file.open(argv[1]);

    auto renderObjects = getRenderObjects(input_file);

    std::cout << "Objects" << std::endl;
    std::cout << "=======" << std::endl;
    for (auto& renderObject : renderObjects) {
        std::cout << *renderObject.get() << std::endl;
    }

    input_file.close();
    return 0;
}
