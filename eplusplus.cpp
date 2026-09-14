#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>

// Optional SDL2 Integration for platforms with native window support
#ifdef EPLUSPLUS_GRAPHICS
    #include <SDL2/SDL.h>
    #if defined(__ANDROID__)
        #include <GLES/gl.h>
        #include <GLES2/gl2.h>
    #endif
#endif

namespace EPlusPlus {
    
    // Value Structure representing dynamic types
    struct Value {
        enum class Type { Null, Number, String, Boolean, Array } type = Type::Null;
        double numberValue = 0.0;
        std::string stringValue;
        bool boolValue = false;
        std::vector<Value> arrayValue;
    };

    // Global Execution Environment / Symbol Table
    std::unordered_map<std::string, Value> Environment;

    // Platform-Safe Standard Printer
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }

    // Core Script Interpreter Pipeline
    void executeScript(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "[E++ Fatal Error]: Could not open source file '" << filepath << "'\n";
            return;
        }

        std::string line;
        size_t lineNumber = 0;

        while (std::getline(file, line)) {
            lineNumber++;
            
            // Mandatory Standard Entry Point Check
            if (lineNumber == 1) {
                if (line.rfind("main", 0) != 0 && line.find("main") == std::string::npos) {
                    std::cerr << "[E++ Compiler Error]: Missing 'main' entry point on line 1.\n";
                    return;
                }
                continue; // Entry point verified
            }

            // Command: version•
            if (line.find("version•") != std::string::npos) {
                print("E++ Compiler Core Engine v1.0.0 (Cross-Platform)");
            }

            // Command: say'" ... "'
            size_t sayStart = line.find("say'\"");
            size_t sayEnd = line.find("\"'");
            if (sayStart != std::string::npos && sayEnd != std::string::npos && sayEnd > sayStart) {
                std::string msg = line.substr(sayStart + 5, sayEnd - (sayStart + 5));
                print(msg);
            }
        }
    }

#ifdef EPLUSPLUS_GRAPHICS
    // Safe Graphics Runner (Gracefully disables if display backend is unavailable)
    void runGraphicsUI() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "[E++ Graphics Warning]: Display init failed (" << SDL_GetError() << "). Falling back to Console Mode.\n";
            return;
        }

        SDL_Window* window = SDL_CreateWindow("E++ Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cerr << "[E++ Graphics Warning]: Window creation failed. Falling back to Console Mode.\n";
            SDL_Quit();
            return;
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        bool running = true;
        SDL_Event event;
        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                    running = false;
                }
            }
            SDL_SetRenderDrawColor(renderer, 24, 24, 32, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
#endif
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "E++ Programming Language Interpreter\n";
        std::cout << "Usage: eplusplus <script.epp>\n";
        return 0;
    }

    std::string filepath = argv[1];

#ifdef EPLUSPLUS_GRAPHICS
    // Attempt graphics runtime if requested
    EPlusPlus::runGraphicsUI();
#endif

    // Execute E++ Language Logic
    EPlusPlus::executeScript(filepath);

    return 0;
}