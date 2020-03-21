// SDL_2 Adidier.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cstdlib>
#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include "vector2.h"
#include <vector>
#include <list>
//#include "Matriz.h"
//Variables for gradient 

//Screen dimension constants
int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;
int tam = 30;
//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;
SDL_Surface* sprite = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);


			}
		}
	}

	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


SDL_Quit();
}

void DrawLine3(float xA, float yA, float xB, float yB)
{
	float dx;
	float dy;
	float x;
	float y;
	float p;
	float i;
	int signx;
	int signy;

	dx = xB - xA;
	dy = yB - yA;
	x = xA;
	y = yA;

	if (dx >= 0)
	{
		signx = +1;
	}
	else
	{
		signx = -1;
	}
	if (dy >= 0)
	{
		signy = 1;
	}
	else
	{
		signy = -1;
	}
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	if (x == xB)
	{
		SDL_RenderDrawLine(gRenderer, x, y, xB, yB);
	}
	if (abs(dy) <= abs(dx))
	{
		p = 2 * dy * signy - dx * signx;
		for (int i = 0; i <= dx * signx; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);

			if (p < 0)
			{
				x = x + signx;
				y = y;
				p = p + 2 * dy * signy;
			}
			else
			{
				x = x + signx;
				y = y + signy;
				p = p + 2 * dy * signy - 2 * dx * signx;
			}
		}
	}
	else if (abs(dy) > abs(dx))
	{
		p = 2 * dx * signx - dy * signy;
		i = 0;
		for (i = 0; i <= dy * signy; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);

			if (p < 0)
			{
				x = x;
				y = y + signy;
				p = p + 2 * dx * signx;
			}
			else if (p >= 0)
			{
				x = x + signx;
				y = y + signy;
				p = p + 2 * dx * signx - 2 * dy * signy;
			}
		}
	}
	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x44, 0xFF);
}
void DrawLine34(float xA, float yA, float xB, float yB)
{
	float dx;
	float dy;
	float x;
	float y;
	float p;
	float i;
	int signx;
	int signy;

	dx = xB - xA;
	dy = yB - yA;
	x = xA;
	y = yA;

	if (dx >= 0)
	{
		signx = +1;
	}
	else
	{
		signx = -1;
	}
	if (dy >= 0)
	{
		signy = 1;
	}
	else
	{
		signy = -1;
	}
	if (x == xB)
	{
		SDL_RenderDrawLine(gRenderer, x, y, xB, yB);
	}
	if (abs(dy) <= abs(dx))
	{
		p = 2 * dy * signy - dx * signx;
		for (int i = 0; i <= dx * signx; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);

			if (p < 0)
			{
				x = x + signx;
				y = y;
				p = p + 2 * dy * signy;
			}
			else
			{
				x = x + signx;
				y = y + signy;
				p = p + 2 * dy * signy - 2 * dx * signx;
			}
		}
	}
	else if (abs(dy) > abs(dx))
	{
		p = 2 * dx * signx - dy * signy;
		i = 0;
		for (i = 0; i <= dy * signy; i++)
		{
			SDL_RenderDrawPoint(gRenderer, x, y);

			if (p < 0)
			{
				x = x;
				y = y + signy;
				p = p + 2 * dx * signx;
			}
			else if (p >= 0)
			{
				x = x + signx;
				y = y + signy;
				p = p + 2 * dx * signx - 2 * dy * signy;
			}
		}
		SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x44, 0xFF);
	}



}
void DrawLine4(Vector2 v1, Vector2 v2)
{
	DrawLine34(v1.getX(), v1.getY(), v2.getX(), v2.getY());
}
void DrawLine5(Vector2 v1, Vector2 v2)
{
	DrawLine3(v1.getX(), v1.getY(), v2.getX(), v2.getY());
}
void DrawLineDiv3(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4)
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x10, 0x10, 0x10);
	DrawLine4(v1, v2);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0x00);
	DrawLine4(v2, v3);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x20, 0xFF, 0x20);
	DrawLine4(v3, v4);
}
void DrawPoly(const std::vector<Vector2>&vertex)
{
	for (auto it = vertex.begin(); it != vertex.end(); it++)
	{
		if (it + 1 != vertex.end())
		{
			DrawLine5(*it, *(it + 1));
		}
		else if (it + 1 == vertex.end())
		{
			DrawLine5(*it, vertex.front());
		}
	}
}
void DrawVector2(const std::vector<Vector2>& vertex)
{
	for (auto it = vertex.begin(); it != vertex.end(); it++)
	{
		if (it + 1 != vertex.end())
		{
			DrawLine5(*it, *(it + 1));
		}
	}
}
void FillCircle(float r, float xc, float yc)
{
	float p = 1 - r;
	float x = 0;
	float y = r;
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	for (int i = 0; x <= y; i++)
	{
		if (p <= 0)
		{
			x = x + 1;
			y = y ;
			p = p + 2 * x + 3;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * x - 2 * y + 5;
		}
		SDL_RenderDrawPoint(gRenderer, x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);
	}
}
void DrawCircle(float r, float xc, float yc)
{
	float p = 1 - r;
	float x = 0;
	float y = r;
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	for (int i = 0; x <=  y; i++)
	{
		if (p <= 0)
		{
			x = x + 1;
			y = y;
			p = p + 2 * x + 3;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p = p + 2 * x - 2 * y + 5;
		}

		SDL_RenderDrawPoint(gRenderer, x+xc, y+yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, y + yc);
		SDL_RenderDrawPoint(gRenderer, -x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, x + xc, -y + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, x + yc);
		SDL_RenderDrawPoint(gRenderer, -y + xc, -x + yc);
		SDL_RenderDrawPoint(gRenderer, y + xc, -x + yc);
	}
	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x44, 0xFF);
}
void DrawCircleFace()
{
	DrawCircle(100, 200, 200);
	DrawLine5(Vector2(250, 150), Vector2(250, 200));
	DrawLine5(Vector2(150, 150), Vector2(150, 200));
	DrawLine5(Vector2(200, 180), Vector2(230, 180));
	DrawLine5(Vector2(230, 180), Vector2(200, 200));
	DrawLine5(Vector2(150, 250), Vector2(200, 280));
	DrawLine5(Vector2(200, 280), Vector2(250, 250));


}
void Rotation( Vector2& vertex, float angle)
{
	float x1 = cos(angle*M_PI /180) * vertex.getX() -sin(angle * M_PI / 180) * vertex.getY();
	float y1 = sin(angle * M_PI / 180) * vertex.getX() + cos(angle * M_PI / 180) * vertex.getY();
	vertex.setX(x1);
	vertex.setY(y1);
}
void Rotate(std::vector<Vector2>& vertexes, float angle)
{
	for (auto& vertex :vertexes )
	{
		Rotation(vertex, angle);	
	}
}
void SetScreen()
{
	if (SCREEN_WIDTH == 0 || SCREEN_HEIGHT == 0)
	{
		SCREEN_WIDTH = 720;
		SCREEN_HEIGHT = 480;
	}
	if (tam == 0)
	{
		tam = 32;
	}
}
void Transladar(std::vector<Vector2>& vertexes, Vector2& trans)
{
	for (auto& vertex : vertexes)
	{
		float x1 = vertex.getX() + trans.getX();
		float y1 = vertex.getY() + trans.getY();
		vertex.setX(x1);
		vertex.setY(y1);
	}
}
void Scale(std::vector<Vector2>& vertexes, Vector2& scale)
{
	for (auto& vertex : vertexes)
	{
		float x1 = vertex.getX() * scale.getX();
		float y1 = vertex.getY() * scale.getY();
		vertex.setX(x1);
		vertex.setY(y1);
	}
}
void DrawPlain()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Dibujamos en y desde la mitad
	SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT;)
	{
		i += 1;
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - i);
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
	}

	//Dibujamos en x desde la mitad
	for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH;)
	{
		i += 1;
		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT / 2);
		SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
	}

	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x00, 0x00);
	for (int i = (SCREEN_WIDTH / 2) + tam; i < SCREEN_WIDTH; i += tam)
	{
		for (int j = (SCREEN_HEIGHT / 2) + tam; j < SCREEN_HEIGHT; j += tam)
		{
			SDL_RenderDrawPoint(gRenderer, i, j);
			SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, j);
			SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT - j);
			SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT - j);
		}
	}


}
void BezierCurve(Vector2 v1, Vector2 v2, Vector2 v3, Vector2 v4)
{
	float x = 0;
	float y = 0;
	Vector2 Vect = Vector2(x,y);
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	for (float t = 0; t <= 1; t += .001)
	{
		x = pow(1 - t, 3) * v1.getX() + 3 * t * pow(1 - t, 2) * v2.getX() + 3 * pow(t, 2) * (1 - t) * v3.getX() + pow(t, 3) * v4.getX();
		y = pow(1 - t, 3) * v1.getY() + 3 * t * pow(1 - t, 2) * v2.getY() + 3 * pow(t, 2) * (1 - t) * v3.getY() + pow(t, 3) * v4.getY();
		SDL_RenderDrawPoint(gRenderer, x, y);
	}
	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x44, 0xFF);

}
int main(int argc, char* args[])
{
	SetScreen();

	struct Line
	{
		int x1;
		int y1;
		int x2;
		int y2;
		int x3;
		int y3;
		int x4;
		int y4;
	};
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;
	int x4 = 0;
	int y4 = 0;
	Vector2 MouseClick1;
	std::vector<Vector2> mousePos;
	std::list<Line> lines;
	bool drawing = false;
	bool linebool = false;
	bool bezier = false;
	bool circle = false;
	//Matriz m(2, 3, 2);
	//Matriz m2(2, 3, 1);
	//Matriz mr(2, 3, 1);
	//m.Print();
	//m2.Print();
	//mr.Print();
	//mr = m + m2;
	//m.Print();
	//m2.Print();
	//mr.Print();

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				//User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_MOUSEMOTION) {
					if (drawing)
					{
						x2 = e.motion.x;
						y2 = e.motion.y;
					}
					break;
				}
				if (e.type == SDL_MOUSEBUTTONUP)
				{

					drawing = false;
					Line line = { x1, y1, x2, y2};
					lines.push_back(line);
					break;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					x1 = e.button.x;
					y1 = e.button.y;
					MouseClick1 = Vector2(x1, y1);
					mousePos.push_back(MouseClick1);
					x2 = e.button.x;
					y2 = e.button.y;

					x3 = e.button.x;
					x4 = e.button.x;
					y4 = e.button.y;
					drawing = true;
					if (x1 >= 0 && x1 <= 20 && y1 >= 50 && y1 <= 60)
					{
						circle = true;
						linebool = false;
						bezier = false;
						lines.clear();
						mousePos.clear();
						std::cout << "colc";
					}
					if (x1 >= 0 && x1 <= 20 && y1 >= 30 && y1 <= 40)
					{
						linebool = true;
						bezier = false;
						circle = false;
						lines.clear();
						mousePos.clear();
						std::cout << "colb";
					}
					if (x1 >= 0 && x1 <= 20 && y1 >= 10 && y1 <= 20)
					{
						bezier = true;
						linebool = false;
						circle = false;
						lines.clear();
						mousePos.clear();
						std::cout << "col";
					}
					if (x1 >= 0 && x1 <= 20 && y1 >= 80 && y1 <= 90)
					{
						lines.pop_back();
						mousePos.clear();
					}
					break;
				}
			}
			SDL_RenderClear(gRenderer);
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

			DrawPlain();

			for (std::list<Line>::const_iterator i = lines.begin(); i != lines.end(); ++i)
			{
				if (circle == true)
				{
					
					Line line = *i;
					DrawCircle(abs(line.x2 - line.x1 + line.y2 -line.y1) , line.x1, line.y1);
				}
				if (linebool == true && mousePos.size() >= 2)
				{
					Line line = *i;
					DrawLine5(Vector2(line.x1,line.y1),Vector2(line.x2,line.y2));

				}
			}

			for (std::vector<Vector2>::const_iterator i = mousePos.begin(); i != mousePos.end(); ++i)
			{
				if (bezier == true && mousePos.size() >= 4)
				{
					Vector2 bez = *i;
					BezierCurve(Vector2(mousePos.at(mousePos.size() - 4)), Vector2(mousePos.at(mousePos.size() - 3)), Vector2(mousePos.at(mousePos.size()-2)),Vector2(mousePos.at(mousePos.size()-1)));
				}
			}
			std::vector<Vector2> a = std::vector<Vector2>(3);
			a[0] = Vector2(0, 80);
			a[1] = Vector2(0, 90);
			a[2] = Vector2(20, 90);
			//std::vector<Vector2> b = std::vector<Vector2>(4);
			//b[0] = Vector2(100, 100);
			//b[1] = Vector2(100, 150);
			//b[2] = Vector2(150, 150);
			//b[3] = Vector2(150, 100);
			//Vector2 scale = Vector2(3,3);
			//Vector2 trans = Vector2(100, 100);
			////Vector2 firstdot = Vector2(5, 5);
			////Vector2 seconddot = Vector2(15, 5);
			////Vector2 thirddot = Vector2(25, 5);
			////Vector2 fourthdot = Vector2(35, 5);
			//Rotate(a,20);
			//Transladar(a, trans);
			//Scale(a, scale);
			DrawPoly(a);
	/*		DrawVector2(b);*/
			DrawLine5(Vector2(0, 30), Vector2(20, 40));
			BezierCurve(Vector2(0, 10), Vector2(0, 20), Vector2(20, 20), Vector2(20, 10));
			DrawCircle(10, 10, 60);
			//DrawLineDiv3(firstdot, seconddot, thirddot, fourthdot);
			//FillCircle(50, 300, 300);
			//DrawCircleFace();
			//DrawVector2(a);
			//Rotation(210, 20, 230, 40, 210, 60, 230, 80);
			//DrawCircle(20, 300, 300);
			SDL_RenderPresent(gRenderer);
		}

	}

	//Free resources and close SDL
	close();

	return 0;
}
// Code based on https://gigi.nullneuron.net/gigilabs/drawing-lines-with-sdl2/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu 
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
