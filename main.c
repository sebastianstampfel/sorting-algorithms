#include "bubblesort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "binary-search.h"
#include "main.h"



node* randomizedArray(int elementCount){
    node* array = malloc(sizeof(node) * elementCount);

    for(int i = 0; i < elementCount; i++){
        node* current = array + i;
        current->number = rand() % 32767;
    }

    return array;
}

void printInMiddle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
    float temp;

    if(win == NULL)
        win = stdscr;
    getyx(win, y, x);
    if(startx != 0)
        x = startx;
    if(starty != 0)
        y = starty;
    if(width == 0)
        width = 80;

    length = strlen(string);
    temp = (width - length)/ 2;
    x = startx + (int)temp;
    wattron(win, color);
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, color);
    refresh();
}

void itemSelectionHandler(char *name){
    // do something
    move(0, 0);
    clrtoeol();
    if(strcmp(name, "First item") == 0){
        printw("First item!");
    } else if(strcmp(name, "Run quicksort") == 0){
        double timeQuicksort1000 = 0;
        double timeQuicksort5000 = 0;
        double timeQuicksort10000 = 0;
        double timeQuicksort25000 = 0;

        quicksort(1000, &timeQuicksort1000);
        quicksort(5000, &timeQuicksort5000);
        quicksort(10000, &timeQuicksort10000);
        quicksort(25000, &timeQuicksort25000);

        attron(A_BOLD);
        attron(COLOR_PAIR(1));
        printw("Quicksort time for %d elements: %f seconds\n", 1000, timeQuicksort1000);
        printw("Quicksort time for %d elements: %f seconds\n", 5000, timeQuicksort5000);
        printw("Quicksort time for %d elements: %f seconds\n", 10000, timeQuicksort10000);
        printw("Quicksort time for %d elements: %f seconds\n", 25000, timeQuicksort25000);
        attroff(A_BOLD);
        attroff(COLOR_PAIR(1));
        printw("Press any key to return to menu...");
    } else {
        printw("ERROR!");
    }
    getch();
    wclear(stdscr);
}

void drawMenuWithBox(WINDOW *window, MENU *menu){
    box(window, 0, 0);
    printInMiddle(window, 1, 0, 40, "Algorithms", COLOR_PAIR(1));
    mvwaddch(window, 2, 0, ACS_LTEE);
    mvwhline(window, 2, 1, ACS_HLINE, 38);
    mvwaddch(window, 2, 39, ACS_RTEE);
    mvprintw(LINES - 2, 0, "F1 to exit");
    refresh();
    post_menu(menu);
    wrefresh(window);;
}

int main() {
    int input;
    initscr();			    /* Start curses mode 		  */
    raw();				    /* Line buffering disabled	*/
    keypad(stdscr, TRUE);	/* We get F1, F2 etc..		*/
    noecho();			    /* Don't echo() while we do getch */
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    WINDOW *my_menu_win;
    my_menu_win = newwin(10, 40, 0, 0);
    keypad(my_menu_win, TRUE);
    scrollok(stdscr, TRUE);

    ITEM *items[6];
    items[0] = new_item("Run all algorithms w/ bsearch", "");
    items[1] = new_item("Run bubblesort", "");
    items[2] = new_item("Run quicksort", "");
    items[3] = new_item("Run mergesort", "");
    items[4] = new_item("Run binary search", "");
    set_item_userptr(items[0], itemSelectionHandler);
    set_item_userptr(items[1], itemSelectionHandler);
    set_item_userptr(items[2], itemSelectionHandler);
    set_item_userptr(items[3], itemSelectionHandler);
    set_item_userptr(items[4], itemSelectionHandler);

    items[5] = (ITEM *)NULL;

    MENU *menu = new_menu(items);
    set_menu_win(menu, my_menu_win);
    set_menu_sub(menu, derwin(my_menu_win, 6, 38, 3, 1));
    set_menu_mark(menu, " * ");

    drawMenuWithBox(my_menu_win, menu);

    while(1){
        input = getch();
        if(input == KEY_F(1)){
            break;
        } else if(input == KEY_UP){
            menu_driver(menu, REQ_UP_ITEM);
        } else if(input == KEY_DOWN){
            menu_driver(menu, REQ_DOWN_ITEM);
        } else if(input == 10){
            ITEM *cur;
            void (*p)(char *);

            cur = current_item(menu);
            p = item_userptr(cur);
            unpost_menu(menu);
            wclear(my_menu_win);
            wrefresh(my_menu_win);
            p((char *)item_name(cur));
            drawMenuWithBox(my_menu_win, menu);
            pos_menu_cursor(menu);
        }
        wrefresh(my_menu_win);
    }

    unpost_menu(menu);
    free_menu(menu);
    free_item(items[0]);
    free_item(items[1]);
    free_item(items[2]);
    free_item(items[3]);
    free_item(items[4]);
    endwin();			    /* End curses mode		  */

    /* char userInput = '\0';
    printf("GDI - Sorting algorithms and bsearch\n");
    printf("Sebastian Stampfel, 2019\n");

    printf("\nStart sorting? (y/n) ");
    userInput = (char) getchar();
    getchar(); // Consumes '\n' from before

    if(userInput == 'y'){
        double timeBubblesort1000 = 0;
        double timeBubblesort5000 = 0;
        double timeBubblesort10000 = 0;
        double timeBubblesort25000 = 0;

        double timeQuicksort1000 = 0;
        double timeQuicksort5000 = 0;
        double timeQuicksort10000 = 0;
        double timeQuicksort25000 = 0;

        double timeMergesort1000 = 0;
        double timeMergesort5000 = 0;
        double timeMergesort10000 = 0;
        double timeMergesort25000 = 0;

        bubblesort(1000, &timeBubblesort1000);
        bubblesort(5000, &timeBubblesort5000);
        bubblesort(10000, &timeBubblesort10000);
        bubblesort(25000, &timeBubblesort25000);

        quicksort(1000, &timeQuicksort1000);
        quicksort(5000, &timeQuicksort5000);
        quicksort(10000, &timeQuicksort10000);
        quicksort(25000, &timeQuicksort25000);

        mergesortTimed(1000, &timeMergesort1000);
        mergesortTimed(5000, &timeMergesort5000);
        mergesortTimed(10000, &timeMergesort10000);
        mergesortTimed(25000, &timeMergesort25000);

        printf("╔══════════════════════════════════════╗\n");
        printf("║             TIMING RESULTS           ║\n");
        printf("╠══════════════════════════════════════╣\n");
        printf("║Times for Bubblesort:                 ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
                       "║5000 Elements: %f seconds       ║\n"
                       "║10000 Elements: %f seconds      ║\n"
                       "║25000 Elements: %f seconds      ║\n"
                       "╠══════════════════════════════════════╣\n",
                       timeBubblesort1000, timeBubblesort5000, timeBubblesort10000, timeBubblesort25000);
        printf("║Times for Quicksort:                  ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
               "║5000 Elements: %f seconds       ║\n"
               "║10000 Elements: %f seconds      ║\n"
               "║25000 Elements: %f seconds      ║\n"
               "╠══════════════════════════════════════╣\n",
               timeQuicksort1000, timeQuicksort5000, timeQuicksort10000, timeQuicksort25000);
        printf("║Times for Mergesort:                  ║\n");
        printf("║1000 Elements: %f seconds       ║\n"
               "║5000 Elements: %f seconds       ║\n"
               "║10000 Elements: %f seconds      ║\n"
               "║25000 Elements: %f seconds      ║\n",
               timeMergesort1000, timeMergesort5000, timeMergesort10000, timeMergesort25000);
        printf("╚══════════════════════════════════════╝\n");
    }

    printf("\nContinue with binary search? (y/n) ");
    userInput = (char) getchar();
    getchar(); // Consumes '\n' from before
    if(userInput != 'y'){
        return 0;
    }
    binarysearch(500); */

    return 0;
}
