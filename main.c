#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

void ExecuteAddition(WINDOW *win) {
	char num1[100];
	char num2[100];
	move(getcury(win)-2,0);
	winstr(win, num1);
	move(getcury(win)+1,0);
	winstr(win, num2);
	move(getcury(win)-1,0);
	printw("%d\n", atoi(num1) + atoi(num2));
	clrtoeol();
}



int main() {	
	int ch;

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
		} else if (ch == 43) { /* if input == + */
			ExecuteAddition(win);
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
