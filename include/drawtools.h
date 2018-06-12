/* drawtools.h --- 
 * 
 * Filename: drawtools.h
 * Description: 
 * Author: Karthik Kumar
 * Maintainer: 
 * Created: Wed Jun 13 03:21:41 2018 (+0530)
 * Version: 
 * Package-Requires: ()
 * Last-Updated: Wed Jun 13 03:21:58 2018 (+0530)
 *           By: Karthik Kumar
 *     Update #: 1
 * URL: 
 * Doc URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change Log:
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.
 */

/* Code: */


/* Header Files */
#include <stdio.h>
#include <cairo/cairo.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/* Macros */
#define DENOMINATOR 10
#define ARROW_HAND 100
#define JOIN_MITER CAIRO_LINE_JOIN_MITER
#define JOIN_BEVEL CAIRO_LINE_JOIN_BEVEL
#define JOIN_ROUND CAIRO_LINE_JOIN_ROUND


/* Global Variables */
typedef enum Colors {BLACK, WHITE, RED, GREEN, BLUE, YELLOW} colors;
typedef float opacity;
int width = 1920;
int height = 1080;
static int count = 0;
double increment = 0.15;
cairo_t *cr;
cairo_surface_t *surface;
char num[10];
char ext[10] = ".png";


struct Point {
    double x;
	double y;
};


/* Line Variables */
bool right_to_left = false;
bool left_to_right = false;
bool up_to_down = false;
bool down_to_up = false;
bool no_line = false;
bool vertical_line = false;
bool horizontal_line = false;



/* Function Prototypes */
void initialize_with_image_surface(int width, int height);
void select_color(cairo_t *cr, colors color);
void create_background(cairo_t *cr, colors color);
void save_image(cairo_surface_t *surface, char* filename);
void clear_memory();
char* itoa(int, char*, int);
void draw_circle(cairo_t *cr, double xc, double yc, double radius,
				 double angle1, double angle2, double line_width,
				 colors color, bool fill, bool stroke);

void draw_circle_animation(cairo_t *cr, double xc, double yc,
						   double radius, double angle1,
						   double angle2, double line_width,
						   colors color, bool fill, bool stroke);

void draw_inv_circle_animation(cairo_t *cr, double xc, double yc,
							   double radius, double angle1,
							   double angle2, double line_width,
							   colors color, bool fill, bool stroke);

void draw_line(cairo_t *cr, double x0, double y0,
			   double x1, double y1, double line_width, colors color);


void draw_line_animation(cairo_t *cr, double x0, double y0,
						 double x1, double y1, double line_width, colors color);

void line_handle_rl_ud(cairo_t *cr, double x0,
					   double y0, double x1,
					   double y1);

void line_handle_rl_du(cairo_t *cr, double x0,
					   double y0, double x1,
					   double y1);

void line_handle_lr_ud(cairo_t *cr, double x0,
					   double y0, double x1,
					   double y1);

void line_handle_lr_du(cairo_t *cr, double x0,
					   double y0, double x1,
					   double y1);
void draw_arrow(cairo_t* cr, struct Point p1, struct Point p2,
				double scale, double line_width, colors color,
				cairo_line_join_t line_join_type);


char *itoa (int value, char *result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}


void initialize_with_image_surface(int width, int height) {
	surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	cr = cairo_create(surface);
}


void select_color(cairo_t *cr, colors color) {
	switch (color) {
	case BLACK: {
		printf("Black: %d\n", BLACK);
		cairo_set_source_rgb(cr, 0.0, 0.0, 0.0); 
		break;
	}

	case WHITE: {
		printf("WHITE: %d\n", WHITE);
		cairo_set_source_rgb(cr, 255.0, 255.0, 255.0);
		break;
	}

	case RED: {
		printf("RED: %d\n", RED);
		cairo_set_source_rgb(cr, 255.0, 0.0, 0.0);
		break;
	}

	case BLUE: {
		printf("BLUE: %d\n", BLUE);
		cairo_set_source_rgb(cr, 0.0, 0.0, 255.0);
		break;
	}

	case GREEN: {
		printf("GREEN: %d\n", GREEN);
		cairo_set_source_rgb(cr, 0.0, 128.0, 0.0);
		break;
	}
	case YELLOW: {
		printf("YELLOW: %d\n", YELLOW);
		cairo_set_source_rgb(cr, 255.0, 255.0, 0.0);
		break;
	}
		
	default: {
		printf("NOT A VALID COLOR\n");
		exit(EXIT_FAILURE);
		break;
	}
	}
}


void create_background(cairo_t *cr, colors color) {
	select_color(cr, color);
	cairo_rectangle(cr, 0, 0, width, height);
	cairo_fill(cr);
}


void draw_circle(cairo_t *cr, double xc, double yc, double radius,
				 double angle1, double angle2, double line_width,
				 colors color, bool fill, bool stroke) {
	select_color(cr, color);
	angle1 = angle1 * (M_PI / 180.0);  /* in radians */
	angle2 = angle2 * (M_PI / 180.0);  /* in radians */
	cairo_set_line_width(cr, line_width);
	cairo_arc(cr, xc, yc, radius, angle1, angle2);

	if (fill) {
		cairo_fill(cr);
		printf("Filling\n");
	}

	if (stroke) {
		cairo_stroke(cr);
		printf("Stroking\n");
		
	}

}

void draw_circle_animation(cairo_t *cr, double xc, double yc,
						   double radius, double angle1,
						   double angle2, double line_width,
						   colors color, bool fill, bool stroke) {
	select_color(cr, color);
	angle1 = angle1 * (M_PI / 180.0);  /* in radians */
	angle2 = angle2 * (M_PI / 180.0);  /* in radians */
	cairo_set_line_width(cr, line_width);


	
	/* char num[10]; */
	/* char ext[10] = ".png"; */
	
	if (angle1 < angle2) {
		for (double i = angle1; i < (angle2 + increment);) {
			cairo_arc(cr, xc, yc, radius, angle1, i);
			if (fill) {
				cairo_fill(cr);
			}

			if (stroke) {
				cairo_stroke(cr);
			}
			char name[30] = "filename";

			itoa(count, num, 10);
			strcat(name, num);
			strcat(name, ext);
			
			cairo_surface_write_to_png(surface, name);
			printf("count: %d. Completed angle2: %f\n", count, i);
			i += increment;
			count++;
		}
	}

	if (angle1 > angle2) {
		while (angle1 > angle2) {
			angle2 = (2 * M_PI) + angle2;
			printf("in while: angle1: %f, angle2: %f, i: %f\n", angle1, angle2, angle1);
		}
		
		for (double i = angle1; i < (angle2 + increment);) {
			cairo_arc(cr, xc, yc, radius, angle1, i);
			if (fill) {
				cairo_fill(cr);
			}

			if (stroke) {
				cairo_stroke(cr);
			}
			char name[30] = "filename";

			itoa(count, num, 10);
			strcat(name, num);
			strcat(name, ext); 
		
			cairo_surface_write_to_png(surface, name);
			printf("count: %d. Completed angle2: %f\n", count, i);
			i += increment;
			count++;
		}
	}
}


void draw_inv_circle_animation(cairo_t *cr, double xc, double yc,
							   double radius, double angle1,
							   double angle2, double line_width,
							   colors color, bool fill, bool stroke) {
	select_color(cr, color);
	angle1 = angle1 * (M_PI / 180.0);  /* in radians */
	angle2 = angle2 * (M_PI / 180.0);  /* in radians */
	cairo_set_line_width(cr, line_width);


	/* char num[10]; */
	/* char ext[10] = ".png"; */

	/* Normal Case */
	if (angle1 > angle2) {
		for (double i = angle1; i > (angle2 - increment);) {
			cairo_arc_negative(cr, xc, yc, radius, angle1, i);
			if (fill) {
				cairo_fill(cr);
			}

			if (stroke) {
				cairo_stroke(cr);
			}

			char name[30] = "filename";
		
			itoa(count, num, 10);
			strcat(name, num);
			strcat(name, ext); 
		
			cairo_surface_write_to_png(surface, name);
			printf("count: %d. Completed angle2: %f\n", count, i);
			i -= increment;
			count++;
		}
	}
	
	if (angle1 < angle2) {
		while (angle1 < angle2) {
			printf("%f changed to %f\n", angle2, (angle2 - (2 * M_PI)));
			printf("Now angle1: %f\n", angle1);
			angle2 = angle2 - (2 * M_PI);
		} 
		
		for (double i = angle1; i > (angle2 - increment);) {
			cairo_arc_negative(cr, xc, yc, radius, angle1, i);
			if (fill) {
				cairo_fill(cr);
			}

			if (stroke) {
				cairo_stroke(cr); 
			}
			char name[30] = "filename";

			itoa(count, num, 10);
			strcat(name, num);
			strcat(name, ext); 
		
			cairo_surface_write_to_png(surface, name);
			printf("count: %d. Completed angle2: %f\n", count, i);
			i -= increment;
			count++;
		}
	}
	
}


void draw_line(cairo_t *cr, double x0, double y0,
			   double x1, double y1, double line_width, colors color) {

	select_color(cr, color);
	cairo_set_line_width(cr, line_width);
	cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
	

	cairo_move_to(cr, x0, y0);
	cairo_line_to(cr, x1, y1);
	cairo_stroke(cr);
	
}


void line_handle_rl_ud(cairo_t *cr, double x0, double y0,
					   double x1, double y1)
{
	cairo_move_to(cr, x0, y0);
	double inc_x = (x0 - x1) / DENOMINATOR;
	double inc_y = (y0 - y1) / DENOMINATOR;

	double slope = (y1 - y0) / (x1 - x0);
	
	
	printf("Line from (%f, %f) to (%f, %f)\n", x0, y0, x1, y1);

	
	for (double i = x0, j = y0; i >= (x1) || j >= (y1); ) {
		cairo_line_to(cr, i, j);
		cairo_stroke(cr);
		char name[30] = "filename";
		itoa(count, num, 10);
		strcat(name, num);
		strcat(name, ext);

		printf("i: %f, j: %f, slope: %f\n", i, j, slope);
		
		cairo_move_to(cr, i, j);

		if (i >= x1) {
			i -= 5.0;
		}

		if (j >= y1) {
			j -= 5.0;
		}

		if (i > x1 || j > y1) {
			cairo_line_to(cr, x1, y1);
			cairo_surface_write_to_png(surface, name);
			count++;

		}
		
		cairo_surface_write_to_png(surface, name);
		count++;

		
	}

	
	
}

void draw_line_animation(cairo_t *cr, double x0, double y0,
						 double x1, double y1, double line_width, colors color) {

	
	select_color(cr, color);
	cairo_set_line_width(cr, line_width);
	cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);

	
	if (x0 > x1) {
		right_to_left = true;
		printf("right_to_left\n");
		/* local_increment_x = -(local_increment_x); */
	}

	if (x0 < x1) {
		left_to_right = true;		
		printf("left_to_right\n");
	}

	if (x0 == x1) {
		vertical_line = true;
		printf("vertical_line\n");
		/* local_increment_x = x1; */
	}


	if (y0 > y1) {
		up_to_down = true;
		printf("up_to_down\n");
		/* local_increment_y = -(local_increment_y); */
	}

	if (y0 < y1) {
		down_to_up = true;
		printf("down_to_up\n");
	}

	if (y0 == y1) {
		horizontal_line = true;
		printf("horizontal_line\n");
		/* local_increment_y = y1; */
	}

	if (vertical_line && horizontal_line) {
		no_line = true;
		/* local_increment_x = x1; */
		/* local_increment_y= y1; */
	}

	printf("\n\nup_to_down: %d\n", up_to_down);
	printf("down_to_up: %d\n", down_to_up);
	printf("right_to_left: %d\n", right_to_left);
	printf("left_to_right: %d\n", left_to_right);
	printf("vertical_line: %d\n", vertical_line);
	printf("horizontal_line: %d\n\n\n", horizontal_line);

	
	if (right_to_left && up_to_down) {
		line_handle_rl_ud(cr, x0, y0, x1, y1);
	}


	/* if (right_to_left && down_to_up) { */
	/* 	line_handle_rl_du(cr, x0, y0, x1, y1); */
	/* } */

	/* if (left_to_right && up_to_down) { */
	/* 	line_handle_lr_ud(cr, x0, y0, x1, y1); */
	/* } */

	/* if (left_to_right && down_to_up) { */
	/* 	line_handle_lr_du(cr, x0, y0, x1, y1); */
	/* } */

	/* if (left_to_right && horizontal_line) { */
		
	/* } */

	/* if (right_to_left && horizontal_line) { */
		
	/* } */

	/* if (up_to_down && vertical_line) { */
		
	/* } */

	/* if (down_to_up && vertical_line) { */
		
	/* } */

	/* if (no_line) { */
		
	/* } */

}



void draw_arrow(cairo_t* cr, struct Point p1, struct Point p2,
				double scale, double line_width, colors color,
				cairo_line_join_t line_join_type)
{
	cairo_set_line_width(cr, line_width);
	select_color(cr, color);
	cairo_set_line_join(cr, line_join_type);
	
	cairo_move_to(cr, p1.x - ARROW_HAND, p1.y + ARROW_HAND);
	cairo_rel_line_to(cr, ARROW_HAND, -ARROW_HAND);
	cairo_rel_line_to(cr, ARROW_HAND, ARROW_HAND);

	cairo_move_to(cr, p1.x, p1.y);
	cairo_line_to(cr, p2.x, p2.y);

	cairo_stroke(cr);
}



void save_image(cairo_surface_t *surface, char* filename) {
	cairo_surface_write_to_png(surface, filename);
}


void clear_memory() {
	cairo_destroy(cr);
	cairo_surface_destroy(surface);
}


/* int main(int argc, char *argv[]) */
/* { */
/* 	initialize_with_image_surface(width, height); */
/* 	create_background(cr, WHITE); */
/* 	draw_inv_circle_animation(cr, width / 2, height / 2, 150.0, 360.0, 0.0, 10.0, BLUE, false, true); */
/* 	draw_circle_animation(cr, width / 2, height / 2, 300.0, 0.0, 270.0, 10.0, BLACK, false, true); */
/* 	draw_inv_circle_animation(cr, width / 2, height / 2, 450.0, 0.0, 180.0, 10.0, RED, false, true); */
/* 	draw_circle_animation(cr, width / 2, height / 2, 600.0, 0.0, 720.0, 10.0, YELLOW, true, true); */
/* 	// draw_circle(cr, width / 2, height / 2, 300.0, 0.0, 360.0 , 10, BLUE, true, true); */
/* 	// save_image(surface, "filename.png"); */

/* 	/\* select_color(cr, BLACK); *\/ */
/* 		/\* double angle1 = 720.0; *\/ */
/* 	/\* angle1 = angle1 * (M_PI / 180.0);  /\\* in radians *\\/ *\/ */
/* 	/\* double angle2 = 0.0; *\/ */
/* 	/\* angle2 = angle2 * (M_PI / 180.0);  /\\* in radians *\\/ *\/ */
/* 	/\* cairo_set_line_width(cr, 10); *\/ */

/* 	/\* cairo_arc(cr, width / 2, height / 2, 300.0, angle1, angle2); *\/ */
/* 	/\* cairo_stroke(cr); *\/ */
/* 	/\* save_image(surface, "filename.png"); *\/ */


/* 	clear_memory();  */
/*     return 0; */
	
/* } */


#undef JOIN_BEVEL
#undef JOIN_MITER
#undef JOIN_ROUND
#undef DENOMINATOR



/* drawtools.h ends here */
