#include <curses.h>
#include <ncurses.h>

int lines[10][10];



int main()
{	int ch;

	WINDOW *win = initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

	while (true) {
		ch = getch();			/* If raw() hadn't been called */

		if (ch == 113) { /* if input == q */
			break;
		} else if (ch == KEY_BACKSPACE) {
			move(getcury(win), getcurx(win)-1);
			delch();
		} else {
			printw("%c", ch);
		}
		refresh();			/* Print it on to the real screen */
	}
	endwin();			/* End curses mode		  */

	return 0;
}



// Apply Bold style
	// attron(A_BOLD);
	// attroff(A_BOLD);
