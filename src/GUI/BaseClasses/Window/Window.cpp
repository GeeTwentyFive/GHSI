#include "Window.h"




void Window::EndGrouping() {

	window->end();

}




void Window::Show() {

	window->show();

}




void Window::Center() {

	int windowWidth = window->w();

	int windowHeight = window->h();




	int centeredX = (SCREEN_WIDTH / 2) - (windowWidth / 2);

	int centeredY = (SCREEN_HEIGHT / 2) - (windowHeight / 2);




	window->position(centeredX, centeredY);

}








void Window::CreateWindow(int w, int h, const char* title) {

	window = new Fl_Window(w, h, title);

	Center();

	window->color(WINDOW_COLOR);

}