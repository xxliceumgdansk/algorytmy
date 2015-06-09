#include <SFML/Graphics.hpp>
#include "BFS.h"
#include <vector>

using namespace sf;

void DrawGraph(vector<node*> graph, sf::RenderWindow& window, sf::Font font)
{
	static const float pi = 3.141592654f;

	float radixDelta = 2 * pi / graph.size() - pi / 2;
	int startingPointX = 200;
	int startingPointY = 200;
	int radius = 100;

	int radix = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		int y = sin(radix) * radius + startingPointY;
		int x = cos(radix) * radius + startingPointX;

		sf::Shape shape = sf::Shape::Circle(x, y, 2, sf::Color(150, 50, 250));

		window.draw(shape);

//		sf::Text numberText;
//		numberText.setColor(sf::Color(250, 150, 100));
//		string numberString = std::to_string(graph.at(i)->number);

//		numberText.setString(numberString);
//		numberText.setPosition(x, y);
//		numberText.setFont(font);

		//window.draw(numberText);

		radix += radixDelta;
	}
}


int main()
{
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Image Image;
    if (!Image.LoadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite Sprite(Image);

//    sf::Font font;
//
//	if (!font.loadFromStream(in))
//	{
//		return -1;
//	}

	string input = "0 1\n\
0 2\n\
0 8\n\
1 4\n\
1 5\n\
1 7\n\
2 9\n\
3 0\n\
3 10\n\
3 11\n\
4 13\n\
5 6\n\
5 7\n\
5 13\n\
7 8\n\
8 9\n\
10 9\n\
10 11\n\
12 0\n\
12 3\n\
13 12";

	vector<node*> graph = GenerateGraph(input, 14);

	// Start the game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

        // Clear screen
        App.Clear();

        // Draw the sprite
        App.Draw(Sprite);

        DrawGraph(graph, window, font);

        // Update the window
        App.Display();
    }

    return EXIT_SUCCESS;
}
