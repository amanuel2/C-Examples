#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>				//Our primitive header file
#include<iostream>
#include<string>
enum GameState {
	PLAY,
	EXIT
};

template<class T>
void checkErr(T err) {
	if (!err)
		exit(1);
}

void colorPicker(float* r, float* g, float* b, std::string color) {
	if (color.compare("Magenta") == 0)
		*r = 255, *g = 0, *b = 255;
}
int main(void) {
	float R, G, B;
	double RADIUS_X = 20, RADIUS_Y = 30;
	unsigned const int _WIDTH = 650, _HEIGHT = 480;
	unsigned int POS_X = _WIDTH / 2, POS_Y = _HEIGHT / 2;
	colorPicker(&R, &G, &B, "Magenta");
	GameState _gameState = GameState::PLAY;
	ALLEGRO_COLOR _COLOR = al_map_rgb(R, G, B);
	ALLEGRO_DISPLAY* _DISPLAY = NULL;
	ALLEGRO_EVENT_QUEUE* _EVQUEUE = NULL;


	checkErr(al_init());

	_DISPLAY = al_create_display(_WIDTH, _HEIGHT);
	checkErr(_DISPLAY);

	//INITALIZE SYSTEMS
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	//Create Event
	_EVQUEUE = al_create_event_queue();
	//Enable Mouse and Keyboard
	al_register_event_source(_EVQUEUE, al_get_keyboard_event_source());
	al_register_event_source(_EVQUEUE, al_get_mouse_event_source());

	//Hide Mouse
	al_hide_mouse_cursor(_DISPLAY);
	while (_gameState != GameState::EXIT) {
		ALLEGRO_EVENT _EV;
		al_wait_for_event(_EVQUEUE, &_EV);

		if (_EV.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			_gameState = GameState::EXIT;
			std::cout << "EXIT" << std::endl;
		} else if(_EV.type == ALLEGRO_EVENT_MOUSE_AXES){
			POS_X = _EV.mouse.x;
			POS_Y = _EV.mouse.y;
			R++, G++, B++;
		}
		else if (_EV.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (_EV.mouse.button & 2) {
				POS_X = 300, POS_Y = 300;
				R--, G--, B--;
			}else{
				POS_X = 0, POS_Y = 0;
				R--, G--, B--;
			}
		}
		al_draw_filled_rounded_rectangle(POS_X, POS_Y, POS_X + 30, POS_Y + 30, RADIUS_X, RADIUS_Y, al_map_rgb(R,G,B));
		al_flip_display();

	}



	//Ofcourse at the end Destroy/Uninstall Systems
	al_destroy_event_queue(_EVQUEUE);
	al_uninstall_mouse();
	al_uninstall_keyboard();
	al_destroy_display(_DISPLAY);

	return 0;
}
