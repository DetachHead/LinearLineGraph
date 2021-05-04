#include <stdio.h>
#include <math.h>

struct Line {
	// y = mx + c

	float m;
	float c;
};

void drawLineGraph(struct Line, int, int);
float getXUsingY(struct Line, int);
float getYUsingX(struct Line, int);

int main(void) {
	struct Line line;

	int xBorder = 0;
	int yBorder = 0;

	int goodInput = 0;

	do {
		printf("Enter graph x border: ");
		goodInput = scanf("%d", &xBorder);
		scanf("%*[^\n]");
	} while (xBorder <= 0 || !goodInput);

	goodInput = 0;

	do {
		printf("Enter graph y border: ");
		goodInput = scanf("%d", &yBorder);
		scanf("%*[^\n]");
	} while (yBorder <= 0 || !goodInput);

	goodInput = 0;

	printf("\nLine equation is y = mx+c ...\n");

	do {
		printf("Enter equation m: ");
		goodInput = scanf("%f", &line.m);
		scanf("%*[^\n]");
	} while (!goodInput);

	goodInput = 0;

	do {
		printf("Enter equation c: ");
		goodInput = scanf("%f", &line.c);
		scanf("%*[^\n]");
	} while (!goodInput);

	drawLineGraph(line, xBorder, yBorder);

	return 0;
}

void drawLineGraph(struct Line line, int xBorder, int yBorder) {
	const char VERTICAL_CHAR = 179;
	const char HORIZONTAL_CHAR = 196;
	const char LINE_CHAR = 219;

	printf("\n\n *** Graph of function: y = %.1fx%+ .1f *** \n\n", line.m, line.c);

	printf("\t");
	for (int x = (xBorder * -1) + 1; x < 0; x++) printf(" ");
	printf("%+2d\n\n", yBorder);
	for (int y = yBorder; y >= yBorder * -1; y--) {
		int lineX = (int)roundf(getXUsingY(line, y));
		for (int x = xBorder * -1; x <= xBorder; x++) {
			int lineY = (int)roundf(getYUsingX(line, x));
			// Print x number or border?
			if (x == xBorder * -1) {
				if (y == 0) printf("%d\t",xBorder * -1);
				else printf("\t");
			}

			// Draw part of the line?
			if (x == lineX) printf("%c", LINE_CHAR);
			else if (y == lineY) printf("%c", LINE_CHAR);

			// ... or draw a border or blank space?
			else if (x == 0 && y == 0) printf("0");
			else if (x == 0) printf("%c", VERTICAL_CHAR);
			else if (y == 0) printf("%c", HORIZONTAL_CHAR);
			else printf(" ");

			// Print x number?
			if (x == xBorder && y == 0) printf(" %+d", xBorder);
		}
		printf("\n");
	}
	printf("\n\t");
	for (int x = (xBorder * -1) + 1; x < 0; x++) printf(" ");
	printf("%2d", yBorder * -1);

	return;
}

float getXUsingY(struct Line line, int y) {
	return (y - line.c) / line.m;
}

float getYUsingX(struct Line line, int x) {
	return (line.m * x) + line.c;
}