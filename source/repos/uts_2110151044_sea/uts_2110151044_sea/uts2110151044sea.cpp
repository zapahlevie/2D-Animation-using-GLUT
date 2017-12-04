#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>
#include <math.h>


typedef struct {
	float x, y;
} point2D_t;

typedef struct {
	float r, g, b;
} color_t;

typedef struct
{
	float r, g, b;
}color;

typedef struct {
	point2D_t p, p0;
	float d, s;
} obyek_t;
//
typedef struct
{
	float v[3];
}vector2D_t;

typedef struct
{
	float matrix[3][3];
}matrix2D_t;

void setColor(color col)
{
	glColor3f(col.r, col.g, col.b);
}

void setColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}

void drawPolyline(point2D_t pnt[], int n)
{
	int i;
	glBegin(GL_LINE_STRIP);
	for (i = 0; i<n; i++)
	{
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}


void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void drawPolygon(point2D_t pnt[], int n)
{
	int i;
	glBegin(GL_LINE_LOOP);
	for (i = 0; i<n; i++)
		glVertex2f(pnt[i].x, pnt[i].y);
	glEnd();
}


void fillPolygon(point2D_t pnt[], int n, color_t color)
{
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i<n; i++)
	{
		setColor(color.r, color.g, color.b);
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}


void gradatePolygon(point2D_t line[], int n, color col[])
{
	glBegin(GL_POLYGON);
	for (int i = 0; i<n; i++)
	{
		setColor(col[i]);
		glVertex2f(line[i].x, line[i].y);
	}
	glEnd();
}

point2D_t interpolasi(point2D_t a, point2D_t b, float m)
{
	point2D_t c;
	c.x = m*a.x + (1. - m)*b.x;
	c.y = m*a.y + (1. - m)*b.y;
	return c;
}

void moveX(point2D_t p[], int index, float m) {
	for (int i = 0; i < index; i++) {
		p[i].x += m;
	}
}

void moveY(point2D_t p[], int index, float m) {
	for (int i = 0; i < index; i++) {
		p[i].y += m;
	}
}

void scale(point2D_t p[], int index, float m) {
	for (int i = 0; i < index; i++) {
		p[i].x *= m;
		p[i].y *= m;
	}
}

void drawCircle(int jari2, int jumlah_titik, int x_tengah, int y_tengah, color_t color) {
	glBegin(GL_POLYGON);
	glColor3f(color.r, color.g, color.b);
	for (int i = 0; i <= 360; i++) {
		float sudut = i*(6.28 / jumlah_titik);
		float x = x_tengah + jari2*cos(sudut);
		float y = y_tengah + jari2*sin(sudut);
		glVertex2f(x, y);
	}
	glEnd();
}

void drawLangit() {
	point2D_t langit[4] = { { -500,50 },{ 800,50 },{ 800,300 },{ -500,300 } };
	color AREA[4] = { { 0.8, 0.9, 1 },{ 0.8, 0.9, 1 },{ 0, 0.73, 0.91 },{ 0, 0.73, 0.91 } };
	gradatePolygon(langit, 4, AREA);
}

void drawLaut() {
	point2D_t laut[4] = { { -500,50 },{ 800,50 },{ 800,-400 },{ -500,-400 } };
	color AREA[4] = { { 0,0.55,0.72 },{ 0,0.55,0.72 },{ 0.46,0.84,0.91 },{ 0.46,0.84,0.91 } };
	gradatePolygon(laut, 4, AREA);
}

void drawAwanDiam() {
	color_t abu = { 0.9, 0.9, 1 };
	drawCircle(20, 200, 140, 218, abu);
	drawCircle(25, 200, 182, 234, abu);
	drawCircle(19, 200, 220, 220, abu);
	drawCircle(20, 200, 182, 209, abu);
	drawCircle(15, 200, 160, 233, abu);
	drawCircle(13, 200, 155, 209, abu);
	drawCircle(14, 200, 207, 228, abu);
	drawCircle(14, 200, 207, 209, abu);

	drawCircle(20, 200, 170, 268, abu);
	drawCircle(25, 200, 212, 284, abu);
	drawCircle(19, 200, 250, 270, abu);
	drawCircle(20, 200, 212, 259, abu);
	drawCircle(15, 200, 190, 283, abu);
	drawCircle(13, 200, 185, 259, abu);
	drawCircle(14, 200, 237, 278, abu);
	drawCircle(14, 200, 237, 259, abu);

	drawCircle(20, 200, 470, 268, abu);
	drawCircle(25, 200, 512, 284, abu);
	drawCircle(19, 200, 550, 270, abu);
	drawCircle(20, 200, 512, 259, abu);
	drawCircle(15, 200, 490, 283, abu);
	drawCircle(13, 200, 485, 259, abu);
	drawCircle(14, 200, 537, 278, abu);
	drawCircle(14, 200, 537, 259, abu);

	drawCircle(-20, 200, -140, 218, abu);
	drawCircle(-25, 200, -182, 234, abu);
	drawCircle(-19, 200, -220, 220, abu);
	drawCircle(-20, 200, -182, 209, abu);
	drawCircle(-15, 200, -160, 233, abu);
	drawCircle(-13, 200, -155, 209, abu);
	drawCircle(-14, 200, -207, 228, abu);
	drawCircle(-14, 200, -207, 209, abu);

	drawCircle(-20, 200, -10, 368, abu);
	drawCircle(-25, 200, 2, 384, abu);
	drawCircle(-19, 200, -40, 370, abu);
	drawCircle(-20, 200, -2, 359, abu);
	drawCircle(-15, 200, 20, 383, abu);
	drawCircle(-13, 200, 25, 359, abu);
	drawCircle(-14, 200, -27, 378, abu);
	drawCircle(-14, 200, -27, 359, abu);

	drawCircle(-20, 200, 70, 408, abu);
	drawCircle(-25, 200, 28, 424, abu);
	drawCircle(-19, 200, -10, 410, abu);
	drawCircle(-20, 200, 28, 399, abu);
	drawCircle(-15, 200, 50, 423, abu);
	drawCircle(-13, 200, 55, 399, abu);
	drawCircle(-14, 200, 3, 418, abu);
	drawCircle(-14, 200, 3, 399, abu);

	drawCircle(-20, 200, 120, 388, abu);
	drawCircle(-25, 200, 78, 404, abu);
	drawCircle(-19, 200, 40, 390, abu);
	drawCircle(-20, 200, 78, 379, abu);
	drawCircle(-15, 200, 100, 403, abu);
	drawCircle(-13, 200, 105, 379, abu);
	drawCircle(-14, 200, 53, 398, abu);
	drawCircle(-14, 200, 53, 379, abu);

	drawCircle(-20, 200, -240, 518, abu);
	drawCircle(-25, 200, -282, 534, abu);
	drawCircle(-19, 200, -320, 520, abu);
	drawCircle(-20, 200, -282, 509, abu);
	drawCircle(-15, 200, -260, 533, abu);
	drawCircle(-13, 200, -255, 509, abu);
	drawCircle(-14, 200, -307, 528, abu);
	drawCircle(-14, 200, -307, 509, abu);

	drawCircle(-20, 200, 240, 518, abu);
	drawCircle(-25, 200, 282, 534, abu);
	drawCircle(-19, 200, 320, 520, abu);
	drawCircle(-20, 200, 282, 509, abu);
	drawCircle(-15, 200, 260, 533, abu);
	drawCircle(-13, 200, 255, 509, abu);
	drawCircle(-14, 200, 307, 528, abu);
	drawCircle(-14, 200, 307, 509, abu);

	drawCircle(-20, 200, 350, 518, abu);
	drawCircle(-25, 200, 282, 534, abu);
	drawCircle(-19, 200, 320, 520, abu);
	drawCircle(-20, 200, 282, 509, abu);
	drawCircle(-15, 200, 260, 533, abu);
	drawCircle(-13, 200, 255, 509, abu);
	drawCircle(-14, 200, 307, 528, abu);
	drawCircle(-14, 200, 307, 509, abu);
}

void createAwan(int tick) {
	color_t gray = { 1, 1, 1 }; color_t;

	drawCircle(20, 350, 140 + tick, 368, gray);	drawCircle(25, 350, 182 + tick, 384, gray);
	drawCircle(19, 350, 220 + tick, 370, gray); drawCircle(20, 350, 182 + tick, 359, gray);
	drawCircle(15, 350, 160 + tick, 383, gray);	drawCircle(13, 350, 155 + tick, 359, gray);
	drawCircle(14, 350, 207 + tick, 378, gray);	drawCircle(14, 350, 207 + tick, 359, gray);

	drawCircle(-20, 350, -140 + tick, 368, gray);	drawCircle(-25, 350, -182 + tick, 384, gray);
	drawCircle(-19, 350, -220 + tick, 370, gray);	drawCircle(-20, 350, -182 + tick, 359, gray);
	drawCircle(-15, 350, -160 + tick, 383, gray);	drawCircle(-13, 350, -155 + tick, 359, gray);
	drawCircle(-14, 350, -207 + tick, 378, gray);	drawCircle(-14, 350, -207 + tick, 359, gray);

	drawCircle(10, 380, -110 + tick, 398, gray);	drawCircle(15, 380, -152 + tick, 414, gray);
	drawCircle(29, 380, -190 + tick, 400, gray);	drawCircle(10, 380, -152 + tick, 389, gray);
	drawCircle(25, 380, -130 + tick, 413, gray);	drawCircle(23, 380, -125 + tick, 389, gray);
	drawCircle(24, 380, -177 + tick, 408, gray);	drawCircle(24, 380, -177 + tick, 389, gray);

	drawCircle(-20, 350, -490 + tick, 368, gray);	drawCircle(-25, 350, -532 + tick, 384, gray);
	drawCircle(-19, 350, -570 + tick, 370, gray);	drawCircle(-20, 350, -532 + tick, 359, gray);
	drawCircle(-15, 350, -510 + tick, 383, gray);	drawCircle(-13, 350, -505 + tick, 359, gray);
	drawCircle(-14, 350, -557 + tick, 378, gray);	drawCircle(-14, 350, -557 + tick, 359, gray);

	drawCircle(-20, 350, -440 + tick, 368, gray);	drawCircle(-25, 350, -482 + tick, 384, gray);
	drawCircle(-19, 350, -520 + tick, 370, gray);	drawCircle(-20, 350, -482 + tick, 359, gray);
	drawCircle(-15, 350, -460 + tick, 383, gray);	drawCircle(-13, 350, -455 + tick, 359, gray);
	drawCircle(-14, 350, -507 + tick, 378, gray);	drawCircle(-14, 350, -507 + tick, 359, gray);

	drawCircle(-20, 350, -465 + tick, 388, gray);	drawCircle(-25, 350, -507 + tick, 404, gray);
	drawCircle(-19, 350, -545 + tick, 390, gray);	drawCircle(-20, 350, -507 + tick, 379, gray);
	drawCircle(-15, 350, -485 + tick, 403, gray);	drawCircle(-13, 350, -480 + tick, 379, gray);
	drawCircle(-14, 350, -532 + tick, 398, gray);	drawCircle(-14, 350, -532 + tick, 379, gray);
}

void drawAwanGerak() {
	static float tick = 0;
	tick = tick + 0.04;
	if (tick>1300) {
		tick = -700;
	}
	createAwan(tick);
}

void createBurung(float tick) {
	float start = 0;
	point2D_t burung[16] = {
		{ 220 , 346 },{ 216 , 351 },{ 215 , 361 },{ 218 , 355 },
		{ 224 , 347 },{ 227 , 349 },{ 229 , 347 },{ 225 , 346 },
		{ 231 , 342 },{ 237 , 339 },{ 229 , 340 },{ 221 , 345 },
		{ 218 , 343 },{ 215 , 343 },{ 217 , 345 },{ 220 , 346 }
	};
	color_t	wburung = { 0, 0, 0 };
	moveX(burung, 16, tick);
	fillPolygon(burung, 16, wburung);

	point2D_t burung2[16] = {
		{ 190 , 346 },{ 186 , 351 },{ 185 , 361 },{ 188 , 355 },
		{ 194 , 347 },{ 197 , 349 },{ 199 , 347 },{ 195 , 346 },
		{ 201 , 342 },{ 207 , 339 },{ 199 , 340 },{ 191 , 345 },
		{ 188 , 343 },{ 185 , 343 },{ 187 , 345 },{ 190 , 346 }
	};
	color_t	wburung2 = { 0, 0, 0 };
	moveX(burung2, 16, tick);
	fillPolygon(burung2, 16, wburung2);

	point2D_t burung3[16] = {
		{ 90 , 246 },{ 86 , 251 },{ 85 , 261 },{ 88 , 255 },
		{ 94 , 247 },{ 97 , 249 },{ 99 , 247 },{ 95 , 246 },
		{ 101 , 242 },{ 107 , 239 },{ 99 , 240 },{ 91 , 245 },
		{ 88 , 243 },{ 85 , 243 },{ 87 , 245 },{ 90 , 246 }
	};
	color_t	wburung3 = { 0, 0, 0 };
	moveX(burung3, 16, tick);
	fillPolygon(burung3, 16, wburung3);

	point2D_t burung4[16] = {
		{ 20 , 346 },{ 16 , 351 },{ 15 , 361 },{ 18 , 355 },
		{ 24 , 347 },{ 27 , 349 },{ 29 , 347 },{ 25 , 346 },
		{ 31 , 342 },{ 37 , 339 },{ 29 , 340 },{ 21 , 345 },
		{ 18 , 343 },{ 15 , 343 },{ 17 , 345 },{ 20 , 346 }
	};
	color_t	wburung4 = { 0, 0, 0 };
	moveX(burung4, 16, tick);
	fillPolygon(burung4, 16, wburung4);

	point2D_t burung5[16] = {
		{ -10 , 346 },{ -14 , 351 },{ -15 , 361 },{ -12 , 355 },
		{ -6 , 347 },{ -3 , 349 },{ -1 , 347 },{ -5 , 346 },
		{ 1 , 342 },{ 7 , 339 },{ -1 , 340 },{ -9 , 345 },
		{ -12 , 343 },{ -15 , 343 },{ -13 , 345 },{ -10 , 346 }
	};
	color_t	wburung5 = { 0, 0, 0 };
	moveX(burung5, 16, tick);
	fillPolygon(burung5, 16, wburung5);
}

void drawBurung() {
	static float tick = 0;
	tick = tick + 0.2;
	if (tick>720) {
		tick = -620;
	}
	createBurung(tick);
}

void createKapal(int tick, float m, float x, float y) {
	//badan
	point2D_t badan[4] = { { -250,-55 },{ -230,-40 },{ -310,-40 },{ -290, -55 } };
	color AREA[4] = { { 0.7,0.5,0.1 },{ 0.7,0.5,0.1 },{ 0.5,0.2,0 },{ 0.5,0.2,0 } };
	scale(badan, 4, m);
	moveX(badan, 4, x); //mengubah starting point
	moveY(badan, 4, y); //mengubah starting point
	moveX(badan, 4, tick);
	gradatePolygon(badan, 4, AREA);

	//badan kanan
	point2D_t badankanan[4] = { { -250, -55 },{ -220, -30 },{ -210, -30 },{ -241,-55 } };
	color AREA2[4] = { { 0.7,0.5,0.1 },{ 0.7,0.5,0.1 },{ 0.7,0.5,0.1 },{ 0.7,0.5,0.1 } };
	scale(badankanan, 4, m);
	moveX(badankanan, 4, x); //mengubah starting point
	moveY(badankanan, 4, y); //mengubah starting point
	moveX(badankanan, 4, tick);
	gradatePolygon(badankanan, 4, AREA2);


	//bdan kiri
	point2D_t badankiri[4] = { { -290,-55 },{ -320,-30 },{ -330,-30 },{ -300,-55 } };
	color AREA3[4] = { { 0.5,0.2,0 },{ 0.5,0.2,0 },{ 0.5,0.2,0 },{ 0.5,0.2,0 } };
	scale(badankiri, 4, m);
	moveX(badankiri, 4, x); //mengubah starting point
	moveY(badankiri, 4, y); //mengubah starting point
	moveX(badankiri, 4, tick);
	gradatePolygon(badankiri, 4, AREA3);

	//tepi atas badan
	point2D_t badantepi[4] = { { -230,-40 },{ -310,-40 },{ -315,-35 },{ -225,-35 } };
	color AREA5[4] = { { 0.5,0.2,0 },{ 0.5,0.2,0 },{ 0.5,0.2,0 },{ 0.5,0.2,0 } };
	scale(badantepi, 4, m);
	moveX(badantepi, 4, x); //mengubah starting point
	moveY(badantepi, 4, y); //mengubah starting point
	moveX(badantepi, 4, tick);
	gradatePolygon(badantepi, 4, AREA5);

	//layar
	point2D_t layar[4] = { { -222,-20 },{ -271,92 },{ -324,-5 },{ -270,-25 } };
	color AREA6[4] = { { 0.5,0.5,0.5 },{ 1,1,1 },{ 0.5,0.5,0.5 },{ 0.2,0,0 } };
	scale(layar, 4, m);
	moveX(layar, 4, x); //mengubah starting point
	moveY(layar, 4, y); //mengubah starting point
	moveX(layar, 4, tick);
	gradatePolygon(layar, 4, AREA6);

	//tiang
	point2D_t tiang[4] = { { -270,105 },{ -273,105 },{ -273,-35 },{ -270,-35 } };
	color AREA8[5] = { { 0.7,0.5,0.1 },{ 0.5,0.2,0 },{ 0.5,0.2,0 },{ 1,0.9,0.5 },{ 1,0.9,0.5 } };
	scale(tiang, 4, m);
	moveX(tiang, 4, x); //mengubah starting point
	moveY(tiang, 4, y); //mengubah starting point
	moveX(tiang, 4, tick);
	gradatePolygon(tiang, 4, AREA8);

	//bendera
	static float ticks = 0;
	float rtick = ((int)ticks % 100) / 80.;
	point2D_t bendera[3] = { { -270,92 },{ -270,105 },{ -300,100 } };
	point2D_t benderalipat[3] = { { -270,92 },{ -270,105 },{ -290,100 } };
	color AREA7[4] = { { 0,0,0 },{ 1,0,0 },{ 1,0,0 },{ 1,0,0 } };
	point2D_t shape[40];
	for (int i = 0; i<3; i++) {
		shape[i] = interpolasi(bendera[i], benderalipat[i], rtick);
	}
	scale(shape, 3, m);
	moveX(shape, 3, x); //mengubah starting point
	moveY(shape, 3, y); //mengubah starting point
	moveX(shape, 3, tick);
	gradatePolygon(shape, 3, AREA7);
	ticks += 0.1;
}

void drawKapal() {
	static float tick = 0;
	tick = tick + 0.1;
	if (tick>900) {
		tick = -400;
	}
	createKapal(tick, 0.5, 0, 50);
}

void drawKapal2() {
	static float tick = 0;
	tick = tick + 0.2;
	if (tick>1500) {
		tick = 150;
	}
	createKapal(tick, 1, -500, -40);
}

void drawKapal3() {
	static float tick = 0;
	tick = tick + 0.3;
	if (tick>1400) {
		tick = -280;
	}
	createKapal(tick, 1.8, -100, -250);
}

void createHiu(int tick, float m, float x, float y) {
	point2D_t siripatas[3] = { { -285,-97 },{ -290,-73 },{ -267,-97 } };
	point2D_t siripbawah[4] = { { -288,-112 },{ -285,-97 },{ -267,-97 },{ -258,-112 } };
	scale(siripatas, 3, m);
	scale(siripbawah, 4, m);
	moveX(siripatas, 3, x);
	moveY(siripatas, 3, y);
	moveX(siripbawah, 4, x);
	moveY(siripbawah, 4, y);
	moveX(siripatas, 3, tick);
	moveX(siripbawah, 4, tick);
	fillPolygon(siripatas, 3, { 0.1f, 0.1f, 0.1f });
	fillPolygon(siripbawah, 4, { 0.1f, 0.1f, 0.1f });
}

void drawHiu() {
	static float tick = 0;
	tick = tick + 0.24;
	if (tick>900) {
		tick = -240;
	}
	createHiu(tick, 0.8, 0, 0);
}

void drawHiu2() {
	static float tick = 0;
	tick = tick + 0.4;
	if (tick>1700) {
		tick = 400;
	}
	createHiu(tick, 2.2, -400, -120);
}

void userdraw()
{
	drawLangit();
	drawLaut();
	drawAwanDiam();
	drawAwanGerak();
	drawBurung();
	drawKapal();
	drawHiu();
	drawKapal2();
	drawKapal3();
	drawHiu2();
}

int End();

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	glutSwapBuffers();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 500);
	glutCreateWindow("UTS Grafika - 2110151044 - Sea");
	glClearColor(0, 0.73, 0.91, 0.0);
	gluOrtho2D(-450., 600., -405., 540.);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}