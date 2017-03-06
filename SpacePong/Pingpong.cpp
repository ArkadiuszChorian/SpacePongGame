#include <allegro.h>
#include <winalleg.h>
#include <conio.h>
#include <cmath>

void init();
void deinit();

bool kolizja1(int xpal1, int ypal1, int spal1, int wpal1, int x1, int y1, int s1, int w1)
{
	if (x1 <= xpal1 + spal1 && x1 > xpal1 && y1 >= ypal1 && y1 <= ypal1 + wpal1) return true; else
		if (x1 <= xpal1 + spal1 && x1 > xpal1 && y1 + w1 >= ypal1 && y1 + w1 <= ypal1 + wpal1) return true; else
			if (x1 + s1 <= xpal1 + spal1 && x1 + s1 > xpal1 && y1 >= ypal1 && y1 <= ypal1 + wpal1) return true; else
				if (x1 + s1 <= xpal1 + spal1 && x1 + s1 > xpal1 && y1 + w1 >= ypal1 && y1 + w1 <= ypal1 + wpal1) return true;
	if (x1 <= xpal1 + spal1 && x1 > xpal1 && y1 + w1 >= ypal1 && y1 + w1 <= ypal1 + wpal1) return true;
	else return false;
};

bool kolizja2(int xpal2, int ypal2, int spal2, int wpal2, int x1, int y1, int s1, int w1)
{
	if (x1 <= xpal2 + spal2 && x1 > xpal2 && y1 >= ypal2 && y1 <= ypal2 + wpal2) return true; else
		if (x1 <= xpal2 + spal2 && x1 > xpal2 && y1 + w1 >= ypal2 && y1 + w1 <= ypal2 + wpal2) return true; else
			if (x1 + s1 <= xpal2 + spal2 && x1 + s1 > xpal2 && y1 >= ypal2 && y1 <= ypal2 + wpal2) return true; else
				if (x1 + s1 <= xpal2 + spal2 && x1 + s1 > xpal2 && y1 + w1 >= ypal2 && y1 + w1 <= ypal2 + wpal2) return true;
	if (x1 <= xpal2 + spal2 && x1 > xpal2 && y1 + w1 >= ypal2 && y1 + w1 <= ypal2 + wpal2) return true;
	else return false;
};

int main()
{
	init();
	BITMAP *bufor = NULL;
	BITMAP *tlo = NULL;
	BITMAP *tlo2 = NULL;
	BITMAP *paletka1 = NULL;
	BITMAP *paletka2 = NULL;
	BITMAP *pilka = NULL;
	BITMAP *blue = NULL;
	BITMAP *green = NULL;
	BITMAP *exit = NULL;
	SAMPLE *muzyka = NULL;
	SAMPLE *odbicie = NULL;

	muzyka = load_sample("muzyka.wav");

	if (!muzyka)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ dzwieku !");
		allegro_exit();
		return 0;
	}

	odbicie = load_sample("odbicie.wav");

	if (!odbicie)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ dzwieku !");
		allegro_exit();
		return 0;
	}


	bufor = create_bitmap(1024, 768);

	if (!bufor)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Nie mogê utworzyæ bufora !");
		allegro_exit();
		return 0;
	}

	blue = create_bitmap(1024, 768);

	if (!blue)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Nie mogê utworzyæ bufora !");
		allegro_exit();
		return 0;
	}

	green = create_bitmap(1024, 768);

	if (!green)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("Nie mogê utworzyæ bufora !");
		allegro_exit();
		return 0;
	}

	exit = create_bitmap(1024, 768);

	if (!exit)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	paletka1 = create_bitmap(1024, 768);

	if (!paletka1)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	paletka2 = create_bitmap(1024, 768);

	if (!paletka2)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	pilka = create_bitmap(1024, 768);

	if (!pilka)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	tlo2 = create_bitmap(1024, 768);

	if (!tlo2)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	BITMAP *menu = NULL;
	menu = create_bitmap(1024, 768);

	if (!menu)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	BITMAP *logo = NULL;
	logo = create_bitmap(1024, 768);

	if (!logo)
	{
		set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
		allegro_message("nie mogê za³adowaæ labiryntu !");
		allegro_exit();
		return 0;
	}

	BITMAP *scr = NULL;
	tlo = load_bmp("tlo.bmp", default_palette);
	paletka1 = load_bmp("paletka1.bmp", default_palette);
	paletka2 = load_bmp("paletka2.bmp", default_palette);
	pilka = load_bmp("pilka.bmp", default_palette);
	tlo2 = load_bmp("tlo2.bmp", default_palette);
	menu = load_bmp("menu.bmp", default_palette);
	logo = load_bmp("logo.bmp", default_palette);
	blue = load_bmp("blue.bmp", default_palette);
	green = load_bmp("green.bmp", default_palette);
	exit = load_bmp("exit.bmp", default_palette);

	int vol = 255;
	play_sample(muzyka, vol, 127, 1000, 1);
	blit(logo, screen, 0, 0, 0, 0, 1024, 768);
	Sleep(2000);

	while (!key[KEY_ESC])
	{
		blit(menu, bufor, 0, 0, 0, 0, 1024, 768);
		textprintf_ex(bufor, font, 170, 50, makecol(255, 255, 0), -1, "Wcisnij 1 aby wybrac", 5, -666);
		textprintf_ex(bufor, font, 670, 50, makecol(255, 255, 0), -1, "Wcisnij 2 aby wybrac", 5, -666);
		textprintf_ex(bufor, font, 100, 500, makecol(0, 0, 0), -1, "W trakcie gry mozesz zmieniac szybkosc poruszania sie paletek uzywajac klawiszy od 1 (wolno) do 5 (szybko)", 5, -666);
		textprintf_ex(bufor, font, 110, 510, makecol(0, 0, 0), -1, "Mozesz takze zmieniac szybkosc calej gry uzywajac klawiszy 'I' - szybko , 'O' - srednio , 'P' - wolno", 5, -666);
		//textprintf_ex( bufor, font, 200, 200, makecol( 69, 69, 69 ), - 1, "Wcisnij 1", 500,  666 );
		rectfill(bufor, 80, 110, 420, 390, makecol(0, 0, 80));
		stretch_blit(tlo, bufor, 0, 0, tlo->w, tlo->h, 100, 130, 300, 240);
		rectfill(bufor, 580, 110, 920, 390, makecol(0, 0, 80));
		stretch_blit(tlo2, bufor, 0, 0, tlo2->w, tlo2->h, 600, 130, 300, 240);
		blit(bufor, screen, 0, 0, 0, 0, 1024, 768);

		if (key[KEY_1])
		{
			scr = load_bmp("tlo.bmp", default_palette);
			break;
		}
		if (key[KEY_2])
		{
			scr = load_bmp("tlo2.bmp", default_palette);
			break;
		}
		if (key[KEY_ESC])
		{
			blit(exit, screen, 0, 0, 0, 0, 1024, 768);
			Sleep(2000);
			return 0;
		}
	}

	int x = 176, y = 163, dodx1 = 7, dody1 = 0, x1 = 300, y1 = 300, zycie1 = 5, zycie2 = 5, less = 1;
	int xpal1 = 0, xpal2 = 972, ypal1 = 293, ypal2 = 293;
	int colortest, pleft, pright, pup, pdown, pktx1 = 23, pkty1 = 373, pktx2 = 995, pkty2 = 373;
	int xc1, yc1, xc2, yc2, vpal = 5, time = 10, pilkaxr, pilkaxl, pilkayu, pilkayd;
	int r, g, b, paletka1xr, paletka1xl, paletka1yu, paletka1yd;
	int paletka2xr, paletka2xl, paletka2yu, paletka2yd;
	int spal1, wpal1, spal2, wpal2, s1, w1;
	tlo = load_bmp("tlo.bmp", default_palette);
	paletka1 = load_bmp("paletka1.bmp", default_palette);
	paletka2 = load_bmp("paletka2.bmp", default_palette);
	pilka = load_bmp("pilka.bmp", default_palette);
	tlo2 = load_bmp("tlo2.bmp", default_palette);
	float odl;
	bool stronau = false;
	bool stronad = false;
	int last = 0;

	while (!key[KEY_ESC])
	{
	restart:
		if (zycie1 == 0)
		{
			while (!key[KEY_ESC])
			{
				zycie1 = 5, zycie2 = 5;
				blit(green, bufor, 0, 0, 0, 0, 1024, 768);
				textprintf_ex(bufor, font, 250, 700, makecol(0, 0, 0), -1, "Aby zagrac ponownie wcisnij ENTER. Jesli chcesz zakonczyc wcisnij ESC", 0, -666);
				blit(bufor, screen, 0, 0, 0, 0, 1024, 768);
				if (key[KEY_ENTER])
					goto restart;
				if (key[KEY_ESC])
				{
					blit(exit, screen, 0, 0, 0, 0, 1024, 768);
					Sleep(2000);
					return 0;
				}
			}
		}

		if (zycie2 == 0)
		{
			while (!key[KEY_ESC])
			{
				zycie1 = 5, zycie2 = 5;
				blit(blue, bufor, 0, 0, 0, 0, 1024, 768);
				textprintf_ex(bufor, font, 250, 700, makecol(0, 0, 0), -1, "Aby zagrac ponownie wcisnij ENTER. Jesli chcesz zakonczyc wcisnij ESC", 0, -666);
				blit(bufor, screen, 0, 0, 0, 0, 1024, 768);
				if (key[KEY_ENTER])
					goto restart;
				if (key[KEY_ESC])
				{
					blit(exit, screen, 0, 0, 0, 0, 1024, 768);
					Sleep(2000);
					return 0;
				}
			}
		}

		xpal1 = 0, xpal2 = 972, ypal1 = 293, ypal2 = 293;
		pktx1 = 23, pkty1 = 373, pktx2 = 995, pkty2 = 373;

		if (last == 0)
		{
			x1 = 922, y1 = 359;
			dodx1 = -7, dody1 = 0;
		}
		if (last == 1)
		{
			x1 = 52, y1 = 359;
			dodx1 = 7, dody1 = 0;
		}

		blit(scr, bufor, 0, 0, 0, 0, 1024, 768);
		blit(paletka1, bufor, 0, 0, xpal1, ypal1, 1024, 768);
		blit(paletka2, bufor, 0, 0, xpal2, ypal2, 1024, 768);
		textprintf_ex(bufor, font, pktx1, pkty1, makecol(255, 255, 0), -1, "%d", zycie1, -666);
		textprintf_ex(bufor, font, pktx2, pkty2, makecol(255, 255, 0), -1, "%d", zycie2, -666);
		masked_stretch_blit(pilka, bufor, 0, 0, pilka->w, pilka->h, x1, y1, 50, 50);
		blit(bufor, screen, 0, 0, 0, 0, 1024, 768);

		if (key[KEY_ESC])
		{
			blit(exit, screen, 0, 0, 0, 0, 1024, 768);
			Sleep(2000);
			return 0;
		}
		if (key[KEY_DOWN] || key[KEY_UP] || key[KEY_LEFT] || key[KEY_RIGHT] || key[KEY_W] || key[KEY_D] || key[KEY_A] || key[KEY_S])
		{

			while (!key[KEY_ESC])
			{
				blit(scr, bufor, 0, 0, 0, 0, 1024, 768);
				blit(paletka1, bufor, 0, 0, xpal1, ypal1, 1024, 768);
				blit(paletka2, bufor, 0, 0, xpal2, ypal2, 1024, 768);
				//textout_ex(bufor,font,"%d",zycie1,pktx1,pkty1 ,makecol(255,255,0),-1);
				textprintf_ex(bufor, font, pktx1, pkty1, makecol(255, 255, 0), -1, "%d", zycie1, -666);
				textprintf_ex(bufor, font, pktx2, pkty2, makecol(255, 255, 0), -1, "%d", zycie2, -666);
				masked_stretch_blit(pilka, bufor, 0, 0, pilka->w, pilka->h, x1, y1, 50, 50);
				//circlefill(bufor, x1, y1 ,10, makecol(0,0,150)); 
				Sleep(time);
				//blit( bufor, screen, 0,0,0,0, 640,480);
				x1 = x1 + dodx1;
				y1 = y1 + dody1;
				if (x1 <= 0)
				{
					zycie1 = zycie1 - less;
					last = 0;
					goto restart;
				}
				if (x1 >= 974)
				{
					zycie2 = zycie2 - less;
					last = 1;
					goto restart;
				}

				if (y1 <= 0)
					dody1 = -dody1;
				if (y1 >= 718)
					dody1 = -dody1;

				blit(bufor, screen, 0, 0, 0, 0, 1024, 768);
				if (key[KEY_ESC])
				{
					blit(exit, screen, 0, 0, 0, 0, 1024, 768);
					Sleep(2000);
					return 0;
				}



				spal1 = 52, spal2 = 52;
				wpal1 = 182, wpal2 = 182;
				s1 = 50;
				w1 = 50;
				int srodekpilki = 25, srodekpaletki = 91;
				int srpilkitest = y1 + srodekpilki;
				int srpilkitest2 = x1 + srodekpilki;
				int strefa1 = 15, strefa2 = 37, strefa3 = 47, strefa4 = 65, strefa5 = 117, strefa6 = 135, strefa7 = 145, strefa8 = 167, strefa9 = 182;
				int strefab1 = 26, strefab2 = 52;

				if (kolizja1(xpal1, ypal1, spal1, wpal1, x1, y1, s1, w1) == true)
				{
					play_sample(odbicie, vol, 127, 1000, 0);

					if ((srpilkitest >= ypal1) && (srpilkitest < ypal1 + strefa1))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest >= ypal1 + strefa1) && (srpilkitest < ypal1 + strefa2))
					{
						dodx1 = 7;
						dody1 = -2;
					}
					if ((srpilkitest >= ypal1 + strefa2) && (srpilkitest < ypal1 + strefa3))
					{
						dodx1 = 7;
						dody1 = 0;
					}
					if ((srpilkitest >= ypal1 + strefa3) && (srpilkitest < ypal1 + strefa4))
					{
						dodx1 = 7;
						dody1 = 2;
					}
					if ((srpilkitest >= ypal1 + strefa4) && (srpilkitest < ypal1 + strefa5))
					{
						dodx1 = 5;
						dody1 = 5;
					}
					if ((srpilkitest >= ypal1 + strefa5) && (srpilkitest < ypal1 + strefa6))
					{
						dodx1 = 7;
						dody1 = 2;
					}
					if ((srpilkitest >= ypal1 + strefa6) && (srpilkitest < ypal1 + strefa7))
					{
						dodx1 = 7;
						dody1 = 0;
					}
					if ((srpilkitest >= ypal1 + strefa7) && (srpilkitest < ypal1 + strefa8))
					{
						dodx1 = 7;
						dody1 = -2;
					}
					if ((srpilkitest >= ypal1 + strefa8) && (srpilkitest < ypal1 + strefa9))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest2 >= xpal1 + strefab1) && (srpilkitest2 < xpal1 + strefab2) && (y1 + w1 == ypal1))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest2 >= xpal1) && (srpilkitest2 < xpal1 + strefab1) && (y1 + w1 == ypal1))
					{
						dodx1 = dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest2 >= xpal1) && (srpilkitest2 < xpal1 + strefab1) && (y1 == ypal1 + wpal1))
					{
						dodx1 = dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest2 >= xpal1 + strefab1) && (srpilkitest2 < xpal1 + strefab2) && (y1 == ypal1 + wpal1))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
				}

				if (kolizja2(xpal2, ypal2, spal2, wpal2, x1, y1, s1, w1) == true)
				{
					play_sample(odbicie, vol, 127, 1000, 0);

					if ((srpilkitest >= ypal2) && (srpilkitest < ypal2 + strefa1))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
					if ((srpilkitest >= ypal2 + strefa1) && (srpilkitest < ypal2 + strefa2))
					{
						dodx1 = -7;
						dody1 = 2;
					}
					if ((srpilkitest >= ypal2 + strefa2) && (srpilkitest < ypal2 + strefa3))
					{
						dodx1 = -7;
						dody1 = 0;
					}
					if ((srpilkitest >= ypal2 + strefa3) && (srpilkitest < ypal2 + strefa4))
					{
						dodx1 = -7;
						dody1 = -2;
					}
					if ((srpilkitest >= ypal2 + strefa4) && (srpilkitest < ypal2 + strefa5))
					{
						dodx1 = -5;
						dody1 = -5;
					}
					if ((srpilkitest >= ypal2 + strefa5) && (srpilkitest < ypal2 + strefa6))
					{
						dodx1 = -7;
						dody1 = -2;
					}
					if ((srpilkitest >= ypal2 + strefa6) && (srpilkitest < ypal2 + strefa7))
					{
						dodx1 = -7;
						dody1 = 0;
					}
					if ((srpilkitest >= ypal2 + strefa7) && (srpilkitest < ypal2 + strefa8))
					{
						dodx1 = -7;
						dody1 = 2;
					}
					if ((srpilkitest >= ypal2 + strefa8) && (srpilkitest < ypal2 + strefa9))
					{
						dodx1 = -dodx1;
						dody1 = -dody1;
					}
				}

				if (key[KEY_I])
					time = 5;

				if (key[KEY_O])
					time = 10;

				if (key[KEY_P])
					time = 20;

				//PREDKOSC GRY

				if (key[KEY_1])
					vpal = 3;

				if (key[KEY_2])
					vpal = 5;

				if (key[KEY_3])
					vpal = 7;

				if (key[KEY_4])
					vpal = 9;

				if (key[KEY_5])
					vpal = 11;

				//PREDKOSC PALETEK

				if (key[KEY_J])
				{
					dodx1 = 2;
					dody1 = 2;
				}

				if (key[KEY_K])
				{
					dodx1 = 5;
					dody1 = 5;
				}

				if (key[KEY_L])
				{
					dodx1 = 10;
					dody1 = 10;
				}

				//PREDKOSC PILKI

				if (ypal1 >= 588)
				{
					pkty1 = pkty1 - vpal;
					ypal1 = ypal1 - vpal;
				}
				if (ypal1 <= -2)
				{
					pkty1 = pkty1 + vpal;
					ypal1 = ypal1 + vpal;
				}

				if (ypal2 >= 588)
				{
					pkty2 = pkty2 - vpal;
					ypal2 = ypal2 - vpal;
				}
				if (ypal2 <= -2)
				{
					pkty2 = pkty2 + vpal;
					ypal2 = ypal2 + vpal;
				}

				if (xpal1 >= 312)
				{
					pktx1 = pktx1 - vpal;
					xpal1 = xpal1 - vpal;
				}
				if (xpal1 <= 0)
				{
					pktx1 = pktx1 + vpal;
					xpal1 = xpal1 + vpal;
				}

				if (xpal2 <= 640)
				{
					pktx2 = pktx2 + vpal;
					xpal2 = xpal2 + vpal;
				}
				if (xpal2 >= 972)
				{
					pktx2 = pktx2 - vpal;
					xpal2 = xpal2 - vpal;
				}

				//GRANICE

				if (key[KEY_A])
				{
					xpal1 = xpal1 - vpal;
					pktx1 = pktx1 - vpal;
				}
				if (key[KEY_D])
				{
					xpal1 = xpal1 + vpal;
					pktx1 = pktx1 + vpal;
				}
				if (key[KEY_W])
				{
					ypal1 = ypal1 - vpal;
					pkty1 = pkty1 - vpal;
				}
				if (key[KEY_S])
				{
					ypal1 = ypal1 + vpal;
					pkty1 = pkty1 + vpal;
				}

				if (key[KEY_LEFT])
				{
					pktx2 = pktx2 - vpal;
					xpal2 = xpal2 - vpal;
				}
				if (key[KEY_RIGHT])
				{
					pktx2 = pktx2 + vpal;
					xpal2 = xpal2 + vpal;
				}
				if (key[KEY_UP])
				{
					pkty2 = pkty2 - vpal;
					ypal2 = ypal2 - vpal;
				}
				if (key[KEY_DOWN])
				{
					pkty2 = pkty2 + vpal;
					ypal2 = ypal2 + vpal;
				}

			}
		}
	}


	deinit();
	return 0;
}

END_OF_MAIN()

void init() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1024, 768, 0, 0);

	if (res != 0) 
	{
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "");
	set_volume(255, 255);
}

void deinit() 
{
	clear_keybuf();
}
