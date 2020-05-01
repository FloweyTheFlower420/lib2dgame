#include "camera.h"

using namespace world; 				// using namespaces for convenience
using namespace types;

int main()
{
	double x = 0; 
	double y = 0;

	sf::Image green;			// example tile image
	sf::Image cyan;				// another tile for testing
	
	green.loadFromFile("green.png");	// load from file
	cyan.loadFromFile("cyan.png");
	
	tileset_t t{green, cyan};		// create tileset
	level_t l{				// create levels, which tells tilemap which tile to use
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0}, 
		{0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
		};
	world::tilemap tmap (t, l, 32);		// create tilemap; 32 is the size of the tiles
	sf::RenderWindow window(sf::VideoMode(352, 320), "tilemap example");

	tmap.render(); 				// render tilemap and store to internal buffer
	while (window.isOpen())
    	{
        	// check all the window's events that were triggered since the last iteration of the loop
        	sf::Event event;
        	while (window.pollEvent(event))
        	{
        	   	// "close requested" event: we close the window
        	    if (event.type == sf::Event::Closed)
        	        window.close();while (window.pollEvent(event))

            	if (event.type == sf::Event::KeyPressed)
            	{
                	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    	y-=1;
                	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    	x-=1;
                	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    	y+=1;
                	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    	x+=1;
                }
        	}
		window.clear();			// clear screen
		tmap.draw(&window, {x,y});	// redraw the tilemap (very fast)
		window.display();		// update screen
    	}  
}
