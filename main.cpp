#define SDL_MAIN_HANDLED

#include <iostream>
#include <chrono>

#include "core/GameBoyConfig.h"
#include "core/GameBoyCore.h"
#include "core/RomReader.h"
#include "core/cpu/instructions/Instruction.h"


#include "SDL2/SDL.h"

int main(int argc, char *argv[])
{
	// init emu
	GameBoyConfig gameBoyClassicConfig;
	gameBoyClassicConfig.displayMemorySize = 8 * 1024;
	gameBoyClassicConfig.workMemorySize = 8 * 1024;
	gameBoyClassicConfig.clockSpeed = 5 * 1000 * 1000;

	GameBoyConfig gameBoyColorConfig;
	gameBoyClassicConfig.displayMemorySize = 16 * 1024;
	gameBoyClassicConfig.workMemorySize = 8 * 1024; // todo update
	gameBoyClassicConfig.clockSpeed = 5 * 1000 * 1000; // todo update

	GameBoyCore core(gameBoyClassicConfig);

	// Privremeno dok je u test fazi...

	RomReader reader("C:\\Stuff\\Projects\\StudyBoy\\roms\\helloworld.gb");
	// RomReader reader("C:\\Users\\adnan\\CLionProjects\\StudyBoy\\roms\\Bounce.gb");


	core.getCpu()->setCodeLoader(new CodeLoader(reader.allocRomBuffer(), reader.getRomSize()));






	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
			"SDL2Test",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			144,
			144,
			0
	);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event e;

	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}

		try {
			core.Step();
		} catch ( const std::invalid_argument& ex ) {
			std::cout<<std::endl;
			std::cout<<ex.what();
			break;
		} catch ( const std::exception& ex ) {
			std::cout<<std::endl<<"SHIET "<<ex.what();
			break;
		}
	}

	core.PrintRegisters();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
