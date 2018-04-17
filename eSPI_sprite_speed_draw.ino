#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(240,320);

TFT_eSprite screen = TFT_eSprite(&tft); // Sprite object graph1
TFT_eSprite screenClear = TFT_eSprite(&tft); // Sprite object stext1

void setup()
{
	tft.init();
	tft.fillScreen(TFT_BLACK);

	// Create a sprite for the graph
	screen.setColorDepth(8);
	screen.createSprite(240, 320);
	screen.fillSprite(TFT_BLACK);

	screenClear.setColorDepth(8);
	screenClear.createSprite(240, 320);
	screenClear.fillSprite(TFT_BLACK);
}

/* The state word must be initialized to non-zero */
uint32_t rnd(uint32_t state)
{
	/* Algorithm "xor" from p. 4 of Marsaglia, "Xorshift RNGs" */
	uint32_t x = state;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	state = x;
	return x;
}

int counter;
void loop()
{
	screen = screenClear;

	for (int i = 0; i < 1000; i++)
		screen.drawLine(100+100*cos(i), 100+100*sin(2*i), 100+100*cos(2*i), 100+100*sin(3*i), counter);

	counter+=101;
	//counter %= 509;
	screen.pushSprite(0, 0);
}
