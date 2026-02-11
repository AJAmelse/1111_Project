/*
    jit.h
    Dan Runningen

    "Just in time" interactive functions. A very small cross-platform
    non-blocking set of keyboard helpers for interactive console games.

    Normally, most of the contents in this file would be in an additional .c
    file. For simplicity with compiling for newer students, this file simply
    needs to be placed at the same level as the file that includes it.

        #include "jit./h"

    NOTE: Compiling with this header will mean you NEED to use the -lm flag!

    Originally drafted by Lumo and refined with some documentation and
    standardization.
*/
#ifndef INPUT_H
#define INPUT_H

#include <math.h>
#include <stdlib.h>

/*
    This clear only works for POSIX systems, but SOMETIMES Windows knows how to
    use it, depending on how the terminal is configured. This call alone is NOT
    platform independent.

    Use clear_screen() instead!
*/
static inline void _posix_clear() {
    fputs("\x1b[2J\x1b[H", stdout);
    fflush(stdout);
}

#ifdef _WIN32 /* ~~~~~~~~~~~~~~~~~~~~ Windows Templates ~~~~~~~~~~~~~~~~~~~~ */
    #include <conio.h>      // Uses the _getch() and _kbhit() functions.
    #include <windows.h>    // Spcifically for the system's Sleep() call.

    // Clears the terminal contents to prepare for a clean frame render.
    static inline void clear_screen() {
        // This only needs to be determined once.
        static int already_done = 0;
        static int posix = 1;
        if (!already_done) {
            //// TODO: Document this better.
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE) {
                posix = 0;
            } else {
                DWORD dwMode = 0;
                if (!GetConsoleMode(hOut, &dwMode)) {
                    posix = 0;
                } else {
                    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                    if (!SetConsoleMode(hOut, dwMode)) {
                        posix = 0;
                    }
                }
            }
            already_done = 1;
        }

        // Use POSIX clearing where possible.
        if (posix) {
            _posix_clear();
        } else {
            system("cls");
        }
    }

    // Waits for a keypress without blocking the rest of the program.
    static inline int get_key() {
        return _getch();
    }

    // Returns true if a keypress is in the buffer.
    static inline int pending_key() {
        return _kbhit();
    }

    // Waits a specified number of seconds before proceeding.
    static inline void wait(float seconds) {
        // Stop silly negative calls.
        if (seconds <= 0) { return; }
        // Convert seconds to milliseconds.
        Sleep((int)floor(seconds * 1000));
    }
#else /* ~~~~~~~~~~~~~~~~~~~~~~~~~ POSIX Templates ~~~~~~~~~~~~~~~~~~~~~~~~~ */
    #include <errno.h>
    #include <fcntl.h>
    #include <sys/select.h>
    #include <termios.h>
    #include <time.h>
    #include <unistd.h>

    // The static variables 
    static struct termios _orig_termios;

    // A lambda function to call with the atexit() function. DO NOT CALL EXTERNALLY.
    static void _termios_restore() {
        tcsetattr(STDIN_FILENO, TCSANOW, &_orig_termios);
    }

    // Clears the terminal contents to prepare for a clean frame render.
    static inline void clear_screen() {
        _posix_clear();
    }

    // Waits for a keypress without blocking the rest of the program.
    static inline int get_key() {
        unsigned char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
            return (int)c;
        }
        return 0; // No key waiting to match Windows behavior.
    }

    // Returns true if a keypress is in the buffer.
    static inline int pending_key() {
        // The terminos library only needs to be initialized once.
        static int termios_initialized = 0;
        if (!termios_initialized) {
            //// TODO: Document this better.
            struct termios new_termios;
            tcgetattr(STDIN_FILENO, &_orig_termios);
            new_termios = _orig_termios;
            new_termios.c_lflag &= ~(ICANON | ECHO);        /* raw mode, no echo */
            tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
            atexit(_termios_restore);                       /* restore on exit */

            // Flag the terminos as being initialized already.
            termios_initialized = 1;
        }

        //// TODO: Document this better.
        fd_set read_fds;
        struct timeval tv = {0, 0};                 /* zero timeout -> poll */
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
        return select(STDIN_FILENO+1, &read_fds, NULL, NULL, &tv) > 0;
    }

    // Waits a specified number of seconds before proceeding.
    static inline void wait(float seconds) {
        // Stop silly negative calls.
        if (seconds <= 0) { return; }
        // Convert seconds to milliseconds.
        struct timespec ts = {
            (int)floor(seconds),                                    // seconds
            (int)((seconds - floor(seconds)) * 1000 * 1000 * 1000)  // nanoseconds
        };
        while (nanosleep(&ts, &ts)) { /* Keep sleeping until done. */ }
    }
#endif // for platform-specific defines

#endif // for INPUT_H
